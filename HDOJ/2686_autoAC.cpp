#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 2005;
const int MAXEDGE = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
struct CEdge
{
        int from, to, cap, flow, cost, next;
}edge[MAXEDGE];
struct CMCMF
{
        int s, t, pp;
        int head[MAXN], a[MAXN], d[MAXN], p[MAXN];
        bool inq[MAXN];
        CMCMF(int ss, int tt)
        {
                s = ss, t = tt;
                pp = 0;
                memset(head, -1, sizeof(head));
        }
        void addEdge(int u, int v, int cap, int cost)
        {
                edge[pp] = (CEdge){u, v, cap, 0, cost, head[u]};
                head[u] = pp++;
                edge[pp] = (CEdge){v, u, 0, 0, -cost, head[v]};
                head[v] = pp++;
        }
        bool bellmanFord(int &flow, int &cost)
        {
                memset(d, INF, sizeof(d));
                memset(inq, false, sizeof(inq));
                queue <int> q;
                q.push(s), inq[s] = true;
                a[s] = INF, d[s] = 0, p[s] = -1;
                while(!q.empty())
                {
                        int u = q.front();
                        q.pop(), inq[u] = false;
                        int next = head[u];
                        while(next != -1)
                        {
                                CEdge &e = edge[next];
                                if(e.cap > e.flow && d[e.to] > d[u] + e.cost)
                                {
                                        d[e.to] = d[u] + e.cost;
                                        a[e.to] = min(a[u], e.cap - e.flow);
                                        p[e.to] = next;
                                        if(!inq[e.to])  inq[e.to] = true, q.push(e.to);
                                }
                                next = e.next;
                        }
                }
                if(d[t] == INF)  return false;
                cost += d[t] * a[t];
                flow += a[t];
                int u = t;
                while(u != s)
                {
                        edge[p[u]].flow += a[t];
                        edge[p[u]^1].flow -= a[t];
                        u = edge[p[u]].from;
                }
                return true;
        }
};
int a[33][33];
int main()
{
        while(scanf("%d",&n) != EOF)
        {
                int s = 1, t = n*n;
                CMCMF mcmf(s, t);
                int tmp;
                for(int i = 0;i < n; i++)
                {
                        for(int j = 1;j <= n; j++)
                        {
                                scanf("%d",&tmp);
                                a[i][j] = tmp;
                                if(j != n)      mcmf.addEdge(i*n+j, i*n+j+1 + n*n, 1, -tmp);
                                if(i != n-1)    mcmf.addEdge(i*n+j, (i+1)*n+j+n*n, 1, -tmp);
                                mcmf.addEdge(i*n+j+n*n, i*n+j, 1, 0);
                        }
                }
                mcmf.addEdge(n*n + n*n, n*n, 1, 0);
                int cost = 0, flow = 0;
                while(mcmf.bellmanFord(flow, cost));
                cout<<-cost - a[0][1] + a[n-1][n]<<endl;
        }
        return 0;
}
