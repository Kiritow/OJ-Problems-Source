#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793
double square(double x)
{
    return x * x;
}
int main(void)
{
    double x1,y1,x2,y2,x3,y3;
    double a2,b2,c2;
    double r;
    while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3) != EOF)
    {
        a2 = square(x1 - x2) + square(y1 - y2);
        b2 = square(x1 - x3) + square(y1 - y3);
        c2 = square(x3 - x2) + square(y3 - y2);
        r = sqrt(c2/(1 - square(a2 + b2 - c2)/a2/b2/4))/2;
        printf("%.2f\n",2 * PI * r);
    }
}
