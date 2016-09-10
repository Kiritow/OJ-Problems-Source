#include "stdio.h"
#include "string.h"
int inf=0x3f3f3f3f;
struct node
{
    int x,y;
}dp[110][110];
int main()
{
    int Case,ii,i,j,n,m,ans;
    int a[110][110];
    scanf("%d",&Case);
    for (ii=1;ii<=Case;ii++)
    {
        scanf("%d%d",&n,&m);
        for (i=1;i<=n;i++)
            for (j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
        memset(dp,inf,sizeof(dp));
        for (i=1;i<=m;i++)
            dp[n][i].x=a[n][i];
        for (i=n-1;i>=1;i--)
            for (j=1;j<=m;j++)
            {
                dp[i][j].x=dp[i+1][j].x+a[i][j];
                dp[i][j].y=j;
                if (j-1>=1 && dp[i+1][j-1].x+a[i][j]<dp[i][j].x)
                {
                    dp[i][j].x=dp[i+1][j-1].x+a[i][j];
                    dp[i][j].y=j-1;
                }
                if (j+1<=m && dp[i+1][j+1].x+a[i][j]<=dp[i][j].x)
                {
                    dp[i][j].x=dp[i+1][j+1].x+a[i][j];
                    dp[i][j].y=j+1;
                }
            }
        ans=inf;
        for (i=1;i<=m;i++)
        if (dp[1][i].x<=ans)
        {
            ans=dp[1][i].x;
            j=i;
        }
        printf("Case %d\n",ii);
        printf("%d",j);
        for (i=1;i<n;i++)
        {
            j=dp[i][j].y;
            printf(" %d",j);
        }
        printf("\n");
    }
    return 0;
}
