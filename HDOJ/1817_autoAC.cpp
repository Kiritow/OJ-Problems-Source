#include <iostream>
using namespace std;
int gcd(int a,int b)
{
  return b==0?a:gcd(b,a%b);
}
__int64 pow(int a,int b)
{
   __int64 s=1;
  for(int i=0;i<b;i++)
     s*=a;
    return s;
}
int main()
{
  int n,i;
   __int64 ans;
  while(cin>>n)
   {
     ans=0;
    if(n>=40)continue;
    if(n<0)break;
    if(n==0){   printf("0\n");continue; }
    for(i=1;i<=n;i++)
       ans+=pow(3,gcd(n,i));
    if(n%2)
     {
       ans+=( pow(3,(n+1)/2)   *n);
     }   
      else 
     {
       ans+=( pow(3,n/2+1) * n/2);
       ans+=( pow(3,n/2)   *n/2 );
     }
     ans/=(2*n);
     printf("%I64d\n",ans);
   }
  return 0;
}
