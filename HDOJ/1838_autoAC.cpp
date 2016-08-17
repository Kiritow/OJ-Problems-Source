#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[2010][2010];
int dp[2010][2010];
int main()
{
    int test,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i = 0; i < n; i++)
            scanf("%s",s[i]);
        for(int i = 0; i < n; i++)
        {
            dp[0][i] = 1;
            dp[i][0] = 1;
        }
        int ans = -1,cnt = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(s[i][j] != s[i-1][j] && s[i][j] != s[i][j-1] && s[i][j] == s[i-1][j-1])
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                else dp[i][j] = 1;
                if(s[i][j] == '1')
                    ans = max(ans,dp[i][j]);
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dp[i][j] == ans && s[i][j] == '1')
                    cnt++;
            }
        }
        printf("%d %d\n",ans,cnt);
    }
    return 0;
}
