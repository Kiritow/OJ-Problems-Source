#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <complex>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef __int64 ll;
bool solve( ll a, ll b, ll c, int k )
{
    if( k == 0 )
    {
        return true;
    }
    if( a % 2 == 0 )
    {
        if( b % 2 == 0 )
        {
            if( c % 2 == 0 ) 
            {
                return solve( a / 2, b / 2, c / 2, k - 1 );
            }
            else             
            {
                return false;
            }
        }
        else
        {
            if( c % 2 == 0 ) 
            {
                return solve( 2 * a, b, c / 2, k - 1 );
            }
            else             
            {
                return solve( 4 * a, 4 * a + 2 * b, a + b + c, k -1 );
            }
        }
    }
    else 
    {
        if( b % 2 == 0 )
        {
            if( c % 2 == 0 ) 
            {
                return solve( 2 * a, b, c / 2, k - 1 );
            }
            else           
            {
                return solve( 4 * a, 4 * a + 2 * b, a + b + c, k - 1 );
            }
        }
        else 
        {
            if( c % 2 == 0 ) 
            {
                return solve( 2 * a, b, c / 2, k - 1 ) ||
                       solve( 4 * a, 4 * a + 2 * b, a + b + c, k - 1 );
            }
            else             
            {
                return false;
            }
        }
    }
}
int main()
{
    int n;
    ll a, b, c;
    scanf("%d",&n);
    while( n-- )
    {
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        if( solve( a, b, c, 32 ) )printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
