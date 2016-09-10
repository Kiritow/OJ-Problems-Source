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
const int N = 26 ;
struct Palindromic_Tree {
    int next[MAXN][N] ;
    int fail[MAXN] ;
    int len[MAXN] ;
    int num[MAXN] ;
    int S[MAXN] , n ;
    int last ;
    int p ;
    int newnode ( int l ) {
        rep ( i , 0 , N ) next[p][i] = 0 ;
        num[p] = 0 ;
        len[p] = l ;
        return p ++ ;
    }
    void init () {
        p = 0 ;
        newnode ( 0 ) ;
        newnode ( -1 ) ;
        last = 1 ;
        n = 0 ;
        S[0] = -1 ;
        fail[0] = 1 ;
    }
    int get_fail ( int v ) {
        while ( S[n - len[v] - 1] != S[n] ) v = fail[v] ;
        return v ;
    }
    int add ( int c ) {
        c -= 'a' ;
        S[++ n] = c ;
        int cur = get_fail ( last ) ;
        if ( !next[cur][c] ) {
            int now = newnode ( len[cur] + 2 ) ;
            fail[now] = next[get_fail ( fail[cur] )][c] ;
            next[cur][c] = now ;
            num[now] = num[fail[now]] + 1 ;
        }
        last = next[cur][c] ;
        return num[last] ;
    }
} ;
Palindromic_ T ;
char s[MAXN] ;
LL sum[MAXN] ;
int n ;
LL ans ;
void solve () {
    ans = 0 ;
    T.init () ;
    n = strlen ( s ) ;
    sum[n] = 0 ;
    rev ( i , n - 1 , 0 ) sum[i] = sum[i + 1] + T.add ( s[i] ) ;
    T.init () ;
    rep ( i , 0 , n ) ans += sum[i + 1] * T.add ( s[i] ) ;
    printf ( "%I64d\n" , ans ) ;
}
int main () {
    while ( ~scanf ( "%s" , s ) ) solve () ;
    return 0 ;
}
