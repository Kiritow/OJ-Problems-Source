#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#pragma comment (linker,"/STACK:102400000,102400000") 
#define REP( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define FOR( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define REV( i , a , b ) for ( int i = a ; i >= b ; -- i )
#define CLR( a , x ) memset ( a , x , sizeof a )
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define mid() ( ( l + r ) >> 1 )
#define root 1 , 1 , n
typedef long long LL ;
const int MAXN = 100005 ;
const int mod = 1e9 + 7 ;
struct Node {
    Node *c[2] , *f ;
    int size[2] ;
    int idx ;
    LL v ;
    Node () : v ( 0 ) {}
} ;
struct Seg_Tree {
    Node node[MAXN] , *cur , *null ;
    int product[MAXN << 2] ;
    int val[MAXN] ;
    int n , m ;
    int cnt ;
    void dfs ( Node* o ) {
        if ( o -> c[0] != null ) dfs ( o -> c[0] ) ;
        o -> idx = ++ cnt ;
        o -> size[0] = o -> idx ;
        if ( o -> c[0] != null ) {
            o -> v += o -> c[0] -> v ;
            o -> size[0] = o -> c[0] -> size[0] ;
        }
        o -> size[1] = o -> idx ;
        if ( o -> c[1] != null ) dfs ( o -> c[1] ) ;
        if ( o -> c[1] != null ) {
            o -> v += o -> c[1] -> v ;
            o -> size[1] = o -> c[1] -> size[1] ;
        }
        val[o -> idx] = o -> v % mod ;
    }
    void update ( int pos , int v , int o , int l , int r ) {
        if ( l == r ) {
            product[o] = v ;
            return ;
        }
        int m = mid () ;
        if ( pos <= m ) update ( pos , v , lson ) ;
        else         update ( pos , v , rson ) ;
        product[o] = ( LL ) product[ls] * product[rs] % mod ;
    }
    int query ( int L , int R , int o , int l , int r ) {
        if ( L <= l && r <= R ) return product[o] ;
        int m = mid () ;
        if ( R <= m ) return query ( L , R , lson ) ;
        if ( m <  L ) return query ( L , R , rson ) ;
        return ( LL ) query ( L , R , lson ) * query ( L , R , rson ) % mod ;
    }
    void build ( int o , int l , int r ) {
        if ( l == r ) {
            product[o] = val[l] ;
            return ;
        }
        int m = mid () ;
        build ( lson ) ;
        build ( rson ) ;
        product[o] = ( LL ) product[ls] * product[rs] % mod ;
    }
    void init () {
        cnt = 0 ;
        null = node ;
        cur = node + 1 ;
    }
    void rotate ( Node* o , int d ) {
        Node* c = o -> c[d ^ 1] ;
        Node* p = o -> f ;
        o -> v -= ( c -> v ) - ( c -> c[d] -> v ) ;
        c -> v += ( o -> v ) - ( c -> c[d] -> v ) ;
        o -> c[d ^ 1] = c -> c[d] ;
        c -> c[d] -> f = o ;
        c -> f = p ;
        if ( p != null ) {
            if ( o == p -> c[0] ) p -> c[0] = c ;
            else p -> c[1] = c ;
        }
        c -> c[d] = o ;
        o -> f = c ;
    }
    void solve () {
        int d , x ;
        int w , l , r ;
        init () ;
        scanf ( "%d%d" , &n , &m ) ;
        cur -> f = null ;
        FOR ( i , 1 , n ) {
            scanf ( "%d%d%d" , &w , &l , &r ) ;
            cur -> v = w ;
            cur -> c[0] = node + l ;
            cur -> c[1] = node + r ;
            if ( l ) cur -> c[0] -> f = node + i ;
            if ( r ) cur -> c[1] -> f = node + i ;
            ++ cur ;
        }
        dfs ( node + 1 ) ;
        build ( root ) ;
        while ( m -- ) {
            scanf ( "%d%d" , &d , &x ) ;
            Node* o = node + x ;
            if ( d < 2 ) {
                Node* c = o -> c[d] ;
                if ( c == null ) continue ;
                c -> size[d ^ 1] = o -> size[d ^ 1] ;
                if ( c -> c[d ^ 1] != null ) o -> size[d] = c -> c[d ^ 1] -> size[d] ;
                else o -> size[d] = o -> idx ;
                rotate ( o , d ^ 1 ) ;
                update ( o -> idx , o -> v % mod , root ) ;
                update ( c -> idx , c -> v % mod , root ) ;
            } else {
                printf ( "%d\n" , query ( o -> size[0] , o -> size[1] , root ) ) ;
            }
        }
    }
} T ;
int main () {
    int t , cas = 0 ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        printf ( "Case #%d:\n" , ++ cas ) ;
        T.solve () ;
    }
    return 0 ;
}
