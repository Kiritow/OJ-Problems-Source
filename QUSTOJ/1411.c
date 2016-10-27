#include <stdio.h>
int main()
{
    long inc,i;
    if(scanf("%d",&inc)!=1)
    {
        return -1;
    }
    for(i=2;i<inc;i++)
    {
        if(inc%i==0)
        {
            printf("0\n");
            return 0;
        }
    }
    printf("1\n");
    return 0;
}
/**************************************************************
    Problem: 1411
    User: 1508080112
    Language: C
    Result: 正确
    Time:0 ms
    Memory:748 kb
****************************************************************/
