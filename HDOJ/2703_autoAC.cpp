# include <stdio.h>
# include <string.h>
int n ;
int dp[25][2010] ;
int p[25], sec[25] ;
int min(int a, int b){return a<b?a:b;}
int max(int a, int b){return a>b?a:b;}
int gao()
{
    int ans = 0, t = 0 ;
    int i, j ;
    for (i = 0 ; i < n ; i++)
    {
        for (j = 0 ; ; j++)
        {
            if (j != 0) dp[i][j] += dp[i][j-1] ;
            if (j > ans && dp[i][j] == 0) break ;
            if (t != 0) t-- ;
            else if (dp[i][j] != 0)
            {
                dp[i+1][j+sec[i]] += min(dp[i][j], p[i]) ;
                dp[i][j] -= min(dp[i][j], p[i]) ;
                t = sec[i]-1 ;
                ans = max(ans, j+sec[i]) ;
            }
        }
    }
    return ans ;
}
int main ()
{
    int m, i ;
    while (1)
    {
        scanf ("%d%d", &n, &m) ;
        if (n == 0 && m == 0) break ;
        n = -n ;
        for (i = 0 ; i < n ; i++)
            scanf ("%d%d", &p[i], &sec[i]) ;
        memset (dp, 0, sizeof(dp)) ;
        dp[0][0] = m ;
        printf ("%d\n", gao()) ;
    }
    return 0 ;
}
