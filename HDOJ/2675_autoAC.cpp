#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
const double ee=2.718281828459;
const double eps=1e-7;
int main()
{
    double x,y;
    while(scanf("%lf",&y)!=EOF)
    {
        double tmp=(1+log(y))/(y*ee);
        double low=1+eps,hei=ee-eps,mid;
        if(tmp*ee-1>eps){puts("Happy to Womens day!");continue;}
        while(hei-low>eps)
        {
            mid=(hei+low)/2;
            if(log(mid)*(y*ee)>(1+log(y))*mid)
            hei=mid;
            else 
            low=mid;
        }
        if(y==1)printf("%.5lf\n",(hei+low)/2);
        else  if(y>1)
        {
            double ans=(hei+low)/2;
            low=ee+eps,hei=2000000000+eps;
            while(hei-low>eps)
            {
                mid=(hei+low)/2;
                if(log(mid)*(y*ee)<(1+log(y))*mid)
                hei=mid;
                else 
                low=mid;
            }
            printf("%.5lf %.5lf\n",ans,(hei+low)/2);
        }
    }
    return 0;
}
