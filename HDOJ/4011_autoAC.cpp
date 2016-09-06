#include <iostream>
#include <stdio.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
const long  N=100010;
__int64 a[N],aa,minx;
int main()
{
    int n,t,b;
    int i,j,k;
      while (cin>>t)
      {
          minx=k=0;
          while (t--)
          {
              scanf("%d%I64d%d",&n,&aa,&b);
              minx=n*b+2*aa;
              scanf("%I64d",&a[0]);
              for (i=1;i<n;i++)
              {
                  scanf("%I64d",&a[i]);
                  if(a[i]-1==a[i-1]) continue;
                  minx+=min((a[i]-a[i-1]-1)*b,2*aa);
              }
              printf("Case #%d: %I64d\n",++k,minx);
          }
      }
return 0;
}
