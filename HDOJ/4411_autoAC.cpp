#include<stdio.h>
#include<string.h>
#define clr(x)memset(x,0,sizeof(x))
#define INF 0x1f1f1f1f
#define min(a,b)(a)<(b)?(a):(b)
#define max(a,b)(a)>(b)?(a):(b)
struct node
{
    int next,from,to,w,c;
}e[1000010];
int tot;
int head[210];
void add(int st,int u,int wi,int flow)
{
    e[tot].from=st;
    e[tot].to=u;
    e[tot].w=wi;
    e[tot].c=flow;
    e[tot].next=head[st];
    head[st]=tot++;
    e[tot].from=u;
    e[tot].to=st;
    e[tot].w=-wi;
    e[tot].c=0;
    e[tot].next=head[u];
    head[u]=tot++;
}
int q[100010];
int pre[2010];
int dis[2010];
int v[220];
int s,t;
int spfa()
{
    int i,x,front,rear,k;
    front=rear=0;
    for(i=0;i<=t;i++)
        dis[i]=INF;
    clr(v);
    pre[s]=-1;
    q[rear++]=s;
    dis[s]=0;
    v[s]=1;
    while(front<rear)
    {
        x=q[front++];
        v[x]=0;
        for(i=head[x];i!=-1;i=e[i].next)
        {
            k=e[i].to;
            if(e[i].c&&dis[x]+e[i].w<dis[k])
            {
                dis[k]=dis[x]+e[i].w;
                pre[k]=i;
                if(!v[k])
                {
                    v[k]=1;
                    if(dis[k]<=dis[x]&&front>0)
                        q[--front]=k;
                    else q[rear++]=k;
                }
            }
        }
    }
    if(dis[t]!=INF)
        return 1;
    return 0;
}
int costflow()
{
    int tt=0;
    int tot=0,flow=0,u,minf=INF;
    while(spfa())
    {
        for(u=pre[t];u!=-1;u=pre[e[u].from])
            minf=min(minf,e[u].c);
        for(u=pre[t];u!=-1;u=pre[e[u].from])
        {
            e[u].c-=minf;
            e[u^1].c+=minf;
            flow+=e[u].w*minf;
        }
    }
    return flow;
}
int g[105][105];
int main()
{
    int m,n,a,b,c,k,K,w,z,i,j;
    while(scanf("%d%d%d",&n,&m,&K)!=EOF)
    {
        if(n==0&&m==0&&K==0)
            break;
        memset(g,INF,sizeof(g));
        for(i=0;i<=n;i++)
            g[i][i]=0;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&w);
            if(w<g[a][b])
                g[a][b]=g[b][a]=w;
        }
        for(k=0;k<=n;k++)
            for(i=0;i<=n;i++)
                for(j=0;j<=n;j++)
                    if(g[i][k]+g[k][j]<g[i][j])
                        g[i][j]=g[i][k]+g[k][j];
        int res;
        s=2*n+1;
        t=2*n+2;
        tot=0;
        memset(head,-1,sizeof(head));
        add(s,0,0,K);
        add(0,t,0,w);
        for(i=1;i<=n;i++)
        {
            add(0,i,g[0][i],1);
            add(i,i+n,-1000000,1);
            add(i+n,t,g[0][i],1);
        }
        for(i=1;i<=n;i++)
            for(j=i+1;j<=n;j++)
                add(i+n,j,g[i][j],1);
        printf("%d\n",costflow()+1000000*n);
    }
    return 0;
}
