#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s1[105],s2[105];
int dp[105][105];
int ans[105],i,j,k,len;
int main()
{
    while(~scanf("%s%s",s1,s2))
    {
        len = strlen(s1);
        memset(dp,0,sizeof(dp));
        for(j = 0; j<len; j++)
        {
            for(i = j; i>=0; i--)
            {
                dp[i][j] = dp[i+1][j]+1;
                for(k = i+1; k<=j; k++)
                {
                    if(s2[i]==s2[k])
                        dp[i][j] = min(dp[i][j],(dp[i+1][k]+dp[k+1][j]));
                }
            }
        }
        for(i = 0; i<len; i++)
            ans[i] = dp[0][i];
        for(i = 0; i<len; i++)
        {
            if(s1[i] == s2[i])
                ans[i] = ans[i-1];
            else
            {
                for(j = 0; j<i; j++)
                    ans[i] = min(ans[i],ans[j]+dp[j+1][i]);
            }
        }
        printf("%d\n",ans[len-1]);
    }
    return 0;
}
