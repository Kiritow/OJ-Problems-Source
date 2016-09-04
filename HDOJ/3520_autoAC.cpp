#include<stdio.h>
#include<string.h>
#include<cmath>
#include<vector>
#include<algorithm>
#define eps 1e-8
#define inf 999999999
#define N 10100
#define pi acos(-1.0)
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
    void in()
    {
        scanf("%lf%lf",&x,&y);
    }
    double len()
    {
        return sqrt(x*x+y*y);
    }
    double operator ^(Point pt)
    {
        return pt.x*x+pt.y*y;
    }
    Point operator -(Point pt)
    {
        return Point(x-pt.x,y-pt.y);
    }
    Point operator +(Point pt)
    {
        return Point(x+pt.x,y+pt.y);
    }
    Point operator *(double t)
    {
        return Point(x*t,y*t);
    }
    Point operator /(double t)
    {
        return Point(x/t,y/t);
    }
};
struct Polygon
{
    Point p[220];
    int n;
    void in()
    {
        for(int i=0;i<n;i++)
            p[i].in();
    }
};
double Xmult(Point o,Point a,Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
double Dis(Point a,Point b)
{
    return (a-b).len();
}
int con[300];
int cn;//铆1掳眉渭&#196;&#182;锟ノ&#227;锚y
Point po;
int cmp(Point a,Point b)
{
    double d=Xmult(po,a,b);
    if(d>0)
        return 1;
    if(d==0 && Dis(a,po)<Dis(b,po))
        return 1;
    return 0;
}
void Graham(Point p[],int &n)
{
    int i,ind=0;
    for(i=1;i<n;i++)
        if(p[ind].y>p[i].y || (p[ind].y==p[i].y && p[ind].x>p[i].x))
            ind=i;
    swap(p[ind],p[0]);
    po=p[0];
    sort(p+1,p+n,cmp);
    con[0]=0;
    con[1]=1;
    cn=1;
    for(i=2;i<n;i++)
    {
        while(cn>0 && Sig(Xmult(p[con[cn-1]],p[con[cn]],p[i]))<=0)
            cn--;
        con[++cn]=i;
    }
    int tmp=cn;
    for(i=n-2;i>=0;i--)
    {
        while(cn>tmp && Sig(Xmult(p[con[cn-1]],p[con[cn]],p[i]))<=0)
            cn--;
        con[++cn]=i;//p[cn]==p[0];
    }
    Point pt[210];
    for(int i=0;i<cn;i++)
        pt[i]=p[con[i]];
    for(int i=0;i<cn;i++)
        p[i]=pt[i];
    n=cn;
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
double Area(Point p[],int n)
{
    double s=0;
    for(int i=0;i<n;i++)
        s+=Xmult(Point(0,0),p[i],p[(i+1)%n]);
    return fabs(s)*0.5;
}
double Get_inter(Polygon p1,Polygon p2)
{
    Polygon tmp,newp;
    newp=p2;
    for(int i=0;i<p1.n;i++)
    {
        Point a=p1.p[i];
        Point b=p1.p[(i+1)%p1.n];
        tmp.n=0;
        for(int j=0;j<newp.n;j++)
        {
            int r1=Sig(Xmult(a,b,newp.p[j]));
            int r2=Sig(Xmult(a,b,newp.p[(j+1)%newp.n]));
            if(r1>=0)
                tmp.p[tmp.n++]=newp.p[j];
            if(r1*r2<0)
            {
                Point pp=Intersection(a,b,newp.p[j],newp.p[(j+1)%newp.n]);
                tmp.p[tmp.n++]=pp;
            }
        }
        newp=tmp;
    }
    return Area(newp.p,newp.n);
}
double Work(Polygon p1,Polygon p2,Point v,double ks,double all)
{
    Polygon tmp;
    double left=0,right=inf;
    double mid;
    while(right-left>eps)
    {
        mid=(left+right)*0.5;
        tmp=p1;
        for(int i=0;i<tmp.n;i++)
            tmp.p[tmp.n+i]=tmp.p[i]+v*mid;
        tmp.n*=2;
        Graham(tmp.p,tmp.n);
        double s=Get_inter(tmp,p2);
        if(Sig(all-s-ks)<=0)
            right=mid-eps;
        else
            left=mid+eps;
    }
    return left;
}
int main()
{
    Polygon p1,p2;
    Point v;
    double k,ange;
    while(scanf("%d",&p2.n)!=EOF)
    {
        p2.in();
        scanf("%d",&p1.n);
        p1.in();
        scanf("%lf%lf",&ange,&k);
        ange=ange/360*2*pi;
        v=Point(cos(ange),sin(ange));
        v=v/v.len();
        double s=Area(p2.p,p2.n);
        Polygon tmp=p1;
        for(int i=0;i<tmp.n;i++)
        {
            tmp.p[tmp.n+i]=tmp.p[i]+v*inf;
        }
        tmp.n*=2;
        Graham(tmp.p,tmp.n);
        double s1=s-Get_inter(p1,p2);
        double s2=s-Get_inter(tmp,p2);
        if(Sig(s1-s*k)<0 || Sig(s2-s*k)>0)
        {
            printf("-1\n");
            continue;
        }
        printf("%.4f\n",Work(p1,p2,v,k*s,s));
    }
    return 0;
}
