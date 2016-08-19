# include<stdio.h>
int main()
{
    _int64 a[51]={0,1};
    int n;
    for(n=2;n<51;n++)
        a[n]=a[n-1]+a[n-2];
    while(scanf("%d",&n)&&n!=-1)
        printf("%I64d\n",a[n]);
    return 0;
}
