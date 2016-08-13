#include<stdio.h>
#include<string.h>
int a[505];
int main()
{
    int n,sum,i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=n,sum=0;i>=1;i--)
        {
            sum=sum+(1+i)*i/2;
        }
        for(i=n-1;i>=0;i=i-2)
        {
            sum=sum+(1+i)*i/2;
        }
        printf("%d\n",sum);
    }
    return 0;
}
