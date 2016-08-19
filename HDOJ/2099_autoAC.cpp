#include<stdio.h>
int main()
{
    int i,j,k,sum,n,m,a[101];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
        break;
        k=0;sum=0;
        for(i=0;i<100;i++)
        {
            if(((n*100)+i)%m==0)
            {
                sum++;
                a[k++]=i;
            }
        }
        for(j=0;j<sum;j++)
        {
            if(j<sum-1)
            {
                if(a[j]<10)
                    printf("0%d ",a[j]);
                else
                    printf("%d ",a[j]);
            }
            else
            {
                if(a[j]<10)
                    printf("0%d",a[j]);
                else
                    printf("%d",a[j]);
            }
        }
        printf("\n");
    }
return 0;
}
