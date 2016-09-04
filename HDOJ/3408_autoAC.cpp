#include<iostream>
#include<cmath>
#include<complex>
#include<algorithm>
using namespace std;
typedef complex<double> point;
const int maxn = 15;
const double eps = 1e-8;
const double pi = acos( -1.0 );
struct line
{
    point a, b;
    line( ){ }
    line( point u, point v ) : a( u ), b( v ) {  }
};
struct polygon
{
    point p[maxn];
    int n;
};
int dblcmp( double x ){ return ( x < -eps ? -1 : x > eps ); }
double operator^( point p1, point p2 ){ return imag( conj( p1 ) * p2 ); }
double operator&( point p1, point p2 ){ return real( conj( p1 ) * p2 ); }
point operator*( line l0, line l1 )
{
    double t = l0.a - l1.a ^ l0.b - l1.a;
    double s = l0.b - l1.b ^ l0.a - l1.b;
    return l1.a + ( l1.b - l1.a ) * t / ( t + s );
}
polygon poly[10];
bool same_point( point p1, point p2 )
{
    return dblcmp( imag( p1 ) - imag( p2 ) ) == 0 && dblcmp( real( p1 ) - real( p2 ) ) == 0;
}
bool on_radial( point p, line l )
{
    if( dblcmp( l.a - p ^ l.b - p ) != 0 )return false;
    return dblcmp( p - l.a & l.b - l.a ) >= 0;
}
bool on_segment( point p, line l )
{
    if( dblcmp( l.a - p ^ l.b - p ) != 0 )return false;
    return dblcmp( l.a - p & l.b - p ) <= 0;
}
int main( )
{
    int i, j, n, m, sz, len;
    double x, y, dx, dy;
    point ss, kk, pp, pp1;
    point xp[200];
    line L, L0;
    while( scanf("%d",&n) && n )
    {
        scanf("%lf%lf",&x, &y);
        ss = point( x, y );
        scanf("%lf%lf",&dx, &dy);
        kk = point( dx, dy );
        L.a = ss;
        L.b = ss + kk;
        pp = ss;
        for( i = 0; i < n; i++ )
        {
            scanf("%d",&m);
            poly[i].n = m;
            for( j = 0; j < m; j++ )
            {
                scanf("%lf%lf",&x, &y);
                poly[i].p[j] = point( x, y );
            }
            poly[i].p[m] = poly[i].p[0];
        }
        sz = poly[0].n;
        for( i = 0; i < sz; i++ )
        {
            L0 = line( poly[0].p[i], poly[0].p[i+1] );
            if( dblcmp( L.b - L.a ^ L0.b - L0.a ) == 0 )
            {
                if( on_radial( L0.a, L ) )
                {
                    if( abs( L0.a - ss ) < abs( L0.b - ss ) ) pp = L0.a;
                    else pp = L0.b;
                    break;
                }
            }
            else
            {
                pp1 = L0 * L;
                if( on_radial( pp1, L ) && on_segment( pp1, L0 ) )
                {
                    if( same_point( pp , ss ) )
                        pp = pp1;
                    else if( abs( pp1 - ss ) < abs( pp - ss ) )
                        pp = pp1;
                }
            }
        }
        if( same_point( pp, ss ) )
        {
            printf("MISS\n");
            continue;
        }
        len = 0;
        for( i = 0; i < n; i++ )
        {
            sz = poly[i].n;
            for( j = 0; j < sz; j++ )
            {
                L0 = line( poly[i].p[j], poly[i].p[j+1] );
                if( dblcmp( L.b - L.a ^ L0.b - L0.a ) == 0 )
                {    
                    if( on_radial( L0.a, L ) )
                        xp[len++] = L0.a, xp[len++] = L0.b;
                }
                else
                {
                    pp1 = L0 * L;
                    if( on_segment( pp1, L0 ) )
                        xp[len++] = pp1;
                }
            }
        }
        double min = 1e10;
        for( i = 0; i < len; i++ )
            if( abs( xp[i] - ss ) < min )
                pp1 = xp[i], min = abs( xp[i] - ss );
        if( same_point( pp, pp1 ) )printf("HIT\n");
        else printf("MISS\n");
    }
    return 0;
}
