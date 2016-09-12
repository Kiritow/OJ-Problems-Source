#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <functional>
#include <cassert>
#include <bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ff(i, n) for(int i=0,END=(n);i<END;i++)
#define fff(i, n, m) for(int i=(n),END=(m);i<=END;i++)
#define dff(i, n, m) for(int i=(n),END=(m);i>=END;i--)
#define travel(e, u) for(int e=first[u], v=vv[first[u]]; ~e; e=nxt[e])
#define mid ((l+r)/2)
#define bit(n) (1ll<<(n))
#define clr(a, b) memset(a, b, sizeof(a))
#define debug(x) cout << #x << " = " << x << endl;
#define ls (rt << 1)
#define rs (ls | 1)
#define lson l, m, ls
#define rson m + 1, r, rs
void work();
int main() {
    work();
    return 0;
}
const int maxn = 222;
const int maxv = 5e4 + 5 + maxn;
const int inf = 0x3f3f3f3f;
int n, m, p;
int dp[maxv];
void zero_one_pack(int v, int c, int V) {
    dff(i, V, v) {
        dp[i] = min(dp[i], dp[i - v] + c);
    }
}
void zero_one_pack2(int v, int c, int V) {
    dff(i, V, v) {
        dp[i] = max(dp[i], dp[i - v] + c);
    }
}
void multi_pack(int v, int c, int num, int V, bool flag = true) {
    int k = 1;
    while (num) {
        if (flag)
            zero_one_pack(v * k, c * k, V);
        else
            zero_one_pack2(v * k, c * k, V);
        num -= k;
        k += k;
        if (k > num) k = num;
    }
}
void input() {
    scanf("%d%d%d", &n, &m, &p);
    clr(dp, inf); dp[0] = 0;
    ff (i, n) {
        int v, c, num;
        scanf("%d%d%d", &v, &c, &num);
        multi_pack(v, c, num, p + 100);
    }
    int V = *min_element(dp + p, dp + p + 100);
    clr(dp, 0);
    ff (i, m) {
        int v, c, num;
        scanf("%d%d%d", &v, &c, &num);
        multi_pack(c, v, num, 50000, false);
    }
    int ans = inf;
    dff(i, 50000, 0) if (dp[i] >= V) {
        ans = min(ans, i);
    }
    if (ans == inf) {
        puts("TAT");
    } else {
        printf("%d\n", ans);
    }
}
void work() {
    int T; scanf("%d", &T);
    fff(cas, 1, T) {
        input();
    }
}
