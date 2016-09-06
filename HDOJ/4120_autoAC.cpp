#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define LL __int64
const int N = 10005;
using namespace std;
int a[N], n, k, s, t;
int Ans()
{
    int i;
    for( i = 1; i <= k; i ++ )
        if( a[i] < 0 )
            return 0;
    for( i = 1; i < k; i ++ )
    {
        a[i] -= a[i+1];
        if( a[i] )
        {
            n --;
            t -= a[i] * i;
        }
    }
    s = a[k];
    a[k] = 0;
    for( i = 1; i < k; i ++ )
        if( a[i] < 0 )
            return 0;
    if( n < 0 || s < n)
        return 0;
    if( n == 0 )
    {
        if( t == 0 && s == 0 )
            return 1;
        else
            return 0;
    }
    if( n == 1 )
    {
        if( t%s == 0 && t/s >= k )
        {
            a[t/s] = s;
            return 1;
        }
        else
            return 0;
    }
    int ans(0), j, tt, mm = ( n*n-n ) / 2;
    for( i = k; i*s <= t-mm; i ++ )
    {
        tt = t-mm - i*s;
        if( tt == 0 )
        {
            for( j = 1; j < n; j ++ )
                a[k+j] = 1;
            a[k] = s-n+1;
            ans ++;
        }
        else if( tt > 1 && n > 2 )
            return 2;
        else if( tt > 1 && n == 2 )
        {
            tt += mm;
            for( j = 1; j < s; j ++ )
            {
                if( j > tt )
                    break;
                else if( ans > 1 )
                    return 2;
                if( tt%j == 0 )
                {
                    a[ tt/j + i ] = j;
                    a[i] = s-j;
                    ans ++;
                }
            }
        }
        else if( s > n )
            return 2;
        else
        {
            for( j = 1; j < n-1; j ++ )
                a[k+j] = 1;
            a[k+n] = 1;
            a[k] = s-n+1;
            ans ++;
        }
        if( ans > 1 )
            return 2;
    }
    return ans;
}
int main()
{
    int ca, cs, i, pre, now;
    scanf( "%d", &ca );
    for( cs = 1; cs <= ca; cs ++ )
    {
        memset( a, 0, sizeof(a) );
        scanf( "%d%d", &n, &k );
        scanf( "%d", &t );
        pre = t;
        for( i = 1; i <= k; i ++ )
        {
            scanf( "%d", &now );
            a[i] = pre - now;
            pre = now;
        }
        printf( "Case #%d:\n", cs );
        now = Ans();
        if( now < 1 )
            printf( "No Solution\n" );
        else if( now > 1 )
            printf( "Multiple Solutions\n" );
        else
        {
            printf( "Unique Solution\n" );
            for( i = 1; i < N; i ++ )
                if( a[i] )
                    printf( "%d %d\n", i, a[i] );
        }
    }
    return 0;
}
