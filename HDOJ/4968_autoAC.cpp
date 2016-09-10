#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define up(i,x,y) for(i=x;i<=y;i++)
#define up2(i,x,y) for(i=x;y;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define w(x) while(x)
#define inf 99999999
double a[105],dp[1005][105];
int i,j,k,n,m,t,sum;
int main()
{
    up(i,60,100)
    {
        if(i<=69) a[i]=2;
        else if(i<=74) a[i]=2.5;
        else if(i<=79) a[i]=3;
        else if(i<=84) a[i]=3.5;
        else a[i]=4;
    }
    scanf("%d",&t);
    w(t--)
    {
        scanf("%d%d",&m,&n);
        sum=n*m;
        up(i,0,sum)
        up(j,0,n)
        dp[i][j]=inf;
        up(i,60,100)
        dp[i][1]=a[i];
        up(j,2,n)
        up(i,0,sum)
        up2(k,60,(k<=100&&(i-k)>=60*(j-1)))
        dp[i][j]=min(dp[i][j],dp[i-k][j-1]+dp[k][1]);
        printf("%.4f ",dp[sum][n]/n);
        up(i,0,sum)
        up(j,0,n)
        dp[i][j]=0;
        up(i,60,100)
        dp[i][1]=a[i];
        up(j,2,n)
        up(i,0,sum)
        up2(k,60,(k<=100&&(i-k)>=60*(j-1)))
        dp[i][j]=max(dp[i][j],dp[i-k][j-1]+dp[k][1]);
        printf("%.4f\n",dp[sum][n]/n);
    }
    return 0;
}
