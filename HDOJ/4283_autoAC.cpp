#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int inf = 10000000;
int n,a[105],sum[105],dp[105][105];
int main()
{
    int t,i,j,k,l,cas = 1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        for(i = 1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        memset(dp,0,sizeof(dp));
        for(i = 1; i<=n; i++)
        {
            for(j = i+1; j<=n; j++)
                dp[i][j] = inf;
        }
        for(l = 1; l<n; l++)
        {
            for(i = 1; i<=n-l; i++)
            {
                j = i+l;
                for(k = 1; k<=j-i+1; k++)
                    dp[i][j] = min(dp[i][j],dp[i+1][i+k-1]+dp[i+k][j]+k*(sum[j]-sum[i+k-1])+a[i]*(k-1));
            }
        }
        printf("Case #%d: %d\n",cas++,dp[1][n]);
    }
    return 0;
}
