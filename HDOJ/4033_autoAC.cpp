#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
double ch[200];
const double PI = 4 * atan( double( 1 ) );
//const double PI = 3.1415926;
int num;
double is_triangle( double a, double b, double c )
{
    if( c > a + b )
        return 100;
    else if( c < fabs( a - b ) )    
        return -100;
    else
        return acos( ( a * a + b * b - c * c ) / ( 2 * a * b ) );
}
double Acos( double a, double b, double c )
{
    return is_triangle( a, b, c );
}
double total_angle( double mid )
{
    double ans = 0;
    for( int i = 2; i <= num; ++i )
    {
        double t = Acos( ch[i], ch[i-1], mid );
        if( fabs( t ) == 100 )            
            return t;        
        else
            ans += Acos( ch[i], ch[i-1], mid );
    }
    return ans;
}
double Bsearch( double ss, double ee )
{
    double left = ss, right = ee, mid, sum_angle;
    while( right - left >= 1e-9 )
    { 
        mid = ( left + right ) / 2.0;
        double t = total_angle( mid );
        if( fabs( t ) == 100 )
        {
            if( t > 0 )
                right = mid;
            else
                left = mid; 
        }
        else
        {
            sum_angle = t + Acos( ch[1] , ch[num], mid ); 
            if( sum_angle - 2 * PI > 1e-9 )
                right = mid;
            else if( sum_angle - 2 * PI < -1e-9 )
                left = mid;
            else 
                return mid;
        }
    }
    return 0;
}
int main(  )
{
    int i,j,k,T;
    cin>>T;
    for(i = 1; i <= T; ++i )
    {
        cin>>num;
        for(j = 1; j <= num; ++j )
            cin>>ch[j]; 
        double ans = Bsearch( fabs( ch[num] - ch[1] ), ch[1] + ch[num] );
        printf( "Case %d: ", i );
        if( ans == 0 )
            puts( "impossible" );
        else
            printf( "%.3lf\n", ans );
    }
    return 0;
}
