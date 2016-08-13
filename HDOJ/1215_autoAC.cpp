#include<stdio.h>
int main()
{
    int n,i,a,j,sum,c;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            sum=0;
            scanf("%d",&a);
            c=a;
            for(j=2;j<c;j++)
                if(a%j==0)
                {
                    sum+=j;
                    if(j!=a/j)
                    {
                        sum+=a/j;
                        c=a/j;
                    }
                }
                sum++;
            printf("%d\n",sum);
        }
    }
}
