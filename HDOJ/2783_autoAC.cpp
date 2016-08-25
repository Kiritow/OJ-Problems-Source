#include <cstdio>
#include <cstring>
#include <queue>
#include <iostream>
#include <map>
#include <stack>
using namespace std ;
typedef pair<int,int> pii ;
#define X first
#define Y second
const int N = 1010 ;
const int inf = 1e9+7 ;
typedef long long LL;
int n , xx[N] , pre[N] , ww[N] , tot ;
vector<pii>g[N];
struct node {
    int a , c , d , id ;
    node(){};
    node( int a , int c , int d , int id ):a(a),c(c),d(d),id(id){}
    bool operator < ( const node &A ) const {
        if( d != A.d ) return d > A.d ;
        else if( c != A.c ) return c > A.c ;
        else {
            stack<int>s1 , s2; int id1 = id , id2 = A.id ;
            while( id1 != -1 ) { s1.push( xx[id1] ); id1 = pre[id1] ; }
            while( id2 != -1 ) { s2.push( xx[id2] ); id2 = pre[id2] ; }
            while( !s1.empty() ) {
                int a = s1.top() ; s1.pop() ;
                int b = s2.top() ; s2.pop() ;
                if( a > b ) return true ;
            }
            return false ;
        }
    }
};
int bestpath[N] , bestcnt , bestcost ;
int tmppath[N] , tmpcnt , tmpcost ;
void Choose_best( int id , int cnt ) {
    if( tmpcost > bestcost ) return  ;
    stack<int>s ;
    while( id != -1 ) { s.push( xx[id] ); id = pre[id] ; }
    tmpcnt = 0 ;
    while( !s.empty() ) { tmppath[tmpcnt++] = s.top() ; s.pop() ; }
    if( tmpcost < bestcost ) {
        bestcnt = tmpcnt ;
        bestcost = tmpcost ;
        for( int i = 0 ; i < tmpcnt ; ++i ) bestpath[i] = tmppath[i] ;
        return ;
    }
    if( cnt > bestcnt ) return ;
    else if( cnt < bestcnt ) {
        bestcnt = tmpcnt ;
        for( int i = 0 ; i < tmpcnt ; ++i ) bestpath[i] = tmppath[i] ;
    } else {
        for( int i = 0 ; i < tmpcnt ; ++i ) {
            if( bestpath[i] > tmppath[i] ) {
                for( int j = i ; j < bestcnt ; ++j ) {
                    bestpath[j] = tmppath[j] ;
                }
            } else if ( bestpath[i] < tmppath[i] ) {
                break ;
            }
        }
    }
}
int dis[N] ;
void dij() {
    memset( dis , 0x3f , sizeof dis );
    priority_queue<node>que;
    tot = 0 ; xx[tot] = 0 , pre[tot] = -1 ; tot++ ;
    que.push( node(0,0,0,tot-1) );
    dis[0] = 0 ;
    while( !que.empty() ) {
        int u = que.top().a , cnt = que.top().c , cost = que.top().d , id = que.top().id ;
        que.pop();
        if( cost > dis[u] ) continue ;
        if( u == 1 ) {
            if( dis[u] ) {
                tmpcost = dis[u] ;
                Choose_best( id , cnt );
            }
            return ;
        }
        for( int i = 0 ; i < g[u].size() ; ++i ) {
            int v = g[u][i].X , w = ww[g[u][i].Y] ;
            if( dis[v] > dis[u] + w ) {
                dis[v] = dis[u] + w ;
                xx[tot] = v ; pre[tot] = id ; tot++;
                que.push( node( v , cnt+1 , dis[v] , tot - 1 ) ) ;
            }
        }
    }
}
void Gao() {
    dij();
    for( int i = 0 ; i < n ; ++i ) {
        int cc = ww[i] ; ww[i] = 0 ;
        dij();
        for( int j = i + 1 ; j < n ; ++j ) {
            int dd = ww[j] ; ww[j] = 0 ;
            dij(); ww[j] = dd ;
        }
        ww[i] = cc ;
    }
    for( int i = 0 ; i < bestcnt ; ++i ) cout << bestpath[i] << ' ' ;
    cout << bestcost << endl ;
}
int Run() {
    while( cin >> n && n ) {
        bestcost = bestcnt = inf ;
        for( int i = 0 ; i < N ; ++i ) g[i].clear();
        for( int i = 0 ; i < n ; ++i ) {
            int u , v , w ; cin >> u >> v >> w ;
            ww[i] = w ;
            g[u].push_back(pii(v,i));
            g[v].push_back(pii(u,i));
        }
        Gao();
    }
    return 0 ;
}
int main() {
    ios::sync_with_stdio(0);
    return Run();
}
