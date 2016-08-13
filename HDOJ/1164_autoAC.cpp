#include<stdio.h>
#include<math.h>
int main()
{
    long int x;
    int k,i;
    while(scanf("%ld",&x)!=EOF)
    {
        k=sqrt((double)x);
        for(i=2;i<=k;i++)
        {
            if(x%i==0)
            {
                x=x/i;
                printf("%d*",i);
                i=1;
                k=sqrt((double)x);
            }
        }
        printf("%d\n",x);
    }
}
