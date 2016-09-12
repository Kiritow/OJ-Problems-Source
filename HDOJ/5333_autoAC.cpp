#pragma comment(linker, "/STACK:1024000000")
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define clr( a , x ) memset ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define root 1 , 1 , n
#define mid ( ( l + r ) >> 1 )
const int MAXN = 100005 ;
const int MAXE = 200005 ;
const int INF = 0x3f3f3f3f ;
struct Edge {
    int v , idx , n ;
    Edge () {}
    Edge ( int v , int idx , int n ) : v ( v ) , idx ( idx ) , n ( n ) {}
} ;
struct Node* null ;
struct Node {
    Node* c[2] ;
    Node* f ;
    bool flip ;
    int minv , val ;
    int eidx , idx ;
    void newnode ( int v , int i ) {
        c[0] = c[1] = f = null ;
        minv = val = v ;
        eidx = idx = i ;
        flip = 0 ;
    }
    void rev () {
        if ( this == null ) return ;
        swap ( c[0] , c[1] ) ;
        flip ^= 1 ;
    }
    void up () {
        if ( this == null ) return ;
        if ( val <= c[0]->minv && val <= c[1]->minv ) {
            minv = val ;
            eidx = idx ;
        } else if ( c[0]->minv <= c[1]->minv && c[0]->minv <= val ) {
            minv = c[0]->minv ;
            eidx = c[0]->eidx ;
        } else {
            minv = c[1]->minv ;
            eidx = c[1]->eidx ;
        }
    }
    void down () {
        if ( this == null ) return ;
        if ( flip ) {
            c[0]->rev () ;
            c[1]->rev () ;
            flip = 0 ;
        }
    }
    bool is_root () {
        return f == null || f->c[0] != this && f->c[1] != this ;
    }
    void sign_down () {
        if ( !is_root () ) f->sign_down () ;
        down () ;
    }
    void setc ( Node* o , int d ) {
        c[d] = o ;
        o->f = this ;
    }
    void rot ( int d ) {
        Node* p = f ;
        Node* g = f->f ;
        p->setc ( c[d] , !d ) ;
        if ( !p->is_root () ) g->setc ( this , f == g->c[1] ) ;
        else f = g ;
        setc ( p , d ) ;
        p->up () ;
    }
    void splay () {
        sign_down () ;
        while ( !is_root () ) {
            if ( f->is_root () ) rot ( this == f->c[0] ) ;
            else {
                if ( f == f->f->c[0] ) {
                    if ( this == f->c[0] ) f->rot ( 1 ) , rot ( 1 ) ;
                    else rot ( 0 ) , rot ( 1 ) ;
                } else {
                    if ( this == f->c[1] ) f->rot ( 0 ) , rot ( 0 ) ;
                    else rot ( 1 ) , rot ( 0 ) ;
                }
            }
        }
        up () ;
    }
    void access () {
        Node* o = this ;
        for ( Node* x = null ; o != null ; x = o , o = o->f ) {
            o->splay () ;
            o->setc ( x , 1 ) ;
            o->up () ;
        }
        splay () ;
    }
    void make_root () {
        access () ;
        rev () ;
    }
    void link ( Node* o ) {
        make_root () ;
        f = o ;
    }
    void cut () {
        access () ;
        c[0] = c[0]->f = null ;
        up () ;
    }
    void cut ( Node* o ) {
        make_root () ;
        o->cut () ;
    }
    int get_min ( Node* o ) {
        make_root () ;
        o->access () ;
        return o->eidx ;
    } 
} ;
Node pool[MAXN + MAXE] ;
Node* cur ;
Node* node[MAXN] ;
Node* edge[MAXE] ;
Edge E[MAXE + MAXN] ;
int H[MAXN] , Q[MAXN] , cntE ;
int U[MAXE] , V[MAXE] ;
int ans[MAXN] ;
int p[MAXN] ;
int c[MAXN] ;
int n , m , q ;
int find ( int x ) {
    return p[x] == x ? x : ( p[x] = find ( p[x] ) ) ;
}
void init ( int n ) {
    cntE = 0 ;
    cur = pool ;
    cur->newnode ( INF , -1 ) ;
    null = cur ++ ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        p[i] = i ;
        H[i] = -1 ;
        Q[i] = -1 ;
        c[i] = 0 ;
        cur->newnode ( INF , -1 ) ;
        node[i] = cur ++ ;
    }
}
void addedge ( int u , int v , int idx , int H[] ) {
    E[cntE] = Edge ( v , idx , H[u] ) ;
    H[u] = cntE ++ ;
}
void add ( int x , int v ) {
    for ( ; x <= n ; x += x & -x ) c[x] += v ;
}
int sum ( int x , int ans = 0 ) {
    for ( ; x > 0 ; x -= x & -x ) ans += c[x] ;
    return ans ;
}
void scanf ( int& x , char c = 0 ) {
    while ( ( c = getchar () ) < '0' ) ;
    x = c - '0' ;
    while ( ( c = getchar () ) >= '0' ) x = x * 10 + c - '0' ;
}
void solve () {
    int cnt = 0 ;
    int u , v ;
    init ( n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) add ( i , -1 ) ;
    for ( int i = 0 ; i < m ; ++ i ) {
        scanf ( "%d%d" , &u , &v ) ;
        if ( u == v ) continue ;
        if ( u < v ) swap ( u , v ) ;
        addedge ( u , v , i , H ) ;
        U[i] = u ;
        V[i] = v ;
        cur->newnode ( v , i ) ;
        edge[i] = cur ++ ;
    }
    for ( int i = 0 ; i < q ; ++ i ) {
        scanf ( "%d%d" , &u , &v ) ;
        addedge ( v , u , i , Q ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ++ cnt ;
        for ( int j = H[i] ; ~j ; j = E[j].n ) {
            int v = E[j].v , idx = E[j].idx ;
            if ( v == i ) continue ;
            int x = find ( i ) ;
            int y = find ( v ) ;
            if ( x != y ) {
                -- cnt ;
                p[x] = y ;
                edge[idx]->link ( node[i] ) ;
                edge[idx]->link ( node[v] ) ;
                add ( v , 1 ) ;
            } else {
                int eidx = node[i]->get_min ( node[v] ) ;
                if ( V[eidx] >= v ) continue ;
                edge[eidx]->cut ( node[U[eidx]] ) ;
                edge[eidx]->cut ( node[V[eidx]] ) ;
                add ( V[eidx] , -1 ) ;
                edge[idx]->link ( node[i] ) ;
                edge[idx]->link ( node[v] ) ;
                add ( v , 1 ) ;
            }
        }
        for ( int j = Q[i] ; ~j ; j = E[j].n ) {
            int v = E[j].v , idx = E[j].idx ;
            ans[idx] = cnt + sum ( v - 1 ) + n - i + v - 1 ;
        }
    }
    for ( int i = 0 ; i < q ; ++ i ) {
        printf ( "%d\n" , ans[i] ) ;
    }
}
int main () {
    while ( ~scanf ( "%d%d%d" , &n , &m , &q ) ) solve () ;
    return 0 ;
}
