#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAXN=100110;
const int MAXM=4000110;
const int INF=0x3f3f3f3f;
struct Node
{
    int to,next,cap;
}edge[MAXM];
int tol;
int head[MAXN];
int gap[MAXN],dis[MAXN],pre[MAXN],cur[MAXN];
void init()
{
    tol=0;
    memset(head,-1,sizeof(head));
}
void addedge(int u,int v,int w,int rw=0)
{
    edge[tol].to=v;edge[tol].cap=w;edge[tol].next=head[u];head[u]=tol++;
    edge[tol].to=u;edge[tol].cap=rw;edge[tol].next=head[v];head[v]=tol++;
}
int sap(int start,int end,int nodenum)
{
    memset(dis,0,sizeof(dis));
    memset(gap,0,sizeof(gap));
    memcpy(cur,head,sizeof(head));
    int u=pre[start]=start,maxflow=0,aug=-1;
    gap[0]=nodenum;
    while(dis[start]<nodenum)
    {
        loop:
        for(int  &i=cur[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&dis[u]==dis[v]+1)
            {
                if(aug==-1||aug>edge[i].cap)
                    aug=edge[i].cap;
                pre[v]=u;
                u=v;
                if(v==end)
                {
                    maxflow+=aug;
                    for(u=pre[u];v!=start;v=u,u=pre[u])
                    {
                        edge[cur[u]].cap-=aug;
                        edge[cur[u]^1].cap+=aug;
                    }
                    aug=-1;
                }
                goto loop;
            }
        }
        int mindis=nodenum;
        for(int i=head[u];i!=-1;i=edge[i].next)
        {
            int v=edge[i].to;
            if(edge[i].cap&&mindis>dis[v])
            {
                cur[u]=i;
                mindis=dis[v];
            }
        }
        if((--gap[dis[u]])==0)break;
        gap[dis[u]=mindis+1]++;
        u=pre[u];
    }
    return maxflow;
}
int num[1025];
int a[11];
int bit[11];
int main()
{
    bit[0]=1;
    for(int i=1;i<=10;i++)bit[i]=bit[i-1]*2;
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++)
        {
            int tmp=0;
            for(int j=0;j<m;j++){scanf("%d",&a[j]);tmp+=a[j]*bit[j];}
            num[tmp]++;
        }
        int start=0,end=1024+m+1,nodenum=2014+m+2;
        for(int i=0;i<1024;i++)
        {
            if(num[i]==0)continue;
            addedge(start,i+1,num[i]);
            for(int j=0;j<10;j++)
                if(i&bit[j] )
                    addedge(i+1,1024+j+1,INF);
        }
        int tmp;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&tmp);
            addedge(i+1024,end,tmp);
        }
        if(sap(start,end,nodenum)==n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
