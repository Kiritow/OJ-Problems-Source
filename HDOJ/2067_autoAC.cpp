#include <stdio.h>
#include <string.h>
int main()
{
    __int64 dp[40][40];
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    int i,j,n;
    for(i=2;i<=36;i++)
        for(j=1;j<=i;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
        i=0;
       while(scanf("%d",&n)&&n!=-1)
           printf("%d %d %I64d\n",++i,n,2*dp[n+1][n+1]);
}
