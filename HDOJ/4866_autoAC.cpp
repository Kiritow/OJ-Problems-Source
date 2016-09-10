#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std ;
#define REP( i , n ) for ( int i = 0 ; i < n ; ++ i )
#define REV( i , n ) for ( int i = n - 1 ; i >= 0 ; -- i )
#define FOR( i , a , b ) for ( int i = a ; i <= b ; ++ i )
#define FOV( i , a , b ) for ( int i = a ; i >= b ; -- i )
#define REPF( i , a , b ) for ( int i = a ; i < b ; ++ i )
#define REPV( i , a , b ) for ( int i = a - 1 ; i >= b ; -- i )
#define CLR( a , x ) memset ( a , x , sizeof a )
#define mid() ( ( l + r ) >> 1 )
typedef long long LL ;
const int MAXN = 100005 ;
const int MAXE = 200005 ;
struct Edge {
    int h , c , n ;
    Edge () {}
    Edge ( int h , int c , int n ) :
        h ( h ) , c ( c ) , n ( n ) {}
} ;
struct Seg_Tree {
    int Ls , Rs ;
    int c ;
    LL val ;
} ;
Edge E[MAXE] ;
int H[MAXN] , cntE ;
Seg_ T[MAXN * 38] ;
int idx ;
int a[MAXN] , cnt ;
int Root[MAXN] ;
int N , M , X , P ;
LL Pre ;
int unique ( int a[] , int n ) {
    int cnt = 1 ;
    sort ( a + 1 , a + n + 1 ) ;
    FOR ( i , 2 , n )
        if ( a[i] != a[cnt] )
            a[++ cnt] = a[i] ;
    return cnt ;
}
int lower_bound ( int key ) {
    int l = 1 , r = cnt + 1 ;
    while ( l < r ) {
        int m = mid () ;
        if ( a[m] >= key )
            r = m ;
        else
            l = m + 1 ;
    }
    return l ;
}
int newnode () {
    return ++ idx ;
}
void build ( int &o , int l , int r ) {
    o = newnode () ;
    T[o].c = 0 ;
    T[o].val = 0 ;
    if ( l == r )
        return ;
    int m = mid () ;
    build ( T[o].Ls , l , m ) ;
    build ( T[o].Rs , m + 1 , r ) ;
}
int insert ( int old , int pos , int val , int c ) {
    int root = newnode () ;
    int now = root ;
    int l = 1 , r = cnt ;
    T[now].c = T[old].c + c ;
    T[now].val = T[old].val + val ;
    while ( l < r ) {
        int m = mid () ;
        if ( pos <= m ) {
            T[now].Ls = newnode () ;
            T[now].Rs = T[old].Rs ;
            now = T[now].Ls ;
            old = T[old].Ls ;
            r = m ;
        }
        else {
            T[now].Ls = T[old].Ls ;
            T[now].Rs = newnode () ;
            now = T[now].Rs ;
            old = T[old].Rs ;
            l = m + 1 ;
        }
        T[now].c = T[old].c + c ;
        T[now].val = T[old].val + val ;
    }
    return root ;
}
LL query ( int now , int kth ) {
    LL ans = 0 ;
    int l = 1 , r = cnt ;
    while ( l < r ) {
        int m = mid () ;
        if ( kth <= T[T[now].Ls].c ) {
            now = T[now].Ls ;
            r = m ;
        }
        else {
            ans += T[T[now].Ls].val ;
            kth -= T[T[now].Ls].c ;
            now = T[now].Rs ;
            l = m + 1 ;
        }
    }
    if ( T[now].c && kth )
        ans += T[now].val / T[now].c * kth ;
    return ans ;
}
void init () {
    cntE = 0 ;
    CLR ( H , -1 ) ;
}
void addedge ( int x , int h , int c ) {
    E[cntE] = Edge ( h , c , H[x] ) ;
    H[x] = cntE ++ ;
}
void solve () {
    int l , r , h ;
    init () ;
    idx = 0 ;
    cnt = 0 ;
    Pre = 1 ;
    FOR ( i , 1 , N ) {
        scanf ( "%d%d%d" , &l , &r , &h ) ;
        addedge ( l , h , 1 ) ;
        addedge ( r + 1 , h , -1 ) ;
        a[++ cnt] = h ;
    }
    cnt = unique ( a , cnt ) ;
    build ( Root[0] , 1 , cnt ) ;
    FOR ( x , 1 , X ) {
        if ( ~H[x] ) {
            int flag = 0 ;
            for ( int i = H[x] ; ~i ; i = E[i].n ) {
                h = E[i].h ;
                if ( !flag ) {
                    Root[x] = insert ( Root[x - 1] , lower_bound ( h ) , E[i].c * h , E[i].c ) ;
                    flag = 1 ;
                }
                else
                    Root[x] = insert ( Root[x] , lower_bound ( h ) , E[i].c * h , E[i].c ) ;
            }
        }
        else {
            Root[x] = newnode () ;
            T[Root[x]] = T[Root[x - 1]] ;
        }
    }
    int pos , a , b , c ;
    REP ( i , M ) {
        scanf ( "%d%d%d%d" , &pos , &a , &b , &c ) ;
        int kth = ( a * Pre + b ) % c ;
        LL score = query ( Root[pos] , kth ) ;
        if ( Pre > P )
            score <<= 1 ;
        printf ( "%I64d\n" , score ) ;
        Pre = score ;
    }
}    
int main () {
    while ( ~scanf ( "%d%d%d%d" , &N , &M , &X , &P ) )
        solve () ;
    return 0 ;
}
