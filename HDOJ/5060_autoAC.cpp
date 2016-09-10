#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const double pi=3.14159265358979,eps=1e-7;
double r,hr,hz;
double f(double n)
{
    return pi*(r*r-n*n);
}
double simpson(double a,double b)
{
    return (b-a)/6.0*(f(a)+4*f((a+b)/2.0)+f(b));
}
double cal(double a,double b)
{
    double sum=simpson(a,b),mid=(a+b)/2.0;
    double t=simpson(a,mid)+simpson(mid,b);
    if(fabs(t-sum)<eps) return sum;
    return cal(a,mid)+cal(mid,b);
}
int main()
{
    while(scanf("%lf%lf%lf",&r,&hr,&hz)!=EOF)
    {
        double v=0,hv=0;
        if(hr>=r&&hz>=r)
        {
            v=4.0/3.0*pi*r*r*r;
            hv=2*pi*hr*hr*hz;
            printf("%.6lf\n",v/hv);
            continue;
        }
        if(hr>=r&&hz<r)
        {
            v=4.0/3.0*pi*r*r*r;
            double t=2*cal(hz,r);
            hv=2*pi*hr*hr*hz;
            printf("%.6lf\n",(v-t)/(hv+t));
            continue;
        }
        if(r*r>=hr*hr+hz*hz)
        {
            v=4.0/3.0*pi*r*r*r;
            hv=2*pi*hr*hr*hz;
            printf("%.6lf\n",hv/v);
            continue;
        }
        if(hr<r&&hz>=r)
        {
            v=4.0/3.0*pi*r*r*r;
            double t=2*cal(sqrt(r*r-hr*hr),r)+2*sqrt(r*r-hr*hr)*pi*hr*hr;
            hv=2*pi*hr*hr*hz;
            printf("%.6lf\n",t/(hv+v-t));
            continue;
        }
        v=4.0/3.0*pi*r*r*r;
        hv=2*pi*hr*hr*hz;
        double t=2*cal(sqrt(r*r-hr*hr),hz)+2*sqrt(r*r-hr*hr)*pi*hr*hr;
        printf("%.6lf\n",t/(hv+v-t));
    }
    return 0;
}
