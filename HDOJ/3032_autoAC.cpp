#include<stdio.h>
int main ()
{
    int i,s,n,a,t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       for(s=0,i=1;i<=n;i++)
       {
          scanf("%d",&a);            
    if(a%4==0)
    s^=(a-1);
    else if(a%4==3)
    s^=(a+1);
    else
    s^=a;
       }
       if(s)
       printf("Alice\n");
       else
       printf("Bob\n");
    }
    return 0;
}
