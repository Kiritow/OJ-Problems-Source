#include<stdio.h>
#include<math.h>
int main()
{
    int n,k;
    __int64 i,j,m;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%I64d",&m);
        m=m+1;
        j=sqrt(m);
        k=0;
            for(i=2;i<=j;i++)
            {
                if(m%i==0)
                k++;
            }
        printf("%d\n",k);
    }
    return 0;
}
