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
#define ls ( o << 1 )
#define rs ( o << 1 | 1 )
#define lson ls , l , m
#define rson rs , m + 1 , r
#define rt o , l , r
#define root 1 , 1 , n
#define mid ( ( l + r ) >> 1 )
const int MAXN = 100005 ;
const int MAXE = 100005 ;
const int mod = 2333333 ;
struct Edge {
    LL v ;
    int n ;
    Edge () {}
    Edge ( LL v , int n ) : v ( v ) , n ( n ) {}
} ;
int mo[19] = { 2333333 , 2196720 , 580608 , 165888 , 55296 , 18432 , 6144 , 2048 , 1024 , 512 , 256 , 128 , 64 , 32 , 16 , 8 , 4 , 2 , 1 } ;
Edge E[MAXE] ;
int H[MAXN] , cntE ;
int sum[MAXN << 2] ;
int len[MAXN << 2] ;
LL add[MAXN << 2] ;
int n , m ;
void clear () {
    cntE = 0 ;
    clr ( H , -1 ) ;
}
void addedge ( int u , LL v ) {
    E[cntE] = Edge ( v , H[u] ) ;
    H[u] = cntE ++ ;
}
int pow ( int a , int b , int mod ) {
    int res = 1 ;
    while ( b ) {
        if ( b & 1 ) res = ( LL ) res * a % mod ;
        a = ( LL ) a * a % mod ;
        b >>= 1 ;
    }
    return res % mod ;
}
void pushdown ( int o ) {
    if ( add[o] ) {
        add[ls] += add[o] ;
        add[rs] += add[o] ;
        sum[ls] = ( sum[ls] + add[o] % mod * len[ls] ) % mod ;
        sum[rs] = ( sum[rs] + add[o] % mod * len[rs] ) % mod ;
        add[o] = 0 ;
    }
}
void build ( int o , int l , int r ) {
    add[o] = 0 ;
    len[o] = r - l + 1 ;
    if ( l == r ) {
        scanf ( "%d" , &sum[o] ) ;
        addedge ( l , sum[o] ) ;
        sum[o] %= mod ;
        return ;
    }
    int m = mid ;
    build ( lson ) ;
    build ( rson ) ;
    sum[o] = ( sum[ls] + sum[rs] ) % mod ;
}
void update ( int L , int R , int v , int o , int l , int r ) {
    if ( L <= l && r <= R ) {
        add[o] += v ;
        sum[o] = ( sum[o] + ( LL ) len[o] * v ) % mod ;
        return ;
    }
    int m = mid ;
    pushdown ( o ) ;
    if ( L <= m ) update ( L , R , v , lson ) ;
    if ( m <  R ) update ( L , R , v , rson ) ;
    sum[o] = ( sum[ls] + sum[rs] ) % mod ;
}
int calc ( int i , int x ) {
    if ( x == 19 ) return 0 ;
    LL tmp = E[i].n == -1 ? E[i].v : pow ( 2 , calc ( E[i].n , x + 1 ) , mo[x] ) + E[i].v ;
    return tmp < mo[x] ? tmp : tmp % mo[x] + mo[x] ;
}
void modify ( int x , int o , int l , int r ) {
    if ( l == r ) {
        E[H[l]].v += add[o] ;
        add[o] = 0 ;
        addedge ( l , 0 ) ;
        sum[o] = calc ( H[l] , 0 ) % mod ;
        return ;
    }
    int m = mid ;
    pushdown ( o ) ;
    if ( x <= m ) modify ( x , lson ) ;
    else modify ( x , rson ) ;
    sum[o] = ( sum[ls] + sum[rs] ) % mod ;
}
int query ( int L , int R , int o , int l , int r ) {
    if ( L <= l && r <= R ) return sum[o] ;
    int m = mid ;
    pushdown ( o ) ;
    if ( R <= m ) return query ( L , R , lson ) ;
    if ( m <  L ) return query ( L , R , rson ) ;
    return ( query ( L , R , lson ) + query ( L , R , rson ) ) % mod ;
}
void solve () {
    int op , l , r , x ;
    clear () ;
    build ( root ) ;
    while ( m -- ) {
        scanf ( "%d" , &op ) ;
        if ( op == 1 ) {
            scanf ( "%d%d" , &l , &r ) ;
            printf ( "%d\n" , query ( l , r , root ) ) ;
        } else if ( op == 2 ) {
            scanf ( "%d" , &x ) ;
            modify ( x , root ) ;
        } else {
            scanf ( "%d%d%d" , &l , &r , &x ) ;
            update ( l , r , x , root ) ;
        }
    }
}
int main () {
    while ( ~scanf ( "%d%d" , &n , &m ) ) solve () ;
    return 0 ;
}
