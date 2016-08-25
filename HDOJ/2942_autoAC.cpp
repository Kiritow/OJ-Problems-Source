#include<stdio.h>
int main()
{
    int i,n,t,a[102];
    while(scanf("%d",&n),n)
    {
         for(i=0;i<n;i++)
         scanf("%d",&a[i]);
          t=a[0]+a[n-1];
         if(n%2!=0)
             printf("No\n");
         else
         {
             for(i=1;i<n/2;i++)
                 if(a[i]+a[n-i-1]!=t)
                     break;
                 if(i==n/2)
                     printf("Yes\n");
                 else
                     printf("No\n");
         }
    }
    return 0;
}
