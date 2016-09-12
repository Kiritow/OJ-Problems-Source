#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <vector>
using namespace std;
template <class T>
inline bool rd(T &ret) {
    char c; int sgn;
    if (c = getchar(), c == EOF) return 0;
    while (c != '-' && (c<'0' || c>'9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0'&&c <= '9') ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
template <class T>
inline void pt(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) pt(x / 10);
    putchar(x % 10 + '0');
}
typedef pair<int, int> pii;
typedef long long ll;
const int N = 1005;
const int mod = 1e9 + 7;
const int inf = 1e9;
int Pow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1)ans = (ll)ans*x%mod;
        y >>= 1;
        x = (ll)x*x%mod;
    }return ans;
}
vector<int>G[N];
int n, k;
int dp[N][N], siz[N], lef[N];
int A[N];
int mul(int x, int y) {
    x = (ll)x*y%mod;
    return x;
}
inline void add(int &x, int y) {
    x += y; if (x >= mod)x -= mod;
}
inline void sub(int &x, int y) {
    x -= y; if (x < 0)x += mod;
}
inline void dv(int &x, int y) {
    x = (ll)x*Pow(y, mod - 2) % mod;
}
int g[N];
void dfs(int u, int fa) {
    siz[u] = 1; lef[u] = 0;
    for (auto v : G[u]) {
        if (v == fa)continue;
        dfs(v, u);
        siz[u] += siz[v];
    }
    if (siz[u] == 1) {
        dp[u][0] = 0; dp[u][1] = 1;
        lef[u] = 1;
        return;
    }
    dp[u][0] = 1;
    int x1 = A[siz[u] - 1], x2 = A[siz[u]];
    siz[u] = 0;
    for (auto v : G[u]) {
        if (v == fa)continue;
        for (int i = lef[u] + lef[v]; i <= min(k, siz[u] + siz[v]); i++)g[i] = 0;
        for (int i = lef[u]; i <= min(k, siz[u]); i++)
        {
            for (int j = lef[v]; j <= min(k, siz[v]) && i + j <= k; j++)
            {
                add(g[i + j], mul(dp[v][j], dp[u][i]));
            }
        }
        for (int i = lef[u] + lef[v]; i <= min(k, siz[u] + siz[v]); i++)dp[u][i] = g[i];
        siz[u] += siz[v];
        lef[u] += lef[v];
        dv(x1, A[siz[v]]);
        dv(x2, A[siz[v]]);
    }
    siz[u]++;
    sub(x2, x1);
    for (int i = min(siz[u], k); i >= lef[u]; i--) {
        int tmp = 0;
        add(tmp, mul(dp[u][i], x2));
        if (i - 1 >= lef[u])
        add(tmp, mul(dp[u][i - 1], x1));
        dp[u][i] = tmp;
    }
}
int main() {
    A[0] = 1;
    for (int i = 1; i < N; i++)A[i] = (ll)A[i - 1] * i%mod;
    int T, Cas = 1; rd(T);
    while (T--) {
        rd(n); rd(k);
        for (int i = 1; i <= n; i++)G[i].clear(), memset(dp[i], 0, sizeof dp[i]);
        for (int i = 1, u, v; i < n; i++) {
            rd(u); rd(v);
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(1, 1);
        printf("Case #%d: ", Cas++);
        pt(dp[1][k]); puts("");
    }
    return 0;
}
