#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
const double eps=1e-6;
int dcmp(double x)
{
    if(fabs(x)<eps)return 0;
    else return x<0?-1:1;
}
int main()
{
    double width,height,door,workers;
    while(scanf("%lf%lf%lf%lf",&width,&height,&door,&workers))
    {
        if(width==0&&height==0&&door==0&&workers==0)break;
        double area=width*height;
        area/=workers;
        double d1=width-door;
        double prex=width;
        double prey=0;
        for(int i=0;i<workers-1;++i)
        {
            double tmp=area;
            double x,y;
            if(dcmp(prey-height)!=0)
            {
                if(dcmp(prex-width)==0)
                {
                    x=width;
                    y=2*tmp/d1+prey;
                    if(y>height)
                    {
                        tmp-=(height-prey)*d1/2;
                        y=height;
                        x=width-tmp*2/y;
                    }
                }
                else if(dcmp(prex)==0)
                {
                    x=0;
                    y=prey-2*tmp/door;
                }
            }
            else
            {
                y=height;
                x=prex-tmp*2/height;
                if(x<0)
                {
                    tmp=tmp-prex*prey/2;
                    x=0;
                    y=height-tmp*2/door;
                }
            }
            prex=x;
            prey=y;
            printf("%.3lf %.3lf ",x,y);
        }
        printf("\n");
    }
    return 0;
}
