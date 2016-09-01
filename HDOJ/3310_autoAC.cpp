#include<stdio.h>
#include<math.h>
double cal(double r1,double r2,double dx)
{
    return sqrt(r1*r1-dx*dx)*sqrt(r2*r2-dx*dx);
}
double fun(double r1,double r2)
{
    int n=1000000;
    double dx=(r1<r2?r1:r2)/n;
    double pi=3.141592653;
    double v=0;
    for(int i=0;i<n;i++)
    {
        v+=cal(r1,r2,(double)dx*i+dx/2);
    }
    return v*8*dx;
}
int main()
{
    int t;
    double r1,r2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf",&r1,&r2);
        printf("%.2lf\n",fun(r1,r2));
    }
    return 0;
}
