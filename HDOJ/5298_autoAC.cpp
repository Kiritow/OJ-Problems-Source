#include <stdio.h>
typedef long long LL ;
struct Node {
    LL x , y , z , d ;
} a[100] , b[10] ;
int n , m , p , q ;
LL f ( LL x ) {
    return ( LL ) x * x ;
}
bool calc ( int x , int y , int z ) {
    bool t = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) if ( a[i].x * x + a[i].y * y + a[i].z * z + a[i].d > 0 ) t ^= 1 ;
    for ( int i = 0 ; i < m ; ++ i ) if ( f ( b[i].d ) > f ( b[i].x - x ) + f ( b[i].y - y ) + f ( b[i].z - z ) ) t ^= 1 ;
    return t ;
}
void solve () {
    int x , y , z , ok = 1 , mark = -1 ;
    scanf ( "%d%d%d%d" , &n , &m , &p , &q ) ;
    for ( int i = 0 ; i < n ; ++ i ) scanf ( "%lld%lld%lld%lld" , &a[i].x , &a[i].y , &a[i].z , &a[i].d ) ;
    for ( int i = 0 ; i < m ; ++ i ) scanf ( "%lld%lld%lld%lld" , &b[i].x , &b[i].y , &b[i].z , &b[i].d ) ;
    for ( int i = 0 ; i < p ; ++ i ) {
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( !ok ) continue ;
        bool tmp = calc ( x , y , z ) ;
        if ( mark == -1 ) mark = tmp ;
        else if ( mark != tmp ) ok = 0 ;
    }
    if ( !ok ) puts ( "Impossible" ) ;
    for ( int i = 0 ; i < q ; ++ i ) {
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( !ok ) continue ;
        bool tmp = calc ( x , y , z ) ;
        if ( mark == -1 ) puts ( "Both" ) ;
        else puts ( mark == tmp ? "Y" : "R" ) ;
    }
}
int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    for ( int i = 1 ; i <= T ; ++ i ) {
        if ( i > 1 ) puts ( "" ) ;
        solve () ;
    }
    return 0 ;
}
