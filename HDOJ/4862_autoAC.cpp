#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std ;
const int N = 2222 ;
const int M = 222222 ;
const int INF = 11111111 ;
struct Edge {
    int from , to , next , flow , cap , cost ;
    Edge () {}
    Edge (int a,int b,int c,int d,int e) {
        from = a , to = b , flow = c , cap = d , cost = e ;
    }
} edge[M] ;
int head[N] , tot ;
void new_edge ( int from , int to , int flow , int cap , int cost ) {
    edge[tot] = Edge ( from , to , flow , cap , cost );
    edge[tot].next = head[from] ;
    head[from] = tot ++ ;
    edge[tot] = Edge ( to , from , 0 , 0 , -cost ) ;
    edge[tot].next = head[to] ;
    head[to] = tot ++ ;
}
int vis[N] , dis[N] , pre[N] , add[N] ;
queue<int> Q ;
int spfa ( int s , int t , int& flow , int& cost , int n ) {
    int i , u , v ;
    for ( i = 1 ; i <= n ; i ++ ) dis[i] = INF ;
    dis[s] = 0 , add[s] = INF ;
    Q.push ( s ) ; vis[s] = 1 ;
    while ( !Q.empty () ) {
        u = Q.front () ; Q.pop () , vis[u] = 0 ;
        for ( i = head[u] ; i != -1 ; i = edge[i].next ) {
            Edge e = edge[i] ;
            v = e.to ;
            if ( e.cap > e.flow && dis[v] > dis[u] + edge[i].cost ) {
                dis[v] = dis[u] + edge[i].cost ;
                add[v] = min ( add[u] , e.cap - e.flow ) ;
                pre[v] = i ;
                if ( !vis[v] ) Q.push (v) , vis[v] = 1 ;
            }
        }
    }
    if ( dis[t] >= 0 ) return 0 ;
    flow += add[t] ; cost += add[t] * dis[t] ;
    u = t ;
    while ( u != s ) {
        edge[pre[u]].flow += add[t] ;
        edge[pre[u]^1].flow -= add[t] ;
        u = edge[pre[u]].from ;
    }
    return 1 ;
}
int mincost_maxflow ( int s , int t , int n ) {
    int flow = 0 , cost = 0 ;
    while ( spfa ( s , t , flow , cost , n ) ) ;
    return cost ;
}
char mp[33][33] ;
int cnt ;
int c[33][33][2] ;
int change ( int x , int y , int z ) {
    if ( !c[x][y][z] ) c[x][y][z] = ++ cnt ;
    return c[x][y][z] ;
}
int main () {
    int n , m , k ;
    int cas , ca = 0 ;
    scanf ( "%d" , &cas ) ;
    while ( cas -- ) {
        scanf ( "%d%d%d" , &n , &m , &k ) ;
        for ( int i = 1 ; i <= n ; i ++ )
            scanf ( "%s" , mp[i]+1 ) ;
        cnt = tot = 0 ;
        memset ( c , 0 , sizeof (c) ) ;
        memset ( head , -1 , sizeof ( head ) ) ;
        int s , t , temp ;
        s = ++ cnt , t = ++ cnt , temp = ++ cnt ;
        new_edge ( s , temp , 0 , k , 0 ) ;
        for ( int i = 1 ; i <= n ; i ++ )
            for ( int j = 1 ; j <= m ; j ++ ) {
                new_edge ( change(i,j,0) , change(i,j,1) , 0 , 1 , -INF ) ;
                new_edge ( change(i,j,1) , t , 0 , 1 , 0 ) ;
                new_edge ( temp , change(i,j,0) , 0 , 1 , 0 ) ;
                for ( int k = j + 1 ; k <= m ; k ++ ) {
                    int add = -(k - j - 1) ;
                    if ( mp[i][j] == mp[i][k] ) add += mp[i][j] - '0' ;
                    new_edge ( change(i,j,1) , change(i,k,0) , 0 , 1 , -add ) ;
                }
                for ( int k = i + 1 ; k <= n ; k ++ ) {
                    int add = -(k - i - 1) ;
                    if ( mp[i][j] == mp[k][j] ) add += mp[i][j] - '0' ;
                    new_edge ( change(i,j,1) , change(k,j,0) , 0 , 1 , -add ) ;
                }
            }
        int fuck = mincost_maxflow ( s , t , cnt ) ;
        printf ( "Case %d : " , ++ ca ) ;
        if ( fuck > -INF * n * m ) puts ( "-1" ) ;
        else printf ( "%d\n" , -(fuck + n * m * INF ) ) ;
    }
    return 0 ;
}
