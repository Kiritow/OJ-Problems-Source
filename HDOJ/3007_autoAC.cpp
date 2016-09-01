#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
using namespace std;
struct Point
{
    double x,y;
};
Point a[1005],d;
double r;
double dist(Point A,Point B)
{
    return sqrt((A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y));
}
double cross(Point A,Point B,Point C)
{
    return (B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y);
}
void MiniDiscWith2Point(Point p,Point q,int n)
{
    d.x=(p.x+q.x)/2.0;
    d.y=(p.y+q.y)/2.0;
    r=dist(p,q)/2;
    int k;
    double c1,c2,t1,t2,t3;
    for(k=1;k<=n;k++)
    {
        if(dist(d,a[k])<=r) continue;
        if(cross(p,q,a[k])!=0.0)
        {
            c1=(p.x*p.x+p.y*p.y-q.x*q.x-q.y*q.y)/2.0;
            c2=(p.x*p.x+p.y*p.y-a[k].x*a[k].x-a[k].y*a[k].y)/2.0;
            d.x=(c1*(p.y-a[k].y)-c2*(p.y-q.y))/((p.x-q.x)*(p.y-a[k].y)-(p.x-a[k].x)*(p.y-q.y));
            d.y=(c1*(p.x-a[k].x)-c2*(p.x-q.x))/((p.y-q.y)*(p.x-a[k].x)-(p.y-a[k].y)*(p.x-q.x));
            r=dist(d,a[k]);
        }
        else
        {
            t1=dist(p,q);
            t2=dist(q,a[k]);
            t3=dist(p,a[k]);
            if(t1>=t2&&t1>=t3)
            {
                d.x=(p.x+q.x)/2.0;
                d.y=(p.y+q.y)/2.0;
                r=dist(p,q)/2.0;
            }
            else if(t2>=t1&&t2>=t3)
            {
                d.x=(a[k].x+q.x)/2.0;
                d.y=(a[k].y+q.y)/2.0;
                r=dist(a[k],q)/2.0;
            }
            else
            {
                d.x=(a[k].x+p.x)/2.0;
                d.y=(a[k].y+p.y)/2.0;
                r=dist(a[k],p)/2.0;
            }
        }
    }
}
void MiniDiscWithPoint(Point pi,int n)
{
    d.x=(pi.x+a[1].x)/2.0;
    d.y=(pi.y+a[1].y)/2.0;
    r=dist(pi,a[1])/2.0;
    int j;
    for(j=2;j<=n;j++)
    {
        if(dist(d,a[j])<=r) continue;
        else
        {
            MiniDiscWith2Point(pi,a[j],j-1);
        }
    }
}
int main()
{
    int i,n;
    while(scanf("%d",&n)&&n)
    {
        for(i=1;i<=n;i++)
            scanf("%lf %lf",&a[i].x,&a[i].y);
        if(n==1)
        {
            printf("%.2lf %.2lf 0.00\n",a[1].x,a[1].y);
            continue;
        }
        r=dist(a[1],a[2])/2.0;
        d.x=(a[1].x+a[2].x)/2.0;
        d.y=(a[1].y+a[2].y)/2.0;
        for(i=3;i<=n;i++)
        {
            if(dist(d,a[i])<=r)continue;
            else MiniDiscWithPoint(a[i],i-1);
        }
        printf("%.2lf %.2lf %.2lf\n",d.x,d.y,r);
    }
    return 0;
}
