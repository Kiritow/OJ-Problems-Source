#include<iostream>
#include<stdio.h>
#include<string.h> 
using namespace std ;
typedef long long LL ;
#define clr( a , x ) memset ( a , x , sizeof a )
const int MAXN = 505 ;
const int mod = 1e9 + 7 ;
int G[MAXN][2] , cnt ;
int f[MAXN] ;
int root[MAXN] , idx ;
int is[MAXN] ;
int num[MAXN] ;
int dp[MAXN] , dp2[MAXN][MAXN] ;
int n , cur ;
void upd ( int& x , int y ) {
    x += y ;
    if ( x >= mod ) x -= mod ;
}
void preprocess () {
    dp[0] = dp[1] = 1 ;
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        for ( int j = 0 ; j < i ; ++ j ) {
            upd ( dp[i] , ( LL ) dp[j] * dp[i - 1 - j] % mod ) ;
        }
    }
}
void dfs ( int u , int x ) {
    int l = G[u][0] , r = G[u][1] ;
    if ( is[u] == is[l] ) dfs ( l , x ) ;
    if ( is[u] == is[r] ) dfs ( r , x ) ;
    if ( is[l] != is[u] && is[r] != is[u] ) {
        if ( !l && !r ) {
            for ( int i = 0 ; i <= x ; ++ i ) {
                dp2[u][i] = dp[i + 1] ;
            }
        } else if ( !l ) {
            for ( int i = 0 ; i <= x ; ++ i ) {
                dp2[u][i] = dp[i] ;
            }
        } else if ( !r ) {
            for ( int i = 0 ; i <= x ; ++ i ) {
                dp2[u][i] = dp[i] ;
            }
        } else {
            dp2[u][0] = 1 ;
            for ( int i = 1 ; i <= x ; ++ i ) {
                dp2[u][i] = 0 ;
            }
        }
    } else if ( is[u] != is[l] ) {
        if ( !l ) {
            for ( int i = 0 ; i <= x ; ++ i ) {
                dp2[u][i] = 0 ;
                for ( int j = 0 ; j <= i ; ++ j ) {
                    upd ( dp2[u][i] , ( LL ) dp[j] * dp2[r][i - j] % mod ) ;
                }
            }
        } else {
            for ( int i = 0 ; i <= x ; ++ i ) {
                dp2[u][i] = dp2[r][i] ;
            }
        }
    } else if ( is[u] != is[r] ) {
        if ( !r ) {
            for ( int i = 0 ; i <= x ; ++ i ) {
                dp2[u][i] = 0 ;
                for ( int j = 0 ; j <= i ; ++ j ) {
                    upd ( dp2[u][i] , ( LL ) dp[j] * dp2[l][i - j] % mod ) ;
                }
            }
        } else {
            for ( int i = 0 ; i <= x ; ++ i ) {
                dp2[u][i] = dp2[l][i] ;
            }
        }
    } else {
        for ( int i = 0 ; i <= x ; ++ i ) {
            dp2[u][i] = 0 ;
            for ( int j = 0 ; j <= i ; ++ j ) {
                upd ( dp2[u][i] , ( LL ) dp2[l][j] * dp2[r][i - j] % mod ) ;
            }
        }
    }
}
int newnode ( int x ) {
    ++ cnt ;
    G[cnt][0] = G[cnt][1] = 0 ;
    f[cnt] = cur ;
    is[cnt] = x ;
    return cnt ;
}
void solve () {
    int op , x ;
    idx = cnt = 0 ;
    cur = 1 ;
    newnode ( 0 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &op ) ;
        if ( op == 0 ) cur = f[cur] ;
        else if ( op <= 2 ) {
            if ( !G[cur][op - 1] ) {
                G[cur][op - 1] = newnode ( is[cur] ) ;
                num[is[cur]] -- ;
            }
            cur = G[cur][op - 1] ;
        } else {
            scanf ( "%d" , &x ) ;
            G[cur][op - 3] = newnode ( ++ idx ) ;
            root[idx] = cnt ;
            num[idx] = x - 1 ;
        }
    }
    int ans = 1 ;
    for ( int i = 1 ; i <= idx ; ++ i ) if ( num[i] ) {
        dfs ( root[i] , num[i] ) ;
        ans = ( LL ) ans * dp2[root[i]][num[i]] % mod ;
    }
    printf ( "%d\n" , ans ) ;
}
int main () {
    int cas = 0 ;
    preprocess () ;
    while ( ~scanf ( "%d" , &n ) ) {
        printf ( "Case #%d: " , ++ cas ) ;
        solve () ;
    }
    return 0 ;
}
