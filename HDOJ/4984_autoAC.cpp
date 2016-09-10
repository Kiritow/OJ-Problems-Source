#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define REP( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define FOR( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define REV( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define travel( e , H , u ) for ( Edge* e = H[u] ; e ; e = e -> next )
#define CLR( a , x ) memset ( a , x , sizeof a )
typedef long long LL ;
const int MAXN = 55 ;
const int MAXE = 205 ;
const double INF = 1e10 ;
const double eps = 1e-8 ;
struct Edge {
    int v ;
    double c ;
    Edge* next ;
} E[MAXE] , *H[MAXN] , *cur ;
struct Line {
    int x , y , a , b ;
    double v ;
    void input () {
        scanf ( "%d%d%d%d" , &x , &y , &a , &b ) ;
    }
    bool operator < ( const Line& p ) const {
        return v > p.v ;
    }
} L[MAXE] ;
int n , m , t ;
int p[MAXN] ;
double f[MAXN] ;
double a[10005] ;
int cnt ;
double st , ed , ans ;
int sgn ( double x ) {
    return ( x > eps ) - ( x < -eps ) ;
}
void clear () {
    cur = E ;
    CLR ( H , 0 ) ; 
    FOR ( i , 1 , n ) {
        p[i] = i ;
        f[i] = INF ;
    }
}
void addedge ( int u , int v , double c ) {
    cur -> v = v ;
    cur -> c = c ;
    cur -> next = H[u] ;
    H[u] = cur ++ ;
}
int find ( int x ) {
    return p[x] == x ? x : ( p[x] = find ( p[x] ) ) ;
}
void kruskal () {
    sort ( L , L + m ) ;
    int cnt = 1 ;
    REP ( i , 0 , m ) {
        int x = find ( L[i].x ) ;
        int y = find ( L[i].y ) ;
        if ( x != y ) {
            p[x] = y ;
            addedge ( L[i].x , L[i].y , L[i].v ) ;
            addedge ( L[i].y , L[i].x , L[i].v ) ;
            if ( ++ cnt == n ) break ;
        }
    }
}
void dfs ( int u , int fa ) {
    travel ( e , H , u ) {
        int v = e -> v ;
        if ( v == fa ) continue ;
        f[v] = min ( f[u] , e -> c ) ;
        dfs ( v , u ) ;
    }
}
int unique ( int n ) {
    int cnt = 1 ;
    sort ( a + 1 , a + n + 1 ) ;
    FOR ( i , 2 , n ) if ( sgn ( a[i] - a[cnt] ) ) a[++ cnt] = a[i] ;
    return cnt ;
}
void solve () {
    ans = 0 ;
    cnt = 0 ;
    scanf ( "%d%d%d" , &n , &m , &t ) ;
    REP ( i , 0 , m ) {
        L[i].input () ;
        REP ( j , 0 , i ) {
            if ( L[i].b == L[j].b ) continue ;
            a[++ cnt] = ( double ) ( L[i].a - L[j].a ) / ( L[j].b - L[i].b ) ;
        }
    }
    a[++ cnt] = t ;
    cnt = unique ( cnt ) ;
    st = 0 ;
    FOR ( i , 1 , cnt ) {
        if ( a[i] < 0 ) continue ;
        if ( a[i] > t ) break ;
        ed = a[i] ;
        double mid = ( st + ed ) / 2 ;
        REP ( j , 0 , m ) L[j].v = L[j].a + L[j].b * mid ;
        clear () ;
        kruskal () ;
        dfs ( 1 , 0 ) ;
        FOR ( j , 2 , n ) ans += f[j] * ( ed - st ) ;
        st = ed ;
    }
    printf ( "%.3f\n" , ans / t ) ;
}
int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    while ( T -- ) solve () ;
    return 0 ;
}
