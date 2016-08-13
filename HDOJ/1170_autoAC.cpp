#include<stdio.h>
int main()
{
    int n,a,b;
    char c;
    scanf("%d",&n);
    while(n--)
    {
       getchar();       
       scanf("%c%d%d",&c,&a,&b);
          if(c=='+')
            printf("%d\n",a+b);
          else if(c=='-')
            printf("%d\n",a-b);
          else if(c=='*')
            printf("%d\n",a*b);
          else 
            a%b?printf("%.2lf\n",a*1.0/b):printf("%d\n",a/b);
    }
    return 0;
}
