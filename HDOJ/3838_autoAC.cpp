#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define PI pair
#define MP make_pair
#define FI first
#define SE second
const double eps = 1e-8;
const double pi = acos(-1.);
using namespace std;
struct point
{
    int x, y;
    bool operator<( const point r )    const
    {
        if( x == r.x )    return y < r.y;
        return x < r.x;
    }
    point( int _x = 0, int _y = 0 ) : x(_x), y(_y){}
} A[10], B[10], C[10];
struct T
{
    point rot, tra;
} ans[40000];
int snap( double x )
{
    if( x < 0 )    return -snap(-x);
    return (int)(x+0.5);
}
void rot( double rx, double ry )
{
    double d, ang = atan2(ry, rx);
    for( int i = 0; i < 3; ++i )
    {
        d = atan2(A[i].y+0., A[i].x+0.);
        double L = sqrt(A[i].x*A[i].x + A[i].y*A[i].y + 0.);
        C[i].x = snap(L*cos(d+ang));
        C[i].y = snap(L*sin(d+ang));
    }
}
int e;
bool line;
void solve( int rx, int ry )
{
    rot(rx, ry);
    int i, j, k;
    int kx, cx, ky, cy;
    bool st;
    sort(C, C+3);
    do
    {
        st = 0;
        if( C[1].x - C[2].x )
        {
            if( B[1].x-B[2].x == 0 )    continue;
            if( (B[1].x-B[2].x)%(C[1].x-C[2].x) == 0 )
            {
                kx = (B[1].x-B[2].x)/(C[1].x-C[2].x);
                cx = B[1].x-C[1].x*kx;
            }
            else    continue;
        }
        else if( C[0].x - C[1].x )
        {
            if( B[0].x-B[1].x == 0 )    continue;
            if( (B[0].x-B[1].x)%(C[0].x-C[1].x) == 0 )
            {
                kx = (B[0].x-B[1].x)/(C[0].x-C[1].x);
                cx = B[0].x-C[0].x*kx;
            }
            else    continue;
        }
        else
        {
            if( B[0].x == B[1].x && B[0].x == B[2].x )
            {
                kx = 1, cx = B[0].x-C[0].x*kx;
                st = 1;
            }
            else    continue;
        }
        if( C[1].y - C[2].y )
        {
            if( B[1].y-B[2].y == 0 )    continue;
            if( (B[1].y-B[2].y)%(C[1].y-C[2].y) == 0 )
            {
                ky = (B[1].y-B[2].y)/(C[1].y-C[2].y);
                cy = B[1].y-C[1].y*ky;
            }
            else    continue;
        }
        else if( C[0].y - C[1].y )
        {
            if( B[0].y-B[1].y == 0 )    continue;
            if( (B[0].y-B[1].y)%(C[0].y-C[1].y) == 0 )
            {
                ky = (B[0].y-B[1].y)/(C[0].y-C[1].y);
                cy = B[0].y-C[0].y*ky;
            }
            else    continue;
        }
        else
        {
            if( B[0].y == B[1].y && B[0].y == B[2].y )
            {
                ky = 1, cy = B[0].y-C[0].y*ky;
                st = 1;
            }
            else    continue;
        }
        for( i = 0; i < 3; ++i )
        {
            if( B[i].x != C[i].x*kx + cx )    break;
            if( B[i].y != C[i].y*ky + cy )    break;
        }
        if( i != 3 )    continue;
        ans[e].rot = point(rx, ry);
        ans[e].tra = point(kx, ky);
        e++;
        if( st )    line = 1;
    } while( next_permutation(C, C+3) );
}
int main()
{
    int cases = 1;
    int i, j, k;
    double d;
    while( 1 )
    {
        for( i = 0; i < 3; ++i )
            scanf("%d %d", &A[i].x, &A[i].y);
        if( !A[0].x && !A[0].y && !A[1].x && !A[1].y && !A[2].x && !A[2].y )
            break;
        for( i = 0; i < 3; ++i )
            scanf("%d %d", &B[i].x, &B[i].y);
        e = 0;
        line = 0;
        for( i = -10; i <= 10; ++i )
        {
            solve(i, 10);    solve(i, -10);
            solve(10, i);    solve(-10, i);
        }
        for( i = 1; i < e; ++i )
        {
            if( ans[i].rot.x == ans[i-1].rot.x && ans[i].rot.y == ans[i-1].rot.y &&
                ans[i].tra.x == ans[i-1].tra.x && ans[i].tra.y == ans[i-1].tra.y )
                continue;
            if( ans[i].rot.x == -ans[i-1].rot.x && ans[i].rot.y == -ans[i-1].rot.y &&
                ans[i].tra.x == -ans[i-1].tra.x && ans[i].tra.y == -ans[i-1].tra.y )
                continue;
            break;
        }
        printf("Case %d: ", cases++);
        if( e == 0 )    puts("no solution");
        else if( line || i < e )    puts("inconsistent solutions");
        else    puts("equivalent solutions");
    }
    return 0;
}
