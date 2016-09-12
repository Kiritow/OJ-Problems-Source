#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define clr( a , x ) memset ( a , x , sizeof a )
#define cpy( a , x ) memcpy ( a , x , sizeof a )
const int MAXN = 10005 ;
const int MAXE = 20005 ;
struct Edge {
    int v , n ;
    Edge () {}
    Edge ( int v , int n ) : v ( v ) , n ( n ) {}
} ;
Edge E[MAXE] ;
int H[MAXN] , cntE ;
int phi[MAXN] ;
LL val[MAXN] ;
LL S[MAXN] , top ;
LL ct[MAXN] ;
int ans ;
int n ;
int Q[MAXN] , head , tail ;
map < LL , int > mp ;
int vis[MAXN] ;
int siz[MAXN] ;
int pre[MAXN] ;
int gcd ( int a , int b ) {
    return b ? gcd ( b , a % b ) : a ;
}
void init () {
    ans = 0 ;
    cntE = 0 ;
    clr ( H , -1 ) ;
    clr ( vis , 0 ) ;
}
void addedge ( int u , int v ) {
    E[cntE] = Edge ( v , H[u] ) ;
    H[u] = cntE ++ ;
}
LL get ( int n , int m ) {
    LL res = 0 ;
    if ( n > m ) swap ( n , m ) ;
    for ( int i = 1 , j ; i <= n ; i = j + 1 ) {
        j = min ( n / ( n / i ) , m / ( m / i ) ) ;
        res += ( LL ) ( phi[j] - phi[i - 1] ) * ( n / i ) * ( m / i ) ;
    }
    return res ;
}
void preprocess () {
    for ( int i = 0 ; i <= 10000 ; ++ i ) {
        phi[i] = i ;
    }
    for ( int i = 2 ; i <= 10000 ; ++ i ) if ( phi[i] == i ) {
        for ( int j = i ; j <= 10000 ; j += i ) {
            phi[j] = phi[j] / i * ( i - 1 ) ;
        }
    }
    for ( int i = 2 ; i <= 10000 ; ++ i ) {
        phi[i] += phi[i - 1] ;
    }
    for ( int t = 1 ; t <= 10000 ; ++ t ) {
        ct[t] = get ( t , t ) + ct[t - 1] ;
    }
}
int get_root ( int s ) {
    head = tail = 0 ;
    Q[tail ++] = s ;
    pre[s] = 0 ;
    while ( head != tail ) {
        int u = Q[head ++] ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( vis[v] || v == pre[u] ) continue ;
            pre[v] = u ;
            Q[tail ++] = v ;
        }
    }
    int root_siz = tail , root = s ;
    while ( head ) {
        int u = Q[-- head] , cnt = 1 ;
        siz[u] = 1 ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( vis[v] || v == pre[u] ) continue ;
            siz[u] += siz[v] ;
            if ( siz[v] > cnt ) cnt = siz[v] ;
        }
        cnt = max ( cnt , tail - siz[u] ) ;
        if ( cnt < root_ ) {
            root_siz = cnt ;
            root = u ;
        }
    }
    return root ;
}
void get_val ( int u , int f , LL value ) {
    S[top ++] = value ;
    for ( int i = H[u] ; ~i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( vis[v] || v == f ) continue ;
        get_val ( v , u , value ^ val[v] ) ;
    }
}
void dfs ( int u ) {
    int root = get_root ( u ) ;
    vis[root] = 1 ;
    mp.clear () ;
    if ( !val[root] ) ++ ans ;
    for ( int i = H[root] ; ~i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( vis[v] ) continue ;
        top = 0 ;
        get_val ( v , root , val[v] ) ;
        for ( int j = 0 ; j < top ; ++ j ) {
            map < LL , int > :: iterator it = mp.find ( S[j] ^ val[root] ) ;
            if ( it != mp.end () ) ans += it->second * 2 ;
            if ( !( S[j] ^ val[root] ) ) ans += 2 ;
        }
        for ( int j = 0 ; j < top ; ++ j ) {
            mp[S[j]] ++ ;
        }
    }
    for ( int i = H[root] ; ~i ; i = E[i].n ) {
        int v = E[i].v ;
        if ( vis[v] ) continue ;
        dfs ( v ) ;
    }
}
void solve () {
    int t , a , b , c ;
    init () ;
    for ( int i = 1 ; i < n ; ++ i ) {
        scanf ( "%d%d" , &a , &b ) ;
        addedge ( a , b ) ;
        addedge ( b , a ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d%d%d" , &t , &a , &b , &c ) ;
        val[i] = ct[t - 1] + c - 1 ;
        val[i] += get ( a - 1 , t ) ;
        val[i] += get ( a , b - 1 ) - get ( a - 1 , b - 1 ) ;
    }
    dfs ( 1 ) ;
    ans = n * n - ans ;
    int x = gcd ( n * n , ans ) ;
    printf ( "%d/%d\n" , ans / x , n * n / x  ) ;
}
int main () {
    preprocess () ;
    while ( ~scanf ( "%d" , &n ) ) solve () ;
    return 0 ;
}
