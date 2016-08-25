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
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    Point(){}
    Point(double x0,double y0):x(x0),y(y0){}
};
int n1,n2;
Point p1[110];
Point p2[110];
double Xmult(Point o,Point a,Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
double Dis(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
Point Intersection(Point u1,Point u2,Point v1,Point v2)
{
    Point ret=u1;
    double t=((u1.x-v1.x)*(v1.y-v2.y)-(u1.y-v1.y)*(v1.x-v2.x))/
             ((u1.x-u2.x)*(v1.y-v2.y)-(u1.y-u2.y)*(v1.x-v2.x));
    ret.x+=(u2.x-u1.x)*t;
    ret.y+=(u2.y-u1.y)*t;
    return ret;
}
void Judge(Point o,Point a,Point b,double &d)
{
    Point tmp=Point(b.y-a.y+o.x,a.x-b.x+o.y);
    Point p=Intersection(o,tmp,a,b);
    if(Sig(Dis(a,b)-Dis(a,p)-Dis(b,p)))
        d=min(Dis(a,o),Dis(b,o));
    else
        d=fabs(Xmult(o,a,b))/Dis(a,b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n1);
        for(int i=0;i<n1;i++)
            p1[i].input();
        p1[n1]=p1[0];
        scanf("%d",&n2);
        for(int i=0;i<n2;i++)
            p2[i].input();
        p2[n2]=p2[0];
        double s1=999999999;
        double s2=999999999;
        double l;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                Judge(p1[i],p2[j],p2[j+1],l);
                    s1=min(s1,l);
            }
        }
        for(int i=0;i<n2;i++)
        {
            for(int j=0;j<n1;j++)
            {
                Judge(p2[i],p1[j],p1[j+1],l);
                    s2=min(s2,l);
            }
        }
        printf("%.8f\n",min(s1,s2)*0.5);
    }
    return 0;
}
