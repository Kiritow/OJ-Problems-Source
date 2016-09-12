#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std ;
typedef long long LL ;
#define clr( a , x ) memset ( a , x , sizeof a )
const int MAXN = 200005 ;
struct Palindromic_Tree {
    int nxt[MAXN][26] ;
    int fail[MAXN] ;
    int len[MAXN] ;
    int S[MAXN] , L , R ;
    int num[MAXN] ;
    int last[2] ;
    int p ;
    LL tot ;
    int newnode ( int l ) {
        for ( int i = 0 ; i < 26 ; ++ i ) nxt[p][i] = 0 ;
        num[p] = 0 ;
        len[p] = l ;
        return p ++ ;
    }
    void init ( int n ) {
        p = 0 ;
        newnode ( 0 ) ;
        newnode ( -1 ) ;
        clr ( S , -1 ) ;
        L = n ;
        R = n - 1 ;
        last[0] = last[1] = 1 ;
        fail[0] = 1 ;
        tot = 0 ;
    }
    int get_fail ( int v , bool d ) {
        if ( d ) while ( S[R - len[v] - 1] != S[R] ) v = fail[v] ;
        else while ( S[L + len[v] + 1] != S[L] ) v = fail[v] ;
        return v ;
    }
    void add ( int c , bool d ) {
        if ( d ) S[++ R] = c ;
        else S[-- L] = c ;
        int cur = get_fail ( last[d] , d ) ;
        if ( !nxt[cur][c] ) {
            int now = newnode ( len[cur] + 2 ) ;
            fail[now] = nxt[get_fail ( fail[cur] , d )][c] ;
            nxt[cur][c] = now ;
            num[now] = num[fail[now]] + 1 ;
        }
        last[d] = nxt[cur][c] ;
        if ( len[last[d]] == R - L + 1 ) last[d ^ 1] = last[d] ;
        tot += num[last[d]] ;
    }
} ;
Palindromic_ T ;
int n ;
void solve () {
    int op ;
    char c ;
    T.init ( n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        scanf ( "%d" , &op ) ;
        if ( op <= 2 ) {
            scanf ( " %c" , &c ) ;
            T.add ( c - 'a' , op - 1 ) ;
        }
        if ( op == 3 ) printf ( "%d\n" , T.p - 2 ) ;
        if ( op == 4 ) printf ( "%I64d\n" , T.tot ) ;
    }
}
int main () {
    while ( ~scanf ( "%d" , &n ) ) solve () ;
    return 0 ;
}
