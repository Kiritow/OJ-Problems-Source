#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
struct Suffix_Arr {
    char s[maxn];
    int n, SA[maxn], rank[maxn], height[maxn];
    int tmp_one[maxn], tmp_two[maxn], c[maxn];
    ll f[maxn];
    void init ();
    void build(int m);
    void get_height();
    void solve ();
    bool judge(ll m);
}AC;
int K;
int main () {
    while (scanf("%d", &K) == 1 && K) {
        AC.init();
        AC.build(256);
        AC.get_height();
        AC.solve();
    }
    return 0;
}
bool Suffix_Arr::judge(ll m) {
    int t = lower_bound(f + 1, f + n + 1, m) - f;
    int R = n - (f[t] - m + 1);
    int len = R - SA[t] + 1;
    memset(c, -1, sizeof(c));
    c[SA[t]] = len;
    for (int i = t+1; i <= n; i++) {
        len = min(len, height[i]);
        if (len == 0)
            return false;
        c[SA[i]] = len;
    }
    int ret = 0, p = n + 1;
    for (int i = 0; i < n; i++) {
        if (i == p) {
            ret++;
            p = n + 1;
        }
        if (c[i] != -1)
            p = min(p, i + c[i]);
        if (ret >= K)
            return false;
    }
    return true;
}
void Suffix_Arr::solve() {
    ll l = 1, r = f[n];
    for (int i = 0; i < 70; i++) {
        ll mid = (l + r) / 2;
        if (judge(mid))
            r = mid;
        else
            l = mid;
    }
    int t = lower_bound(f + 1, f + n + 1, r) - f;
    int len = n - (f[t] - r + 1);
    for (int i = SA[t]; i <= len; i++)
        printf("%c", s[i]);
    printf("\n");
}
void Suffix_Arr::init() {
    scanf("%s", s);
    n = strlen(s) + 1;
}
void Suffix_Arr::get_height() {
    for (int i = 0; i < n; i++)
        rank[SA[i]] = i;
    int mv = height[n-1] = 0;
    for (int i = 0; i < n - 1; i++) {
        if (mv) mv--;
        int j = SA[rank[i] - 1];
        while (s[i+mv] == s[j+mv])
            mv++;
        height[rank[i]] = mv;
    }
    n--;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        f[i] = f[i-1] + n - SA[i] - height[i];
}
void Suffix_Arr::build(int m) {
    int *x = tmp_one, *y = tmp_two;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[x[i] = s[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i-1];
    for (int i = n - 1; i >= 0; i--) SA[--c[x[i]]] = i;
    for (int k = 1; k <= n; k <<= 1) {
        int mv = 0;
        for (int i = n - k; i < n; i++) y[mv++] = i;
        for (int i = 0; i < n; i++) if (SA[i] >= k)
            y[mv++] = SA[i] - k;
        for (int i = 0; i < m; i++) c[i] = 0;
        for (int i = 0; i < n; i++) c[x[y[i]]]++;
        for (int i = 1; i < m; i++) c[i] += c[i-1];
        for (int i = n - 1; i >= 0; i--) SA[--c[x[y[i]]]] = y[i];
        swap(x, y);
        mv = 1;
        x[SA[0]] = 0;
        for (int i = 1; i < n; i++)
            x[SA[i]] = (y[SA[i-1]] == y[SA[i]] && y[SA[i-1] + k] == y[SA[i] + k] ? mv - 1 : mv++);
        if (mv >= n)
            break;
        m = mv;
    }
}
