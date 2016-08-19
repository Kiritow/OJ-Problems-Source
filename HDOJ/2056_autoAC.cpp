#include<stdio.h>
double max(double a,double b)
{
    if(a>b)
        return a;
    else
        return b;
}
double min(double a,double b)
{
    if(a<b)
        return a;
    else
        return b;
}
int main()
{
    double x1,y1,x2,y2,x3,y3,x4,y4,t;
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
    {
        if (x1>x2) t=x1,x1=x2,x2=t;
        if (y1>y2) t=y1,y1=y2,y2=t;
        if (x3>x4) t=x3,x3=x4,x4=t;
        if (y3>y4) t=y3,y3=y4,y4=t;
            x1=max(x1,x3);
            y1=max(y1,y3);
            x2=min(x2,x4);
            y2=min(y2,y4);
        printf("%.2lf\n",x1>x2||y1>y2?0:(x2-x1)*(y2-y1));
    }
}
