#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define REP( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define REV( i , a , b ) for ( int i = a - 1 ; i >= b ; -- i )
#define FOR( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define FOV( i , a , b ) for ( int i = a ; i >= b ; -- i )
#define CLR( a , x ) memset ( a , x , sizeof a )
typedef long long LL ;
const int MAXN = 1005 ;
const int MAXQ = 2000005 ;
const int MAXE = 2000005 ;
const int INF = 0x3f3f3f3f ;
struct Node {
    int x , y , idx ;
    Node () {}
    Node ( int x , int y , int idx ) : x ( x ) , y ( y ) , idx ( idx ) {}
    void input ( int __ ) {
        scanf ( "%d%d" , &x , &y ) ;
        idx = __ ;
    }
    bool operator < ( const Node &a ) const {
        return x != a.x ? x < a.x : y < a.y ;
    }
} a[MAXN] ;
struct Edge {
    int v , c , n ;
    Edge () {}
    Edge ( int v , int c , int n ) : v ( v ) , c ( c ) , n ( n ) {}
} ;
Edge E[MAXE] ;
int H[MAXN] , cntE ;
int Q[MAXQ] ;
int head , tail , inq[MAXN] ;
int d[MAXN] ;
int n , L ;
int s , t ;
void init () {
    cntE = 0 ;
    CLR ( H , -1 ) ;
}
void addedge ( int u , int v , int c ) {
    E[cntE] = Edge ( v , c , H[u] ) ;
    H[u] = cntE ++ ;
    E[cntE] = Edge ( u , c , H[v] ) ;
    H[v] = cntE ++ ;
}
LL dist ( int i , int j ) {
    LL x = a[i].x - a[j].x ;
    LL y = a[i].y - a[j].y ;
    return x * x + y * y ;
}
void spfa () {
    head = tail = 0 ;
    CLR ( inq , 0 ) ;
    CLR ( d , INF ) ;
    d[s] = 0 ;
    Q[tail ++] = s ;
    while ( head != tail ) {
        int u = Q[head ++] ;
        inq[u] = 0 ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( d[v] > d[u] + 1 ) {
                d[v] = d[u] + 1 ;
                if ( !inq[v] ) {
                    inq[v] = 1 ;
                    Q[tail ++] = v ;
                }
            }
        }
    }
}
int cha ( int i , int j , int k ) {
    LL x1 = a[i].x - a[j].x ;
    LL x2 = a[j].x - a[k].x ;
    LL y1 = a[i].y - a[j].y ;
    LL y2 = a[j].y - a[k].y ;
    if ( x1 * y2 - x2 * y1 )
        return 1 ;
    return 0 ;
}
void build () {
    LL LLL = ( LL ) L * L ;
    REP ( i , 0 , n )
        REP ( j , i + 1 , n )
            if ( dist ( i , j ) <= LLL ) {
                int ok = 1 ;
                int minx = min ( a[i].x , a[j].x ) ;
                int maxx = max ( a[i].x , a[j].x ) ;
                int miny = min ( a[i].y , a[j].y ) ;
                int maxy = max ( a[i].y , a[j].y ) ;
                for ( int k = i + 1 ; ok && k < j ; ++ k )
                    if ( cha ( i , j , k ) == 0 )
                        ok = 0 ;
                if ( ok )
                    addedge ( i , j , 1 ) ;
            }
}
void solve () {
    init () ;
    int x , y ;
    scanf ( "%d%d" , &n , &L ) ;
    a[n].input ( n ) ;
    a[n + 1].input ( n + 1 ) ;
    REP ( i , 0 , n )
        a[i].input ( i ) ;
    n += 2 ;
    sort ( a , a + n ) ;
    build () ;
    REP ( i , 0 , n ) {
        if ( a[i].idx == n - 2 )
            s = i ;
        if ( a[i].idx == n - 1 )
            t = i ;
    }
    spfa () ;
    if ( d[t] == INF )
        printf ( "impossible\n" ) ;
    else
        printf ( "%d\n" , d[t] - 1 ) ;
}
int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    while ( T -- )
        solve () ;
    return 0 ;
}
