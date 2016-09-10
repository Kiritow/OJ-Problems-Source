#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const double pi=acos(-1.0);
const double g=9.8;
double v,h;
double ans(double a)
{
    double a1=v*v*sin(a)*sin(a);
    double a2=2*g*h;
    a1=a1+a2;
    a1=sqrt(a1);
    a1=a1/g;
    a1=a1+v*sin(a)/g;
    a1=a1*v*cos(a);
    return a1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%lf%lf",&h,&v);
        double l=0;
        double r=pi/2;
        while (r-l>=0.0000001)
        {
            double m=(l+r)/2;
            double mm=(m+r)/2;
            if (ans(m)<ans(mm))
                l=m;
            else
                r=mm;
        }
        printf("%.2f\n",ans(l));
    }
}
