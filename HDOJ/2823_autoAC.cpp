#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 50100;
const double eps = 1e-8;
const double pi = acos( -1.0 );
const double inf = 1e100;
#define _sign(x) ((x)>eps?1:((x<-eps)?2:0))
int D( double x ) { return ( x < -eps ? -1 : x > eps ); }
struct point {
    double x, y;
    point( double _x = 0, double _y = 0 ) : x( _x ), y( _y ) { }
    void input( ) { scanf( "%lf%lf", &x, &y ); }
    bool operator < (const point a)const 
    {
        if(y==a.y)
            return x<a.x;
        return y<a.y;
    }
};
typedef struct line 
{
    point a,b;
}Line;
point operator + ( const point & a, const point & b ) {
    return point( a.x + b.x, a.y + b.y );
}
point operator - ( const point & a, const point & b ) {
    return point( a.x - b.x, a.y - b.y );
}
point operator * ( const point & a, const double scale ) {
    return point( a.x * scale, a.y * scale );
}
point operator / ( const point & a, const double scale ) {
    return point( a.x / scale, a.y / scale );
}
double operator ^ ( const point & a, const point & b ) {
    return ( a.x * b.y - a.y * b.x );
}
double operator & ( const point & a, const point & b ) {
    return ( a.x * b.x + a.y * b.y );
}
double dis2( const point & a, const point & b ) {
    point p = a - b;
    return ( p.x * p.x + p.y * p.y );
}
double dis( const point & a, const point & b ) {
    return sqrt( dis2( a, b ) );
}
double displ( const point & a, const point & b, const point & p ) {
    if( D( b - a & p - a ) > 0 && D( a - b & p - b ) > 0 ) {
        return fabs( a - p ^ b - p ) / dis( a, b );
    }
    return min( dis( p, a ), dis( p, b ) );
}
double disll( const point & a, const point &b, const point &c, const point &d ) {
    return min( min( displ( a, b, c ), displ( a, b, d ) ),
        min( displ( c, d, a ), displ( c, d, b ) ) );
}
double det(double x1,double y1,double x2,double y2)        
{ 
    return x1*y2-x2*y1;
}
double cross (const point & a, const point &b, const point &c)        
{
    return det(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
point a[maxn],np[maxn];
struct poly {
    int n;
    point p[ maxn ];
    void in( ) {
        for( int i = 0; i < n; i++ ) {
            p[ i ].x=np[i].x;
            p[i].y=np[i].y;
        }
        if( get_area( ) < 0 ) {
            reverse( p, p + n );
        }
    }
    double get_area( ) const {
        double area = 0;
        for( int i = 0; i < n; i++ ) {
            area += ( p[ i ] ^ p[ ( i + 1 ) % n ] );
        }
        return area;
    }
};
void solve( const poly & g1, const poly & g2 ) {
    int f[ 2 ] = { 0, 0 };
    point p0, p1, p2, p3;
    for( int i = 0; i < g1.n; i++ ) {
        if( g1.p[ i ].y < g1.p[ f[ 0 ] ].y ) {
            f[ 0 ] = i;
        }
    }
    for( int i = 0; i < g2.n; i++ ) {
        if( g2.p[ i ].y > g2.p[ f[ 1 ] ].y ) {
            f[ 1 ] = i;
        }
    }
    int cnt = 0;
    double best = inf;
    while( cnt < g1.n ) {
        p0 = g1.p[ f[ 0 ] ], p1 = g1.p[ ( f[ 0 ] + 1 ) % g1.n ];
        p2 = g2.p[ f[ 1 ] ], p3 = g2.p[ ( f[ 1 ] + 1 ) % g2.n ];
        int tmp = D( p1 - p0 ^ p3 - p2 );
        if( tmp == 0 ) {
            cnt++;
            f[ 0 ] = ( f[ 0 ] + 1 ) % g1.n;
            f[ 1 ] = ( f[ 1 ] + 1 ) % g2.n;
            best = min( best, disll( p0, p1, p2, p3 ) );
        }
        else if( tmp < 0 ) {
            cnt++;
            f[ 0 ] = ( f[ 0 ] + 1 ) % g1.n;
            best = min( best, displ( p0, p1, p2 ) );
        }
        else {
            f[ 1 ] = ( f[ 1 ] + 1 ) % g2.n;
            best = min( best, displ( p2, p3, p0 ) );    
        }
    }
    printf( "%.4lf\n", best );
}
int covex_hull(int n)
{ 
    int sz;
    sort(a,a+n); 
    np[0]=a[0]; 
    np[1]=a[1]; 
    sz=1; 
    for(int i=2;i<n;i++) 
    { 
        while(sz>0 && cross(np[sz],a[i],np[sz-1])<=0){
            sz--; }
        np[++sz]=a[i];
    } 
    int temp=sz; 
    for(int i=n-2;i>=0;i--) 
    { 
        while(sz>temp && cross(np[sz],a[i],np[sz-1])<=0) {
            sz--; }
        np[++sz]=a[i]; 
    }
    return sz;
}
bool pequal(const point & a,const point & b)
{
    if(D(a.x-b.x)==0&&D(a.y-b.y)==0)return 1;
    else return 0;
}
int intersect(Line a,Line b)
{
    if(D(cross(a.a,b.a,a.b)*cross(a.a,a.b,b.b))>0)return 1;
    else return 0;
} 
int dotsOnSeg(const point & p,Line l)
{
    if(pequal(l.a,l.b)){if(pequal(p,l.a))return 1 ;else return 0;}
    if(D(cross(p,l.a,l.b))==0&&(l.a.x-p.x)*(l.b.x-p.x)<=eps&&(l.a.y-p.y)*(l.b.y-p.y)<=eps)return 1;
    else return 0;
}
int intersectSegToSeg(Line a,Line b)
{
    if(dotsOnSeg(a.a,b)||dotsOnSeg(a.b,b)||dotsOnSeg(b.a,a)||dotsOnSeg(b.b,a))return 1;
    if(intersect(a,b)&&intersect(b,a))return 1;
    else return 0;
}
int inside_convex(const point &q,int n,const point *p)
{
    int i,s[3]={1,1,1};
    for(i=0;i<n&&s[1]|s[2];i++)
    {
        s[_sign(cross(p[i],p[(i+1)%n],q))]=0;
    }
    return s[1]|s[2];
}
poly g1, g2;
int convex_intersect()
{
    int flag=0;
    Line l1,l2;
    for(int i=1;i<=g1.n&&!flag;i++)
    {
        l1.a=g1.p[i-1];
        l1.b=g1.p[i%g1.n];
        for(int j=1;j<=g2.n;j++)
        {
            l2.a=g2.p[j-1];
            l2.b=g2.p[j%g2.n];
            if(intersectSegToSeg(l1,l2)){flag=1;break;}
        }
    }
    for(int i=0;i<g1.n&&g2.n>=3;i++)
    {
        if(inside_convex(g1.p[i],g2.n,g2.p)){flag=1;break;}
    }
    if(!flag)for(int i=0;i<g2.n&&g1.n>=3;i++)
    {
        if(inside_convex(g2.p[i],g1.n,g1.p)){flag=1;break;}
    }
    return flag;
}
int main( ) {
    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
        {
            a[i].input();
        }    
        g1.n=covex_hull(n);
        g1.in( );
        for(int i=0;i<m;i++)
        {
            a[i].input();
        }    
        g2.n=covex_hull(m);
        g2.in( );
        if(g1.n==1&&g2.n==1)
        {
            double ans=dis(g2.p[0],g1.p[0]);
            printf("%.4lf\n",ans);
            continue ;
        }
        if(!convex_intersect()){    
            if(g1.n==1&&g2.n>1)
            {
                double ans=inf;
                for(int i=1;i<=g2.n;i++)
                {
                    ans=min(ans,displ(g2.p[i-1],g2.p[i%g2.n],g1.p[0]));
                }
                printf("%.4lf\n",ans);
                continue ;
            }
            if(g2.n==1&&g1.n>1)
            {
                double ans=inf;
                for(int i=1;i<=g1.n;i++)
                {
                    ans=min(ans,displ(g1.p[i-1],g1.p[i%g1.n],g2.p[0]));
                }
                printf("%.4lf\n",ans);
                continue ;
            }
            if(g2.n==2&&g1.n>1)
            {
                double ans=inf;
                for(int i=1;i<=g1.n;i++)
                {
                    ans=min(ans,disll(g1.p[i-1],g1.p[i%g1.n],g2.p[0],g2.p[1]));
                }
                printf("%.4lf\n",ans);
                continue ;
            }
            if(g1.n==2&&g2.n>1)
            {
                double ans=inf;
                for(int i=1;i<=g2.n;i++)
                {
                    ans=min(ans,disll(g2.p[i-1],g2.p[i%g1.n],g1.p[0],g1.p[1]));
                }
                printf("%.4lf\n",ans);
                continue ;
            }
            solve( g1, g2 );
        }
        else printf("%.4lf\n",0);
    }
    return 0;
}
