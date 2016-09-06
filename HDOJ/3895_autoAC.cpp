#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
const double eps=1e-4;
using namespace std;
inline double sqr(double a)
{
    return a*a;
}
double ax, x2, x3, ay, y2, y3, r1, r2, r3;
int m1, m2, m3;
bool check(double x, double y, double r)
{
    if(fabs(sqr(x-ax)+sqr(y-ay)-sqr(r+m1*r1))>eps)return false;
    if(fabs(sqr(x-x2)+sqr(y-y2)-sqr(r+m2*r2))>eps)return false;
    if(fabs(sqr(x-x3)+sqr(y-y3)-sqr(r+m3*r3))>eps)return false;
    return true;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t-->0)
    {
        scanf("%lf%lf%lf%d%lf%lf%lf%d%lf%lf%lf%d", &ax, &ay, &r1, &m1, &x2, &y2, &r2, &m2, &x3, &y3, &r3, &m3);
        if(m1==0)m1=-1;
        if(m2==0)m2=-1;
        if(m3==0)m3=-1;
        double a, b, c, d, aa, bb, cc, dd;
        a=2*(ax-x2);
        b=2*(ay-y2);
        c=2*(r2*m2-r1*m1);
        d=m2*m2*r2*r2-m1*m1*r1*r1-x2*x2+ax*ax-y2*y2+ay*ay;
        aa=2*(ax-x3);
        bb=2*(ay-y3);
        cc=2*(r3*m3-r1*m1);
        dd=m3*m3*r3*r3-m1*m1*r1*r1-x3*x3+ax*ax-y3*y3+ay*ay;
        double a1, b1, a2, b2;
        if(fabs(bb*a-aa*b)<eps){printf("NO SOLUTION!\n");continue;}
        a1=(a*cc-c*aa)/(bb*a-aa*b);
        b1=(dd*a-d*aa)/(bb*a-aa*b);
        if(fabs(b*aa-bb*a)<eps){printf("NO SOLUTION!\n");continue;}
        a2=(cc*b-c*bb)/(b*aa-bb*a);
        b2=(b*dd-bb*d)/(b*aa-bb*a);
        double A, B, C;
        A=a2*a2+a1*a1-1;
        B=2*a2*b2-2*ax*a2+2*a1*b1-2*ay*a1-2*m1*r1;
        C=b2*b2-2*ax*b2+ax*ax+b1*b1-2*ay*b1+ay*ay-r1*r1;
        double rr;
        if(B*B-4*A*C<0){printf("NO SOLUTION!\n");continue;}
        if(fabs(A)<eps){printf("NO SOLUTION!\n");continue;}
        rr=(sqrt(B*B-4*A*C)-B)/2/A;
        double rx=a2*rr+b2;
        double ry=a1*rr+b1;
        if(rr>=-eps&&check(rx, ry, rr))
        {
            printf("%.4lf %.4lf", rx, ry);
            if(fabs(rr)>=eps)printf(" %.4lf", rr);
            printf("\n");
            continue;
        }
        rr=(-B-sqrt(B*B-4*A*C))/2/A;
        rx=a2*rr+b2;
        ry=a1*rr+b1;
        if(rr>=-eps&&check(rx, ry, rr))
        {
            printf("%.4lf %.4lf", rx, ry);
            if(fabs(rr)>=eps)printf(" %.4lf", rr);
            printf("\n");
            continue;
        }
        printf("NO SOLUTION!\n");
    }
    return 0;
}
