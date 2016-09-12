#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define clr(a,x); memset ( a , x , sizeof a ) ;
const int MAXN = 1 << 17 ;
const int mod = 998244353 ;
const int g = 3 ;
LL f[MAXN] , invf[MAXN] ;
LL tcnt[MAXN] ;
LL dp[MAXN] , dp2[MAXN] ;
LL x1[MAXN] , x2[MAXN] , x3[MAXN] ;
int n ;
LL power ( LL a , int b ) {
    LL res = 1 , tmp = a ;
    while ( b ) {
        if ( b & 1 ) res = res * tmp % mod ;
        tmp = tmp * tmp % mod ;
        b >>= 1 ;
    }
    return res ;
}
void NTT ( LL y[] , int n , int rev ) {
    for ( int i = 1 , j , k , t ; i < n ; ++ i ) {
        for ( j = 0 , k = n >> 1 , t = i ; k ; k >>= 1 , t >>= 1 ) {
            j = j << 1 | ( t & 1 ) ;
        }
        if ( i < j ) swap ( y[i] , y[j] ) ;
    }
    for ( int s = 2 , ds = 1 ; s <= n ; ds = s , s <<= 1 ) {
        LL wn = power ( g , ( mod - 1 ) / s ) ;
        if ( !rev ) wn = power ( wn , mod - 2 ) ;
        for ( int k = 0 ; k < n ; k += s ) {
            LL w = 1 , t ;
            for ( int i = k ; i < k + ds ; ++ i , w = w * wn % mod ) {
                y[i + ds] = ( y[i] - ( t = y[i + ds] * w % mod ) + mod ) % mod ;
                y[i] = ( y[i] + t ) % mod ;
            }
        }
    }
    if ( !rev ) {
        LL invn = power ( n , mod - 2 ) ;
        for ( int i = 0 ; i < n ; ++ i ) {
            y[i] = y[i] * invn % mod ;
        }
    }
}
void cdq_fz ( int l , int r ) {
    if ( l == r ) return ;
    if ( l + 1 == r ) {
        dp[r] = ( dp[r] + dp[l] ) % mod ;
        return ;
    }
    int m = ( l + r ) >> 1 , n1 = 1 ;
    cdq_fz ( l , m ) ;
    while ( n1 <= r - l + 1 ) n1 <<= 1 ;
    for ( int i = 0 ; i < n1 ; ++ i ) {
        x1[i] = l + i <= m ? dp[l + i] * invf[l + i] % mod : 0 ;
        x2[i] = l + i <= r ? tcnt[i + 1] * invf[i] % mod : 0 ;
        x3[i] = l + i <= r ? tcnt[i + 2] * invf[i] % mod : 0 ;
    }
    NTT ( x1 , n1 , 1 ) ;
    NTT ( x2 , n1 , 1 ) ;
    NTT ( x3 , n1 , 1 ) ;
    for ( int i = 0 ; i < n1 ; ++ i ) {
        x3[i] = x1[i] * x3[i] % mod ;
        x2[i] = x1[i] * x2[i] % mod ;
    }
    NTT ( x2 , n1 , 0 ) ;
    NTT ( x3 , n1 , 0 ) ;
    for ( int i = m + 1 ; i <= r ; ++ i ) {
        dp[i] = ( dp[i] + f[i - 1] * x2[i - l - 1] % mod ) % mod ;
        dp2[i] = ( dp2[i] + f[i - 2] * x3[i - l - 2] % mod ) % mod ;
    }
    cdq_fz ( m + 1 , r ) ;
}
void preprocess () {
    f[0] = invf[0] = 1 ;
    dp[0] = dp2[0] = dp2[1] = 1 ;
    for ( int i = 1 ; i <= 100000 ; ++ i ) {
        f[i] = f[i - 1] * i % mod ;
        invf[i] = power ( f[i] , mod - 2 ) ;
        if ( i >= 2 ) tcnt[i] = power ( i , i - 2 ) ;
    }
    tcnt[1] = 1 ;
    cdq_fz ( 0 , 100000 ) ;
}
void solve () {
    int x ;
    scanf ( "%d" , &n ) ;
    int ans1 = power ( 2 , n ) , ans2 = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &x ) ;
        ans1 = ans1 * dp[x] % mod ;
        if ( n > 2 ) ans2 = ans2 * dp2[x] % mod ;
    }
    printf ( "%d\n" , ( ans1 - ans2 + mod ) % mod ) ;
}
int main () {
    int T ;
    preprocess () ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        solve () ;
    }
    return 0 ;
}
