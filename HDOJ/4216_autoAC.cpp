#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define D 10000
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
int num[105][2];
int dp[2][20005][2];
int T,n,x,y;
double dis(int a,int b)
{
    double c=(double)a,d=(double)b;
    return sqrt((c-x)*(c-x)+(d-y)*(d-y));
}
int main()
{
    scanf("%d",&T);
    for(int cas=1; cas<=T; ++cas)
    {
        scanf("%d%d%d",&n,&x,&y);
        x+=D;
        y+=D;
        for(int i=1; i<=n; ++i)
        {
            scanf("%d%d",&num[i][0],&num[i][1]);
        }
        memset(dp,-1,sizeof(dp));
        dp[0][D][0]=dp[0][D][1]=D;
        for(int i=1; i<=n; ++i)
        {
            for(int j=0; j<=20000; ++j)
                for(int k=0; k<2; ++k)
                {
                    if(dp[(i-1)&1][j][k]!=-1)
                    {
                        if(dp[i&1][j+num[i][1]][0]==-1||dp[i&1][j+num[i][1]][0]>dp[(i-1)&1][j][k]+num[i][0])
                            dp[i&1][j+num[i][1]][0]=dp[(i-1)&1][j][k]+num[i][0];
                        if(dp[i&1][j-num[i][1]][0]==-1||dp[i&1][j-num[i][1]][0]>dp[(i-1)&1][j][k]-num[i][0])
                            dp[i&1][j-num[i][1]][0]=dp[(i-1)&1][j][k]-num[i][0];
                        if(dp[i&1][j+num[i][1]][1]==-1||dp[i&1][j+num[i][1]][1]<dp[(i-1)&1][j][k]+num[i][0])
                            dp[i&1][j+num[i][1]][1]=dp[(i-1)&1][j][k]+num[i][0];
                        if(dp[i&1][j-num[i][1]][1]==-1||dp[i&1][j-num[i][1]][1]<dp[(i-1)&1][j][k]-num[i][0])
                            dp[i&1][j-num[i][1]][1]=dp[(i-1)&1][j][k]-num[i][0];
                    }
                }
        }
        double dist=0.0;
        for(int i=0; i<=20000; ++i)
            for(int j=0; j<2; ++j)
                if(dp[n&1][i][j]!=-1)
                    dist=max(dist,dis(dp[n&1][i][j],i));
        printf("Case %d: %.3f\n",cas,dist);
    }
    return 0;
}
