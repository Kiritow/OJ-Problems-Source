#include <stdio.h>
int main()
{
    __int64 a[21];
    int i,n;
    a[1]=0;
    a[2]=1;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=3;i<n+1;i++)
        {a[i]=(i-1)*(a[i-1]+a[i-2]);}
        printf("%I64d\n",a[n]);
    }
    return 0;
}
