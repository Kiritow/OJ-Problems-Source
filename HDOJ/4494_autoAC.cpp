#include<iostream>
#include<cstring>
#include<cstring>
#include<cmath>
#include<cstdio>
#define inf 100000000
using namespace std;
const int Maxn = 600;
struct Edge{
    int v;
    int val;
    int cost;
    int next;
}edge[Maxn*600];
struct Point{
    double x,y;
}p[Maxn];
int head[Maxn],n,m,k;
int e;
int dis[Maxn],pre[Maxn], pos[Maxn],sta[Maxn],en[Maxn],ty[Maxn][20],flow;
int  que[Maxn*600];
double d[Maxn][Maxn];
bool vis[Maxn];
void add(int u, int v, int val, int cost)
{
    edge[e].v = v;
    edge[e].val = val;
    edge[e].cost = cost;
    edge[e].next = head[u];
    head[u] = e++;
    edge[e].v = u;
    edge[e].val = 0;
    edge[e].cost = -cost;
    edge[e].next = head[v];
    head[v] = e++;
}
double DIS(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void init()
{
    memset(head,-1,sizeof(head));
    e=0;
}
bool spfa(int s, int t)
{
    int i;
    memset(pre, -1, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    int Head, tail;
    Head = tail = 0;
    for(i = 0; i < Maxn; i++)
        dis[i] = inf;
    que[tail++] = s;
    pre[s] = s;
    dis[s] = 0;
    vis[s] = 1;
    while(Head != tail)
    {
        int now = que[Head++];
        vis[now] = 0;
        for(i=head[now]; i != -1; i = edge[i].next)
        {
            int adj = edge[i].v;
            if(edge[i].val > 0 && dis[now] + edge[i].cost < dis[adj])
            {
                dis[adj] = dis[now] + edge[i].cost;
                pre[adj] = now;
                pos[adj] = i;
                if(!vis[adj])
                {
                    vis[adj] = 1;
                    que[tail++] = adj;
                }
            }
        }
    }
    return pre[t] != -1;
}
int MinCostFlow(int s, int t)
{
    int i;
    int cost = 0;
    flow = 0;
    while(spfa(s, t))
    {
        int f = 100000000;
        for(i = t; i != s; i = pre[i])
        if (edge[pos[i]].val < f)
            f = edge[pos[i]].val;
            flow += f;
            cost += dis[t] * f;
            for(i = t; i != s; i = pre[i])
            {
                edge[pos[i]].val -= f;
                edge[pos[i] ^ 1].val += f;
            }
    }
    return cost;
}
void build(int type)
{
    int i,j;
    init();
    for(i=2;i<=n;i++){
        add(1,i,ty[i][type],1);
        add(i,i+2*n,ty[i][type],0);
        add(1,i+n,ty[i][type],0);
        add(i+2*n,3*n+1,ty[i][type],0);
        for(j=2;j<=n;j++){
            if(sta[i]+en[i]+d[i][j]<=sta[j]){
                add(i+n,j+2*n,ty[i][type],0);
            }
        }
    }
}
int solve()
{
    int i,j,u,v;
    int ans=0;
    for(i=1;i<=m;i++){
        build(i);
        ans+=MinCostFlow(1,3*n+1);
    }
    return ans;
}
int main()
{
    int i,j,u,v,c,t;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        scanf("%lf%lf",&p[1].x,&p[1].y);
        for(i=2;i<=n;i++){
            scanf("%lf%lf%d%d",&p[i].x,&p[i].y,&sta[i],&en[i]);
            for(j=1;j<=m;j++){
                scanf("%d",&ty[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            for(j=i+1;j<=n;j++){
                d[i][j]=d[j][i]=DIS(p[i],p[j]);
            }
        }
        printf("%d\n",solve());
    }
    return 0;
}
