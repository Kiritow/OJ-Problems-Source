#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
__int64 dp[70][70],a[70],sum[70];
__int64 pow(__int64 n)
{
    __int64 ans= 1;
    int i;
    for(i = 1; i<=n; i++)
        ans*=2;
    return ans;
}
int main()
{
    int t,i,j,k,s;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        for(i = 1; i<=n; i++)
        {
            scanf("%I64d",&a[i]);
            sum[i] = sum[i-1]+a[i];
        }
        memset(dp,0,sizeof(dp));
        for(s = 0; s<=n; s++)
        {
            for(i = 1; i<=n && i+s<=n; i++)
            {
                j = i+s;
                if(s<=19)
                    dp[i][j] =a[i]*pow(j-i)*2;
                else
                    dp[i][j] = (sum[j]-sum[i-1])*2;
                for(k = i; k<=j; k++)
                    dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
        }
        printf("%I64d\n",dp[1][n]);
    }
    return 0;
}
