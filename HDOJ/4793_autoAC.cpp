#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define eps 1e-8
using namespace std;
#define N 10007
int sgn(double x)
{
    if(x > eps) return 1;
    if(x < -eps) return -1;
    return 0;
}
int main()
{
    double Rm,R,r,x,y,vx,vy;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf",&Rm,&R,&r,&x,&y,&vx,&vy)!=EOF)
    {
        double A1 = (vx*vx+vy*vy);
        double B1 = (2*vx*x+2*y*vy);
        double C1 = x*x+y*y-(R+r)*(R+r);
        double A2 = A1;
        double B2 = B1;
        double C2 = x*x+y*y-(Rm+r)*(Rm+r);
        double delta1 = B1*B1 - 4.0*A1*C1;
        double delta2 = B2*B2 - 4.0*A2*C2;
        if(sgn(delta1) <= 0)
        {
            puts("0.000");
            continue;
        }
        double J11 = (-B1 + sqrt(delta1))/(2.0*A1);
        double J12 = (-B1 - sqrt(delta1))/(2.0*A1);
        if(sgn(J12) >= 0)
        {
            if(sgn(delta2) <= 0)
            {
                printf("%.3f\n",fabs(J11-J12));
                continue;
            }
            double J22 = (-B2 - sqrt(delta2))/(2.0*A2);
            printf("%.3f\n",(J22-J12)*2.0);
        }
        else
            puts("0.000");
    }
    return 0;
}
