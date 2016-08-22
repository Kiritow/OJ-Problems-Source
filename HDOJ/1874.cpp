#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define INF 0x3f3f3f3f

namespace SPFA
{
const int MAXN = 256;
int d[MAXN];/// distance [ From S to ... ]
int v[MAXN];/// visit
int q[MAXN];///
int mp[MAXN][MAXN]; /// mp[i][j] i<--> j is connected.
int n;

int spfa(int s,int t)
{
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    /*
    for(int i=1;i<MAXN;i++)
        d[i]=INF,v[i]=0;*/
    int cnt=0;
    q[cnt++]=s;
    v[s]=1;
    d[s]=0;
    while(cnt>0)
    {
        int c=q[--cnt];
        v[c]=0;
        for(int i=1;i<=n;i++)
        {
            if(mp[c][i]!=INF&&d[i]>d[c]+mp[c][i])
            {
                d[i]=d[c]+mp[c][i];
                if(!v[i])   v[i]=1,q[cnt++]=i;
            }
        }
    }
    return d[t];
}

}/// End of NameSpace SPFA

int main()
{
    using namespace SPFA;
    int N,M;
    while(scanf("%d %d",&N,&M)==2)
    {
        memset(mp,0x3f,sizeof(mp));
        for(int i=0;i<M;i++)
        {
            int a,b,cost;
            scanf("%d %d %d",&a,&b,&cost);
            ++a;++b;
            if(mp[a][b]>cost)
            {
                mp[b][a]=mp[a][b]=cost;
            }
        }
        int s,t;
        scanf("%d %d",&s,&t);
        if(s==t)
        {
            printf("0\n");continue;
        }
        ++s;++t;
        SPFA::n=N;
        int ans=spfa(s,t);
        printf("%d\n",ans>=INF ? -1 : ans );
    }
    return 0;
}
