#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N=105;
int head[N],tot;
int dp[N][N*5];
struct Edge
{
    int from,to,cost,pre;
    Edge(){}
    Edge(int a,int b,int c,int d){from=a;to=b;cost=c;pre=d;}
}edge[N*3];
void addEdge(int u,int v,int cost)
{
    edge[tot]=Edge(u,v,cost,head[u]);
    head[u]=tot++;
}
int spfa(int st,int ed)
{
    queue<int> que;
    int vis[N],dis[N],pre[N];
    memset(vis,0,sizeof(vis));
    memset(dis,0x7f,sizeof(dis));
    memset(pre,-1,sizeof(pre));
    que.push(st);
    vis[st]=1;  dis[st]=0;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();  vis[u]=0;
        for(int i=head[u];i!=-1;i=edge[i].pre)
        {
            int v=edge[i].to,cost=edge[i].cost;
            if(dis[v]>dis[u]+cost)
            {
                dis[v]=dis[u]+cost;
                pre[v]=i;
                if(!vis[v])
                {
                    vis[v]=1;
                    que.push(v);
                }
            }
        }
    }
    for(int i=ed;i!=st;i=edge[pre[i]].from)
    {
        edge[pre[i]].cost=0;
        edge[pre[i]^1].cost=0;
    }
    return dis[ed];
}
void dfs(int u,int fa,int coin)
{
    for(int e=head[u];e!=-1;e=edge[e].pre)
    {
        int v=edge[e].to,cost=edge[e].cost*2;
        if(v==fa||coin<cost) continue;
        dfs(v,u,coin-cost);
        for(int i=coin;i>=cost;i--)
        {
            for(int j=0;j+cost<=i;j++)
            {
                if(dp[u][i-j-cost]!=-1&&dp[v][j]!=-1)
                    dp[u][i]=max(dp[u][i],dp[u][i-j-cost]+dp[v][j]);
            }
        }
    }
}
int main()
{
    int n,t;
    while(scanf("%d%d",&n,&t)!=EOF)
    {
        tot=0;
        memset(dp,-1,sizeof(dp));
        memset(head,-1,sizeof(head));
        for(int i=0;i<n-1;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        for(int i=1;i<=n;i++) scanf("%d",&dp[i][0]);
        t-=spfa(1,n);
        if(t<0) puts("Human beings die in pursuit of wealth, and birds die in pursuit of food!");
        else
        {
            dfs(1,0,t);
            int res=0;
            for(int i=0;i<=t;i++) res=max(res,dp[1][i]);
            printf("%d\n",res);
        }
    }
    return 0;
}
