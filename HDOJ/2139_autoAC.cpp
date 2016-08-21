#include<stdio.h>
__int64 a[2500];
int main()
{
    __int64 sum,i,n;
    a[1]=1;
    for(i=3;i<=2500;i+=2)
    {
        a[i]+=a[i-2]+i*i;
    } 
    while(scanf("%I64d",&n)!=EOF)
    {
        printf("%I64d\n",a[n]);
    }
return 0;
}
