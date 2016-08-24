#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int dp[1010][1010];
char str[1010][1010];
int main()
{
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        for(int i = 0;i < n;i++)
            scanf("%s",str[i]);
        int ans = 1;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
            {
                if(i == 0 || j == n-1)
                {
                    dp[i][j] = 1;
                    continue;
                }
                int t1 = i, t2 = j;
                while(t1 >= 0 && t2 < n && str[t1][j] == str[i][t2])
                {
                    t1--;
                    t2++;
                }
                t1 = i - t1;
                if(t1 >= dp[i-1][j+1]+1)dp[i][j] = dp[i-1][j+1]+1;
                else dp[i][j] = t1;
                ans = max(ans,dp[i][j]);
            }
        printf("%d\n",ans);
    }
    return 0;
}
