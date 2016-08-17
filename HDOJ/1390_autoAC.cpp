#include<stdio.h>
int main()
{
    int N,n,i,flag1;
    __int64 flag;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=0,flag=0,flag1=0;flag<n;i++)
        {
            flag=1<<i;    
            if((n&flag)==flag&&flag1==1)
            {
                printf(" %d",i);
            }
            if((n&flag)==flag && flag1==0)
            {
                flag1=1;
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
