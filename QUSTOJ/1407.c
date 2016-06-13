#include <stdio.h>
int main()
{
    long inc;
    if(scanf("%d",&inc)!=1)
    {
        return -1;
    }
    else
    {
        long i,cur;
        for(cur=2;cur<=inc;cur++)
        {
            for(i=2;i<cur;i++)
            {
                if(cur%i==0)
                {
                    break;
                }
            }
            if(i==cur)
            {
                printf("%d ",cur);
            }
        }
        printf("\n");
    }
    return 0;
}
