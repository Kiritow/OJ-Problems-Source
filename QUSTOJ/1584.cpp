#include <stdio.h>
#include <math.h>
int main()
{
   int m,i,k,pc;
   scanf("%d",&pc);
   for(;pc>0;pc--)
   {
   scanf("%d",&m);
   k=(int)sqrt(m);
   for(i=2;i<=k;i++)
      if(m%i==0)
         break;
   if(i>k)
       printf("Yes\n");
   else
       printf("No\n");
   }
   return 0;
}
