#include<stdio.h>
int main()
{
    int t,n,a,b;
    while(scanf("%d",&t)!=EOF)
    {
        while(t--)
        {
            scanf("%d",&n);
            if(n>=1&&n<=30)
            {
                a=1;
                for(b=1;b<=n;b++)
                {
                    a=a*2;
                }
                a=a-1;
                printf("%d\n",a);
            }
        }
    }
    return 0;
}
