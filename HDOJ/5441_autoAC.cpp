#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 20007
using namespace std;
int fa[MAX],num[MAX],t,n,m,q,pp[MAX];
struct Query
{
    int x,id;
    bool operator < ( const Query& a )const 
    {
        return x < a.x;
    }
}a[MAX];
struct Edge
{
    int u,v,w;
    bool operator < ( const Edge& a ) const 
    {
        return w < a.w;
    }
}e[MAX*5];
void init ( )
{
    for ( int i = 1 ; i <= n ; i++ )
    {
        num[i] = 1;
        fa[i] = i;
    }
}
int _find ( int x )
{
    return fa[x] == x? x : fa[x] = _find ( fa[x] );
}
void _union ( int x , int y )
{
    x = _find ( x );
    y = _find ( y );
    if ( y < x ) swap ( x , y );
    fa[y] = x;
    num[x] += num[y];
}
int main ( )
{
    scanf ( "%d" ,&t );
    while ( t-- )
    {
        int ans = 0;
        scanf ( "%d%d%d" , &n , &m , &q );
        init ( ); 
        for ( int i = 0 ; i < m ; i++ )
            scanf ( "%d%d%d" , &e[i].u , &e[i].v , &e[i].w );
        sort ( e , e+m );
        int j = 0;
        for ( int i = 0 ; i < q ; i++ )
        {
            a[i].id = i;
            scanf ( "%d" , &a[i].x );
        }
        sort ( a , a+q );
        for ( int i = 0 ; i < q ; i++ )
        {
            while ( j < m && e[j].w <= a[i].x )
            {
                int u = _find ( e[j].u );
                int v = _find ( e[j].v );
                j++;
                if ( u == v ) continue;
                ans += (num[u]+num[v])*(num[u]+num[v]-1)-num[u]*(num[u]-1) - num[v]*(num[v]-1);
                _union ( u , v );
            }
            pp[a[i].id] = ans;
        }
        for ( int i = 0 ; i < q ; i++ )
            printf ( "%d\n" , pp[i] );
    }
}
