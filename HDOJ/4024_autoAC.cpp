#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int main()
{
    double x1,y1,x2,y2,Lx,Ly,vD,vB,L;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&Lx,&Ly,&vD,&vB,&L))
    {
        if(x1==0&&y1==0&&x2==0&&y2==0&&Lx==0&&Ly==0&&vD==0&&vB==0&&L==0)break;
        double a=vD*vD-Lx*Lx-Ly*Ly;
        double b=2*L*vD-2*Lx*(x1-x2+L*Lx/vB)-2*Ly*(y1-y2+L*Ly/vB);
        double c=L*L-(x1-x2+L*Lx/vB)*(x1-x2+L*Lx/vB)-(y1-y2+L*Ly/vB)*(y1-y2+L*Ly/vB);
        double s1=(-b-sqrt(b*b-4*a*c))/(2*a);
        double s2=(-b+sqrt(b*b-4*a*c))/(2*a);
        b=-2*L*vD-2*Lx*(x1-x2+L*Lx/vB)-2*Ly*(y1-y2+L*Ly/vB);
        double s3=(-b-sqrt(b*b-4*a*c))/(2*a);
        double s4=(-b+sqrt(b*b-4*a*c))/(2*a);
        printf("%.3lf ",L);
        if(s1<0)s1=10000000000.0;
        if(s2<0)s2=10000000000.0;
        if(s3<0)s3=10000000000.0;
        if(s4<0)s4=10000000000.0;
        printf("%.3lf\n",min(s1,min(s2,min(s3,s4)))+L/vB);
    }
    return 0;
}
