#include <stdio.h>
int main()
{
     __int64 n,s;
     while(~scanf("%I64d",&n))
     {
           s=((n*(n+1)/2%10000)*(n*(n+1)/2%10000))%10000;
           printf("%04I64d\n",s);
     }
     return 0;    
}
