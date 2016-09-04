#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int N=300;
int head[N];
const int MAXE=5000000;
const int inf=1<<30;
int n,m,k;
int cnt,s,t;
int H[]={1,3,5,7,9};
int d[N],pre[N];
int ans=0;
bool vis[N];
int q[MAXE];
struct Edge
{
    int u,v,c,w,next;
}edge[MAXE];
void addedge(int u,int v,int w,int c)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].w=w;
    edge[cnt].c=c;
    edge[cnt].next=head[u];
    head[u]=cnt++;
    edge[cnt].v=u;
    edge[cnt].u=v;
    edge[cnt].w=-w;
    edge[cnt].c=0;
    edge[cnt].next=head[v];
    head[v]=cnt++;
}
int SPFA()
{
    int l,r;
    memset(pre,-1,sizeof(pre));
    memset(vis,0,sizeof(vis));
    for(int i=0;i<=t;i++) d[i]=inf;
    d[s]=0;
    l=0;r=0;
    q[r++]=s;
    vis[s]=1;
    while(l<r)
    {
        int u=q[l++];
        vis[u]=0;
        for(int j=head[u];j!=-1;j=edge[j].next)
        {
            int v=edge[j].v;
            if(edge[j].c>0&&d[u]+edge[j].w<d[v])
            {
                d[v]=d[u]+edge[j].w;
                pre[v]=j;
                if(!vis[v])
                {
                    vis[v]=1;
                    q[r++]=v;
                }
            }
        }
    }
    if(d[t]==inf)
        return 0;
    return 1;
}
void MCMF()
{
    int flow=0;
    while(SPFA())
    {
        int u=t;
        int mini=inf;
        while(u!=s)
        {
            if(edge[pre[u]].c<mini)
                mini=edge[pre[u]].c;
                u=edge[pre[u]].u;
        }
        flow+=mini;
        ans+=d[t]*mini;
        u=t;
        while(u!=s)
        {
            edge[pre[u]].c-=mini;
            edge[pre[u]^1].c+=mini;
            u=edge[pre[u]].u;
        }
    }
    if (flow<k)
    printf("-1\n");
    else
    printf("%d\n",ans);
}
int main()
{
    while (scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        int u,v,c,w;
        cnt=0;
        s=0;
        t=n;
        ans=0;
        memset(head,-1,sizeof(head));
        addedge(s,1,0,k);
        for (int i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&w,&c);
            for (int j=0;j<c;j++)
            {
                addedge(u,v,H[j]*w,1);
            }
        }
        addedge(n,t,0,inf);
        MCMF();
    }
}
