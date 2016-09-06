#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
#define INF 2000000
const int N=60;
struct Edge
{
    int v,w;
    Edge *nxt;
}memo[N*N],*cur,*adj[N];
int n,m,K,mask;
int st[N],vis[N][1<<11];
int d[N][1<<11],dp[1<<11];
queue<int>que;
void addEdge(int u,int v,int w)
{
    cur->v=v;    cur->w=w;
    cur->nxt=adj[u]; 
    adj[u]=cur++;
}
bool check(int s)
{
    int res=0;
    for(int i=0;s;i++,s>>=1)
        res+=(s&1)*(i<K?1:-1);
    return (res==0?true:false);
}
void spfa()
{
    while(que.size())
    {
        int top=que.front(); que.pop();
        int u=top/10000,s=top%10000;
        vis[u][s]=0;
        for(Edge* it=adj[u];it;it=it->nxt)
        {
            int v=it->v,w=it->w;
            if(d[v][s|st[v]]>d[u][s]+w)
            {
                d[v][s|st[v]]=d[u][s]+w;
                if((s|st[v])==s&&!vis[v][s]) 
                    que.push(v*10000+s),vis[v][s]=1;
            }
        }
    }
}
void init()
{
    cur=memo; mask=(1<<(2*K))-1;
    memset(st,0,sizeof(st));
    memset(vis,0,sizeof(vis));
    memset(adj,0,sizeof(adj));
    for(int i=1;i<=n;i++)
        for(int j=0;j<=mask;j++) d[i][j]=INF;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int u,v,w;
        scanf("%d%d%d",&n,&m,&K);
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addEdge(u,v,w);
            addEdge(v,u,w);
        }
        for(int i=1;i<=K;i++)
        {
            st[i]=1<<(i-1);    
            d[i][st[i]]=0;
            st[n-i+1]=(1<<(K+(i-1)));    
            d[n-i+1][st[n-i+1]]=0;
        }
        for(int s=0;s<=mask;s++)
        {
            for(int i=1;i<=n;i++)
            {
                for(int p=(s-1)&s;p;p=(p-1)&s)
                d[i][s]=min(d[i][s],d[i][p|st[i]]+d[i][(s-p)|st[i]]);
                if(d[i][s]<INF&&!vis[i][s]) 
                    que.push(i*10000+s),vis[i][s]=1;
            }
            spfa();
        }
        for(int s=0;s<=mask;s++)
        {
            dp[s]=INF;
            for(int i=1;i<=n;i++) dp[s]=min(dp[s],d[i][s]);
        }
        for(int s=1;s<=mask;s++)
            if(check(s))
                for(int p=(s-1)&s;p;p=(p-1)&s)
                    if(check(p)) dp[s]=min(dp[s],dp[p]+dp[s-p]);
        if(dp[mask]>=INF) puts("No solution");
        else printf("%d\n",dp[mask]);
    }
    return 0;
}
