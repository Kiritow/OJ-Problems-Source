#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct node
{
    int x,y,v;
}a[20];
int dp[1005][1005];
int main()
{
    int i,j,k,n,X,Y,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&X,&Y);
        for(i = 0;i<n;i++)
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].v);
        memset(dp,0,sizeof(dp));
        for(i = 0;i<=X;i++)
        {
            for(j = 0;j<=Y;j++)
            {
                for(k = 0;k<n;k++)
                {
                    if(i>=a[k].x && j>=a[k].y)
                    dp[i][j] = max(dp[i][j],max((dp[i-a[k].x][j]+dp[a[k].x][j-a[k].y]),(dp[i][j-a[k].y]+dp[i-a[k].x][a[k].y]))+a[k].v);
                    if(i>=a[k].y && j>=a[k].x)
                    dp[i][j] = max(dp[i][j],max((dp[i-a[k].y][j]+dp[a[k].y][j-a[k].x]),(dp[i][j-a[k].x]+dp[i-a[k].y][a[k].x]))+a[k].v);
                }
            }
        }
        printf("%d\n",dp[X][Y]);
    }
    return 0;
}
