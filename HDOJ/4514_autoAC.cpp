#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int N = 100005;
int n, m, ans;
int set[N];
int dp[N];
struct Edge {
    int v, f;
    Edge() {}
    Edge(int _v, int _f) : v(_v), f(_f) {}
};
vector<Edge>vt[N];
int find(int x) {
    return x == set[x] ? x : x = find(set[x]);
}
void dfs(int p, int u) {
    int forkmax = 0;
    for (int i = 0; i < (int)vt[u].size(); ++i) {
        int v = vt[u][i].v, f = vt[u][i].f;
        if (v == p) continue;
        dfs(u, v);
        ans = max(ans, dp[v]+f+forkmax);
        forkmax = max(forkmax, dp[v] + f);
    }
    dp[u] = forkmax;
}
void solve() {
    for (int i = 1; i <= n; ++i) {
        if (dp[i] == -1) dfs(0, i);
    }
    printf("%d\n", ans);
}
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        int a, b, c, x, y;
        bool loop = false;
        ans = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = -1;
            set[i] = i;
            vt[i].clear();
        }
        for (int i = 0; i < m; ++i) {
            scanf("%d %d %d", &a, &b, &c);
            if (loop) continue;
            x = find(a), y = find(b);
            if (x != y) set[x] = y;
            else loop = true;
            vt[a].push_back(Edge(b, c));
            vt[b].push_back(Edge(a, c));
        }
        if (loop) {
            puts("YES");
            continue;
        }
        solve();
    }
    return 0;
}
