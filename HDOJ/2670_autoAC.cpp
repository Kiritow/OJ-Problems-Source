#include <cstdio>
#include <cstring>
#include <algorithm>
#define max(a,b) ( a>b ? a:b )
using namespace std; 
struct ha
{
    int a, b;
} s[1111];
int haha ( ha a, ha b )
{
    return a.b > b.b;
}
int main ()
{
    int i, j, k;
    int n, m, v;
    int dp[1111];
    while ( ~scanf ("%d %d", &n, &m) )
    {
        memset ( dp, 0, sizeof (dp));
        for ( i=0 ; i<n ; i++ )
            scanf ("%d", &s[i].a);
        for ( i=0 ; i<n ; i++ )
            scanf ("%d", &s[i].b);
        sort (s, s+n, haha);
        for ( i=0 ; i<n ; i++ )
            for ( j=m ; j>0 ; j-- )
                dp[j] = max (dp[j], dp[j-1]+s[i].a-(j-1)*s[i].b);
        printf ("%d\n" ,dp[m]);
    }
}
