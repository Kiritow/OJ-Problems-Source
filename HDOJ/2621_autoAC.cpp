#include<stdio.h>
#include<string.h>
 __int64 C(__int64 n, __int64 m)   
 {   
      __int64 i, j;   
      if (m > n/2) m = n - m;   
      for (i = 1, j = 1;i <= m; i++)   
      {   
      j = j * (n + 1 - i) / i;   
      }   
      return j;   
 }   
int main ()
{
  int i,j,t;
  __int64 k1,k2,k;
  __int64 m,n;
  while(scanf("%I64d%I64d",&n,&m)!=EOF&&n||m)
  {
      t=m>n?n:m;
  printf("%I64d\n",C(m+n,t));
  }
  return 1;
}
