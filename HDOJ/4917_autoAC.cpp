#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
#define ll __int64
using namespace std ;
vector<int> vec[44] ;
const int mod = 1000000007 ;
int dp[1<<21] ;
int fa[44] , sz[44] , vis[44] ;
int to[44] , id[44] , du[44] ;
int c[44][44] ;
void init () {
    c[0][0] = 1 ;
    for ( int i = 1 ; i < 44 ; i ++ ) {
        c[i][0] = 1 ;
        for ( int j = 1 ; j <= i ; j ++ )
            c[i][j] = ( c[i-1][j] + c[i-1][j-1] ) % mod ;
    }
}
int find ( int a ) {
    return fa[a] == a ? a : fa[a] = find ( fa[a] ) ;
}
struct Point {
    int id , st ;
    Point () {}
    Point (int a , int b):id(a),st(b) {}
} ;
int gao ( int s , int n , int& re) {
    int tot = 0 ;
    queue<Point> Q ;
    for ( int i = 1 ; i <= n ; i ++ ) {
        if ( find (i) == s && du[i] == 0 ) {
            to[tot++] = 0 ;
            Q.push ( Point(i,1<<tot-1) ) ;
        }
    }
    while ( !Q.empty () ) {
        Point u = Q.front () ;
        int st = u.st ;
        int f = u.id ;
        Q.pop () ;
        for ( int i = 0 ; i < vec[f].size () ; i ++ ) {
            int v = vec[f][i] ;
            du[v] -- ;
            id[v] |= st ;
            if ( du[v] == 0 ) {
                to[tot++] = id[v] ;
                Q.push ( Point(v,id[v]|(1<<(tot-1))) ) ;
            }
        }
    }
    ll ret = c[re][tot] ;
    re -= tot ;
    dp[0] = 1 ;
    for ( int i = 1 ; i < 1<<tot ; i ++ ) {
        dp[i] = 0 ;
        for ( int j = 0 ; j < tot ; j ++ ) {
            if ( ((i&(1<<j))) ) {
                int st = i ^ (1<<j) ;
                if ( (~st)&to[j] ) continue ;
                dp[i] += dp[i^(1<<j)] ;
                dp[i] %= mod ;
            }
        }
    }
    ret *= dp[(1<<tot)-1] ;
    ret %= mod ;
    return ret ;
}
int main () {
    init () ;
    int n , m ;
    while ( scanf ( "%d%d" , &n , &m ) != EOF ) {
        int re = n ;
        memset ( vis , 0 , sizeof ( vis ) ) ;
        for ( int i = 1 ; i <= n ; i ++ ) {
            vec[i].clear () ;
            fa[i] = i ;
            du[i] = 0 ;
            id[i] = 0 ;
        }
        for ( int i = 1 ; i <= m ; i ++ ) {
            int a , b ;
            scanf ( "%d%d" , &a , &b ) ;
            vec[a].push_back ( b ) ;
            du[b] ++ ;
            int x = find ( a ) , y = find ( b ) ;
            if ( x != y ) fa[x] = y ;
        }
        ll ans = 1 ;
        for ( int i = 1 ; i <= n ; i ++ ) {
            if ( !vis[find(i)] ) {
                ans *= gao (find(i),n,re) ;
                ans %= mod ;
                vis[find(i)] = 1 ;
            }
        }
        printf ( "%I64d\n" , ans ) ;
    }
    return 0 ;
}
