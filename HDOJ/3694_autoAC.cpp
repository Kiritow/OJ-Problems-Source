#include<cstdio>
#include<iostream>
#include<utility>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
const int M=15; 
const double inf=1e250;
struct point
{
    double x,y;
    bool operator < (const point a)const
    {
        if(y==a.y)
            return x<a.x;
        return y<a.y;
    }
}p[M],stac[M];
int n,top;
double dis(point a,point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
double xmult(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}
double cross(point p0,point p1,point p2)
{
    double x1=p1.x-p0.x,y1=p1.y-p0.y;
    double x2=p2.x-p0.x,y2=p2.y-p0.y;
    return xmult(x1,y1,x2,y2);
}
void covex_hull()
{
    sort(p,p+n);
    stac[0]=p[0];
    stac[1]=p[1];
    top=1;
    for(int i=2;i<n;i++)
    {
        while(top>0 && cross(stac[top],p[i],stac[top-1])<=0)
            top--;
        stac[++top]=p[i];
    }
    int temp=top;
    for(int i=n-2;i>=0;i--)
    {
        while(top>temp && cross(stac[top],p[i],stac[top-1])<=0)
            top--;
        stac[++top]=p[i];
    }
}
int main()
{
    while(scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y)==8)
    {
        if(p[0].x==-1 && p[0].y==-1 && p[1].x==-1 && p[1].y==-1 && p[2].x==-1 && p[2].y==-1 && p[3].x==-1 && p[3].y==-1)
            break;
        n=4;
        covex_hull();
        double ans;
        if(top==4)
        {
            ans=dis(stac[0],stac[2])+dis(stac[1],stac[3]);
        }
        else
        {
            ans=inf;
            ans=min(ans,dis(p[0],p[1])+dis(p[0],p[2])+dis(p[0],p[3]));
            ans=min(ans,dis(p[1],p[0])+dis(p[1],p[2])+dis(p[1],p[3]));
            ans=min(ans,dis(p[2],p[1])+dis(p[2],p[0])+dis(p[2],p[3]));
            ans=min(ans,dis(p[3],p[1])+dis(p[3],p[2])+dis(p[3],p[0]));
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}
