#include<stdio.h>
int main()
{
      int n,a,b,c,d,sum;    
    scanf("%d",&n);
    while(n--)
    {
         scanf("%d%d",&a,&b);
         c=a%100;
         d=b%100;
         sum=((c+d)%100);
         printf("%d\n",sum);
    }
}
