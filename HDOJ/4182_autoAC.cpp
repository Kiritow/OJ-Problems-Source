#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std ;
#define maxn 201
#define INF 10000000
struct node
{
    int e , d ;
}qe[maxn] ;
int dp[maxn][maxn] , k ;
int cmp( node a , node b )
{
    return a.d > b.d ;
}
bool check( int n , int m )
{
    int i , j ;
    for( i = 0 ; i <= n ;i++ )
        for( j = 0 ; j <= m ;j++ )
          dp[i][j] = INF ;
    dp[0][0] = 0 ;
    for( i = 1 ; i <= n ;i++ )
    {
        dp[i][0] = dp[i-1][0]+qe[i].e ;
        for( j = 1 ; j <= m && j <= i;j++ )
        {
           dp[i][j] = dp[i-1][j]+qe[i].e ;
           dp[i][j] = min( dp[i][j],dp[i-1][j-1]+j*qe[i].d) ;
        }
    }
    return dp[n][m] <= k ;
}
int main()
{
    int i , j , n , m ,ans ,case1 = 0 , tot ;
    while( scanf("%d%d",&n , &k ) != EOF)
    {
        if( n == k && k == 0 ) break ;
        tot = 0 ;
        for( i = 1 ; i <= n ;i++ ) {
            scanf("%d%d" , &qe[i].e,&qe[i].d) ;
            tot += qe[i].e ;
        }
        sort(qe+1,qe+1+n,cmp) ;
        ans = -1 ;
        if( tot <= k ) ans = 0 ;
        for( i = n ; i >= 0 ;i-- )
        {
            if(check(n,i))
            {
                ans = i ;
                break ;
            }
        }
        if( ans == -1 )printf("%d: Mission Impossible\n",++case1) ;
        else printf("%d: %d\n",++case1,ans) ;
    }
}
