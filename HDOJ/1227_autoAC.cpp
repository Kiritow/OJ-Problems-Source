#include <stdio.h>
#define inf 0x7fffffff
int abbs(int a) { return a<0 ? -a : a ; }
int  food[205], dp[35][205], dis[205][205];
int  main()
{
    int  n, m, i, j, k, mid, minn, p=1;
    while(scanf("%d%d", &n, &m) != EOF )
    {
        if( n==0 && m==0 ) break;
        for(i=1; i<=n; i++)
            scanf("%d",&food[i]);
        for(i=1; i<=n; i++)
        {
            for(j=i; j<=n; j++)
            {
                dis[i][j] = 0;    mid = (i+j)/2;
                for(k=i;   k<=j;  k++ )
                    dis[i][j] += abbs( food[k] - food[mid] ) ;
            }
        }
        for( i=1; i<=n; i++ )
        {
            dp[1][i] = dis[1][i];
        }
        for(i=2; i<=m; i++ )
        {
            for(j=i; j<=n; j++ )
            {
                dp[i][j] = inf ;
                for(k=i-1; k<j; k++ )
                    if( dp[i][j] > dp[i-1][k] + dis[k+1][j] )
                        dp[i][j] = dp[i-1][k] + dis[k+1][j] ;
            }
        }
        printf("Chain %d\nTotal distance sum = %d\n\n" , p++, dp[m][n] );
    }
}
