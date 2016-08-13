#include<stdio.h>
int main()
{
    int n,a;
    while(~scanf("%d",&n))
    {
        a=n/2;
        n-=a;
        printf("%d\n",a*(a-1)/2+n*(n-1)/2);
    }
    return 0;
}
