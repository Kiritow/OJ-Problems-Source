#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
const double eps=1e-9;
const double pi=acos(-1.0);
struct point
{
    double x, y;
    point() {}
    point(double xx, double yy):x(xx), y(yy) {}
    point operator + (const point &a) const
    {
        return point(x+a.x, y+a.y);
    }
    point operator - (const point &a) const
    {
        return point(x-a.x, y-a.y);
    }
} po[105], cen, s, e, tp[105];
double r;
int t1, t2, t;
int n, pn;
point cg()
{
    point p, s, re;
    re.x=0.0;
    re.y=0.0;
    double area=0.0, ar;
    p=po[0];
    po[n]=po[0];
    for(int i=1; i<=n; i++)
    {
        s=po[i];
        ar=p.x*s.y-s.x*p.y;
        area+=(ar/2);
        re.x+=(p.x+s.x)*ar;
        re.y+=(p.y+s.y)*ar;
        p=s;
    }
    re.x/=(6*area);
    re.y/=(6*area);
    return re;
}
point pointrotate(point o, double ang, point p)
{
    point tp;
    p.x-=o.x;
    p.y-=o.y;
    tp.x=p.x*cos(ang)-p.y*sin(ang)+o.x;
    tp.y=p.y*cos(ang)+p.x*sin(ang)+o.y;
    return tp;
}
double dis(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double dot(point sp, point ep, point op)
{
    return (sp.x-op.x)*(ep.x-op.x)+(sp.y-op.y)*(ep.y-op.y);
}
double cross(point sp, point ep, point op)
{
    return (sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x);
}
double coverdeg(double ang, double d, double r)
{
    double neg=1;
    if(ang<0)
    {
        ang=-ang;
        neg=-1;
    }
    double sina=d*sin(ang)/r;
    if(sina>1)sina=1;
    return neg*(asin(sina)-ang);
}
int main ()
{
    int i;
    while(~scanf("%lf%lf%lf%lf%lf%d%d%d%d", &s.x, &s.y, &e.x, &e.y, &r, &n, &t1, &t2, &t))
    {
        for(i=0; i<n; i++)scanf("%lf%lf", &po[i].x, &po[i].y);
        cen=cg();
        double a2=(double)(t%t2)/t2*2*pi;
        for(i=0; i<n; i++)po[i]=pointrotate(cen, a2, po[i]);
        double a1=(double)(t%t1)/t1*2*pi;
        point newcen=pointrotate(e, a1, cen);
        point mov=newcen-cen;
        for(i=0; i<n; i++)po[i]=po[i]+mov;
        double se=dis(s, e);
        double maxang=acos(r/se);
        double maxarc=2*maxang*r;
        if(dot(s, newcen, e)<0)
        {
            printf("%.2lf\n", maxarc);
            continue;
        }
        double supang=pi*0.5-maxang;
        point up=po[0], lp=po[0];
        for(int i=1; i<n; i++)
        {
            if(cross(up, po[i], s)>eps)up=po[i];
            if(cross(lp, po[i], s)<-eps)lp=po[i];
        }
        double ua=acos(dot(up, e, s)/(se*dis(s, up)));
        double la=acos(dot(lp, e, s)/(se*dis(s, lp)));
        if(cross(e, up, s)<0)ua=-ua;
        if(cross(e, lp, s)<0)la=-la;
        double cvua=min(supang, ua), cvla=max(-supang, la);
        if(cvua<cvla)
        {
            printf("%.2lf\n", maxarc);
            continue;
        }
        double coverarc=r*(coverdeg(cvua, se, r)-coverdeg(cvla, se, r));
        printf("%.2lf\n", maxarc-coverarc);
    }
    return 0;
}
