#include<stdio.h>
int main ()
{
   int a,b,t,sw;
   while(~scanf("%d%d",&a,&b))
   {
       if(!a&&!b)
       break;
       t=0;
       while(1)
       {
          if(a<b)
          sw=a,a=b,b=sw;
          t++;
          if(!b||!(a%b)||a/b>=2)
          break;
          a=a%b;
       }
       if(t&1)
       printf("Stan wins\n");
       else
       printf("Ollie wins\n");
   }
   return 0;
}
