#include<stdio.h>
int main()
{
    int m,k;
    while(scanf("%d%d",&m,&k)!=EOF&&m&&k)
    {
        int sum=0;
        while(m-k>=0)
        {
            sum+=k;
            m=m-k+1;
        }
        sum+=m;
        printf("%d\n",sum);
    }
    return 0;
}
