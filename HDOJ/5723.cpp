#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXN 100100
#define MAXM 1000100
#define MAXW 1000100
using LL = long long;
struct edge
{
    int u,v,w;
};
bool cmp(const edge& a,const edge& b)
{
    return a.w<b.w;
}
edge bus[MAXM];
int father[MAXN];
char vis[MAXN];

/// Global For DFS
int n,m;

vector<pair<int,int>> vec[MAXN];

int findfather(int x)
{
    return father[x]==x?x:father[x]=findfather(father[x]);
}

/// Global For DFS
LL totalans;

LL dfs(int index)
{
    vis[index]=1;
    int sz=vec[index].size();
    LL ksum=0;
    LL nextans=0;
    for(int i=0;i<sz;i++)
    {
		int tt=vec[index].at(i).first;
        if(!vis[tt])
        {
            nextans=dfs(tt);
            ksum+=nextans;
            totalans+=(n-nextans)*nextans*vec[index].at(i).second;
        }
    }
    return 1+ksum;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        /// ...
        if(n==0||m==0)
        {
            printf("0 0.00\n");
            continue;
        }
        for(int i=0;i<=n;i++)
        {
            father[i]=i;
        }
        for(int i=0;i<MAXN;i++)
        {
            vec[i].clear();
        }
        memset(vis,0,sizeof(vis));

        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&bus[i].u,&bus[i].v,&bus[i].w);
        }
        sort(bus,bus+m,cmp);

        LL sum=0;

        int ss=0;
        for(int cc=0;cc<m&&ss<n-1;cc++)
        {
            /// father[x]==x : x is standalone
            int fu=findfather(bus[cc].u);
            int fv=findfather(bus[cc].v);
            if(fu!=fv)
            {
                father[fu]=fv;
                ++ss;
                sum+=bus[cc].w;
                vec[bus[cc].u].push_back(make_pair(bus[cc].v,bus[cc].w));
                vec[bus[cc].v].push_back(make_pair(bus[cc].u,bus[cc].w));
            }
        }

        int b;
        for(b=1;b<=n;b++)
            /// FAQ: Why == 1 ? ANS: Because Nodes At the Edge of the graph has only 1 route.
            if(vec[b].size()==1) break;

        totalans=0;
        dfs(b);

        double tans=0.5*n*(n-1);
        /// Use Long Long?
        printf("%I64d %.2lf\n",sum,(double)totalans/tans);
    }
    return 0;
}
