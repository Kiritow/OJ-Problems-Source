#include <stdio.h>  
#include <string.h>  
#include <algorithm>  
using namespace std;  
const int N = 100005;  
typedef long long ll;  
int n, m;  
ll q;  
struct Hash {  
    int v, id;  
    void read(int id) {  
        scanf("%d", &v);  
        this->id = id;  
    }  
} h[N];  
bool cmp(Hash a, Hash b) {  
    return a.v < b.v;  
}  
int a[N];  
int bit[N], l[N];  
inline int lowbit(int x) {return (x&(-x));}  
void add(int x, int v) {  
    while (x <= n) {  
        bit[x] += v;  
        x += lowbit(x);  
    }  
}  
int get(int x) {  
    int ans = 0;  
    while (x) {  
        ans += bit[x];  
        x -= lowbit(x);  
    }  
    return ans;  
}  
ll sum[N], sum2[N];  
ll ans[N];  
int X[N], Y[N];  
void gao(ll q, int bo) {  
    if (q < 0) return;  
    memset(bit, 0, sizeof(bit));  
    int r = 0;  
    ll tot = 0;  
    for (int i = 1; i <= n; i++) {  
        while (r <= n && tot <= q) {  
            r++;  
            if (r > n) break;  
            tot += (r - i) - get(a[r]);  
            add(a[r], 1);  
        }  
        l[i] = r - 1;  
        add(a[i], -1);  
        tot -= get(a[i] - 1);  
    }  
    sum[n + 1] = 0;  
    for (int i = n; i >= 1; i--)  
        sum[i] = sum[i + 1] + (l[i] - i + 1);  
    int x, y;  
    for (int i = 0; i < m; i++) {  
        int x = X[i], y = Y[i];  
        int tmp = lower_bound(l + x, l + y + 1, y) - l - 1;  
        ans[i] += bo * (sum[x] - sum[tmp + 1] + sum2[y - tmp]);  
    }  
}  
int main() {  
    for (int i = 1; i < N; i++)  
        sum2[i] = sum2[i - 1] + i;  
    while (~scanf("%d%d%I64d", &n, &m, &q)) {  
        for (int i = 1; i <= n; i++)  
            h[i].read(i);  
        sort(h + 1, h + n + 1, cmp);  
        int tmp = 1;  
        a[h[1].id] = 1;  
        for (int i = 1; i <= n; i++) {  
            if (h[i].v != h[i - 1].v) tmp++;  
            a[h[i].id] = tmp;  
        }  
        for (int i = 0; i < m; i++) scanf("%d%d", &X[i], &Y[i]);  
        memset(ans, 0, sizeof(ans));  
        gao(q, 1); gao(q - 1, -1);  
        for (int i = 0; i < m; i++)  
            printf("%I64d\n", ans[i]);  
    }  
    return 0;  
}
