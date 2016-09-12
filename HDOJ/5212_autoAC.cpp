#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef long long LL;
int dp[11111];
int num[11111];
int sum[11111];
int n;
int main()
{
    while(scanf("%d", &n) != EOF)
    {
        int maxnum = 0, ans = 0;
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; i ++)
        {
            scanf("%d", &num[i]);
            sum[num[i]] ++;
            maxnum = maxnum < num[i] ? num[i] : maxnum;
        }
        memset(dp, 0, sizeof(dp));
        for(int i = 2; i <= maxnum; i ++)
        {
            for(int j = i; j <= maxnum; j += i)
            {
                dp[i] += sum[j];
            }
            dp[i] *= dp[i];
        }
        for(int i = maxnum; i >= 2; i --)
        {
            for(int j = i + i; j <= maxnum; j += i)
                dp[i] -= dp[j];
            ans = (ans + (LL)i * (i - 1) * dp[i]) % 10007;
        }
        printf("%d\n", ans);
    }
    return 0;
}
