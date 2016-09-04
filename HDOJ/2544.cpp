#include <cstdio>
#include <cstdlib>
#include <cstring>

#define INF 0x3f3f3f3f

using namespace std;

namespace SPFA
{
const int MAXN = 110;
int d[MAXN];/// distance
int v[MAXN];/// visit
int q[MAXN];/// 基于数组的队列(也可用queue等...)
int n;///点总数
int m;///边总数
int mp[MAXN][MAXN]; /// mp[i][j] 表示ｉ<--> j 连通 从1开始

int spfa(int s,int t)
{
    for(int i=1;i<=n;i++)
        d[i]=INF,v[i]=0;
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


int main()
{
    using namespace SPFA;
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        memset(mp,-1,sizeof(mp));
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            mp[a][b]=mp[b][a]=c;/// 这里并没有判断a b的关系..
        }
        printf("%d\n",spfa(1,n));
    }
    return 0;
}
