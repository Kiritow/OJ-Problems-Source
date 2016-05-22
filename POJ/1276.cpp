#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

///Internet 背包
namespace PackageNet
{
using namespace std ;
#define MAX 100001
struct NODE
{
    int n ;
    int d ;
};
int dp[MAX] ;
NODE node[11] ;
int cash, n ;
void ZeroOnePack( int cost )
{
    int i ;
    for ( i = cash ; i >= cost ; i-- )
    {
        if ( dp[i] < dp[i-cost]+cost )
            dp[i] = dp[i-cost]+cost ;
    }
}
void CompletePack( int cost )
{
    int i ;
    for ( i = cost ; i <= cash ; i++ )
    {
        if ( dp[i] < dp[i-cost]+cost )
            dp[i] = dp[i-cost]+cost ;
    }
}
void MultiplePack( int cost, int count )
{
    if ( cost*count >= cash )
    {
        CompletePack( cost ) ;
    }
    else
    {
        int k = 1 ;
        while ( k < count )
        {
            ZeroOnePack( cost*k ) ;
            count -= k ;
            k *= 2 ;
        }
        ZeroOnePack( cost*count ) ;
    }
}
int main()
{
// freopen( "e:\\in.txt" , "r" , stdin ) ;
    while ( cin >> cash >> n )
    {
        int i ;
        for ( i = 1 ; i <= n ; i++ )
            cin >> node[i].n >> node[i].d ;
        memset( dp, 0, sizeof( dp ) ) ;
        for ( i = 1 ; i <= n ; i++ )
        {
            MultiplePack( node[i].d, node[i].n ) ;
        }
        cout << dp[cash] << endl ;
    }
    return 0 ;
}
}
int main()
{
    return PackageNet::main();
}
