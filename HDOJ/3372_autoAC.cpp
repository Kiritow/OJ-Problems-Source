#include<iostream>
#include<cmath>
#include<complex>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#define MAXN 20
using namespace std;
typedef complex<double> point;
const double eps = 1e-8;
const double pi = acos( -1.0 );
double operator^( point p1, point p2 ){ return imag( conj( p1 ) * p2 ); }
int dblcmp( double x ){ return ( x < -eps ? -1 : x > eps ); }
bool com( point p1, point p2 )
{
    return dblcmp( p1.real( ) - p2.real( ) ) < 0 ||
        dblcmp( p1.real( ) - p2.real( ) ) == 0 && dblcmp( p1.imag( ) - p2.imag( ) ) < 0;
}
point p[MAXN],np[MAXN],out[MAXN];
int N,Ns;
int num1[MAXN],num2[MAXN];
int compute( int n, int q )
{
    int j,i=0,k=0;
    for( j=0; j<n; j++ )
    {
        if( q & 1 ) num1[i++] = j;
        else num2[k++] = j; 
        q >>= 1;
    }
    return i;   //杩烘ュ涓
}
void convex_hull( int n )
{
    int i,k;
    if( n<=2 )
    {
        for( i=0; i<n; i++ )
            np[i] = p[i];
        Ns = n;
        return ;
    }
    sort( p, p+n, com );
    Ns = 0;
    for( i=0; i<n; i++ )
    {
        while( Ns >= 2 && dblcmp( np[Ns-1] - np[Ns-2] ^ p[i] - np[Ns-1] ) <= 0 )
           Ns--;            
        np[Ns++] = p[i];
    }
    k = Ns;
    for( i = n-2; i >= 0; i-- )
    {
        while( Ns > k && dblcmp( np[Ns-1] - np[Ns-2] ^ p[i] - np[Ns-2] ) <= 0 )
            Ns--;
        np[Ns++] = p[i];
    }
    Ns--;
}
double disptoseg( point p0, point l1, point l2 )
{
    point t = p0;
    t.real( l1.imag( ) - l2.imag( ) );
    t.imag( l2.real( ) - l1.real( ) );
    if( dblcmp( ( l1 - p0 ^ t - p0 ) * ( l2 - p0 ^ t - p0 ) ) > 0 )
        return abs( p0 - l1 ) < abs( p0 - l2 ) ? abs( p0 - l1 ) : abs( p0 - l2 ); 
    return fabs( p0 - l1 ^ p0 - l2 ) / abs( l1 - l2 );
}
bool point_in_polygon( const point &p0, const double &area2 )
{
    int i;
    double area1 = 0.0;
    if( Ns == 2 )
        return dblcmp( real( conj( np[0] - p0 ) * ( p0 - np[1] ) ) ) >= 0 ;
    for( i = 0; i < Ns; i++ )
    {
        area1 += fabs( np[i] - p0 ^ np[i+1] - p0 );
    }
    if( area1 - fabs( area2 ) > eps ) return false;
    return true;
}
bool touch( int n, const double &d )
{
    int i,j;
    double len;
    for( i = 0; i < n; i++ )
    {
        for( j = 0; j < Ns; j++ )
        {
            len = disptoseg( out[i], np[j], np[j+1] );
            if( len - d < eps )return true;
        }
    }
    return false;
}
int main( )
{ 
    point pp[MAXN];
    double d,r,L,carea,maxarea,area,len,x,y,C;
    int i,j,max,n,t,k,q;
   scanf("%d",&t);
    while( t-- )
    {
       scanf("%d%lf%lf",&n,&d,&L);
        for( i=0; i<n; i++ )
        {
           scanf("%lf%lf",&x,&y);
           pp[i].real( x );
          pp[i].imag( y );
            p[i] = pp[i];
        }
        r = d / 2.0;
        C = pi * d;
       carea = pi * r * r ;
       convex_hull( n );
        len = 0.0;
       np[Ns] = np[0];
        for( j = 0; j < Ns; j++ )
            len += abs( np[j] - np[j+1] );
       if( L - ( len + C ) > -eps )
       {
            area = 0.0; 
            for( j = 0; j < Ns; j++ )
                area += np[j] ^ np[j+1];
            area = fabs( area ) / 2.0 + len * r - ( n - 1 ) * carea;
            if( area > 0 ) maxarea = area;
        }
        else 
        {
            max = ( 1 << n );
            maxarea = 0.0;
            for( i = max-1; i > 0; i-- )
            {
                k = compute( n, i );
                q = n - k;
                for( j = 0; j < k; j++ )
                    p[j] = pp[ num1[j] ];
                for( j = 0; j < q; j++ )  
                    out[j] = pp[ num2[j] ];
                convex_hull( k );
                len = 0.0;
                np[Ns] = np[0];
                for( j = 0; j < Ns; j++ )
                    len += abs( np[j] - np[j+1] );
                if( L - ( len + C ) > -eps )
                {
                    area = 0.0; 
                    for( j = 0; j < Ns; j++ )
                        area += np[j] ^ np[j+1];
                    k = 0;
                    for( j = 0; j < n; j++ )
                        if( point_in_polygon( pp[j], area ) )
                            k++;
                    area = fabs( area ) / 2.0 + len * r - ( k - 1 ) * carea;
                    if( area > maxarea && !touch( q, d ) ) maxarea = area;
                }
            }
        }
        printf("%.3lf\n",maxarea);
    }
    return 0;
}
