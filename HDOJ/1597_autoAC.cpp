#include<stdio.h>
#include<math.h>
int main()
{
    __int64 i,t,n,m;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        m=((__int64)sqrt(1+8*(n-1))-1)/2;
        n-=m*(m+1)/2;
        printf("%I64d\n",n%9!=0?n%9:9);
    }
    return 0;
}
