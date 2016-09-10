#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
long long  INF = 0x7fffffff;
using namespace std;
const int maxn=1000+10;
long long n,m;
long long x[maxn*maxn],y[maxn*maxn],z[maxn*maxn];
long long cost[maxn][maxn];
void init()
{
    z[0]= (x[0] * 90123 + y[0] )%8475871 + 1;
    z[1]= (x[1] * 90123 + y[1] )%8475871 + 1;
    for(int i=2;i<n*n;i++)
    {
        x[i] = ( (12345)+(x[i-1]*23456)%5837501+(x[i-2]*34567)%5837501+ ((x[i-1]*x[i-2])%5837501)*45678 )%5837501;
        y[i] = ( (56789)+(y[i-1]*67890)%9860381+(y[i-2]*78901)%9860381+ ((y[i-1]*y[i-2])%9860381)*89012 )%9860381;
        z[i] = (x[i] * 90123 + y[i] )%8475871 + 1;
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        if(i==j) cost[i][j]=0;
        else cost[i][j] = z[i*n+j];
    }
}
bool done[maxn];
long long d[maxn];
void dijkstra()
{
    memset(done,0,sizeof(done));
    for(int i=0;i<n;i++) d[i]= INF;
    d[0]=0;
    for(int i=0;i<n;i++)
    {
        long long x,m=INF;
        for(int y=0;y<n;y++)if(!done[y]&&d[y]<=m) m=d[x=y];
        done[x]=true;
        for(int y=0;y<n;y++)d[y] = min(d[y],d[x]+cost[x][y]);
    }
}
int main()
{
    while(scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&n,&m,&x[0],&x[1],&y[0],&y[1])==6)
    {
        init();
        dijkstra();
        long long ans=INF;
        for(int i=1;i<n;i++)
            ans = min(ans,d[i]%m);
        printf("%I64d\n",ans);
    }
    return 0;
}
