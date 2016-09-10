#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
using namespace std;
#define  N    333
#define  LL   long long
#define  mod  10007ll
#define  inf  0XFFFFFFF
#define  pii  pair<int, int>
#define  mp   make_pair
#define  eps  1e-3
int n;
vector<int> node[N];
int sz[N];
int pre(LL dp[]) {
    int ret = n;
    while (ret > 0 && dp[ret] == 0) ret--;
    return ret;
}
int dfs(int u, int fa) {
    int ret = 1;
    for (int i = 0; i < node[u].size(); i++) {
        if (node[u][i] == fa) continue;
        int tmp = dfs(node[u][i], u);
        sz[u] = max(sz[u], tmp);
        ret += tmp;
    }
    if (fa != -1)
        sz[u] = max(sz[u], n - ret);
    return ret;
}
LL dp[N][N];
void getdp(int u, int fa) {
    for (int i = 0; i < node[u].size(); i++) {
        if (node[u][i] == fa) continue;
        getdp(node[u][i], u);
    }
    dp[u][0] = 1;
    dp[u][1] = 1;
    for (int i = 0; i < node[u].size(); i++) {
        int v = node[u][i];
        if (v == fa) continue;
        int x = pre(dp[u]);
        int y = pre(dp[v]);
        for (int l1 = x; l1 > 0; l1--) {
            for (int l2 = y; l2 > 0; l2--) {
                dp[u][l1 + l2] += dp[u][l1] * dp[v][l2];
                dp[u][l1 + l2] %= mod;
            }
        }
    }
}
LL work1(int u1, int u2) {
    getdp(u1, u2);
    getdp(u2, u1);
    LL ret = 0;
    for (int i = 1; i <= n; i++)
        ret = (ret + dp[u1][i] * dp[u2][i]) % mod;
    return ret;
}
LL f[N];
LL work(int u) {
    getdp(u, -1);
    LL ct = 0;
    for (int i = 0; i < node[u].size(); i++) {
        memset(f, 0, sizeof f);
        f[0] = 1;
        int v = node[u][i];
        for (int j = 0; j < node[u].size(); j++) {
            if (i == j) continue;
            int l1 = pre(f);
            int l2 = pre(dp[node[u][j]]);
            for (int x = l1; x >= 0; x--) {
                for (int y = l2; y > 0; y--) {
                    f[x + y] += f[x] * dp[node[u][j]][y];
                    f[x + y] %= mod;
                }
            }
        }
        int l1 = pre(dp[v]);
        for (int x = 0; x <= l1; x++) {
            for (int y = 0; y < x; y++) {
                ct += dp[v][x] * f[y];
                ct %= mod;
            }
        }
    }
    LL l = 0;
    for (int i = 1; i <= n; i++)
        l = (l + dp[u][i]) % mod;
    return (l + mod - ct) % mod;
}
int Main() {
    int T; scanf("%d", &T);
    int tt = 0;
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            node[i].clear();
        }
        memset(sz, 0, sizeof sz);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n - 1; i++) {
            int u, v; scanf("%d%d", &u, &v);
            node[u].push_back(v);
            node[v].push_back(u);
        }
        dfs(1, -1);
        int u1 = 0, u2 = 0;
        sz[0] = n + n;
        for (int i = 1; i <= n; i++) {
            if (sz[i] < sz[u1])
                u1 = i;
            else if (sz[i] == sz[u1])
                u2 = i;
        }
        cout << "Case " << ++tt << ": ";
        if (sz[u1] == sz[u2])
            cout << work1(u1, u2) << endl;
        else cout << work(u1) << endl;
    }
    return 0;
}
int main() {
    return Main();
}
