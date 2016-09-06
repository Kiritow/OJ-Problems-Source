#include<stdio.h>
#include<string.h>
#include<algorithm>
#include <stdlib.h>
#define ll __int64
using namespace std ;
const int maxn = 1111111 ;
ll f[maxn] , g[maxn] ;
int wa[maxn] , wb[maxn] , wv[maxn] , ws[maxn] , pos[maxn] ;
struct suf
{
    int sa[maxn] , hei[maxn] , rank[maxn] ;
    int cmp ( int *r , int i , int j , int l )
    {
        return r[i] == r[j] && r[i+l] == r[j+l] ;
    }
    void da ( int *r , int n , int m )
    {
        int *x = wa , *y = wb , *t ;
        int i , j , p ;
        for ( i = 0 ; i < m ; i ++ ) ws[i] = 0 ;
        for ( i = 0 ; i < n ; i ++ ) ws[x[i]=r[i]] ++ ;
        for ( i = 1 ; i < m ; i ++ ) ws[i] += ws[i-1] ;
        for ( i = n - 1 ; i >= 0 ; i -- ) sa[--ws[x[i]]] = i ;
        for ( j = 1 , p = 1 ; p < n ; j *= 2 , m = p )
        {
            for ( p = 0 , i = n - j ; i < n ; i ++ ) y[p++] = i ;
            for ( i = 0 ; i < n ; i ++ ) if ( sa[i] >= j ) y[p++] = sa[i] - j ;
            for ( i = 0 ; i < m ; i ++ ) ws[i] = 0 ;
            for ( i = 0 ; i < n ; i ++ ) ws[x[i]] ++ ;
            for ( i = 1 ; i < m ; i ++ ) ws[i] += ws[i-1] ;
            for ( i = n - 1 ; i >= 0 ; i -- ) sa[--ws[x[y[i]]]] = y[i] ;
            for ( t = x , x = y , y = t , p = 1 , x[sa[0]] = 0 , i = 1 ; i < n ; i ++ )
                x[sa[i]] = cmp ( y , sa[i-1] , sa[i] , j ) ? p - 1 : p ++ ;
        }
        int k = 0 ;
        for ( i = 1 ; i < n ; i ++ ) rank[sa[i]] = i ; 
        for ( i = 0 ; i < n - 1 ; hei[rank[i++]] = k )
            for ( k ? k -- : 0 , j = sa[rank[i]-1] ; r[i+k] == r[j+k] ; k ++ ) ;
    }
    int solve ( int n )
    {
        int ans = 0 , i ;
        for ( i = 1 ; i <= n ; i ++ )
            ans += n - sa[i] - hei[i] ;
        return ans ;
    }
} arr ;
int s1[maxn] , dp[20][2222] ;
void rmq ( int n )
{
    int i , j ;
    f[0] = 1 ;
    for ( i = 1 ; i <= 15 ; i ++ )
        f[i] = f[i-1] * 2 ;
    g[0] = -1 ;
    for ( i = 1 ; i < 2222 ; i ++ )
        g[i] = g[i>>1] + 1 ;
    for ( i = 1 ; f[i] <= n ; i ++ )
        for ( j = 1 ; j + f[i] - 1 <= n ; j ++ )
            dp[i][j] = min ( dp[i-1][j] , dp[i-1][j+f[i-1]] ) ;
}
int query ( int l , int r )
{
    if ( l == r ) return dp[0][l] ;
    if ( l > r ) swap ( l , r ) ;
    int i , j , k ;
    k = g[r-l+1] ;
    return min ( dp[k][l] , dp[k][r-f[k]+1] ) ;
}
char s[maxn] ;
int num[maxn] ;
int main ()
{
    int n , k , i , l , r ;
    int cas ;
    scanf ( "%d" , &cas ) ;
    while ( cas -- )
    {
        int q ;
        scanf ( "%s" , s ) ;
        int len = strlen ( s ) ;
        for ( i = 0 ; i < len ; i ++ ) s1[i] = s[i] ;
        s1[len] = 0 ;
        arr.da ( s1 , len + 1 , 555 ) ;
        for ( i = 1 ; i <= len ; i ++ )
            dp[0][i] = arr.hei[i] ;
        rmq ( len ) ;
        n = len ;
        scanf ( "%d" , &q ) ;
        while ( q -- )
        {
            scanf ( "%d%d" , &l , &r ) ;
            int ans = ( r - l + 1 ) * ( r - l + 2) / 2 ;
            for ( i = 0 ; i <= n ; i ++ ) pos[i] = -1 ;
            for ( i = l ; i <= r ; i ++ ) 
                pos[arr.rank[i-1]] = i - 1 ;
            int last = -1 , d = 0 ;
            for ( i = 1 ; i <= n ; i ++ )
            {
                if ( pos[i] != -1 )
                {
                    if ( last != -1 )
                    {
                        int t = query ( arr.rank[last] + 1 , arr.rank[pos[i]] ) ;
                        d = min ( d , t ) ;
                        d = max ( d , min ( t , r - last ) ) ;
                        ans -= min ( d , r - pos[i] ); 
                    }
                    last = pos[i] ;
                }
            }
            printf ( "%d\n" , ans ) ;
        }
    }
}
