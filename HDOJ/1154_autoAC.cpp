#include <iostream>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;
#define maxn 1200
#define eps 1e-8
struct point
{
    double x;
    double y;
}po[maxn],rec[maxn];
struct line
{
    point a;
    point b;
}temp,temp1;
double xmulit(point &a,point &b,point &c)
{
    return (a.x-b.x)*(a.y-c.y)-(a.y-b.y)*(a.x-c.x);
}
bool across(point &a,point &b,point &c,point &d)
{
double p=xmulit(a,b,c),p1=xmulit(a,b,d);
if( fabs(p1) <= eps || fabs(p) <= eps ) return true;
if( p*p1 < -eps )
return true;
return false;
}
bool one_line(point &a,point &b,point &c,point &d)
{
double p=xmulit(a,b,c),p1=xmulit(a,b,d);
if( fabs(p1) < eps && fabs(p) < eps ) return true;
return false;
}
bool is_equal(point &a,point &b)
{
return (fabs(a.x-b.x) <= eps) && (fabs(a.y-b.y) <=eps);
}
point intersection(line &u,line &v)
{
point ret=u.a;
double t=((u.a.x-v.a.x)*(v.a.y-v.b.y) - (u.a.y-v.a.y)*(v.a.x-v.b.x))/((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
ret.x+=(u.b.x-u.a.x)*t;
ret.y+=(u.b.y-u.a.y)*t;
return ret;
}
int n,m;
double dis(point &a,point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int cmp(point a, point b)
{
    if(fabs(a.x-b.x)<eps)
        return a.y<b.y;
    return a.x<b.x;
}
bool on_segment(point pi,point pj,point pk)
{
    if(xmulit(pi, pj, pk)==0)
    {
        if(pk.x>=min(pi.x,pj.x)&&pk.x<=max(pi.x,pj.x)&&pk.y>=min(pi.y,pj.y)&&pk.y<=max(pi.y,pj.y))
            return true;
    }
    return false;
}
bool segments_intersect(point p1,point p2,point p3,point p4)
{
    double d1=xmulit(p3,p4,p1);
    double d2=xmulit(p3,p4,p2);
    double d3=xmulit(p1,p2,p3);
    double d4=xmulit(p1,p2,p4);
    if(d1*d2<0&&d3*d4<0)
        return true;
    else if(d1==0&&on_segment(p3,p4,p1))
        return true;
    else if(d2==0&&on_segment(p3,p4,p2))
        return true;
    else if(d3==0&&on_segment(p1,p2,p3))
        return true;
    else if(d4==0&&on_segment(p1,p2,p4))
        return true;
    return false;
}
int inpoto(point a)
{
    int i;
    point b,c,d;
    b.y=a.y;
    b.x=1e15;
    int flag=0;
    int count=0;
    for(i=0;i<n;i++)
    {
        c = po[i];
        d = po[i + 1];
        if(on_segment(c,d,a))
            return 1;
        if(abs(c.y-d.y)<eps)
            continue;
        if(on_segment(a,b,c))
        {
            if(c.y>d.y)
                count++;
        }
        else if(on_segment(a,b,d))
        {
            if(d.y>c.y)
                count++;
        }
        else if(segments_intersect(a,b,c,d))
            count++;
    }
    return count%2;
}
point mid(point &a,point &b)
{
    point c;
    c.x=(a.x+b.x)/2;
    c.y=(a.y+b.y)/2;
    return c;
}
double find_ans()
{
    point a,b;
    int i,j,k,pos=0;
    double ans=0;
    po[n]=po[0];
    for(i=0;i<n;i++)
    {
        if(one_line(temp.a,temp.b,po[i],po[i+1]))
        {
          rec[pos++]=po[i];
          rec[pos++]=po[i];
          continue;
        }
        if(across(temp.a,temp.b,po[i],po[i+1]))
        {
          temp1.a=po[i],temp1.b=po[i+1];
          rec[pos++]=intersection(temp,temp1);
        }
    }
    sort(rec,rec+pos,cmp);
    for(i=0;i<pos-1;i++)
    {
       if(inpoto(mid(rec[i],rec[i+1])))
          ans+=dis(rec[i],rec[i+1]);
    }
    return ans;
}
int main()
{
    int i,j,k;
    while(scanf("%d%d",&n,&m))
    {
        if(m==0 && m==0)
        return 0;
        for(i=0;i<n;i++)
        scanf("%lf%lf",&po[i].x,&po[i].y);
        for(i=0;i<m;i++)
        {
            scanf("%lf%lf%lf%lf",&temp.a.x,&temp.a.y,&temp.b.x,&temp.b.y);
            printf("%.3lf\n",find_ans());
        }
    }
    return 0;
}
