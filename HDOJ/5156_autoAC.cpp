#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )
const int MAXN = 50005 ;
const int MAXE = 2100005 ;
struct Edge {
    int v , n ;
    Edge () {}
    Edge ( int v , int n ) : v ( v ) , n ( n ) {}
} ;
Edge E[MAXE] ;
int H[MAXN] , cntE ;
int A[MAXN] , B[MAXN << 1] , Q[MAXN] ;
int vis[MAXN] ;
int num[MAXN] ;
int p[MAXN] ;
int n , m ;
void clear () {
    cntE = 1 ;
    clr ( A , 0 ) ;
    clr ( B , 0 ) ;
    clr ( Q , 0 ) ;
    clr ( H , 0 ) ;
    clr ( vis , 0 ) ;
    clr ( num , 0 ) ;
}
int find ( int x ) {
    int tmp , ans , o = x ;
    while ( p[x] != x ) x = p[x] ;
    ans = x , x = o ;
    while ( p[x] != x ) {
        tmp = p[x] ;
        p[x] = ans ;
        x = tmp ;
    }
    return ans ;
}
void addedge ( int u , int v , int H[] ) {
    E[cntE] = Edge ( v , H[u] ) ;
    H[u] = cntE ++ ;
}
void dfs ( int u , int f = 0 ) {
    for ( int i = A[u] ; i ; i = E[i].n ) addedge ( E[i].v , u , B ) ;
    for ( int i = H[u] ; i ; i = E[i].n ) if ( E[i].v != f ) dfs ( E[i].v , u ) ;
}
void tarjan ( int u , int f = 0 ) {
    p[u] = u ;
    vis[u] = 1 ;
    for ( int i = Q[u] ; i ; i = E[i].n ) if ( vis[E[i].v] ) -- num[find ( E[i].v )] ;
    for ( int i = H[u] ; i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( vis[v] ) continue ;
        tarjan ( v , u ) ;
        p[v] = u ;
    }
    for ( int i = H[u] ; i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( v == f ) continue ;
        num[u] += num[v] ;
    }
}
void scanf ( int& x , char c = 0 ) {
    while ( ( c = getchar () ) < '0' ) ;
    x = c - '0' ;
    while ( ( c = getchar () ) >= '0' ) x = x * 10 + c - '0' ;
}
void solve () {
    int u , v ;
    clear () ;
    rep ( i , 1 , n ) {
        scanf ( u ) ;
        scanf ( v ) ;
        addedge ( u , v , H ) ;
        addedge ( v , u , H ) ;
    }
    For ( i , 1 , m ) {
        scanf ( u ) ;
        scanf ( v ) ;
        addedge ( u , v , A ) ;
        ++ num[u] ;
    }
    dfs ( 1 ) ;
    For ( i , 1 , 100000 ) if ( B[i] ) {
        u = 0 ;
        for ( int j = B[i] ; j ; j = E[j].n ) {
            v = E[j].v ;
            if ( u ) {
                if ( u != v ) {
                    addedge ( u , v , Q ) ;
                    addedge ( v , u , Q ) ;
                } else -- num[v] ;
            }
            u = v ;
        }
    }
    tarjan ( 1 ) ;
    For ( i , 1 , n ) printf ( "%d%c" , num[i] , i < n ? ' ' : '\n' ) ;
}
int main () {
    while ( ~scanf ( "%d%d" , &n , &m ) ) solve () ;
    return 0 ;
}
