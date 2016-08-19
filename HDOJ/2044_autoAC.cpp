#include <stdio.h>
__int64 a[100]={0};
int main()
{
    int n;
    a[1]=1,a[2]=2;
    for(int i=3;i<51;i++)
    {
        a[i]=a[i-1]+a[i-2];
    }
    scanf("%d",&n);
    while(n--)
    {
        int c,b;
        scanf("%d%d",&c,&b);
        printf("%I64d\n",a[b-c]);
    }
    return 0;
}
