#include<stdio.h>
int main()
{
    double i;
    double a,r,b;
    while(scanf("%lf%lf%lf",&a,&r,&b)!=EOF)
    {
        for(i=1;;i++)
        {
            a=a+a*r*(1.0/100);
            if(a>=b) break;
        }
        printf("%.0lf\n",i);
    }
    return 0;
}
