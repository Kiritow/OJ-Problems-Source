#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int N=200010;
int head[N],to[N],ne[N],w[N];
int dis[N],que[N];
bool vis[N];
int edge,m,n;
void init()
{
    memset(head,-1,sizeof(head));
    edge=0;
}
void add(int u,int v,int c)
{
    to[edge]=v,w[edge]=c,ne[edge]=head[u],head[u]=edge++;
    to[edge]=u,w[edge]=c,ne[edge]=head[v],head[v]=edge++;
}
void bfs(int s)
{
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
    int l,r,v,u;
    l=r=0;
    vis[s]=1;
    dis[s]=0;
    que[r++]=s;
    while(r>l)
    {
        u=que[l++];
        for(int i=head[u]; ~i; i=ne[i])
        {
            if(!vis[v=to[i]])
            {
                vis[v]=1;
                dis[v]=dis[u]+w[i];
                que[r++]=v;
            }
        }
    }
}
int treediameter(int s)
{
    int u,maxl;
    bfs(s);
    maxl=0,u=s;
    for(int i=1; i<=n; i++)
        if(dis[i]>maxl)
            u=i,maxl=dis[i];
    bfs(u);
    maxl=0;
    for(int i=1; i<=n; i++)
        if(dis[i]>maxl)
            maxl=dis[i];
    return maxl;
}
int main()
{
    int u,v,d=1,t,i,j,x;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        for(i=1;i<=n-1;i++)
        {
            scanf("%d%d",&u,&v);
            add(u,v,1);
        }
        int ans=treediameter(1);
        ans++;
        while(m--)
        {
            scanf("%d",&x);
            if(x<=ans) printf("%d\n",x-1);
            else       printf("%d\n",(x-ans)*2+ans-1);
        }
    }
    return 0;
}
