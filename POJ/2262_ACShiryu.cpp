#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
bool isprime ( int k )
{
    int t = sqrt ( k + 0.5 ) ;
    for ( int i = 2  ; i <= t ; i ++ )
        if ( k % i == 0 )
            return false ;
    return true ;
}
int main()
{
    int n ;
    while ( scanf ("%d", &n) , n )
    {
        int i ;
        int t = n / 2 ;
        for ( i = 3 ; i <= t ; i += 2 )
            if ( isprime ( i ) && isprime ( n - i ) )
                break ;
        printf ( "%d = %d + %d\n" , n , i , n - i ) ;
    }
    return 0;
}
