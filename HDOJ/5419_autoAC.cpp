#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define LL __int64
LL dp[50100] ;
int a[50100] ;
LL gcd(LL a,LL b) {
    return b == 0 ? a : gcd(b,a%b) ;
}
int main() {
    int t , n , m ;
    int i , l , r ;
    LL x , y , temp ;
    scanf("%d", &t) ;
    while( t-- ) {
        scanf("%d %d", &n, &m) ;
        memset(dp,0,sizeof(dp)) ;
        for(i = 1 ; i <= n ; i++)
            scanf("%d", &a[i]) ;
        while( m-- ) {
            scanf("%d %d", &l, &r) ;
            dp[l]++ ;
            dp[r+1]-- ;
        }
        x = 0 ;
        y = (LL)n*(n-1)*(n-2)/6 ;
        for(i = 1 ; i <= n ; i++) {
            dp[i] += dp[i-1] ;
            if( dp[i] > 2 )
                x += dp[i]*(dp[i]-1)*(dp[i]-2)/6*a[i] ;
        }
        if( x == 0 || y == 0 ) {
            printf("0\n") ;
            continue ;
        }
        temp = gcd(x,y) ;
        x /= temp ;
        y /= temp ;
        if( y == 1 )
            printf("%I64d\n", x ) ;
        else
            printf("%I64d/%I64d\n", x, y) ;
    }
    return 0 ;
}
