#include<stdio.h>
int main()
{
    int n,x2,t,i;
    while(~scanf("%d",&n))
    {
        t=1;
        x2=n/2;
        t+=x2;
        for(i=0;i<=x2;i++)
            t+=(n-i*2)/3;
        printf("%d\n",t);
    }
        return 0;
}
