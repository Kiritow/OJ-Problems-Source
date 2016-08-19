#include<stdio.h>
int main()
{
    int n;
    _int64 a[35],b[35];
    int i;
    a[0]=1;
    b[0]=0;
    for(i=1;i<34;i++)
    {
        a[i]=3*a[i-1]+2*b[i-1];
        b[i]=b[i-1]+a[i-1];
    }
    while(scanf("%d",&n)!=EOF&&n!=-1)
    {
        printf("%I64d, %I64d\n",a[n],b[n]);
    }
    return 0;
}
