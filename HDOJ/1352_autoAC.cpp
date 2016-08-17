#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<vector>
#define eps 1e-8
using namespace std;
struct Point
{
    double x,y;
    Point(){}
    Point(double x0,double y0):x(x0),y(y0){}
    void Input()
    {
        scanf("%lf%lf",&x,&y);
    }
};
struct Line
{
    Point a,b;
    double inter,k;
    Line(){}
    Line(Point a0,Point b0):a(a0),b(b0){}
};
double Xmult(Point o,Point a,Point b)
{
    return (a.x-o.x)*(b.y-o.y)-(b.x-o.x)*(a.y-o.y);
}
int Sig(double a)
{
    return a<-eps?-1:a>eps;
}
int cmp(Line l1,Line l2)
{
    if(!Sig(l1.k-l2.k) && !Sig(l1.inter-l2.inter) && !Sig(l1.a.x-l2.a.x))
        return l1.b.x<l2.b.x;
    if(!Sig(l1.k-l2.k) && !Sig(l1.inter-l2.inter))
        return l1.a.x<l2.a.x;
    if(!Sig(l1.k-l2.k))
        return l1.inter<l2.inter;
    return l1.k<l2.k;
}
int Count(vector<Line> v)
{
    int n=v.size();
    for(int i=0;i<n;i++)
    {
        v[i].inter=-(v[i].a.x)*(v[i].b.y-v[i].a.y)/(v[i].b.x-v[i].a.x)+v[i].a.y;
        v[i].k=(v[i].b.y-v[i].a.y)/(v[i].b.x-v[i].a.x);
    }
    sort(v.begin(),v.end(),cmp);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(!Sig(v[i].inter-v[i-1].inter) && !Sig(v[i].k-v[i-1].k) && Sig(v[i].a.x-v[i-1].b.x)<=0)
        {
            ans++;
            v[i].b.x=max(v[i-1].b.x,v[i].b.x);
        }
    }
    return ans;
}
int cmp1(Line l1,Line l2)
{
    if(!Sig(l1.inter-l2.inter) && !Sig(l1.a.y-l2.a.y))
        return l1.b.y<l2.b.y;
    if(!Sig(l1.inter-l2.inter))
        return l1.a.y<l2.a.y;
    return l1.inter<l2.inter;
}
int main()
{
    int n;
    Point a,b;
    vector<Line> v;
    vector<Line> v1;
    while(scanf("%d",&n) && n)
    {
        v.clear();
        v1.clear();
        for(int i=0;i<n;i++)
        {
            a.Input();
            b.Input();
            if(a.x>b.x)
                swap(a,b);
            if(a.x==b.x)
                v1.push_back(Line(a,b));
            else
                v.push_back(Line(a,b));
        }
        int ans=0;
        ans=Count(v);
        for(int i=0;i<v1.size();i++)
        {
            v1[i].inter=v1[i].a.x;
            if(v1[i].a.y>v1[i].b.y)
                swap(v1[i].a,v1[i].b);
        }
        sort(v1.begin(),v1.end(),cmp1);
        for(int i=1;i<v1.size();i++)
            if(!Sig(v1[i].inter-v1[i-1].inter) && Sig(v1[i].a.y-v1[i-1].b.y)<=0)
            {
                ans++;
                v1[i].b.y=max(v1[i].b.y,v1[i-1].b.y);
            }
        printf("%d\n",n-ans);
    }
    return 0;
}
