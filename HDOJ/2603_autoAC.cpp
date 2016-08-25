#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define PI acos(-1.0)
#define G  9.87
#define H1 3
#define H2 0.5
int main()
{
    double v,m,a;
    while(~scanf("%lf%lf%lf",&v,&m,&a))
    {
        double vx=v*cos(a*PI/180);
        double vy=v*sin(a*PI/180);
        double x,t1,t2,t;
        if(vy*vy>G)                
        {   
            double t1=2*(vy-sqrt(vy*vy-2*H2*G))/G;
            double t2=(sqrt(vy*vy+2*G*H1)-vy)/G;
            t=t1+t2;  
        }
        else
        {
            t=2*vy/G+(sqrt(vy*vy+2*G*H1)-vy)/G;
        }
        x=t*vx;
        printf("%.3lf\n",x);
    }
    return 0;
}
