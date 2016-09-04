#include<cstdio>
#include<cstring>
#include<cmath>
#define N 10005
using namespace std;
int n,m,num,adj[N],q[N];
bool f[N];
double low[N],p[N],w[N];
struct edge
{
    int v,pre;
    double w;
    edge(){}
    edge(int vv,double ww,int p){v=vv;w=ww;pre=p;}
}e[N*5];
void insert(int u,int v,double w)
{
    e[num]=edge(v,w,adj[u]);
    adj[u]=num++;
}
void spfa(int x)
{
    int i,v,head=0,tail=0;
    memset(f,0,sizeof(f));
    memset(low,-0x3f,sizeof(low));
    low[x]=0;
    q[++tail]=x;
    while(head!=tail)
    {
        x=q[head=(head+1)%N];
        f[x]=0;
        for(i=adj[x];~i;i=e[i].pre)
            if(low[v=e[i].v]<low[x]+e[i].w)
            {
                low[v]=low[x]+e[i].w;
                if(!f[v])
                {
                    f[v]=1;
                    q[tail=(tail+1)%N]=v;
                }
            }
    }
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int i,k,a,b;
        double t,ans=0;
        num=0;
        memset(adj,-1,sizeof(adj));
        for(i=1;i<=n;i++)
            scanf("%lf%lf",p+i,w+i);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d",&k);
            scanf("%d",&a);
            for(i=1;i<k;i++)
            {
                scanf("%lf%d",&t,&b);
                insert(b,a,log(t));
                a=b;
            }
        }
        for(i=1;i<=n;i++)
            insert(0,i,log(p[i]));
        spfa(0);
        for(i=1;i<=n;i++)
        {
            if(p[i]<exp(low[i]))
                p[i]=exp(low[i]);
            ans+=p[i]*w[i];
        }
        printf("%.2f\n",ans);
    }
}
