#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <string>
#include <utility>
#include <assert.h> 
using namespace std;
typedef long long ll;
#define prt(k) cout<<#k" = "<<k<<endl;
const int N = 100007;
const int W = 107;
int f[N][107], g[N][107];
int father[N];
int n;
int w[N];
int F[N][107], G[N][107];
int maxw;
struct edge
{
        int v, next;
}e[N<<1];
int head[N], mm;
void add(int u,  int v)
{
        e[mm].v = v;
        e[mm].next = head[u];
        head[u] = mm++;
}
struct P
{
        int d, id;
        P() {}
        P(int _id, int _d=0) { d=_d, id=_id; }
        bool operator < (P b) const
        {
                return d > b.d;
        }
}p[N];
bool vis[N];
void bfs()
{
        queue<P> q;
        q.push(P(1,0));
        memset(vis,0,sizeof vis);
        vis[1] = true;
        father[1] = 1;
        while (!q.empty()) {
                P u = q.front(); q.pop();
                int now = u.id;
                p[now].id = now;
                p[now].d = u.d + 1;
                for (int i=head[now];~i;i=e[i].next) {
                        int v = e[i].v;
                        if (!vis[v]) {
                                q.push(P(v, u.d + 1));
                                vis[v] = true;
                                father[v] = now;
                        }
                }
        }
}
void gao(int u, int fa)
{
        assert(!vis[u]);
        vis[u] = true;
        bool flag = false;
        g[u][0] = 0;
        for (int i=head[u];~i;i=e[i].next) {
                int v = e[i].v;
                if (v==fa) continue;
                flag = true;
                g[u][0] += f[v][0];
                assert(vis[v]);
        }
        if (!flag) {
                g[u][0] = 0;
                f[u][w[u]] = 1;
        }
        for (int j=0;j<=maxw;j++) {
                ll sum=0;
                for (int i=head[u];~i;i=e[i].next) {
                        int v = e[i].v;
                        if (v==fa) continue;
                        int t = F[v][j+1];
                        if (j > 0)
                                t = min(t, G[v][j-1]);
                        sum += t;
                        if (sum >= n) { sum = n; break; }
                }
                if (sum < n ) for (int i=head[u];~i;i=e[i].next) {
                        int v = e[i].v;
                        if (v==fa) continue;
                        int t = F[v][j+1];
                        if (j > 0) t = min(t, G[v][j-1]);
                        if (0<=sum && sum < n) f[u][j] = min(f[u][j], (int)(f[v][j+1] + sum - t ) ) ;
                }
                sum = 0;
                int t;
                for (int i=head[u];~i;i=e[i].next) {
                        int v = e[i].v;
                        if (v==fa) continue;
                        int t = F[v][j];
                        if (j > 0) t = min(t, G[v][j-1]);
                        sum += t;
                        if (sum >= n)  { sum = n; break; }
                }
                if (j>0 && sum < n) for (int i=head[u];~i;i=e[i].next) {
                        int v = e[i].v;
                        if (v==fa) continue;
                        int t = F[v][j];
                        if (j > 0) t = min(t, G[v][j-1]);
                        if (0<=sum && sum < n) g[u][j]=min(g[u][j], (int)(g[v][j-1] + sum -  t ) );
                }
        }
        ll sum = 0;
        for (int i=head[u];~i;i=e[i].next) {
                int v = e[i].v;
                if (v==fa) continue;
                sum += min(F[v][w[u]+1], w[u]>0 ? G[v][w[u]-1] : n);
        }
        if (0<=sum && sum<n) f[u][w[u]]=min(f[u][w[u]], int(1 +  sum ));
        for (int i=100;i>=0;i--) f[u][i] = min(f[u][i], f[u][i+1]);
        for (int i=1;i<=100;i++) g[u][i] =  min(g[u][i], g[u][i-1]);
        F[u][0] = f[u][0];
        G[u][0] = g[u][0];
        for (int j=1;j<=maxw+1;j++) {
                F[u][j] = min(F[u][j-1], f[u][j]);
                G[u][j] = min(G[u][j-1], g[u][j]);
        }
}
int main()
{
        while (scanf("%d", &n)==1) {
                maxw = 0;
                for (int i=1;i<=n;i++) scanf("%d", w+i), maxw=max(maxw, w[i]);
                mm=0; memset(head,-1,sizeof head);
                for (int i=1;i<=n-1;i++)
                {
                        int u, v; scanf("%d%d", &u, &v);
                        add(u, v);
                        add(v, u);
                }
                memset(f, 63, sizeof f);
                memset(g, 63, sizeof g);
                bfs();
                sort(p+1, p+n+1);
                memset(vis, 0, sizeof vis);
                for (int i=1;i<=n;i++) {
                        gao(p[i].id, father[p[i].id]);
                }
                int ans = n;
                for (int i=0;i<=maxw;i++)
                        ans =  min(ans, f[1][i]);
                printf("%d\n", ans);
        }
}
