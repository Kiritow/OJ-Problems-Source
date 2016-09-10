#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define travel( e , H , u ) for ( Edge* e = H[u] ; e ; e = e -> next )
#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define FOR( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )
const int MAXN = 100005 ;
struct Node {
    int x , idx ;
    double v ;
    bool operator < ( const Node& a ) const {
        return x < a.x ;
    }
} p[MAXN] ;
int idx[MAXN] ;
int n , m ;
double T[MAXN] ;
void add ( int x , double v ) {
    while ( x <= n ) {
        T[x] += v ;
        x += x & -x ;
    }
}
double sum ( int x , double ans = 0 ) {
    while ( x ) {
        ans += T[x] ;
        x -= x & -x ;
    }
    return ans ;
}
int L_find ( int x ) {
    int l = 1 , r = n ;
    while ( l < r ) {
        int m = ( l + r ) >> 1 ;
        if ( p[m].x >= x ) r = m ;
        else l = m + 1 ;
    }
    return l ;
}
int R_find ( int x ) {
    int l = 1 , r = n ;
    while ( l < r ) {
        int m = ( l + r + 1 ) >> 1 ;
        if ( p[m].x <= x ) l = m ;
        else r = m - 1 ;
    }
    return r ;
}
void solve () {
    int x , k ;
    double ans = 0 ;
    clr ( T , 0 ) ;
    scanf ( "%d%d" , &n , &m ) ;
    FOR ( i , 1 , n ) {
        scanf ( "%d%lf" , &p[i].x , &p[i].v ) ;
        p[i].idx = i ;
    }
    sort ( p + 1 , p + n + 1 ) ;
    FOR ( i , 1 , n ) add ( i , p[i].v ) ;
    FOR ( i , 1 , n ) idx[p[i].idx] = i ;
    while ( m -- ) {
        scanf ( "%d%d" , &x , &k ) ;
        int l = 1 , r = p[n].x ;
        int v = idx[x] ;
        while ( l <= r ) {
            int mid = ( l + r ) >> 1 ;
            int L = L_find ( p[v].x - mid ) ;
            int R = R_find ( p[v].x + mid ) ;
            if ( R - L < k ) l = mid + 1 ;
            else if ( R - L > k + 1 ) r = mid - 1 ;
            else if ( R - L == k ) {
                double tmp = ( sum ( R ) - sum ( L - 1 ) - p[v].v ) / k ;
                ans += tmp ;
                add ( v , -p[v].v ) ;
                add ( v , tmp ) ;
                p[v].v = tmp ;
                break ;
            } else if ( R - L == k + 1 ) {
                if ( p[v].x - p[L].x == p[R].x - p[v].x ) {
                    if ( p[L].idx < p[R].idx ) -- R ;
                    else ++ L ;
                }
                else if ( p[v].x - p[L].x < p[R].x - p[v].x ) -- R ;
                else ++ L ;
                double tmp = ( sum ( R ) - sum ( L - 1 ) - p[v].v ) / k ;
                ans += tmp ;
                add ( v , -p[v].v ) ;
                add ( v , tmp ) ;
                p[v].v = tmp ;
                break ;
            }
        }
    }
    printf ( "%.3f\n" , ans ) ;
}
int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    while ( T -- ) solve () ;
    return 0 ;
}
