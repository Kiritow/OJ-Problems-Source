#include<stdio.h>
int main()
{
   int T,n,a,b,i,j,g=0;
   char _char;
   scanf("%d",&T);
   while(T--)
   {
       if(g!=0)printf("\n");
           g=1;
         getchar();
       _char=getchar();
       scanf("%d",&n);
         a=(n/6)+1 ;
         b=(n-3)/2 ;
       for(i=1;i<=n;i++)
       {
           for(j=1 ; j<=2*a+n-3-b ; j++)
           {
                   if(i==1||i==(2+b)||i==n)
                   { 
                     if(j==a-b+n-2)
                     {
                         break;
                     }
                   if(j<a+1) putchar(' ');
                   else
                       putchar(_char);
               }
               else
               {
                   if(j>a&&j<a-b+n-2)
                       putchar(' ');
                   else putchar(_char);
               }
               }
           printf("\n");
       }
   }
   return 0;
}
