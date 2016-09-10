#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std ;
void get_num ( int& n ) {
    n = 0 ;
    char c ;
    while ( c = getchar () ) {
        if ( c >= '0' && c <= '9' ) break ;
    }
    n = c - '0' ;
    while ( c = getchar () ) {
        if ( c < '0' || c > '9' ) break ;
        n = n * 10 + c -'0' ;
    }
}
const int maxn = 50005 ;
const int mod = 10007 ;
short dp[2][33][33][maxn] ;
int c[33] , d[33] ;
char s[maxn] , s1[33] ;
vector<int> vec[maxn] ;
int p[20][maxn] , fa[maxn] , deep[maxn] ;
struct LCA {
    void dfs ( int u ) {
        if ( u == 1 ) fa[u] = 0 ;
        p[0][u] = fa[u] ;
        deep[u] = deep[fa[u]] + 1 ;
        for ( int i = 1 ; i < 20 ; i ++ ) p[i][u] = p[i-1][p[i-1][u]] ;
        int sz = vec[u].size () ;
        for ( int i = 0 ; i < sz ; i ++ ) {
            int v = vec[u][i] ;
            if ( v == fa[u] ) continue ;
            fa[v] = u ;
            dfs ( v ) ;
        }
    }
    int father_k ( int u , int k ) {
        for ( int i = 0 ; i < 20 ; i ++ )
            if ( k & ( 1 << i ) )
                u = p[i][u] ;
        return u ;
    }
    int query ( int a , int b ) {
        if ( deep[a] > deep[b] ) swap ( a , b ) ;
        b = father_k ( b , deep[b] - deep[a] ) ;
        if ( a == b ) return a ;
        for ( int i = 19 ; i >= 0 ; i -- ) {
            if ( fa[a] == fa[b] ) break ;
            if ( p[i][a] != p[i][b] ) {
                a = p[i][a] ;
                b = p[i][b] ;
            }
        }
        return fa[a] ;
    }
} lca ;
int l ;
void dfs ( int u , int x , int c ) {
    for ( int i = x ; i <= l ; i ++ ) {
        dp[c][x][i][u] += dp[c][x][i][fa[u]] ;
        if ( dp[c][x][i][u] >= mod ) dp[c][x][i][u] -= mod ;
        if ( s[u] == s1[i] )
            dp[c][x][i][u] += dp[c][x][i-1][fa[u]] ;
        if ( dp[c][x][i][u] >= mod ) dp[c][x][i][u] -= mod ;
    }
    int sz = vec[u].size () ;
    for ( int i = 0 ; i < sz ; i ++ ) {
        int v = vec[u][i] ;
        if ( v == fa[u] ) continue ;
        dfs ( v , x , c ) ;
    }
}
void DP ( int n , int c ) {
    for ( int i = 0 ; i <= l + 1 ; i ++ ) {
        for ( int j = 0 ; j <= n ; j ++ ) {
            for ( int k = 0 ; k <= i ; k ++ )
                dp[c][k][i][j] = 0 ;
            if (i) dp[c][i][i-1][j] = 1 ;
        }
    }
    for ( int i = 1 ; i <= l ; i ++ )
        dfs ( 1 , i , c ) ;
}
int main () {
    int T , n , q ;
    scanf ( "%d" , &T ) ;
    while ( T -- ) {
        scanf ( "%d%d" , &n , &q ) ;
        for ( int i = 1 ; i <= n ; i ++ ) vec[i].clear () ;
        for ( int i = 1 ; i < n ; i ++ ) {
            int a , b ;
            get_num (a) ;
            get_num (b) ;
            vec[a].push_back (b) ;
            vec[b].push_back (a) ;
        }
        scanf ( "%s" , s + 1 ) ;
        scanf ( "%s" , s1 + 1 ) ;
        l = strlen ( s1 + 1 ) ;
        lca.dfs ( 1 ) ;
        reverse ( s1 + 1 , s1 + l + 1 ) ;
        DP ( n , 0 ) ;
        reverse ( s1 + 1 , s1 + l + 1 ) ;
        DP ( n , 1 ) ;
        while ( q -- ) {
            int a , b , x , y ;
            get_num (a) ;
            get_num (b) ;
            if ( a == b ) {
                if ( l == 1 && s[a] == s1[1] ) puts ( "1" ) ;
                else puts ( "0" ) ;
                continue ;
            }
            int w = lca.query ( a , b ) ;
            int ans = 0 ;
            memset ( c , 0 , sizeof ( c ) ) ;
            memset ( d , 0 , sizeof ( d ) ) ;
            for ( int i = 0 ; i <= l ; i ++ ) {
                c[i] = dp[0][l-i+1][l][a] ;
                d[i] = dp[1][l-i+1][l][b] ;
                for ( int j = 0 ; j < i ; j ++ ) {
                    c[i] -= (c[j] * dp[0][l-i+1][l-j][w] % mod) ;
                    d[i] -= (d[j] * dp[1][l-i+1][l-j][w] % mod) ;
                    c[i] += mod ;
                    if ( c[i] >= mod ) c[i] -= mod ;
                    d[i] += mod ;
                    if ( d[i] >= mod ) d[i] -= mod ;
                }
            }
            for ( int i = 0 ; i <= l ; i ++ ) {
                ans += c[i] * d[l-i] % mod ;
                if ( ans >= mod ) ans -= mod ;
            }
            for ( int i = 0 ; i < l ; i ++ ) {
                if ( s[w] == s1[i+1] ) {
                    ans += c[i] * d[l-i-1] % mod ;
                    if ( ans >= mod ) ans -= mod ;
                }
            }
            printf ( "%d\n" , ans ) ;
        }
    }
}
