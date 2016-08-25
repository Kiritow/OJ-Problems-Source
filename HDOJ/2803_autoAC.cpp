#include <stdio.h>
int main ()
{
    __int64 n,m,a[102],i,max,t;
    while(scanf("%I64d",&n)!=EOF&&n!=0)
    {
        max=0;t=0;
        for(i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
            if(a[i]>max)
            {
                max=a[i];
                t=i;
            }
        }
        m=0;
        for(i=0;i<n;i++)
        {
            m=m+a[i];
        }
        m=m-a[t]+a[t]*(2010-n);
        printf("%I64d\n",m);
    }
}
