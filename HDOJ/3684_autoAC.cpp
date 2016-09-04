#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
typedef struct pnode
{
    double x,y,d;
    pnode( double a, double b ) {x = a;y = b;}
    pnode(){};
}point;
point P[ 105 ][ 1005 ];
point P0,Pn;
int   Q[ 105 ];
int   top[ 105 ];
typedef struct lnode
{
    double x,y,dx,dy,d;
    int    id,hit,sign;
    lnode( point a, point b ) {x = a.x;y = a.y;dx = b.x-a.x;dy = b.y-a.y;}
    lnode(){};
}line;
line L[ 10005 ];
typedef struct knode
{
    int   size;
    line  l[ 1005 ];
    point a[ 1005 ];
    point b[ 1005 ];
}slope;
slope S[ 105 ];
double dist( point a, point b )
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dist( point a, line l )
{
    return fabs(l.dx*(a.y-l.y)-l.dy*(a.x-l.x))/sqrt(l.dx*l.dx+l.dy*l.dy);
}
double crossproduct( point a, point b, point c )
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
double parameter( line l, point a )
{
    if ( l.dx ) return (a.x-l.x)/l.dx*l.sign;
    else return (a.y-l.y)/l.dy*l.sign;
}
bool l_cross_l( line a, line b )
{
    double t1 = b.dx*(a.y-b.y)-b.dy*(a.x-b.x);
    double t2 = b.dx*(a.y+a.dy-b.y)-b.dy*(a.x+a.dx-b.x);
    return t1*t2 <= 0;
} 
point crosspoint( line l, point a, point b )
{
    line m = line( a, b );
    if ( m.dx*l.dy == m.dy*l.dx ) {
        if ( dist( point( l.x, l.y ), a ) < dist( point( l.x, l.y ), b ) )
            return a;
        else return b;
    }else {
        double a1 = -l.dy,b1 = l.dx,c1 = l.dx*l.y-l.dy*l.x;
        double a2 = -m.dy,b2 = m.dx,c2 = m.dx*m.y-m.dy*m.x;
        double x = (c1*b2-c2*b1)/(a1*b2-a2*b1);
        double y = (c1*a2-c2*a1)/(b1*a2-b2*a1);
        return point( x, y );
    } 
}
double angle( line a, line b )
{
    return (a.dx*b.dx+a.dy*b.dy)/sqrt(a.dx*a.dx+a.dy*a.dy)/sqrt(b.dx*b.dx+b.dy*b.dy);
}
bool cmp1( point a, point b )
{
    if ( a.x == b.x ) return a.y < b.y;
    else return a.x < b.x;
}
bool cmp2( point a, point b )
{
    double cp = crossproduct( P0, a, b );
    if ( cp == 0 ) return a.d < b.d;
    else return cp > 0;
}
bool cmp3( line a, line b )
{
    return a.dy*b.dx < b.dy*a.dx;
}
bool cmp4( line a, line b )
{
    return a.id < b.id;
}
void Graham( int N, int M )
{
    point  *p,q; 
    double  d1,d2,a1,a2;
    for ( int i = 0 ; i < N ; ++ i ) {
        p = &P[i][0];
        sort( p+0, p+Q[i], cmp1 );
        P0 = p[0];
        for ( int j = 1 ; j < Q[i] ; ++ j )
            p[j].d = dist( P0, p[j] );
        sort( p+1, p+Q[i], cmp2 );
        if ( Q[i] > 2 ) {
            int top = 2;
            for ( int j = 3 ; j < Q[i] ; ++ j ) {
                while ( top > 0 && crossproduct( p[top-1], p[top], p[j] ) <= 0 ) -- top;
                p[++ top] = p[j];
            }
            p[++ top] = p[0];
            int now = 1;
            for ( int j = 2 ; j <= top ; ++ j ) 
                if ( crossproduct( p[now-1], p[now], p[j] ) == 0 ) p[now] = p[j];
                else p[++ now] = p[j];
            Q[i] = now;
        }
        int L1 = 0,L2 = 0;
        if ( Q[i] > 1 ) L2 = 1;
        for ( int j = 1 ; j < Q[i] ; ++ j )
            if ( p[j].x > p[(j+1)%Q[i]].x ) {
                L2 = j;break;
            }
        int Ln = L2;
        line lt = line( point(0,0), point(0,-1) );
        S[i].size = -1;
        while ( p[L1].x <= p[(L1+1)%Q[i]].x || p[L2].x >= p[(L2+1)%Q[i]].x ) {            
            a1 = angle( lt, line( p[L1], p[(L1+1)%Q[i]] ) );
            a2 = angle( lt, line( p[(L2+1)%Q[i]], p[L2] ) );
            S[i].size ++;
            S[i].a[S[i].size] = p[L1];
            S[i].b[S[i].size] = p[L2];
            if ( a1 > a2 && p[L1].x <= p[(L1+1)%Q[i]].x ) {
                lt = line( p[L1], p[(L1+1)%Q[i]] );
                L1 = (L1+1)%Q[i];
            }else {
                lt = line( p[(L2+1)%Q[i]], p[L2] );
                L2 = (L2+1)%Q[i];
            }
            S[i].l[S[i].size] = lt;
        }
        S[i].size ++;
        S[i].a[S[i].size] = p[0];
        S[i].b[S[i].size] = p[Ln];
        S[i].l[S[i].size] = line( point(0,0), point(0,1) );
    }
    int now[101];
    for ( int i = 0 ; i < N ; ++ i ) 
        now[i] = 0;
    sort( L, L+M , cmp3 );
    for ( int i = 0 ; i < M ; ++ i ) {
        L[i].hit = -1;
        for ( int j = 0 ; j < N ; ++ j ) {
            while ( cmp3( S[j].l[now[j]], L[i] ) ) ++ now[j];
            if ( l_cross_l( line( S[j].a[now[j]], S[j].b[now[j]] ), L[i] ) ) {
                q  = crosspoint( L[i], S[j].a[now[j]], S[j].b[now[j]] );
                d2 = dist( q, point( L[i].x, L[i].y ) );
                if ( parameter( L[i], q ) < 0 ) continue;
                if ( L[i].hit == -1 ) {
                    L[i].hit = j;
                    L[i].d = d2;
                }else if ( L[i].d > d2 ) {
                    L[i].hit = j;
                    L[i].d = d2;
                }
            }
        }
    }
    sort( L, L+M, cmp4 );
    for ( int i = 0 ; i < M ; ++ i ) 
        if ( L[i].hit != -1 )
            printf("HIT %d\n",L[i].hit);
        else printf("MISS\n");
}
int main()
{
    int T,N,M;
    while ( scanf("%d",&T) != EOF ) 
    while ( T -- ) {
        scanf("%d",&N);
        for ( int i = 0 ; i < N ; ++ i ) {
            scanf("%d",&Q[i]);
            for ( int j = 0 ; j < Q[i] ; ++ j )
                scanf("%lf%lf",&P[i][j].x,&P[i][j].y);
        }
        scanf("%d",&M);
        for ( int i = 0 ; i < M ; ++ i ) {
            scanf("%lf%lf%lf%lf",&L[i].x,&L[i].y,&L[i].dx,&L[i].dy);
            L[i].id = i;
            if ( L[i].dx < 0 ) {
                L[i].dx *= -1;
                L[i].dy *= -1;
                L[i].sign = -1;
            }else L[i].sign = 1;
        }
        Graham( N, M );
        printf("*****\n");
    }
    return 0;
}
