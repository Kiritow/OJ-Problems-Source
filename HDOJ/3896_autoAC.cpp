#include <cstdio>
#include <cstring>
#include <cstdlib>
#define len1 100001
#define len2 1000001
#define min(x1,x2) ((x1)<(x2)?(x1):(x2))
#define swap(x1,x2) {int _t = x1 ; x1 = x2 ; x2 = _t;}
int dfn[len1] , low[len1] , final[len1] , hash[len1] , sm = 0 , timel = 0 , deep[len1] ;
int n , m , lim = 0 ;
int fa[20][len1] , ed[20] ;
struct edge
{
    int tot  ;
    int now[len1] , next[len2] , g[len2] ;
    void add( int st, int ed )
    {
        ++tot;
        g[tot] = ed ;
        next[tot] = now[st];
        now[st] = tot ;
    }
}e;
void dfs( int x , int ff , int dep )
{
    ++timel ;
    dfn[x] = low[x] = timel ;
    hash[x] = sm ;
    deep[x] = dep ;
    for ( int i = e.now[x] ; i ; i = e.next[i] )
    if ( e.g[i] != ff )
    {
        if ( hash[ e.g[i] ] != sm )
        {
            dfs( e.g[i] , x , dep+1 );
            low[x] = min( low[x] , low[ e.g[i] ] );
            fa[1][ e.g[i] ] = x ;
        }
        else
            low[x] = min( low[x] , dfn[ e.g[i] ] );
    }
    final[x] = ++timel ;
}
bool ini( int a , int b )
{
    if ( dfn[a] >= dfn[b] && final[a] <= final[b] )
        return true ;
    return false;
}
bool judge( int sc , int sv , int g1 , int g2 ) 
{
    int fl = 0 ;
    if ( deep[g1] < deep[g2] )
        swap(g1,g2);
    if ( ini( sc , g1 ) && ini( sv , g1 ) )
        fl = 1 ;
    else if ( !ini( sc , g1 ) && !ini( sv , g1 ) )
        fl = 1 ;
    else if ( low[g1] <= dfn[g2] )
        fl = 1 ;
    return fl ;
}
int move( int x , int step )
{
    int t = x , p = 1;
    if ( step < 0 )
        return -1 ;
    while ( step )
    {
        if ( step & 1 )
            t = fa[p][t];
        step >>= 1 ;
        ++p;
    }
    return t ;
}
int main()
{
    FILE *in , *out;
    int sc , sv , g1 , g2 , q , t , t1 , t2 ;
    int fl = 1 ;
    scanf("%d%d",&n,&m);
    ed[1] = 1 ;
    for ( int i = 2 ; ; ++i )
    {
        ed[i] = (ed[i-1]<<1);
        lim = i ;
        if ( ed[i] >= n )
            break;
    }
    for ( int i = 1 ; i <= m ; ++i )
    {
        scanf("%d%d",&sc,&sv);
        e.add( sc , sv );
        e.add( sv , sc );
    }
    ++sm  ;
    dfs( 1 , 1 , 1 );
    for ( int i = 2 ; i <= lim ; ++i )
        for ( int j = 1 ; j <= n ; ++j )
            fa[i][j] = fa[i-1][ fa[i-1][j] ];
    scanf("%d",&q);
    for ( int i = 1 ; i <= q ; ++i )
    {
        if ( i == 27 )
            i = 27 ;
        scanf("%d",&t);
        fl = 0 ;
        if ( t == 1 )
        {
            scanf("%d%d%d%d",&sc,&sv,&g1,&g2);
            fl = judge( sc , sv , g1 , g2 );
        }
        else
        {
            scanf("%d%d%d",&sc,&sv,&g1);
            if ( !ini( sc , g1 ) && !ini( sv , g1 ) )
                fl = 1 ;
            else if ( ini( sc , g1 )^ini( sv , g1 ) )
            {
                if ( ini( sc , g1 ) )
                {
                    t = move( sc , deep[sc] - deep[g1] - 1 );
                    if ( low[t] < dfn[g1] )
                        fl = 1 ;
                }
                else
                {
                    t = move( sv , deep[sv] - deep[g1] - 1 );
                    if ( low[t] < dfn[g1] )
                        fl = 1 ;
                }
            }
            else
            {
                t1 = move( sc , deep[sc] - deep[g1] - 1 );
                t2 = move( sv , deep[sv] - deep[g1] - 1 );
                if ( t1 == t2 )
                    fl = 1 ;
                else
                {
                    if ( low[t1] < dfn[g1] && low[t2] < dfn[g1] )
                        fl = 1;
                }
            }
        }
        if ( fl )
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
