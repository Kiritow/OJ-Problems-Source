#include <stdio.h>
int dp[102][102][2];
int main()
{
    int z,ca,n,k;
    scanf("%d",&z);
    dp[1][0][0] = dp[1][0][1] = 1;
    for(int i=2;i<=100;i++)
    {
        dp[i][0][0] = dp[i-1][0][0] + dp[i-1][0][1];
        dp[i][0][1] = dp[i-1][0][0];
        for(int j=1;j<i;j++)
        {
            dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
            dp[i][j][1] = dp[i-1][j][0] + dp[i-1][j-1][1];
        }
    }
    while(z--)
    {
        scanf("%d%d%d",&ca,&n,&k);
        printf("%d %d\n",ca,dp[n][k][0]+dp[n][k][1]);
    }
    return 0;
}
