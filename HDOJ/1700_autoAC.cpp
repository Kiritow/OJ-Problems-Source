#include<stdio.h>
#include<math.h>
int main()
{
    double x1,x2,x3,y1,y2,y3,a,b,c,r;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf",&x1,&y1);
        r=sqrt(x1*x1+y1*y1);
        a=1;
        b=y1;
        c=r*r/4-x1*x1;
        y2=(-b-sqrt(b*b-4*a*c))/(2*a);
        y3=(-b+sqrt(b*b-4*a*c))/(2*a);
        if(fabs(x1-0)<1e-7)
        {
            x2=-sqrt(r*r-y2*y2);
            x3=sqrt(r*r-y3*y3);
        }
        else
        {
            x2=(-r*r/2-y1*y2)/x1;
            x3=(-r*r/2-y1*y3)/x1;
        }
        printf("%.3lf %.3lf %.3lf %.3lf\n",x2,y2,x3,y3);
    }
    return 0;
}
