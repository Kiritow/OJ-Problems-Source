#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
double fly_pos(double vx,double vy,double h)
{
    return vx*(vy+sqrt(vy*vy+19.6*h))/9.8;
}
double fly_h(double vy,double h,double t)
{
    return h+vy*t-4.9*t*t;
}
int main()
{
    double h,vx,vy,t,h0,l,v1,v2,v3;
    char bird[10];
    while(~scanf("%lf%s",&h,bird))
    {
        if(!strcmp("Red",bird))
        {
            scanf("%lf%lf",&vx,&vy);
            printf("%.3lf\n",fly_pos(vx,vy,h));
        }
        else if(!strcmp("Blue",bird))
        {
            scanf("%lf%lf%lf%lf%lf%lf",&vx,&vy,&t,&v1,&v2,&v3);
            if(fly_pos(vx,vy,h)<t*vx)
            {
                printf("%.3lf\n",fly_pos(vx,vy,h));
                continue;
            }
            h0=fly_h(vy,h,t);
            l=vx*t;
            vy=vy-9.8*t;
            printf("%.3lf %.3lf %.3lf\n",l+fly_pos(v1,vy,h0),l+fly_pos(v2,vy,h0),l+fly_pos(v3,vy,h0));
        }
        else
        {
            scanf("%lf%lf%lf",&vx,&vy,&t);
            if(fly_pos(vx,vy,h)<t*vx)
            {
                printf("%.3lf\n",fly_pos(vx,vy,h));
                continue;
            }
            h0=fly_h(vy,h,t);
            l=vx*t;
            vy=vy-9.8*t;
            printf("%.3lf\n",l+fly_pos(2*vx,2*vy,h0));
        }
    }
    return 0;
}
