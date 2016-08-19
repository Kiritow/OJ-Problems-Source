#include<stdio.h>
int con(int n,int m)
{
    __int64 a=1,b=1,i;
    for(i=1;i<=m;i++,n--)
    {
        b*=i;a*=n;
    }
    return a/b;
}
int main()
{
    int i,n;
    __int64 t,a[13];
    a[0]=1;a[1]=0;a[2]=1;a[3]=2;
    for(i=4;i<=12;i++)
        a[i]=(i-1)*(a[i-1]+a[i-2]);
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        t=0;
    for(i=0;i<=n/2;i++)
        t+=a[i]*con(n,i);
    printf("%I64d\n",t);
    }
}
