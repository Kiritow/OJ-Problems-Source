#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#define LL __int64
const int N = 1e9;
using namespace std;
int r, d[10005], n[40], pr[10005], qpr[10005], tq;
void Pr()
{
 int i, j;
 memset( pr, 1, sizeof(pr) );
 pr[1] = 0;
 for( i = 2; i <= 10000; i ++ )
 if( pr[i] )
 {
 j = i+i;
 while( j <= 10000 )
 {
 pr[j] = 0;
 j += i;
 }
            qpr[tq++] = i;
 }
}
int Gcd( int a, int b )
{
 if( !b )
 return a;
 else
 return Gcd( b, a%b );
}
void Op()
{
 memset( d, 0, sizeof(d) );
 int t, i, j, tt;
 for( j = 0; j < r; j ++ )
 {
 t = n[j];
 for( i = 0; i < tq && t > 1; i ++ )
 if( !( t % qpr[i] ) )
 {
 tt = 1;
                t/=qpr[i];
 while( !( t%qpr[i] ) )
 {
 tt ++;
 t/=qpr[i];
 }
                d[ qpr[i] ] = d[ qpr[i] ] > tt ? d[ qpr[i] ] : tt;
 }
 }
}
int main()
{
 int i, j, k, ti, qu[10004], top, na, mu[30];
    LL qa[30], t, ans;
 Pr();
 while( ~scanf( "%d", &r ) )
 {
 for( i = 0; i < r; i ++ )
 {
 scanf( "%d%d", n+i, &k );
 k = Gcd( n[i], k );
 n[i] /= k;
 }
 Op();
 ans = 1;
 top = 0;
 for( i = 0; i < tq; i ++ )
 if( d[ qpr[i] ] > 0)
 {
 ans *= d[ qpr[i] ]+1;
 qu[ top++ ] = qpr[i];
 }
        if( top > 0 && qu[0] == 2 )
            na = 2;
 else
            na = 1;
        printf( "%I64d\n", ans-na );
 ans = ans < 16+na ? ans : 16+na;
     qa[0] = 1;
        mu[0] = 0;
        for( k = 1; k < ans; k ++ )
        {
            t = N*(LL)N;
            for( i = 0; i < k; i ++ )
                if( mu[i] < top && qu[ mu[i] ] * qa[i] < t )
                    t = qu[ mu[i] ]*qa[i];
            qa[k] = t;
            mu[k] = -1;
            for( j = 0; j <= k; j ++ )
                if( mu[j] < 0 || ( mu[j] < top && qu[ mu[j] ] * qa[j] == qa[k] ) )
                {
                    for( i = mu[j]+1; i < top; i ++ )
                    {
                        ti = 0;
                        t = qa[j];
                        while( !( t % qu[i] ) )
                        {
                            ti ++;
                            t /= qu[i];
                        }
                        if( ti < d[ qu[i] ] )
                            break;
                    }
                    mu[j] = i;
                }
        }
        if( na < ans )
        {
            printf( "%I64d", qa[na] );
            na ++;
            for( j = 1; na < ans && j < 16; na ++, j ++ )
                printf( " %I64d", qa[na] );
            printf( "\n" );
        }            
 }
 return 0;
}
