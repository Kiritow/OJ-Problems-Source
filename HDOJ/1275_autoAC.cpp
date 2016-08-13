#include<stdio.h>
#include<math.h>
double l,v1,v2,v;
int n;
double f(double t1,double t2)
{
    if(t2-t1<=1e-6)
        return t1;
    double time=(t1+t2)/2;
    if(floor((time*v/l+1)/2.0)+floor((time*(v1+v2)/l+1)/2.0)>=n)
        return f(t1,time);
    else
        return f(time,t2);
}
int main()
{
    int t;
    double time,x,dist;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%d",&l,&v1,&v2,&n);
        if(v1>v2)
            v=v1-v2;
        else
            v=v2-v1;
        time=f(0,100000);
        x=time*v1;
        while(x>0)
            x=x-l;
        dist=(-x)<l+x?(-x):l+x;
        printf("Time=%.3lf Dist=%.3lf\n",time,dist);
    }
    return 0;
}
