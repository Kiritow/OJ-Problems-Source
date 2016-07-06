#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mi,mj;
    int mv=0;
    for(int i=1;i<=3;i++)
    {
        for(int j=1;j<=4;j++)
        {
            int tmp;
            scanf("%d",&tmp);
            if(tmp>mv) mi=i,mj=j,mv=tmp;
        }
    }
    return printf("%d\n%d %d\n",mv,mi,mj),0;
}
