#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 5e5 + 10;
const int INF = 0x3f3f3f3f;
int w[MAXN];
int cnt[MAXN];
int deg[MAXN];
vector<int> G[MAXN];
int n;
int BFS(void)   {
    queue<int> Q;   int ret = 0;
    for (int i=1; i<=n; ++i)    cnt[i] = 1;
    for (int i=1; i<=n; ++i)    {
        if (!deg[i])    Q.push (i);
    }
    while (!Q.empty ()) {
        int u = Q.front (); Q.pop ();
        ret = max (ret, cnt[u]);
        for (int i=0; i<G[u].size (); ++i)   {
            int v = G[u][i];
            cnt[v] += cnt[u];
            if (!(--deg[v]))    Q.push (v);
        }
    }
    return ret;
}
int main(void)  {
    while (scanf ("%d", &n) == 1)   {
        for (int i=1; i<=n; ++i)    scanf ("%d", &w[i]);
        for (int i=1; i<=n; ++i)    G[i].clear ();
        memset (deg, 0, sizeof (deg));
        for (int i=1; i<=n-1; ++i)  {
            int u, v;   scanf ("%d%d", &u, &v);
            if (w[u] < w[v])    swap (u, v);    
            G[u].push_back (v); deg[v]++;
        }
        printf ("%d\n", BFS ());
    }
    return 0;
}
