#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int cnt=0;
    int cash;
    scanf("%d",&cash);
    int amax=cash/5;
    int bmax=cash/2;
    int cmax=cash;
    for(int a=1;a<=amax;a++)
    {
        for(int b=1;b<=bmax;b++)
        {
            for(int c=1;c<=cmax;c++)
            {
                if(5*a+2*b+c==cash)
                {
                    cnt++;
                }
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}
