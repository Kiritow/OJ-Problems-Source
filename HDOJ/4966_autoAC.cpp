#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <cctype>
using namespace std;
const int INF=1<<30;
const int maxn=500+50;
const int maxm=2000+10;
struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}e[maxn+maxm];
int sum[maxn],a[maxn],tot,in[maxn],pre[maxn],id[maxn],vis[maxn];
void add(int u,int v,int w)
{
    e[tot++]=edge(u,v,w);
}
int Directed_MST(int root,int numv,int nume)
{
    int i,j,k,u,v,ans=0;
    while(true)
    {
        for(i=0;i<numv;i++)in[i]=INF;
        for(i=0;i<nume;i++)
        {
            u=e[i].u;
            v=e[i].v;
            if(e[i].w<in[v]&&u!=v)
            {
                pre[v]=u;
                in[v]=e[i].w;
            }
        }
        for(i=0;i<numv;i++)
        {
            if(i==root)continue;
            if(in[i]==INF)return -1;
        }
        int t=0;
        memset(id,-1,sizeof(id));
        memset(vis,-1,sizeof(vis));
        in[root]=0;
        for(i=0;i<numv;i++)
        {
            ans+=in[i];
            v=i;
            while(vis[v]!=i&&id[v]==-1&&v!=root)
            {
                vis[v]=i;
                v=pre[v];
            }
            if(v!=root&&id[v]==-1)
            {
                for(u=pre[v];u!=v;u=pre[u])
                    id[u]=t;
                id[v]=t++;
            }
        }
        if(t==0)break;
        for(i=0;i<numv;i++)
            if(id[i]==-1)id[i]=t++;
        for(i=0;i<nume;i++)
        {
            v=e[i].v;
            e[i].u=id[e[i].u];
            e[i].v=id[e[i].v];
            if(e[i].u!=e[i].v)
                e[i].w-=in[v];
        }
        numv=t;
        root=id[root];
    }
    return ans;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)break;
        int i,j,k;
        sum[0]=tot=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            a[i]++;             
            sum[i+1]=sum[i]+a[i];
        }
        for(i=0;i<n;i++)
        {
            for(j=sum[i+1]-1;j>sum[i];j--)add(j,j-1,0);
            add(sum[n],sum[i],0);
        }
        int c,d,l1,l2,money;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d%d%d",&c,&l1,&d,&l2,&money);
            add(sum[c-1]+l1,sum[d-1]+l2,money);
        }
        printf("%d\n",Directed_MST(sum[n],sum[n]+1,tot));
    }
    return 0;
}
