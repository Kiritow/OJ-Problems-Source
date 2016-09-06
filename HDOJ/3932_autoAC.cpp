#include <cstdio>
#include <cmath>
#include <time.h>
#include <cstdlib>
using namespace std;
const double pi=acos(-1.0);
const int maxn=1005;
double x[maxn], y[maxn];
int n;
double dis2 (double x1,double y1 ,double x2,double y2)
{
       double tmp1=x1-x2,tmp2=y1-y2;
       tmp1*=tmp1;
       tmp2*=tmp2;
       return tmp1+tmp2;
}
double test(double xx, double yy) 
{
       double max = 0,tmp;
       for (int i=0;i<n;i++)
           if(max<(tmp=dis2(xx,yy,x[i],y[i])))max=tmp;
       return max;
}
int main()
{
    double xx,yy;
    double delta,theta;
    double X,Y;
    double retx,rety,ans;
    while (~scanf("%lf%lf%d",&X,&Y,&n))
    {
        for (int i=0 ; i<n ; i++)
            scanf("%lf%lf",x+i,y+i);
        double ans=1000000000.0;
        for (int i=0 ; i<10 ; ++i)
        {
            xx=((double)(rand()%1001)/1000.0)*X;
            yy=((double)(rand()%1001)/1000.0)*Y;
            double dis=test(xx,yy);
            for (delta=X ; delta>0.001 ; delta*=0.9) 
            {
                for (theta=0 ; theta<=2*pi ; theta+=(pi/25.0))
                {
                    double tx=xx+delta*cos(theta);
                    double ty=yy+delta*sin(theta);
                    double tdis=test(tx,ty);
                    if(tdis<dis)
                    {
                        xx=tx;
                        yy=ty;
                        dis=tdis;
                    }
                }
            }
            if(dis<ans)
            {
                retx=xx;
                rety=yy;
                ans=dis;
            }
        }
        printf("(%.1lf,%.1lf).\n%.1lf\n",retx,rety,sqrt(ans));
    }
    return 0;
}
