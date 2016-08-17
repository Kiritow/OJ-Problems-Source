#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
double a,b,l,r;
double F(double x)
{
    return b*sqrt((1-x/a)*(1+x/a));
}
double simpson(double a,double b)
{
    double c=(a+b)/2;
    return (F(a)+4*F(c)+F(b))*(b-a)/6.;
}
double asr(double a,double b,double eps,double A)
{
    double c=(a+b)/2;
    double L=simpson(a,c),R=simpson(c,b);
    if(fabs(L+R-A)<=15*eps) return L+R+(L+R-A)/15.0;
    return asr(a,c,eps/2,L)+asr(c,b,eps/2,R);
}
double ASR(double a,double b,double eps)
{
    return asr(a,b,eps,simpson(a,b));
}
int main()
{
    int T_T;
    scanf("%d",&T_T);
    while(T_T--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
        printf("%.3lf\n",2.*ASR(l,r,1e-6));
    }  
    return 0;
}
