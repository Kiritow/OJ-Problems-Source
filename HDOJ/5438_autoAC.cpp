#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e4 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
const int M = 1e5 + 10;
int n, m;
int deg[N], val[N];
vector<int> G[N];
bool vis[N];
void dfs(int u, int &cnt, long long& sum) {
    sum += val[u];
    ++cnt;
    vis[u] = true;
    for(int i = 0; i < G[u].size(); ++i) {
        int v = G[u][i];
        if(vis[v]) continue;
        dfs(v, cnt, sum);
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) {
            scanf("%d", val + i);
            G[i].clear();
            vis[i] = false;
            deg[i] = 0;
        }
        for(int i = 1; i <= m; ++i) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
            ++deg[u], ++deg[v];
        }
        queue<int> q;
        for(int i = 1; i <= n; ++i)
            if(deg[i] < 2) q.push(i);
        while(q.size()) {
            int u = q.front(); q.pop();
            deg[u] = 0; vis[u] = true;
            for(int i = 0; i < G[u].size(); ++i) {
                int v = G[u][i];
                if(--deg[v] < 2 && !vis[v]) q.push(v);
            }
        }
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            if(vis[i]) continue;
            int cnt = 0; long long sum = 0;
            dfs(i, cnt, sum);
            if(cnt & 1) ans += sum;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
