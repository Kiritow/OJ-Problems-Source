#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int MAX = 999999;
int val[111],time[111],dp[111][1111];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        int i,j,k;
        for(i = 0; i<n; i++)
            scanf("%d%d",&time[i],&val[i]);
        for(i = 0; i<=m; i++)
        {
            for(j = 0; j<=l; j++)
            {
                if(i==0)
                    dp[i][j] = 0;
                else
                    dp[i][j] = -MAX;
            }
        }
        for(i = 0; i<n; i++)
        {
            for(j = m; j>=1; j--)
            {
                for(k = l; k>=time[i]; k--)
                {
                    dp[j][k] = max(dp[j][k],dp[j-1][k-time[i]]+val[i]);
                }
            }
        }
        if(dp[m][l]<0)
            dp[m][l] = 0;
        printf("%d\n",dp[m][l]);
    }
    return 0;
}
