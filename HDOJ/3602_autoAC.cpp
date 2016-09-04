#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int a[110], b[110];
int dp[110][10100][2];
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int n, m, k;
        int sum = 0;
        int num = 0;
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            if(a[i] > k)  continue;
            a[i]++;
            sum += b[i];
            a[++num] = a[i];
            b[num] = b[i];
        }
        n = num;
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i <= n; i++)
        {
            dp[i][0][0] = 1;
            dp[i][0][1] = 0;
        }
        for(int i = 1; i <= n; i++)
        {
            for(int j = sum; j >= b[i]; j--)
            {
                dp[i][j][0] = dp[i-1][j][0];
                dp[i][j][1] = dp[i-1][j][1];
                if(dp[i-1][j-b[i]][1] == -1)  continue;
                if(dp[i-1][j-b[i]][1] + a[i] <= k)
                {
                    if(dp[i][j][0] == -1 || dp[i-1][j-b[i]][0] < dp[i][j][0] ||
                    (dp[i-1][j-b[i]][0] == dp[i][j][0] && dp[i-1][j-b[i]][1] + a[i] < dp[i][j][1]))
                    {
                        dp[i][j][0] = dp[i-1][j-b[i]][0];
                        dp[i][j][1] = dp[i-1][j-b[i]][1] + a[i];
                    }
                }
                else
                {
                    if(dp[i][j][0] == -1 || dp[i-1][j-b[i]][0] + 1 < dp[i][j][0] ||
                    (dp[i-1][j-b[i]][0] + 1 == dp[i][j][0] && a[i] < dp[i][j][1]))
                    {
                        dp[i][j][0] = dp[i-1][j-b[i]][0] + 1;
                        dp[i][j][1] = a[i];
                    }
                }
            }
        }
        int rmax = 0;
          for(int j = 0; j <= sum; j++)
          if(dp[n][j][0] != -1 && dp[n][j][0] <= m && j > rmax)
          {
              rmax = j;
          }
        printf("%d\n", rmax);
    }
    return 0;
}
