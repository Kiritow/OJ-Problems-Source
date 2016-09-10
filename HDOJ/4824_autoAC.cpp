#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define max3(a,b,c) (max(a,max(b,c)))
#define min(a,b) ((a)<(b)?(a):(b))
const int N=1005;
struct Point
{
    int road,area;
    void Get ()
    {
        scanf("%d%d",&road,&area);
    }
    int Dis (Point b)
    {
        int tmp=fabs(b.area-area);
        return 400*fabs(b.road-road)+min( tmp,360-tmp);
    }
}data[N];
int dis[N][N];
int dp[N][N];
int main ()
{
    int T,i,j,n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        data[0].area=0;
        data[0].road=0;
        memset(dis,0,sizeof(dis));
        memset(dp,0,sizeof(dp));
        for (i=1;i<=n;i++)
            data[i].Get();
        for (i=0;i<=n;i++)
            for (j=i+1;j<=n;j++)
                dis[i][j]=dis[j][i]=data[i].Dis(data[j]);
        dp[0][0]=0;
        n++;
        for (i=1;i<n;i++)
            dp[i][0]=dis[i][0];
        for (i=1;i<n-1;i++)
        {
            dp[i+1][i]=1000000000;
            for (j=0;j<=i-1;j++)
            {
                dp[i+1][j]=dp[i][j]+dis[i][i+1];
                dp[i+1][i]=min(dp[i+1][i],dp[i][j]+dis[j][i+1]);
            }
        }
        printf("%d\n",dp[n-1][n-2]+dis[n-1][n-2]+10*(n-1));
    }
    return 0;
}
