#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MOD 1000000007
#define MAX 200007
using namespace std;
typedef long long LL;
LL a[MAX];
int p,cnt1,cnt2;
int t,n,m;
int bf1 ( int i )
{
    if ( i > (n+1)/2 )
    {
        int temp = i*2-n-1;
        if ( n&1 ) return temp;
        else return temp+1;
    }
    else return i*2-1;
}
int bf2 ( int i )
{
    return n+1-i;
}
void f3 ( )
{
    p++;
}
LL ans[107];
char s[5];
int q[MAX],x;
int query ( int x , int cnt )
{
    for ( int i = cnt-1 ; i >= 0 ; i-- )
        if ( q[i] == 1 ) x = bf1(x);
        else x = bf2(x);
    return x;
}
int main ( )
{
    scanf ( "%d" , &t );
    while ( t-- )
    {
        p = cnt1 = cnt2 = 0;
        scanf ( "%d%d" , &n , &m );
        for ( int i = 1 ; i <= n ; i++ )
            a[i] = i;
        for ( int i = 1 ; i <= m ; i++ )
        {
            scanf ( "%s" , s );
            scanf ( "%d" , &x );
            if ( s[0] == 'O' )
            {
                if ( x == 3 ) f3( );
                else q[cnt1++] = x;
            }
            else 
            {
                int id = query ( x , cnt1 );
                LL tx = a[id];
                for ( int i = 0 ; i < p ; i++ )
                    tx *= tx , tx %= MOD;
                ans[cnt2++] = tx;
            }
        }
      for ( int i = 0 ; i < cnt2 ; i++ )
        printf ( "%I64d\n" , ans[i] );  
    }
}
