#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#define inf 0x7fffffff
#define exp 1e-10
#define PI 3.141592654
using namespace std;
typedef long long ll;
struct Point
{
    double x,y;
    Point (double x=0,double y=0):x(x),y(y){}
};
double dist(Point a,Point b)
{
    double x=(a.x-b.x)*(a.x-b.x);
    double y=(a.y-b.y)*(a.y-b.y);
    return sqrt(x+y);
}
double Area_of_overlap(Point c1,double r1,Point c2,double r2)
{
    double d=dist(c1,c2);
    if (r1+r2<d+exp) return 0;
    if (d<fabs(r1-r2)+exp)
    {
        double r=min(r1,r2);
        return PI*r*r;
    }
    double x=(d*d+r1*r1-r2*r2)/(2*d);
    double t1=acos(x/r1);
    double t2=acos((d-x)/r2);
    return r1*r1*t1+r2*r2*t2-d*r1*sin(t1);
}
int main()
{
    int t,ncase=1;
    double r,R;
    Point a,b;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%lf%lf",&r,&R);
        scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
        double bb_area=Area_of_overlap(a,R,b,R);
        double bs_area=Area_of_overlap(a,R,b,r);
        double ss_area=Area_of_overlap(a,r,b,r);
        printf("Case #%d: %.6lf\n",ncase++,bb_area-2.0*bs_area+ss_area);
    }
    return 0;
}
