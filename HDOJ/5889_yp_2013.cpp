#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
#define inf 1e9
#define INF 1e9
const int maxm = 4000000+50;
struct Node
{
    int v,w;
    Node(int vv,int ww):v(vv),w(ww){};
};
vector<Node>e[maxn];
int s,t,n,m,vs,vt;
int d[maxn];
int vis[maxn];
void spfa()
{
    memset(vis,0,sizeof(vis));
    for(int i = 1;i<=n;i++)
        d[i]=inf;
    d[s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u]=0;
        for(int i = 0;i<e[u].size();i++)
        {
            int v = e[u][i].v;
            int w = e[u][i].w;
            if(d[v]>d[u]+1)
            {
                d[v]=d[u]+1;
                if(!vis[v])
                    q.push(v);
                vis[v]=1;
            }
        }
    }
}


struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct Dinic
{
//  int n,m;
    int s,t;
    vector<Edge>edges;        //边数的两倍
    vector<int> G[maxn];      //邻接表，G[i][j]表示结点i的第j条边在e数组中的序号
    bool vis[maxn];           //BFS使用
    int d[maxn];              //从起点到i的距离
    int cur[maxn];            //当前弧下标
    void init()
    {
       for (int i=0;i<=n+1;i++)
           G[i].clear();
       edges.clear();
    }
    void AddEdge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));        //反向弧
        int mm=edges.size();
        G[from].push_back(mm-2);
        G[to].push_back(mm-1);
    }
    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int>q;
        q.push(s);
        d[s]=0;
        vis[s]=1;
        while (!q.empty())
        {
            int x = q.front();q.pop();
            for (int i = 0;i<G[x].size();i++)
            {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to]=1;
                    d[e.to] = d[x]+1;
                    q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a)
    {
        if (x==t || a==0)
            return a;
        int flow = 0,f;
        for(int &i=cur[x];i<G[x].size();i++)
        {
            Edge &e = edges[G[x][i]];
            if (d[x]+1 == d[e.to] && (f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if (a==0)
                    break;
            }
        }
        return flow;
    }

    int Maxflow(int s,int t)
    {
        this->s=s;
        this->t=t;
        int flow = 0;
        while (BFS())
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
}dc;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i = 0;i<=n;i++)
            e[i].clear();
        for(int i = 1;i<=m;i++)
        {
            int u,v,di;
            scanf("%d%d%d",&u,&v,&di);
            e[u].push_back(Node(v,di));
            e[v].push_back(Node(u,di));
        }
        s=1,t=n;
        spfa();
        dc.init();
        for(int i = 1;i<=n;i++)
            for(int j = 0;j<e[i].size();j++)
                if(d[e[i][j].v]==d[i]+1)
                    dc.AddEdge(i,e[i][j].v,e[i][j].w);
        printf("%d\n",dc.Maxflow(s,t));
    }
}
