#include <stdio.h>
int main()
{
    int i,t,k,a,b,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        k=1;
        for(i=0;i<n;i++)
            k*=(b-i);
        printf("%d\n",a*k);
    }
    return 0;
}
