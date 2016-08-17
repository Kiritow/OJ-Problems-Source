#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<queue>
using namespace std;
#define ll long long
#define db double
const int maxn=108;
const int INF=0x7f7f7f7f;
int mp[maxn][maxn];
int low[maxn],vis[maxn];
int sum;
void prim(int n)
{
    int i,j,k,mi;
    memset(vis,0,sizeof(vis));
    for(i=1;i<=n;i++)
        low[i]=mp[1][i];
    for(i=2;i<=n;i++)
    {
        mi=INF;
        for(j=2;j<=n;j++)
            if(!vis[j]&&low[j]<mi)
            {
                k=j;
                mi=low[j];
            }
        vis[k]=1;
        for(j=2;j<=n;j++)
            if(!vis[j]&&low[j]>mp[k][j])
                low[j]=mp[k][j];
    }
    for(i=1;i<=n;i++)
        sum+=low[i];
}
int main()
{
    int i,j,k,n,a,b,c,d,m;
    while(scanf("%d",&n)==1&&n)
    {
        memset(mp,INF,sizeof(mp));
        for(i=1;i<=n;i++)    mp[i][i]=0;
        m=n*(n-1)/2;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            if(d==1)
                mp[a][b]=mp[b][a]=0;
            else
                mp[a][b]=mp[b][a]=c;
        }
        sum=0;
        prim(n);
        printf("%d\n",sum);
    }
    return 0;
}
