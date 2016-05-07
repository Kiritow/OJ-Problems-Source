#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 105
int father[MAXN];
int noderank[MAXN];

void init()
{
    for(int i=0;i<MAXN;i++)
    {
        father[i]=i;
        noderank[i]=0;
    }
}

int findfather(int node)
{
    if(father[node]!=node)
    {
        father[node]=findfather(father[node]);
    }
    return father[node];
}

void UNION(int a,int b)
{
    int fa=findfather(a);
    int fb=findfather(b);
    if(fa==fb)
    {
        return;
    }
    if(noderank[fa]>noderank[fb])
    {
        father[fb]=fa;
    }
    else
    {
        father[fa]=fb;
        if(noderank[fa]==noderank[fb])
        {
            noderank[fb]++;
        }
    }
}

struct pack
{
    int a,b,v;
};
#define MAXM 5000
pack pk[MAXM];

bool cmp(const pack& a,const pack& b)
{
    return a.v<b.v;
}

int main()
{
    int N;
    while(scanf("%d",&N)==1&&N!=0)
    {
        init();
        int cnt=0;
        int a,b,c,d;
        int M=(N-1)*N/2;
        for(int i=0;i<M;i++)
        {
            /// Start End Value IsBuilt
            scanf("%d %d %d %d",&a,&b,&c,&d);
            if(d)
            {
                UNION(a,b);
            }
            else
            {
                pk[cnt].a=a;
                pk[cnt].b=b;
                pk[cnt].v=c;
                ++cnt;
            }
        }
        sort(pk,pk+cnt,cmp);
        int ans=0;
        for(int i=0;i<cnt;i++)
        {
            int fa=findfather(pk[i].a);
            int fb=findfather(pk[i].b);
            if(fa!=fb)
            {
                UNION(fa,fb);
                ans+=pk[i].v;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
