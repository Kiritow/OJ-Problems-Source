#include<iostream>
#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std ;
const int N = 100010;
const int M = 500010;
const long long K = 100000;
int n , m ;
struct node {
    int u , v ;
    long long cnt ;
    bool operator < ( const node &a ) const {
        if( u != a.u ) return u < a.u ;
        else return v < a.v ;
    }
} e[M] ;
int tot ;
int in[N] ;
const int HASH = 300007;
struct HASHMAP {
    long long key[N] , f[N] ;
    int head[HASH] , next[N] , size ;
    void init() {
        memset( head , -1 , sizeof head ) ;
        size = 0 ;
    }
    void insert( int u , int v , long long ans ) {
        long long KEY = K * u + v ;
        int c = KEY % HASH ;
        f[size] = ans ;
        key[size] = KEY ;
        next[size] = head[c] ;
        head[c] = size++;
    }
    long long find( int u , int v ) {
        long long KEY = K * u + v ;
        int c = KEY % HASH ;
        for( int i = head[c] ; ~i ; i = next[i] ) {
            if( key[i] == KEY ) return f[i] ;
        }
        return -1 ;
    }
} mp ;
long long find( int u , int v ) {
    int l = 0 , r = m - 1 ;
    if( l > r ) return -1 ;
    if( u > e[r].u || ( u == e[r].u && v > e[r].v ) ) return -1 ;
    if( v < e[l].v || ( v == e[l].v && u < e[l].u ) ) return -1 ;
    while( l <= r ) {
        int mid = (l+r)>>1;
        if( u < e[mid].u ) {
            r = mid - 1 ;
        }
        else if( u == e[mid].u ) {
            if( v < e[mid].v ) r = mid - 1 ;
            else if( v > e[mid].v ) l = mid + 1 ;
            else return e[mid].cnt ;
        }
        else {
            l = mid + 1 ;
        }
    }
    return -1 ;
}
vector< pair<int,long long> >g[N];
void Work() {
    mp.init();
    int q ; cin >> q ;
    while( q-- ) {
        int u , v ; cin >> u >> v ;
        u-- , v-- ;
        if( u > v ) swap( u , v ) ;
        else if( u == v ) { cout << "0 1"<< endl ; continue ; }
        long long ans = find( u , v ) ;
        if( ans != -1 ) {
            cout << "1 " << ans << endl ;
        } else {
            ans = mp.find( u , v ) ;
            if( ans == -1 ) {
                ans = 0 ;
                if( in[u] > in[v] ) swap( u , v ) ;
                for( int i = 0 ; i < g[u].size() ; ++i ) {
                    int mid = g[u][i].first ;
                    long long cnt1 = g[u][i].second , cnt2 = find( min(mid,v) , max(mid,v) );
                    if( cnt2 != -1 ) ans += cnt1 * cnt2 ;
                }
                if( u > v ) swap( u , v ) ;
                mp.insert( u , v , ans ) ;
            }
            if( ans ) cout << "2 " << ans << endl ;
            else cout << "The pair of cities are not connected or too far away." << endl ;
        }
    }
}
void Gao() {
    memset( in , 0 , sizeof in );
    for( int i = 0 ; i < n ; ++i ) g[i].clear();
    cin >> n >> m ;
    if( !m ) return  ;
    for( int i = 0 ; i < m ; ++i ) {
        int x , y ; cin >> x >> y ;
        x-- , y-- ;
        if( x > y ) swap( x , y ) ;
        e[i].u = x , e[i].v = y , e[i].cnt = 1 ;
        in[x]++ , in[y]++ ;
    }
    sort( e , e + m ) ;
    tot = 1 ;
    for( int i = 1 ; i < m ; ++i ) {
        if( e[tot-1].u == e[i].u && e[tot-1].v == e[i].v ) {
            e[tot-1].cnt++ ;
        } else {
            e[tot++] = e[i] ;
        }
    }
    m = tot ;
    for( int i = 0 ; i < m ; ++i ) {
        g[e[i].u].push_back( make_pair( e[i].v,e[i].cnt) ) ;
        g[e[i].v].push_back( make_pair( e[i].u,e[i].cnt) ) ;
    }
}
int Run() {
    int _ , cas = 1 ; cin >> _ ;
    while( _-- ) {
        cout << "Case #" << cas++ << ":" << endl ;
        Gao(); Work();
    }
    return 0 ;
}
int main() {
    ios::sync_with_stdio(0);
    return Run();
}
