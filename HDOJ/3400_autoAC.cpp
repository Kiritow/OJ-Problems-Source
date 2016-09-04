#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct point
{
    double x,y;
};
const double eps=1e-4;
double p,q,r;
double dis(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double cal_ab(point a,point b,point m)
{
    point left=a,right=b;
    point mid,midmid;
    double ans1,ans2;
    do
    {
        mid.x=(left.x+right.x)/2.0;
        mid.y=(left.y+right.y)/2.0;
        midmid.x=(left.x+mid.x)/2.0;
        midmid.y=(left.y+mid.y)/2.0;
        ans1=dis(mid,a)/p+dis(mid,m)/r;
        ans2=dis(midmid,a)/p+dis(midmid,m)/r;
        if(ans1<ans2)
            left=midmid;
        else
            right=mid;
    }while(fabs(ans1-ans2)>eps);
    return ans1;
}
double cal_abcd(point a,point b,point c,point d)
{
    point left=c,right=d;
    point m,mm;
    double ans1,ans2;
    do
    {
        m.x=(left.x+right.x)/2.0;
        m.y=(left.y+right.y)/2.0;
        mm.x=(left.x+m.x)/2.0;
        mm.y=(left.y+m.y)/2.0;
        ans1=dis(m,d)/q+cal_ab(a,b,m);
        ans2=dis(mm,d)/q+cal_ab(a,b,mm);
        if(ans1<ans2)
            left=mm;         
        else
            right=m;
    }while(fabs(ans1-ans2)>eps);
    return ans1;
}
int main()
{
    int t;
    point a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
        scanf("%lf%lf%lf",&p,&q,&r);
        printf("%.2lf\n",cal_abcd(a,b,c,d));
    }
    return 0;
}
