#include<stdio.h>
#include<cmath>
double x,y,v;  
const double g=9.8;  
double f(double a)  
{  
    return x*tan(a)-x*x*g/(2*v*v*cos(a)*cos(a));  
}  
double  sanf(double  bottom,double  top) 
{
    double rightthir,leftthir;
    while(top-bottom>1e-9)
    {
        rightthir=(bottom+top*2)/3;
        leftthir=(bottom*2+top)/3;
        if(f(rightthir)>f(leftthir))
        {
            bottom=leftthir+1e-10;
        }
        else
        {
            top=rightthir-1e-10;
        }
    }
    return (top+bottom)/2;
}
double erfen(double bottom,double top)
{
    double mid;
    while(top-bottom>1e-9)
    {
        mid=(top+bottom)/2;
        if(f(mid)>y)
        {
            top=mid-1e-10;
        }
        else
        {
            bottom=mid+1e-10;
        }
    }
    return (bottom+top)/2;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf",&x,&y,&v);
        double max=sanf(0,3.1415926535897932384626433832795/2.0);
        if(f(max)<y)
        {
            printf("-1\n");
        }
        else
        {
            printf("%.6lf\n",erfen(0,max));
        }
    }
}
