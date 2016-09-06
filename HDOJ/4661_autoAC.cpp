#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<cstring>
typedef long long LL;
#define MAXN 1000010
#define MAXM 2000010
#define MOD 1000000007
int n;
LL fac[MAXN];
LL invfac[MAXN];
int first[MAXN], next[MAXM], v[MAXM], e;
bool vis[MAXN];
LL dp[MAXN];
LL f[MAXN];
int size[MAXN];
LL ext_gcd(LL a, LL b, LL &x, LL &y) {
    LL t, d;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    d = ext_gcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
LL invmod(LL a, LL n = MOD) {
    LL x, y;
    if (ext_gcd(a, n, x, y) != 1)
        return -1;
    return (x % n + n) % n;
}
void init() {
    int i;
    fac[0] = 1;
    for (i = 1; i < MAXN; i++) {
        fac[i] = fac[i - 1] * i;
        fac[i] %= MOD;
    }
    for (i = 0; i < MAXN; i++) {
        invfac[i] = invmod(fac[i]);
    }
}
inline void addEdge(int x, int y) {
    v[e] = y;
    next[e] = first[x];
    first[x] = e++;
}
void getSize(int x) {
    vis[x] = true;
    size[x] = 1;
    for (int i = first[x]; i != -1; i = next[i]) {
        int y = v[i];
        if (!vis[y]) {
            getSize(y);
            size[x] += size[y];
        }
    }
}
void dfs(int x) {
    vis[x] = true;
    dp[x] = fac[size[x] - 1];
    for (int i = first[x]; i != -1; i = next[i]) {
        int y = v[i];
        if (!vis[y]) {
            dfs(y);
            dp[x] *= invfac[size[y]];
            dp[x] %= MOD;
            dp[x] *= dp[y];
            dp[x] %= MOD;
        }
    }
}
void search(int x, int pre) {
    vis[x] = true;
    if (pre != -1) {
        f[x] = fac[n - 1];
        f[x] *= invfac[n - size[x]];
        f[x] %= MOD;
        LL tmp = f[pre];
        tmp *= invfac[n - 1];
        tmp %= MOD;
        tmp *= fac[n - 1 - size[x]];
        tmp %= MOD;
        tmp *= fac[size[x]];
        tmp %= MOD;
        tmp *= invmod(dp[x]);
        tmp %= MOD;
        f[x] *= tmp;
        f[x] %= MOD;
        for (int i = first[x]; i != -1; i = next[i]) {
            int y = v[i];
            if (!vis[y]) {
                f[x] *= invfac[size[y]];
                f[x] %= MOD;
                f[x] *= dp[y];
                f[x] %= MOD;
            }
        }
    }
    for (int i = first[x]; i != -1; i = next[i]) {
        int y = v[i];
        if (!vis[y]) {
            search(y, x);
        }
    }
}
int main() {
    int T;
    int i;
    int x, y;
    int ans;
    init();
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        e = 0;
        memset(first, -1, sizeof(first));
        for (i = 1; i < n; i++) {
            scanf("%d%d", &x, &y);
            addEdge(x, y);
            addEdge(y, x);
        }
        memset(vis, false, sizeof(vis));
        getSize(1);
        memset(vis, false, sizeof(vis));
        dfs(1);
        memset(vis, false, sizeof(vis));
        f[1] = dp[1];
        search(1, -1);
        ans = 0;
        for (i = 1; i <= n; i++) {
            ans += (f[i] * f[i]) % MOD;
            ans %= MOD;
        }
        printf("%d\n", ans);
    }
    return 0;
}
