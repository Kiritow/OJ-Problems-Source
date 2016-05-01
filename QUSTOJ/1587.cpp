#include <stdio.h>
int main()
{
    int inc;
    int p1,p5,p10,p20,p50;
    p1=0;
    p5=0;
    p10=0;
    p20=0;
    p50=0;
    while(scanf("%d",&inc)==1&&inc!=0)
    {
        switch(inc)
        {
        case 1:
            p1++;break;
        case 5:
            p5++;break;
        case 10:
            p10++;break;
        case 20:
            p20++;break;
        case 50:
            p50++;break;
        default:
            return -1;
        }
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n",p1+5*p5+10*p10+20*p20+50*p50,p1,5*p5,10*p10,20*p20,50*p50);
    return 0;
}
