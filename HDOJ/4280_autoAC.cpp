#include"stdio.h"
#include"string.h"
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define inf 99999999
int min(int a,int b)
{
    return a<b?a:b;
}
int e,head[100005];
int level[100005];
int q[100005];
struct node
{
    int to,val;
    int next;
}edge[200005];
void add_edge(int x,int y,int w)
{
    edge[e].to=y;
    edge[e].val=w;
    edge[e].next=head[x];
    head[x]=e++;
    edge[e].to=x;
    edge[e].val=w;
    edge[e].next=head[y];
    head[y]=e++;
}
bool bfs(int s,int t)
{
    int front=0,rear=0;
    int top,k;
    q[rear++]=s;
    memset(level,0,sizeof(level));
    level[s]=1;
    while(front<rear)
    {
        top=q[front++];
        if(top==t)
            return true;
        for(k=head[top];k!=-1;k=edge[k].next)
        {
            if(!level[edge[k].to]&&edge[k].val>0)
            {
                level[edge[k].to]=level[top]+1;
                q[rear++]=edge[k].to;
            }
        }
    }
    return false;
}
int dfs(int now,int maxf,int t)
{
    int ret=0,f,k;
    if(now==t)
        return maxf;
    for(k=head[now];k!=-1;k=edge[k].next)
    {
        if(level[edge[k].to]==level[now]+1&&edge[k].val>0)
        {
            f=dfs(edge[k].to,min(maxf-ret,edge[k].val),t);
            edge[k].val-=f;
            edge[k^1].val+=f;
            ret+=f;
            if(ret==maxf)
                return ret;
        }
    }
    if(ret==0)
        level[now]=0;
    return ret;
}
int dinic(int s,int t)
{
    int ans=0;
    while(bfs(s,t))
        ans+=dfs(s,inf,t);
    return ans;
}
int main( )
{
    int T,i,n,m,s,t;
    int x,y,w,ps,pt;
    scanf("%d",&T);
    while(T--)
    {
        e=0;s=inf;t=0;
        memset(head,-1,sizeof(head));
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&x,&y);
            if(s>x)
            {s=x;ps=i;}
            if(t<x)
            {t=x;pt=i;}
        }            
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            add_edge(x,y,w);
        }
        printf("%d\n",dinic(ps,pt));
    }
    return 0;
}
