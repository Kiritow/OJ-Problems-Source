#include<stdio.h>
int main()
{
    int n,m,i,j;
    while(scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)
            break;
        for(j=1;;j++)
        {
            if((n+m*n)%60==0)
            {
                printf("%d\n",j);
                break;
            }
            n=(n+m*n)%60;
            if(j>=1000)
            {
                printf("Impossible\n");
                break;
            }
        }   
    }
    return 0;
}
