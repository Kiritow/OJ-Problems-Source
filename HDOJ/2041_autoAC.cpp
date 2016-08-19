#include <stdio.h>
int main()
{
    int n;
    int i;
    int m;
    int count;
    int dp[50];
    while(scanf("%d",&n)!=EOF)
    {
        dp[1]=1;
        dp[2]=1;
        dp[3]=2;
        while(n--)
        {
            count=0;
            scanf("%d",&m);
            for(i=4; i<=m; i++)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            printf("%d\n",dp[m]);
        }
    }
    return 0;
}
