#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005

#define INF 10000000000000LL
using LL = long long;

LL a[MAXN];
LL b[MAXN];
LL c[MAXN];
LL d[MAXN];
LL x[MAXN];
LL dis[MAXN][MAXN];

LL nextpos[MAXN];



int main()
{
    int n,StartPoint,EndPoint;
    scanf("%d %d %d",&n,&StartPoint,&EndPoint);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&x[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&b[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&c[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&d[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) {dis[i][j]=0;continue;}
            if(j>i)
            {
                dis[i][j]=abs(x[i]-x[j])+d[i]+a[j];
            }
            else /// (j<i)
            {
                dis[i][j]=abs(x[i]-x[j])+c[i]+b[j];
            }
        }
    }
    nextpos[StartPoint]=EndPoint;
    LL sum=dis[StartPoint][EndPoint];
    int GoodTargetPoint=0;
    for(int PointToView=1;PointToView<=n;PointToView++)
    {
        if(PointToView==StartPoint||PointToView==EndPoint) continue;
        LL MinDis=INF;
        for(int CurrentPoint=StartPoint;CurrentPoint!=EndPoint;CurrentPoint=nextpos[CurrentPoint])
        {
            LL tmp=dis[CurrentPoint][PointToView]+dis[PointToView][nextpos[CurrentPoint]]-dis[CurrentPoint][nextpos[CurrentPoint]];
            if(tmp<MinDis)
            {
                MinDis=tmp;
                GoodTargetPoint=CurrentPoint;
            }
        }
        sum+=MinDis;
        nextpos[PointToView]=nextpos[GoodTargetPoint];
        nextpos[GoodTargetPoint]=PointToView;
    }
    printf("%lld\n",sum);
    return 0;
}
