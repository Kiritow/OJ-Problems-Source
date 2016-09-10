#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std ;
int son[11111] ;
int chain[10][1111] , a[11111] ;
int vis[11111] , du[11111] , len[11] ;
double dfs ( int u , int step , int c ) {
    chain[c][step] = a[u] ;
    if ( son[u] == -1 ) return step + 2 ;
    return dfs ( son[u] , step + 1 , c ) ;
}
int main () {
    int n , m ;
    int T ;
    scanf ( "%d" , &T ) ;
    while ( T -- ) {
        scanf ( "%d%d" , &n , &m ) ;
        memset ( chain , 0 , sizeof ( chain ) ) ;
        memset ( du , 0 , sizeof ( du ) ) ;
        memset ( son , -1 , sizeof ( son ) ) ;
        for ( int i = 0 ; i < n ; i ++ )
            scanf ( "%d" , &a[i] ) ;
        for ( int i = 1 ; i <= m ; i ++ ) {
            int a , b ;
            scanf ( "%d%d" , &a , &b ) ;
            son[a] = b ;
            du[b] ++ ;
        }
        double sum = 1 , ans = 0 ;
        int tot = 0 ;
        for ( int i = 0 ; i < n ; i ++ ) {
            if ( du[i] == 0 ) {
                len[tot] = dfs ( i , 0 , tot ) ;
                sum *= len[tot] ;
                len[tot] -- ;
                tot ++ ;
            }
        }
        sum -= 1 ;
        for ( int i = 0 ; i < 1000 ; i ++ ) {
            for ( int j = 0 ; j < 1 << tot ; j ++ ) {
                int flag = 0 ;
                double add = 0 , p = 1 , x = 0 , cnt = 0 ;
                for ( int k = 0 ; k < tot ; k ++ ) {
                    if ( chain[k][i] ) cnt ++ ;
                    if ( j & (1<<k) ) {
                        if ( chain[k][i] == 0 ) {
                            flag = 1 ;
                            break ;
                        }
                        add += chain[k][i] ;
                        x ++ ;
                        p *= len[k] - i ;
                    }
                    else {
                        p *= min ( len[k] + 1 , i + 1 ) ;
                    }
                }
                if ( flag ) continue ;
                double fuck = ( add + (x>1?(add*x/cnt):0) ) * p ;
                ans += fuck ;
            }
        }
        printf ( "%.3f\n" , ans / sum ) ;
    }
    return 0 ;
}
