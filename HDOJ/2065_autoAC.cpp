#include<stdio.h>
int main()
{
    int i,j,a[50]={1},t,w,s,p,q;
    _int64 n;
    for(i=1;i<50;i++)
    {
        a[i]=a[i-1]*2%100;
        for(j=0;j<i&&a[i]!=a[j];j++);
        if(j!=i)
        {
            t=j;
            w=i-1;
            break;
        }
    }
    q=w-t+1;
    while(scanf("%d",&s)&&s)
    {
        p=1;
        while(s--)
        {
            scanf("%I64d",&n);
            n--;
            if(n>w)
                n=(n-t)%q+t;
            printf("Case %d: %d\n",p++,(a[n]*(a[n]+1))%100);
        }
        printf("\n");
    }
    return 0;
}
