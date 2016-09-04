#include <iostream>
using namespace std;
const __int64 Mod=100000007;
__int64 mod_exp(__int64 a,__int64 b0,__int64 n=Mod)
{
if( a > n ) 
   a %= n;
__int64 i, d = 1, b[35];
for( i=0; i < 35; ++i )
{
   b[i] = b0%2;
   b0 /= 2;
   if( b0 == 0 ) 
    break;
}
for( ;i >= 0; --i )
{
   d = (d*d)%n;
   if( b[i] == 1 )
    d = (d*a)%n;
}
return d;
}
__int64 solve (__int64 n,__int64 m)
{
__int64 ans=1;
for (__int64 i=m*n+2-n;i<m*n+1;i++)
{
   ans=((((ans*i)%Mod)*mod_exp(i-m*n+n-1,Mod-2)))%Mod;
}
ans=(ans*mod_exp(n,Mod-2))%Mod;
return ans;
}
int main ()
{
__int64 n,m;
while (scanf ("%I64d%I64d",&n,&m)!=EOF)
{
   printf ("%I64d\n",solve(n,m));
}
return 0;
}
