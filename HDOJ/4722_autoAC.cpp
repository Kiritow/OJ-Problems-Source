#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
__int64 bit[20];
__int64 dp[20][10];
__int64 solve(__int64 n)
{
    __int64 ans;
    __int64 tem1 = n,len,sum,i,x,j,k;
    len = sum = ans = 0;
    memset(dp,0,sizeof(dp));
    while(tem1)
    {
        bit[++len] = tem1%10;
        tem1/=10;
    }
    for(i = 1; i<=len/2; i++)
    {
        int t;
        t = bit[i];
        bit[i] = bit[len-i+1];
        bit[len-i+1] = t;
    }
    x = 0;
    for(i = 1; i<=len; i++)
    {
        for(j = 0; j<10; j++)
            for(k = 0; k<10; k++)
                dp[i][(j+k)%10]+=dp[i-1][j];
        for(j = 0; j<bit[i]; j++)
            dp[i][(x+j)%10]++;
        x = (x+bit[i])%10;
    }
    if(!x)
        dp[len][0]++;
    return dp[len][0];
}
int main()
{
    __int64 T,l,r,cas = 1;
    __int64 ans;
    scanf("%I64d",&T);
    while(T--)
    {
        ans = 0;
        scanf("%I64d%I64d",&l,&r);
        ans = solve(r)-solve(l-1);
        printf("Case #%I64d: %I64d\n",cas++,ans);
    }
    return 0;
}
