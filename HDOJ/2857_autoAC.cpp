#include<stdio.h>
#include<math.h>
struct line
{
       double a,b,c;
}p,s;
double x3, y3, x2, y2, x, y;
double xs,xe,ys,ye,ansx,ansy;
void jiaodian()
{
       s.a=y-ye;
       s.b=xe-x;
       s.c=x*ye-y*xe;
       if(fabs(p.b)<1e-6)
       {
          ansx = -p.c / p.a;
          ansy = (-s.c - s.a * ansx) / s.b;
       }
       else
       {
           ansx = (p.c * s.b - p.b * s.c) / (p.b * s.a - s.b * p.a);
           ansy = (-p.c- p.a* ansx) / p.b;
       }
}
void duichen()
{
       double d;
       p.a=y3-y2;
       p.b=x2-x3;
       p.c=x3*y2-y3*x2;
       d=p.a*p.a+p.b*p.b;
       x=(p.b * p.b * xs - p.a * p.a * xs - 2 * p.a * p.b * ys - 2 * p.a * p.c) / d;
       y=(p.a * p.a * ys - p.b * p.b * ys - 2 * p.a * p.b * xs - 2 * p.b * p.c) / d;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&x3,&y3,&x2,&y2);
        scanf("%lf%lf%lf%lf",&xs,&ys,&xe,&ye);
        duichen();
        jiaodian();
        if(fabs(ansx)<1e-6)ansx=fabs(ansx);
        if(fabs(ansy)<1e-6)ansy=fabs(ansy);
        printf("%.3lf %.3lf\n",ansx,ansy);
    }
    return 0;
}
