#include<cstdio>
#include<cstring>
#define N 1005
#define inf 999999999
#define min(a,b) ((a)<(b)?(a):(b))
int n,m,k,s,t,num;
int low[N],pre[N],adj[N],q[N];
struct edge
{
    int u,v,c,w,next;
    edge(){}
    edge(int uu,int vv,int ww,int cc,int n)
    {u=uu;v=vv;w=ww;c=cc;next=n;}
}e[10005];
void insert(int u,int v,int w,int c)
{
    e[num]=edge(u,v,w,c,adj[u]);
    adj[u]=num++;
    e[num]=edge(v,u,-w,0,adj[v]);
    adj[v]=num++;
}
int spfa()
{
    int i,x,f[N]={0},head=0,tail=0;
    q[++tail]=s;
    memset(low,0x3f,sizeof(low));
    pre[s]=-1;
    low[s]=0;
    while(head!=tail)
    {
        x=q[head=(head+1)%N];
        f[x]=0;
        for(i=adj[x];i!=-1;i=e[i].next)
            if(e[i].c&&low[e[i].v]>low[x]+e[i].w)
            {
                pre[e[i].v]=i;
                low[e[i].v]=low[x]+e[i].w;
                if(!f[e[i].v])
                {
                    f[e[i].v]=1;
                    q[tail=(tail+1)%N]=e[i].v;
                }
            }
    }
    return low[t]<inf;
}
int mincost()
{
    int ans=0;
    while(spfa())
    {
        if(low[t]>k)
            break;
        int v;
        ans++;
        for(v=pre[t];v!=-1;v=pre[e[v].u])
        {
            e[v].c--;
            e[v^1].c++;
        }
    }
    return ans;
}
int main()
{
    int i,u,v;
    while(~scanf("%d%d%d",&n,&m,&k),n)
    {
        num=0;
        memset(adj,-1,sizeof(adj));
        s=0;
        t=n+n-1;
        while(m--)
        {
            scanf("%d%d",&u,&v);
            u--;v--;
            insert(u*2+1,v*2,1,1);
        }
        insert(s,1,0,inf);
        insert(2*n-2,t,0,inf);
        for(i=1;i<n-1;i++)
            insert(i*2,i*2+1,0,1);
        printf("%d\n",mincost());
    }
}
