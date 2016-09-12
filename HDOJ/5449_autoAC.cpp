#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 50005;
int N, E, first[maxn], jump[maxn<<1], linker[maxn<<1];
ll sz[maxn], up[maxn], dn[maxn], f[20][maxn], dep[maxn];
void addEdge(int u, int v) {
    jump[E] = first[u];
    linker[E] = v;
    first[u] = E++;
}
void dfs (int u, int far, int d) {
    sz[u] = 1;
    dep[u] = d;
    f[0][u] = far;
    for (int i = first[u]; i + 1; i = jump[i]) {
        int v = linker[i];
        if (v == far) continue;
        dfs(v, u, d + 1);
        sz[u] += sz[v];
    }
}
void dfs (int u) {
    if (f[0][u] != -1) {
        up[u] = up[f[0][u]] + 2 * sz[u] - 1;
        dn[u] = dn[f[0][u]] + 2 * (N-sz[u]) - 1;
    } else
        up[u] = dn[u] = 0;
    for (int i = first[u]; i + 1; i = jump[i]) {
        int v = linker[i];
        if (v == f[0][u]) continue;
        dfs(v);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    int d = dep[u] - dep[v];
    for (int i = 0; i < 20; i++) if ((1<<i)&d)
        u = f[i][u];
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (f[i][u] != f[i][v]) {
            u = f[i][u];
            v = f[i][v];
        }
    }
    return f[0][u];
}
void init () {
    E = 0;
    memset(first, -1, sizeof(first));
    int u, v;
    scanf("%d", &N);
    for (int i = 1; i < N; i++) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }
    dfs(0, -1, 0);
    dfs(0);
    for (int k = 1; k < 20; k++) {
        for (int i = 0; i < N; i++)
            f[k][i] = f[k-1][f[k-1][i]];
    }
}
ll get (int u, int v) {
    int l = lca(u, v);
    return up[u] - up[l] + dn[v] - dn[l];
}
void solve () {
    int q, p, u, v;
    scanf("%d", &q);
    while (q--) {
        ll ans = 0;
        scanf("%d%d", &p, &u);
        while (p--) {
            scanf("%d", &v);
            ans += get(u, v);
            u = v;
        }
        printf("%lld.0000\n", ans);
    }
}
int main () {
    int cas;
    scanf("%d", &cas);
    while (cas--) {
        init();
        solve();
        if (cas) printf("\n");
    }
    return 0;
}
