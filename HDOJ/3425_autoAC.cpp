#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<iostream>
#define eps 1e-8
#define N 20010
using namespace std;
int Sig(double a)
{
    return a<-eps?-1:a>eps;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double x0,double y0):x(x0),y(y0){}
    bool operator <(Point pt)
    {
        if(pt.x==x)
            return y<pt.y;
        return x<pt.x;
    }
    bool operator >(Point pt)
    {
        if(pt.x==x)
            return y>pt.y;
        return x>pt.x;
    }
    bool operator ==(Point pt)
    {
        return !Sig(pt.x-x) && !Sig(pt.y-y);
    }
    Point operator +(Point pt)
    {
        return Point(x+pt.x,y+pt.y);
    }
    Point operator -(Point pt)
    {
        return Point(x-pt.x,y-pt.y);
    }
    Point operator *(double t)
    {
        return Point(x*t,y*t);
    }
    void Input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
struct Range
{
    Point a,b;
    Range(){}
    Range(Point a0,Point b0):a(a0),b(b0){}
    bool operator <(Range r)
    {
        if(a==r.a)
            return b<r.b;
        return a<r.a;
    }
};
int cmp(Range r1,Range r2)
{
    return r1<r2;
}
Point s,e;
Point p[110];
Range rang[110];
double r[110];
int cnt;
Point Intersection(Point u1,Point u2,Point v1,Point v2)
{
    Point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
             ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}
double Dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double Xmult(Point o,Point a,Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
void Count(Point p,double r)
{
    double d=fabs(Xmult(p,s,e))/Dis(s,e);
    if(d-r>=0)
        return ;
    double h=sqrt(r*r-d*d);
    Point tmp=Point(e.y-s.y,s.x-e.x);
    Point o=Intersection(p,p+tmp,s,e);
    Point p1,p2;
    p1=o+(e-s)*(h/Dis(s,e));
    p2=o-(e-s)*(h/Dis(s,e));
    if(p2<p1)
        swap(p1,p2);
    if(p2<s || p2==s || e<p1 || e==p1)
        return ;
    if(p1<s)
        p1=s;
    if(e<p2)
        p2=e;
    rang[cnt++]=Range(p1,p2);
}
int main()
{
    int n;
    while(scanf("%d",&n) && n)
    {
        s.Input();
        e.Input();
        if(e<s)
            swap(s,e);
        for(int i=0;i<n;i++)
        {
            p[i].Input();
            scanf("%lf",&r[i]);
        }
        cnt=0;
        for(int i=0;i<n;i++)
            Count(p[i],r[i]);
        if(cnt==0)
        {
            printf("0.00\n");
            continue;
        }
        if(s.x==e.x)
        {
            sort(rang,rang+cnt,cmp);
            double sum=0;
            double left=rang[0].a.y,right=rang[0].b.y;
            for(int i=1;i<cnt;i++)
            {
                if(rang[i].a.y<=right)
                    right=max(rang[i].b.y,right);
                else
                {
                    sum+=(right-left);
                    left=rang[i].a.y;
                    right=rang[i].b.y;
                }
            }
            sum+=(right-left);
            printf("%.2lf\n",sum/(e.y-s.y)*100);
        }
        else
        {
            sort(rang,rang+cnt,cmp);
            double sum=0;
            double left=rang[0].a.x,right=rang[0].b.x;
            for(int i=1;i<cnt;i++)
            {
                if(rang[i].a.x<=right)
                    right=max(rang[i].b.x,right);
                else
                {
                    sum+=(right-left);
                    left=rang[i].a.x;
                    right=rang[i].b.x;
                }
            }
            sum+=(right-left);
            printf("%.2lf\n",sum/(e.x-s.x)*100);
        }
    }
    return 0;
}
