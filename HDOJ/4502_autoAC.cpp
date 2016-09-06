#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int n,m,i,j,t;
    int a[105][105],dp[105];
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&n,&m);
        for(i = 1;i<=m;i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            a[x][y] = max(a[x][y],c);
        }
        for(i = 1;i<=n;i++)
        {
            for(j = i;j>=1;j--)
            dp[i] = max(dp[i],dp[j-1]+a[j][i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
