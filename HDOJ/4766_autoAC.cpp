#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=1e3+9;
const double inf=1e11,epx=0.00001;
int n;
double rx,ry,d;
double x[maxn],y[maxn];
double cal(double x1,double y1,double x2,double y2)
{
    double a=(x1-x2)*(x1-x2);
    double b=(y1-y2)*(y1-y2);
    return sqrt(a+b);
}
bool chk(double xx,double yy)
{
    for(int i=1;i<=n;i++)
    if(cal(xx,yy,x[i],y[i])>d+epx) return false;
    return true;
}
int main()
{
    while(scanf("%lf %lf",&rx,&ry)!=EOF)
    {
        scanf("%lf",&d);
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        scanf("%lf %lf",&x[i],&y[i]);
        bool flag=false;
        double ans=inf;
        if(chk(rx,ry))
        {
            ans=0;
            flag=true;
        }
        for(int i=1;i<=n;i++)
        {
            double tmp=cal(x[i],y[i],rx,ry);
            double xx=x[i]+(rx-x[i])*(d/tmp);
            double yy=y[i]+(ry-y[i])*(d/tmp);
            if(ans>cal(xx,yy,rx,ry))
            if(chk(xx,yy))
            {
                ans=cal(xx,yy,rx,ry);
                flag=true;
            }
        }
        for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            if(cal(x[i],y[i],x[j],y[j])>2*d+epx) continue;
            if(fabs(x[i]-x[j])<epx&&fabs(y[i]-y[j])<epx) continue;
            double x1=x[j]-x[i];
            double y1=y[j]-y[i];
            double xx=x[i]+x1/2,yy=y[i]+y1/2;
            double tmp=cal(xx,yy,x[i],y[i]);
            double txt=sqrt(d*d-tmp*tmp);
            double ex,ey;
            if(fabs(x1-0)>epx) ey=1,ex=-y1/x1;
            else ex=1,ey=-x1/y1;
            double tt=sqrt(ex*ex+ey*ey);
            xx+=txt*ex/tt;
            yy+=txt*ey/tt;
            if(cal(xx,yy,rx,ry)<ans)
            if(chk(xx,yy))
            {
                ans=cal(xx,yy,rx,ry);
                flag=true;
            }
            xx-=txt*ex*2/tt;
            yy-=txt*ey*2/tt;
            if(cal(xx,yy,rx,ry)<ans)
            if(chk(xx,yy))
            {
                ans=cal(xx,yy,rx,ry);
                flag=true;
            }
        }
        if(!flag) printf("X\n");
        else printf("%.2lf\n",ans);
    }
    return 0;
}
