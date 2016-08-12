#include<stdio.h>
#include<algorithm>
using std::sort;
int cmp( int a, int b )
{
    if( a < b ) return true;
    return false;
}
int main()
{
    int t[1005], k[1005], n, i, j, c;
    while( scanf( "%d", &n ), n )
    {
        c = 0;
        for( i = 0; i < n; i ++ )
        scanf( "%d", &t[i] );
        sort( t, t+n, cmp );
        for( i = 0; i < n; i ++ )
        scanf( "%d", &k[i] );
        sort( k, k + n, cmp );
         i= j = 0;
         int flag1= n-1, flag2 = n-1;
        while( i <= flag1 )
        {
            if( t[flag1] > k[flag2] )
            {
                ++c;
                --flag1;
                --flag2;
            }
            else if( t[flag1] == k[flag2] )
            {
                if( t[i]>k[j] )
                {
                    ++c;
                    ++i;
                    ++j;
                }
                else if( t[i] == k[j] )
                {
                    if( t[i] < k[flag2] ) --c; 
                    ++i;
                    --flag2;
                }
                else if( t[i] < k[j] )
                {
                    --c;
                    ++i;
                    --flag2;
                }
            }
            else
            {
                --c;
                ++i;
                --flag2;
            }
        } 
        printf( "%d\n", c*200 );
    }
}
