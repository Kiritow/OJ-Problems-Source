#include<stdio.h>
int main()
{
    int T,q;
    double y,e,f,g;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%d%lf%lf%lf",&y,&q,&e,&f,&g);
        double sum1=y*(1+(f*(q+365))/36500);
        double sum2;
        sum2=y*(1+(e*q)/36500);
        sum2=sum2*(1+g/100);
        printf("%.1lf\n%.1lf\n",sum2,sum1);
    }
    return 0;
}
