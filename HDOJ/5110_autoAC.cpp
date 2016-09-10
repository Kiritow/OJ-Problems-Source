#include <set>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )
const int MAXN = 1005 ;
const int L = 33 ;
int G[MAXN][MAXN] ;
int down[MAXN][MAXN] ;
int prefix[MAXN][MAXN] ;
int prefix_dn[MAXN][MAXN] ;
int prefix_lt[MAXN][MAXN] ;
int prefix_rt[MAXN][MAXN] ;
int ans[L][MAXN][MAXN] ;
int n , m , q , sqrtD ;
char s[MAXN] ;
void scanf ( int &x , char c = 0 ) {
    while ( ( c = getchar () ) < '0' || c > '9' ) ;
    x = c - '0' ;
    while ( ( c = getchar () ) >= '0' && c <= '9' ) x = x * 10 + c - '0' ;
}
void read () {
    For ( i , 1 , n ) {
        scanf ( "%s" , s + 1 ) ;
        For ( j , 1 , m ) {
            G[i][j] = ( s[j] == 'X' ) ;
            prefix[i][j] = prefix[i][j - 1] + G[i][j] ;
        }
    }
}
void solve1 () {
    int x , y , D ;
    sqrtD = ( int ) sqrt ( ( double ) n ) ;
    For ( k , 1 , sqrtD ) {
        For ( i , 1 , n ) {
            For ( j , 1 , m ) {
                down[i][j] = G[i][j] ;
                if ( i - k > 0 ) down[i][j] += down[i - k][j] ;
                prefix_dn[i][j] = prefix_dn[i][j - 1] + down[i][j] ;
                prefix_lt[i][j] = down[i][j] ;
                if ( i - k > 0 ) {
                    if ( j - k <= 0 ) prefix_lt[i][j] += prefix_dn[i - k][j - 1] - prefix_dn[i - k][0] ;
                    else {
                        prefix_lt[i][j] += prefix_dn[i - k][j - 1] - prefix_dn[i - k][j - k] ;
                        prefix_lt[i][j] += prefix_lt[i - k][j - k] ;
                    }
                }
            }
            rev ( j , m , 1 ) {
                prefix_rt[i][j] = down[i][j] ;
                if ( i - k > 0 ) {
                    if ( j + k > m ) prefix_rt[i][j] += prefix_dn[i - k][m] - prefix_dn[i - k][j] ;
                    else {
                        prefix_rt[i][j] += prefix_rt[i - k][j + k] ;
                        prefix_rt[i][j] += prefix_dn[i - k][j + k - 1] - prefix_dn[i - k][j] ;
                    }
                }
            }
            For ( j , 1 , m ) ans[k][i][j] = prefix_lt[i][j] + prefix_rt[i][j] - down[i][j] ;
        }
    }
    while ( q -- ) {
        scanf ( x ) ;
        scanf ( y ) ;
        scanf ( D ) ;
        if ( D <= sqrtD ) {
            //printf ( "%d %d\n" , prefix_lt[x][y][D] , prefix_rt[x][y][D] ) ;
            printf ( "%d\n" , ans[D][x][y] ) ;
        }
        else {
            int L = y , R = y , sum = 0 ;
            while ( x > 0 ) {
                sum += prefix[x][R] - prefix[x][L - 1] ;
                x -= D ;
                L = max ( 1 , L - D ) ;
                R = min ( m , R + D ) ;
            }
            printf ( "%d\n" , sum ) ;
        }
    }
}
void solve2 () {
    int x , y , D ;
    while ( q -- ) {
        scanf ( x ) ;
        scanf ( y ) ;
        scanf ( D ) ;
        int L = y , R = y , sum = 0 ;
        while ( x > 0 ) {
            sum += prefix[x][R] - prefix[x][L - 1] ;
            x -= D ;
            L = max ( 1 , L - D ) ;
            R = min ( m , R + D ) ;
        }
        printf ( "%d\n" , sum ) ;
    }
}
int main () {
    while ( ~scanf ( "%d%d%d" , &n , &m , &q ) ) {
        read () ;
        if ( q > 1000 ) solve1 () ;
        else solve2 () ;
    }
    return 0 ;
}
