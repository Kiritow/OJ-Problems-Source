#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=62002;
const int M=62002;
const __int64 INF=1LL<<60;
int t,n,m,tot,cas=1;
int gap[M],dis[M],pre[M],head[N],cur[N],vis[N];
int NE,NV,sink,source;
struct Node
{
    __int64 c;
    int pos,next;
} E[9999999];
#define FF(i,NV) for(int i=0;i<NV;i++)
__int64 sap(int s,int t)
{
    memset(dis,0,sizeof(int)*(NV+1));
    memset(gap,0,sizeof(int)*(NV+1));
    FF(i,NV) cur[i] = head[i];
    int u = pre[s] = s;
    __int64 maxflow = 0,aug =INF;
    gap[0] = NV;
    while(dis[s] < NV)
    {
loop:
        for(int &i = cur[u]; i != -1; i = E[i].next)
        {
            int v = E[i].pos;
            if(E[i].c && dis[u] == dis[v] + 1)
            {
                if(aug>E[i].c) aug=E[i].c;
                pre[v] = u;
                u = v;
                if(v == t)
                {
                    maxflow += aug;
                    for(u = pre[u]; v != s; v = u,u = pre[u])
                    {
                        E[cur[u]].c -= aug;
                        E[cur[u]^1].c += aug;
                    }
                    aug =INF;
                }
                goto loop;
            }
        }
        if( (--gap[dis[u]]) == 0)   break;
        int mindis = NV;
        for(int i = head[u]; i != -1 ; i = E[i].next)
        {
            int v = E[i].pos;
            if(E[i].c >0&& mindis > dis[v])
            {
                cur[u] = i;
                mindis = dis[v];
            }
        }
        gap[ dis[u] = mindis+1 ] ++;
        u = pre[u];
    }
    return maxflow;
}
void addEdge(int u,int v,__int64 c )
{
    E[NE].c = c;
    E[NE].pos = v;
    E[NE].next = head[u];
    head[u] = NE++;
    E[NE].c = 0;
    E[NE].pos = u;
    E[NE].next = head[v];
    head[v] = NE++;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int i,j,a,b,w,cost,val;
        __int64 sum=0;
        source=0,sink=3000,NE=0,NV=sink+1;
        memset(head,-1,sizeof(int)*(NV));
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&m);
            for(int j=1; j<=m; j++)
            {
                scanf("%d%d%d",&cost,&val,&w);
                val-=cost;
                if(val>0)
                {
                    addEdge(source,i*26+j,val);
                    sum+=val;
                }
                else    addEdge(i*26+j,sink,-val);
                while(w--)
                {
                    scanf("%d%d",&a,&b);
                    addEdge(i*26+j,a*26+b,INF);
                }
            }
        }
        __int64 ans=sap(source,sink);
        printf("Case #%d: %I64d\n",cas++,sum-ans);
    }
    return 0;
}
