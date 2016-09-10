#include <map>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#pragma comment(linker, "/STACK:16777216")
#define rep( i , a , b ) for ( int i = ( a ) ; i <  ( b ) ; ++ i )
#define For( i , a , b ) for ( int i = ( a ) ; i <= ( b ) ; ++ i )
#define rev( i , a , b ) for ( int i = ( a ) ; i >= ( b ) ; -- i )
#define clr( a , x ) memset ( a , x , sizeof a )
#define mid ( ( l + r ) >> 1 )
const int MAXN = 100005 ;
const int MAXE = 100005 ;
struct Node {
    Node* c[2] ;
    int sum ;
} ;
struct Edge {
    int v , n ;
    Edge () {}
    Edge ( int v , int n ) : v ( v ) , n ( n ) {}
} ;
struct Seg {
    int L , R ;
    Seg () {}
    Seg ( int L , int R ) : L ( L ) , R ( R ) {}
} ;
struct HeavyLightDecompose {
    Edge E[MAXE] ;
    int H[MAXN] , cntE ;
    int pre[MAXN] ;
    int pos[MAXN] ;
    int dep[MAXN] ;
    int siz[MAXN] ;
    int son[MAXN] ;
    int top[MAXN] ;
    int val[MAXN] ;
    int tree_ ;
    void clear () {
        tree_idx = 0 ;
        dep[1] = 0 ;
        pre[1] = 0 ;
        siz[0] = 0 ;
        cntE = 0 ;
        clr ( H , -1 ) ;
    }
    void addedge ( int u , int v ) {
        E[cntE] = Edge ( v , H[u] ) ;
        H[u] = cntE ++ ;
    }
    void dfs ( int u ) {
        siz[u] = 1 ;
        son[u] = 0 ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( v == pre[u] ) continue ;
            pre[v] = u ;
            dep[v] = dep[u] + 1 ;
            dfs ( v ) ;
            siz[u] += siz[v] ;
            if ( siz[v] > siz[son[u]] ) son[u] = v ;
        }
    }
    void rebuild ( int u , int top_ ) {
        top[u] = top_ ;
        pos[u] = ++ tree_ ;
        if ( son[u] ) rebuild ( son[u] , top_ ) ;
        for ( int i = H[u] ; ~i ; i = E[i].n ) {
            int v = E[i].v ;
            if ( v != pre[u] && v != son[u] ) {
                rebuild ( v , v ) ;
            }
        }
    }
} ;
Node pool[MAXN * 50] ;
Node* root[MAXN] ;
Node* cur ;
HeavyLightDecompose T1 , T2 ;
Seg seg[MAXN] ;
int top ;
int cnt ;
int n1 , n2 , q ;
map < int , int > mp ;
void clear () {
    T1.clear () ;
    T2.clear () ;
    mp.clear () ;
    cur = pool ;
}
void build ( Node* &now , int l , int r ) {
    now = cur ++ ;
    now->sum = 0 ;
    if ( l == r ) return ;
    int m = mid ;
    build ( now->c[0] , l , m ) ;
    build ( now->c[1] , m + 1 , r ) ;
}
void insert ( Node* &now , Node* old , int x , int v , int l , int r ) {
    now = cur ++ ;
    if ( l == r ) {
        now->sum = old->sum + v ;
        return ;
    }
    int m = mid ;
    if ( x <= m ) {
        now->c[1] = old->c[1] ;
        insert ( now->c[0] , old->c[0] , x , v , l , m ) ;
    } else {
        now->c[0] = old->c[0] ;
        insert ( now->c[1] , old->c[1] , x , v , m + 1 , r ) ;
    }
    now->sum = now->c[0]->sum + now->c[1]->sum ;
}
int query ( Node* now , Node* old , int x , int l , int r ) {
    if ( x == 0 ) return 0 ;
    int ans = 0 ;
    while ( l < r ) {
        int m = mid ;
        if ( x <= m ) {
            now = now->c[0] ;
            old = old->c[0] ;
            r = m ;
        } else {
            ans += now->c[0]->sum - old->c[0]->sum ;
            now = now->c[1] ;
            old = old->c[1] ;
            l = m + 1 ;
        }
    }
    ans += now->sum - old->sum ;
    return ans ;
}
void dfs ( int u ) {
    if ( mp.count ( T2.val[u] ) ) insert ( root[T2.pos[u]] , root[T2.pos[u] - 1] , mp[T2.val[u]] , 1 , 1 , cnt ) ;
    else root[T2.pos[u]] = root[T2.pos[u] - 1] ;
    if ( T2.son[u] ) dfs ( T2.son[u] ) ;
    for ( int i = T2.H[u] ; ~i ; i = T2.E[i].n ) {
        int v = T2.E[i].v ;
        if ( v != T2.pre[u] && v != T2.son[u] ) {
            dfs ( v ) ;
        }
    }
}
void get_seg ( int x , int y ) {
    top = 0 ;
    while ( T1.pos[T1.top[x]] != T1.pos[T1.top[y]] ) {
        if ( T1.dep[T1.top[x]] < T1.dep[T1.top[y]] ) swap ( x , y ) ;
        seg[top ++] = Seg ( T1.pos[T1.top[x]] , T1.pos[x] ) ;
        x = T1.pre[T1.top[x]] ;
    }
    if ( T1.dep[x] > T1.dep[y] ) swap ( x , y ) ;
    seg[top ++] = Seg ( T1.pos[x] , T1.pos[y] ) ;
}
int get_sum ( int x , int y ) {
    int ans = 0 ;
    while ( T2.pos[T2.top[x]] != T2.pos[T2.top[y]] ) {
        if ( T2.dep[T2.top[x]] < T2.dep[T2.top[y]] ) swap ( x , y ) ;
        rep ( i , 0 , top ) {
            int L = seg[i].L ;
            int R = seg[i].R ;
            ans -= query ( root[T2.pos[x]] , root[T2.pos[T2.top[x]] - 1] , L - 1 , 1 , cnt ) ;
            ans += query ( root[T2.pos[x]] , root[T2.pos[T2.top[x]] - 1] , R , 1 , cnt ) ;
        }
        x = T2.pre[T2.top[x]] ;
    }
    if ( T2.dep[x] > T2.dep[y] ) swap ( x , y ) ;
    rep ( i , 0 , top ) {
        int L = seg[i].L ;
        int R = seg[i].R ;
        ans -= query ( root[T2.pos[y]] , root[T2.pos[x] - 1] , L - 1 , 1 , cnt ) ;
        ans += query ( root[T2.pos[y]] , root[T2.pos[x] - 1] , R , 1 , cnt ) ;
    }
    return ans ;
}
void solve () {
    int u , v ;
    clear () ;
    cnt = n1 ;
    For ( i , 2 , n1 ) {
        scanf ( "%d" , &u ) ;
        T1.addedge ( u , i ) ;
    }
    For ( i , 1 , n1 ) scanf ( "%d" , &T1.val[i] ) ;
    scanf ( "%d" , &n2 ) ;
    For ( i , 2 , n2 ) {
        scanf ( "%d" , &u ) ;
        T2.addedge ( u , i ) ;
    }
    For ( i , 1 , n2 ) scanf ( "%d" , &T2.val[i] ) ;
    T1.dfs ( 1 ) ;
    T1.rebuild ( 1 , 1 ) ;
    For ( i , 1 , n1 ) mp[T1.val[i]] = T1.pos[i] ;
    build ( root[0] , 1 , cnt ) ;
    T2.dfs ( 1 ) ;
    T2.rebuild ( 1 , 1 ) ;
    dfs ( 1 ) ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        scanf ( "%d%d" , &u , &v ) ;
        get_seg ( u , v ) ;
        scanf ( "%d%d" , &u , &v ) ;
        int ans = get_sum ( u , v ) ;
        printf ( "%d\n" , ans ) ;
    }
}
int main () {
    while ( ~scanf ( "%d" , &n1 ) ) solve () ;
    return 0 ;
}
