#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int maxn = 1010;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, cap, flow;
    Edge(int from, int to, int cap, int flow): from(from), to(to), cap(cap), flow(flow) {}
};
int high, low;
struct EK
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int p[maxn];
    int a[maxn];
    void init(int n)
    {
        this->n = n;
        edges.clear();
        for(int i = 0; i <= n; i++) G[i].clear();
    }
    void AddEdge(int from, int to, int cap)
    {
        edges.push_back(Edge (from, to, cap, 0));
        edges.push_back(Edge (to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BFS(int s, int t, int &flow)
    {
        memset(a, 0, sizeof(a));
        queue<int> Q;
        Q.push(s);
        a[s] = INF;
        while(!Q.empty())
        {            
            int u = Q.front(); Q.pop();
            for(int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if(!a[e.to] && e.cap > e.flow)
                {
                    p[e.to] = G[u][i];
                    Q.push(e.to);
                    a[e.to] = min(a[u], e.cap-e.flow);
                }
            }
        }
        if(a[t] == 0) return 0;
        flow += a[t];
        low = INF;
        int u = t;
        while(u != s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
            low = min(low, edges[p[u]].cap); 
            u = edges[p[u]].from;
        }
        high = max(high, low); 
        return 1;
    }
    int Maxflow(int s, int t)
    {
        this->s = s; this->t = t;
        int flow = 0;
        while(BFS(s, t, flow)) ;
        return flow;
    }
};
void readint(int &x)
{
    char c;
    while(!isdigit(c)) c = getchar();
    x = 0;
    while(isdigit(c)) { x = x*10 + c-'0'; c = getchar(); }
}
void writeint(int x)
{
    if(x > 9) writeint(x/10);
    putchar(x%10+'0');
}
EK solver;
int n, m, s, t;
int kase;
void solve()
{
    scanf("%d%d%d%d%d", &kase, &n, &m, &s, &t);
    solver.init(n+3);
    high = -INF;
    while(m--)
    {
        int x, y, z;
        readint(x), readint(y), readint(z);
        solver.AddEdge(x, y, z);
    }
    int ans = solver.Maxflow(s, t);
    printf("%d %.3lf\n", kase, ans*1.0/high);
}
int main()
{
    int T;
    for(readint(T); T > 0; T--) solve();
    return 0;
}
