#include<stdio.h>
int main ()
{
   int t ,a ,b ,c ,Ans ,x ,y;
   scanf("%d" ,&t);
   while(t--)
   {
      scanf("%d %d %d" ,&a ,&b ,&c);
      x = 1 ,Ans = 0;
      while(1)
      {
         if(x * a >= c) break;
         if((c - x * a) % b == 0) Ans ++;
         x ++;
      }
      printf("%d\n" ,Ans);
   }
   return 0;
}
