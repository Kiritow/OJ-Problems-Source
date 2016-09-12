#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define clr( a , x ) memset ( a , x , sizeof a )
const int MAXN = 50005 ;
const int INF = 0x3f3f3f3f ;
struct Node {
    int sum , lsum , rsum ;
    int lnum , rnum ;
    int lf , rf ;
    int ls , rs ;
    int l , r , len ;
    int add ;
    void init ( int _l , int _r ) {
        add = sum = lnum = rnum = lf = rf = ls = rs = 0 ;
        l = _l ;
        r = _r ;
        lsum = rsum = len = r - l + 1 ;
    }
} ;
Node T[MAXN * 60] ;
int root , cur ;
int n , m ;
void check ( int& o , int l , int r ) {
    if ( o ) return ;
    o = ++ cur ;
    T[o].init ( l , r ) ;
    if ( l == 1 ) T[o].lf = INF ;
    if ( r == n ) T[o].rf = INF ;
}
void pushup ( int o ) {
    int m = ( T[o].l + T[o].r ) >> 1 ;
    check ( T[o].ls , T[o].l , m ) ;
    check ( T[o].rs , m + 1 , T[o].r ) ;
    int ls = T[o].ls , rs = T[o].rs ;
    T[o].sum = T[ls].sum + T[rs].sum ;
    T[o].lnum = T[ls].lnum ;
    T[o].rnum = T[rs].rnum ;
    T[o].lsum = T[ls].lsum ;
    T[o].rsum = T[rs].rsum ;
    T[o].lf = T[ls].lf ;
    T[o].rf = T[rs].rf ;
    if ( T[ls].rnum == T[rs].lnum ) {
        if ( T[ls].rf < T[ls].rnum && T[rs].lf < T[rs].lnum ) {
            T[o].sum += T[ls].rsum + T[rs].lsum ;
        }
        if ( T[ls].rsum == T[ls].len ) {
            T[o].lf = T[rs].lf ;
            T[o].lsum += T[rs].lsum ;
        }
        if ( T[rs].lsum == T[rs].len ) {
            T[o].rf = T[ls].rf ;
            T[o].rsum += T[ls].rsum ;
        }
    } else {
        if ( T[ls].lsum == T[ls].len ) {
            T[o].lf = T[rs].lnum ;
        }
        if ( T[ls].rnum > T[ls].rf && T[ls].rnum > T[rs].lnum ) {
            T[o].sum += T[ls].rsum ;
        }
        if ( T[rs].rsum == T[rs].len ) {
            T[o].rf = T[ls].rnum ;
        }
        if ( T[rs].lnum > T[rs].lf && T[rs].lnum > T[ls].rnum ) {
            T[o].sum += T[rs].lsum ;
        }
    }
}
void upd ( int o , int addv ) {
    T[o].add += addv ;
    T[o].lnum += addv ;
    T[o].rnum += addv ;
    T[o].lf += addv ;
    T[o].rf += addv ;
}
void pushdown ( int o ) {
    int m = ( T[o].l + T[o].r ) >> 1 ;
    if ( T[o].add ) {
        check ( T[o].ls , T[o].l , m ) ;
        check ( T[o].rs , m + 1 , T[o].r ) ;
        upd ( T[o].ls , T[o].add ) ;
        upd ( T[o].rs , T[o].add ) ;
        T[o].add = 0 ;
    }
}
void update ( int L , int R , int v , int& o , int l , int r ) {
    check ( o , l , r ) ;
    if ( L <= l && r <= R ) {
        upd ( o , v ) ;
        return ;
    }
    pushdown ( o ) ;
    int m = ( l + r ) >> 1 ;
    if ( L <= m ) update ( L , R , v , T[o].ls , l , m ) ;
    if ( m <  R ) update ( L , R , v , T[o].rs , m + 1 , r ) ;
    pushup ( o ) ;
}
void show ( int o , int l , int r ) {
    if ( o == 0 ) {
        for ( int i = l ; i <= r ; ++ i ) {
            printf ( "%d " , 0 ) ;
        }
        return ;
    } else if ( !T[o].ls && !T[o].rs ) {
        for ( int i = l ; i <= r ; ++ i ) {
            printf ( "%d " , T[o].lnum ) ;
        }
        return ;
    }
    pushdown ( o ) ;
    int m = ( l + r ) >> 1 ;
    show ( T[o].ls , l , m ) ;
    show ( T[o].rs , m + 1 , r ) ;
    pushup ( o ) ;
}
void solve () {
    int l , r , v ;
    root = cur = 0 ;
    int ans = 0 ;
    for ( int i = 0 ; i < m ; ++ i ) {
        scanf ( "%d%d%d" , &l , &r , &v ) ;
        l ^= ans ;
        r ^= ans ;
        v ^= ans ;
        if ( l > r ) swap ( l , r ) ;
        update ( l , r , v , root , 1 , n ) ;
        ans = T[1].sum ;
        printf ( "%d\n" , T[1].sum ) ;
    }
}
int main () {
    while ( ~scanf ( "%d%d%*d" , &n , &m ) ) solve () ;
    return 0 ;
}
