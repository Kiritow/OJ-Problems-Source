#include <stdio.h>
#include <string.h>
#include <math.h>
struct node
{
    double x,y,z;
}p,q,r,t,t2,t3,t4,t5;
int main()
{
    double a,b,hu;
    while(~scanf("%lf%lf%lf",&p.x,&p.y,&p.z))
    {
        scanf("%lf%lf%lf",&q.x,&q.y,&q.z);
        scanf("%lf",&hu);
        a=atan(q.y/q.x);
        r.x=sqrt(q.x*q.x+q.y*q.y);
        r.y=0;
        r.z=q.z;
        b=atan(r.x/r.z);
        t.x=p.x*cos(a)+p.y*sin(a);
        t.y=-p.x*sin(a)+p.y*cos(a);
        t.z=p.z;
        t2.x=t.x*cos(b)-t.z*sin(b);
        t2.z=t.x*sin(b)+t.z*cos(b);
        t2.y=t.y;
        t3.x=t2.x*cos(hu)-t2.y*sin(hu);
        t3.y=t2.x*sin(hu)+t2.y*cos(hu);
        t3.z=t2.z;
        t4.x=t3.x*cos(b)+t3.z*sin(b);
        t4.z=-t3.x*sin(b)+t3.z*cos(b);
        t4.y=t3.y;
        t5.x=t4.x*cos(a)-t4.y*sin(a);
        t5.y=t4.x*sin(a)+t4.y*cos(a);
        t5.z=t4.z;
        printf("%.3lf %.3lf %.3lf\n",t5.x,t5.y,t5.z);
    }
    return 0;
}
