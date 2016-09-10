#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 1007
using namespace std;
int n;
int num;
int sum;
int gcd ( int a , int b )
{
    return b==0?a:gcd ( b , a%b );
}
int main ( )
{
    while ( ~scanf ( "%d" , &n ) )
    {
        sum = 0;
        for ( int i = 0 ; i < n ; i ++ )
        {
            bool flag = true;
            scanf  ( "%d" , &num );
            for ( int i = 2 ; i < num ; i ++ )
                if ( gcd ( num , i ) > 1 )
                {
                    flag = false;
                    break;
                }
            if ( flag ) sum+=num;
        }
        printf ( "%d\n" , sum );
    }
}
