#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )
const int MAXN = 100005 ;
const int MAXE = 200005 ;
struct Node {
    int v , p , d ;
    Node () {}
    Node ( int v , int p , int d ) : v ( v ) , p ( p ) , d ( d ) {}
} ;
struct Edge {
    int v , n ;
    Edge () {}
    Edge ( int v , int n ) : v ( v ) , n ( n ) {}
} ;
Node Q[3000005] ;
Edge E[MAXE] ;
int H[MAXN] , cntE ;
int head , tail ;
LL ans ;
int n , k ;
void clear () {
    ans = 0 ;
    cntE = 0 ;
    clr ( H , -1 ) ;
}
void addedge ( int u , int v ) {
    E[cntE] = Edge ( v , H[u] ) ;
    H[u] = cntE ++ ;
}
void bfs () {
    int cnt = 0 ;
    head = tail = 0 ;
    For ( i , 1 , n ) Q[tail ++] = Node ( i , 0 , 0 ) ;
    while ( head != tail ) {
        Node x = Q[head ++] ;
        int u = x.v , p = x.p ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( v != p ) {
                Q[tail ++] = Node ( v , u , x.d + 1 ) ;
                ans += x.d + 1 ;
                ++ cnt ;
                if ( cnt == k ) return ;
            }
        }
    }
}
void solve () {
    int u , v ;
    clear () ;
    scanf ( "%d%d" , &n , &k ) ;
    k *= 2 ;
    rep ( i , 1 , n ) {
        scanf ( "%d%d" , &u , &v ) ;
        addedge ( u , v ) ;
        addedge ( v , u ) ;
    }
    bfs () ;
    printf ( "%I64d\n" , ans / 2 ) ;
}
int main () {
    int T ;
    scanf ( "%d" , &T ) ;
    while ( T -- ) solve () ;
    return 0 ;
}
