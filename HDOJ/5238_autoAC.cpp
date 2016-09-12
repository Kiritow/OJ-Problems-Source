#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define clr( a , x ) memset ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define mid ( ( l + r ) >> 1 )
#define root 1 , 1 , n
const int MAXN = 50005 ;
const int MOD = 29393 ;
int mod[4] = { 7 , 13 , 17 , 19 } ;
int p[4][20][MOD] ;
int f[MAXN << 2][4][20] ;
int n , m ;
void preprocess () {
    for ( int i = 0 ; i < 4 ; ++ i ) {
        for ( int j = 0 , m = mod[i] ; j < m ; ++ j ) {
            p[i][j][0] = 1 ;
            for ( int k = 1 ; k < MOD ; ++ k ) {
                p[i][j][k] = p[i][j][k - 1] * j % m ;
            }
        }
    }
}
void upd ( int o , char op , int x ) {
    for ( int i = 0 ; i < 4 ; ++ i ) {
        for ( int j = 0 , m = mod[i] ; j < m ; ++ j ) {
            if ( op == '+' ) f[o][i][j] = ( j + x ) % m ;
            else if ( op == '*' ) f[o][i][j] = ( j * x ) % m ;
            else f[o][i][j] = p[i][j][x] ;
        }
    }
}
void push_up ( int o ) {
    for ( int i = 0 ; i < 4 ; ++ i ) {
        for ( int j = 0 , m = mod[i] ; j < m ; ++ j ) {
            f[o][i][j] = f[rs][i][f[ls][i][j]] ;
        }
    }
}
void build ( int o , int l , int r ) {
    if ( l == r ) {
        char c ;
        int x ;
        scanf ( " %c%d" , &c , &x ) ;
        upd ( o , c , x ) ;
        return ;
    }
    int m = mid ;
    build ( lson ) ;
    build ( rson ) ;
    push_up ( o ) ;
}
void update ( int x , char c , int v , int o , int l , int r ) {
    if ( l == r ) {
        upd ( o , c , v ) ;
        return ;
    }
    int m = mid ;
    if ( x <= m ) update ( x , c , v , lson ) ;
    else update ( x , c , v , rson ) ;
    push_up ( o ) ;
}
int exgcd ( int a , int b , int &x , int &y ) {
    if ( !b ) {
        x = 1 ;
        y = 0 ;
        return a ;
    }
    int ans = exgcd ( b , a % b , y , x ) ;
    y -= a / b * x ;
    return ans ;
}
int crt ( int v ) {
    int ans = 0 ;
    for ( int i = 0 ; i < 4 ; ++ i ) {
        int t = MOD / mod[i] , x , y ;
        exgcd ( t , mod[i] , x , y ) ;
        ans = ( ans + f[1][i][v % mod[i]] * t * ( x % mod[i] ) ) % MOD ;
    }
    return ( ans + MOD ) % MOD ;
}
void solve () {
    int op , x , v ;
    char c ;
    scanf ( "%d%d" , &n , &m ) ;
    build ( root ) ;
    while ( m -- ) {
        scanf ( "%d%d" , &op , &x ) ;
        if ( op == 1 ) {
            printf ( "%d\n" , crt ( x ) ) ;
        } else {
            scanf ( " %c%d" , &c , &v ) ;
            update ( x , c , v , root ) ;
        }
    }
}
int main () {
    int T ;
    preprocess () ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        printf ( "Case #%d:\n" , i ) ;
        solve () ;
    }
    return 0 ;
}
