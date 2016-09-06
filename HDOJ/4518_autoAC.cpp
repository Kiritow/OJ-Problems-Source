#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
const int N = 600;
LL n;
int bit[20];
LL f[60];
LL dp[15][N]; 
LL POW[15]; 
LL seq[60];
LL suf[20];
queue<int>q;
struct Ac_Auto{
    int ch[N][10];
    int fail[N];
    bool flag[N];
    int idx, root;
    int newnd() {
        memset(ch[idx], 0, sizeof (ch[idx]));
        flag[idx] = false, fail[idx] = 0;
        return idx++;
    }
    void init() {
        idx = 0, root = newnd();
    }
    void insert(LL x) {
        int id = 0;
        while (x) bit[id++] = x%10, x/=10;
        int p = root;
        for (int i = id-1; i >= 0; --i) {
            if (!ch[p][bit[i]]) ch[p][bit[i]] = newnd();
            p = ch[p][bit[i]];
        }
        flag[p] = true;
    }
    void build() {
        for (int i = 0; i < 10; ++i) {
            if (ch[root][i]) {
                q.push(ch[root][i]);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = 0; i < 10; ++i) {
                int &v = ch[u][i];
                int x = fail[u];
                if (v) {
                    q.push(v);
                    while (x && !ch[x][i]) x = fail[x];
                    fail[v] = ch[x][i];
                    flag[v] = flag[v] || flag[fail[v]];
                } else {
                    v = ch[x][i]; 
                }
            }
        }
    }
    void find(LL x) {
        int id = 0;
        while (x) bit[id++] = x%10, x/=10;
        int p = root;
        for (int i = id-1; i >= 0; --i) {
            p = ch[p][bit[i]];
            if (flag[p]) {
                cout << "OMG" << endl;
                return;
            }
        }
    }
};
Ac_Auto ac;
LL count(int p, int sta, bool bound) {
    if (p == 0) return 0;
    if (!bound && ~dp[p][sta]) return dp[p][sta];
    int y = bound ? bit[p] : 9;
    LL sum = 0;
    int tsta;
    for (int i = 0; i <= y; ++i) {
        tsta = ac.ch[sta][i];
        if (ac.flag[tsta]) {
            if (bound&&i==y) sum += suf[p-1]+1;
            else sum += POW[p-1];
            continue;
        }
        sum += ::count(p-1, tsta, bound&&i==y);
    }
    if (!bound) dp[p][sta] = sum;
    return sum;
}
LL cal(LL x) {
    int idx = 1;
    while (x) suf[idx] = suf[idx-1]+x%10*POW[idx-1], bit[idx++] = x%10, x/=10;
    return ::count(idx-1, ac.root, true);
}
void prepare() {
    f[1] = 1, f[2] = 1;
    for (int i = 3; i <= 55; ++i) {
        f[i] = f[i-1] + f[i-2];
    }
    ac.init();
    for (int i = 7; i <= 55; ++i) {
        ac.insert(f[i]);
    }
    ac.build();
    POW[0] = 1;
    for (int i = 1; i < 15; ++i) POW[i] = POW[i-1] * 10;
    memset(dp, 0xff, sizeof (dp));
    LL tmp;
    for (int i = 2; i <= 55; ++i) {
        LL l = 13, r = POW[12], mid;
        while (l <= r) {
            mid = (l + r) >> 1;
            if ((tmp=cal(mid)) < f[i]) l = mid + 1;
            else if (tmp > f[i]) r = mid - 1;
            else seq[i] = mid, r = mid - 1;
        }
    }
}
int main() {
    prepare();
    while (cin >> n, n != -1) {
        LL ret = 1LL << 60;
        for (int i = 2; i <= 55; ++i) {
            LL t = seq[i] - n;
            if (t < 0) t = -t;
            ret = min(ret, t);
        }
        cout << ret << endl;
    }
    return 0;
}
