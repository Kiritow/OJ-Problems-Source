#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define ll __int64
using namespace std ;
const int maxn = 211111 ;
int c[26][maxn] , tot , dis[maxn] , pos[maxn] , rk[maxn] ;
int tim[maxn] , dp[25][maxn] , cnt[maxn] , g[maxn] , line[maxn] , lon[maxn] ;
ll val[maxn] , f[25] , pow26[maxn] ;
const int mod = 1000000007 ;
struct Edge
{
    int to , next , v ;
} edge[maxn<<1] ;
int head[maxn] , E , n ;
struct Point
{
    int id ;
    int tim ;
    bool operator < ( const Point &t ) const
    {
        return tim < t.tim ;
    }
} ;
vector<Point> vec[maxn] ;
void new_edge ( int a , int b , char *s )
{
    edge[E].to = b ;
    edge[E].next = head[a] ;
    edge[E].v = s[0] - 'a' ;
    head[a] = E ++ ;
    edge[E].to = a ;
    edge[E].next = head[b] ;
    edge[E].v = s[0] - 'a' ;
    head[b] = E ++ ;
}
int new_node ()
{
    int i ;
    for ( i = 0 ; i < 26 ; i ++ ) c[i][tot] = 0 ;
    val[tot] = 0 ;
    return tot ++ ;
}
int step ;
void cal ( int u , int fa , int now )
{
    int i ;
    Point fuck ;
    for ( i = head[u] ; i != -1 ; i = edge[i].next )
    {
        int v = edge[i].to ;
        if ( v == fa ) continue ;
        dis[v] = dis[u] + 1 ;
        tim[v] = ++ step ;
        fuck.id = v , fuck.tim = step ;
        vec[dis[v]].push_back ( fuck ) ;
        int k = edge[i].v ;
        if ( !c[k][now] ) 
        {
            c[k][now] = new_node () ;
            val[c[k][now]] = ( (ll) val[now] * 26 % mod + k ) % mod ;
        }
        pos[v] = c[k][now] ;
        cal ( v , u , c[k][now] ) ;
        lon[u] = max ( lon[u] , lon[v] ) ;
        cnt[u] += cnt[v] ;
    }
    lon[u] = max ( lon[u] , dis[u] ) ;
    cnt[u] ++ ;
}
void cal1 ( int now )
{
    rk[now] = step ++ ;
    g[rk[now]] = now ;
    int i ;
    for ( i = 0 ; i < 26 ; i ++ )
        if ( c[i][now] )
            cal1 ( c[i][now] ) ;
}
int dep ;
void init ()
{
    for ( int i = 0 ; i <= n ; i ++ )
    {
        head[i] = -1 , vec[i].clear () ;
        lon[i] = dis[i] = rk[i] = cnt[i] = 0 ;
    }
    tot = E = 0 ;
    new_node () ;
}
int T ;
void rmq ()
{
    int i , j ;
    T = 0 ;
    for ( i = 1 ; i <= n ; i ++ )
    {
        int l = vec[i].size () ;
        if ( l == 0 ) break ;
        line[i] = T + 1 ;
        for ( j = 0 ; j < l ; j ++ )
            dp[0][++T] = rk[pos[vec[i][j].id]] ;
    }
    for ( i = 1 ; f[i] <= T ; i ++ )
        for ( j = 1 ; j + f[i] - 1 <= T ; j ++ )
            dp[i][j] = max ( dp[i-1][j] , dp[i-1][j+f[i-1]] ) ;
}
int query ( int l , int r )
{
    if ( l == r ) return dp[0][l] ;
    if ( l > r ) swap ( l , r ) ;
    int i , j , k ;
    for ( i = 0 ; i <= 22 ; i ++ )
        if ( f[i] >= ( r - l + 1 ) )
        {
            k = i - 1 ;
            break ;
        }
    return max ( dp[k][l] , dp[k][r-f[k]+1] ) ;
}
char s[111] ;
int main ()
{
    int cas , i , j , a , b , q ;
    f[0] = pow26[0] = 1 ;
    for ( i = 1 ; i <= 22 ; i ++ )
        f[i] = (ll) f[i-1] * 2 % mod ;
    for ( i = 1 ; i < 100005 ; i ++ )
        pow26[i] = (ll) pow26[i-1] * 26 % mod ;
    scanf ( "%d" , &cas ) ;
    while ( cas -- )
    {
        scanf ( "%d" , &n ) ;
        init () ;
        for ( i = 1 ; i < n ; i ++ )
        {
            scanf ( "%d%d%s" , &a , &b , s ) ;
            new_edge ( a , b , s ) ;
        }
        step = 0 ;
        cal ( 1 , 0 , 0 ) ;
        step = 0 ;
        cal1 ( 0 ) ;
        rmq () ;
        pos[1] = 0 ;
        scanf ( "%d" , &q ) ;
        while ( q -- )
        {
            int u , m ;
            scanf ( "%d%d" , &u , &m ) ;
            if ( m == 0 )
            {
                puts ( "0" ) ;
                continue ;
            }
            if ( dis[u] + m > lon[u] )
            {
                puts ( "IMPOSSIBLE" ) ;
                continue ;
            }
            int dep = dis[u] + m ;
            Point fuck ;
            fuck.tim = tim[u] ;
            int l = lower_bound ( vec[dep].begin () , vec[dep].end () , fuck ) - vec[dep].begin () ;
            if ( l == vec[dep].size () ) l -- ;
            l += line[dep] ;
            fuck.tim = tim[u] + cnt[u] - 1 ;
            int r = upper_bound ( vec[dep].begin () , vec[dep].end () , fuck ) - vec[dep].begin () ;
            r -- ;
            r += line[dep] ;
            int k = query ( l , r ) ;
            k = g[k] ;
            u = pos[u] ;
            printf ( "%I64d\n" , ( val[k] - val[u] * pow26[m] % mod + mod ) % mod ) ;
        }
    }
}
