#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

namespace SPFA
{
const int MAXN = 1005;
int d[MAXN];/// distance [ From S to ... ]
int v[MAXN];/// visit
int q[MAXN];/// ???????(???queue?...)
int mp[MAXN][MAXN]; /// mp[i][j] ???<--> j ?? ?1??
int n;

int spfa(int s,int t)
{
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    /*
    for(int i=1;i<MAXN;i++)
        d[i]=INF,v[i]=0;*/
    int cnt=0;
    q[cnt++]=1;
    v[1]=1;
    d[1]=0;
    while(cnt>0)
    {
        int c=q[--cnt];
        v[c]=0;
        for(int i=1;i<=n;i++)
        {
            if(mp[c][i]!=-1&&d[i]>d[c]+mp[c][i])
            {
                d[i]=d[c]+mp[c][i];
                if(!v[i])   v[i]=1,q[cnt++]=i;
            }
        }
    }
    return d[t];
}

}/// End of NameSpace SPFA

bool labled[SPFA::MAXN];

int main()
{
    using namespace SPFA;
    int T,S,D;
    while(scanf("%d %d %d",&T,&S,&D)==3)
    {
        memset(mp,0x3f,sizeof(mp));
        memset(labled,false,sizeof(labled));
        n=0;
        for(int i=0;i<T;i++)
        {
            int a,b,t;
            scanf("%d %d %d",&a,&b,&t);
            mp[a+1][b+1]=mp[b+1][a+1]=min(mp[a+1][b+1],t);
            n=max(n,max(a+1,b+1));
        }
        for(int i=0;i<S;i++)
        {
            int x;
            scanf("%d",&x);
            mp[1][x+1]=mp[x+1][1]=0;
        }
        spfa(1,1);
        int mintime=INF;
        for(int i=0;i<D;i++)
        {
            int x;
            scanf("%d",&x);
            mintime=min(mintime,d[x+1]);
        }
        printf("%d\n",mintime);
    }
    return 0;
}
