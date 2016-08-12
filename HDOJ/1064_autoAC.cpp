#include<stdio.h>
int main()
{
    double avg,cache;
    int i;
    avg=cache=0;
    for(i=0;i<12;i++)
    {
        scanf("%lf",&cache);
        avg+=cache;
    }
    printf("$%.2lf\n",avg/12);
    return 0;
}
