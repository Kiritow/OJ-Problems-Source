#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#define eps 1e-8
#define N 200
using namespace std;
const double PI=acos(-1.0);
int dlcmp(double x)
{
    return x<-eps?-1:x>eps;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double a,double b):x(a),y(b){}
    Point operator + (const Point a) const {return Point(x+a.x,y+a.y);}
    Point operator - (const Point a) const {return Point(x-a.x,y-a.y);}
    Point operator * (const double a) const {return Point(x*a,y*a);}
    Point operator / (const double a) const {return Point(x/a,y/a);}
    bool operator == (const Point a)
    {
        return !dlcmp(x-a.x)&&!dlcmp(y-a.y);
    }
    Point trunc(double d) const
    {
        double dis(Point,Point);
        double len=dis(*this,Point(0,0));
        return Point(x*d/len,y*d/len);
    }
    Point rotate(double a)
    {
        return Point(x*cos(a)-y*sin(a),y*cos(a)+x*sin(a));
    }
};
struct Circle
{
    Point o;
    double r;
    Circle(){}
    Circle(Point a,double l):o(a),r(l){}
};
struct node
{
    double s,e;
    node(){}
    node(double a,double b):s(a),e(b){}
};
Circle c[N],red,purple;
vector<node>arc;
double sqr(double x)
{
    return x*x;
}
double fix(double x)
{
    if (dlcmp(x-1)>=0)
        return 1;
    if (dlcmp(x+1)<=0)
        return -1;
    return x;
}
double dis(Point a,Point b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
void get_InCommonTangent(Circle c1,Circle c2,Point &s1,Point &e1,Point &s2,Point &e2)
{
    double l=dis(c1.o,c2.o);
    double d=l*c1.r/(c1.r+c2.r);
    double tmp=c1.r/d;
    tmp=fix(tmp);
    double theta=acos(tmp);
    Point vec=c2.o-c1.o;
    vec=vec.trunc(c1.r);
    s1=c1.o+vec.rotate(theta);
    s2=c1.o+vec.rotate(-theta);
    vec=c1.o-c2.o;
    vec=vec.trunc(c2.r);
    e1=c2.o+vec.rotate(theta);
    e2=c2.o+vec.rotate(-theta);
}
void inter_circle_ray(Circle c,Point s,Point e,Point &p)
{
    Point vec=e-s;
    double A=sqr(vec.x)+sqr(vec.y);
    double B=2*(vec.x*(s.x-c.o.x)+vec.y*(s.y-c.o.y));
    double C=sqr(s.x-c.o.x)+sqr(s.y-c.o.y)-sqr(c.r);
    double delta=sqr(B)-4*A*C;
    delta=fabs(delta);
    double k=(-B+sqrt(delta))/(2*A);
    p=s+vec*k;
}
double get_angle(Point a)
{
    return atan2(a.y,a.x);
}
double cmp(node a,node b)
{
    if (dlcmp(a.s-b.s)==0)
        return dlcmp(a.e-b.e)<0;
    else
        return dlcmp(a.s-b.s)<0;
}
int main()
{
    int n,p,x,y,r,i,j;
    double ans,sum,cur;
    node u,v;
    Point s1,e1,s2,e2,vec,p1,p2;
    while (scanf("%d%d%d%d%d",&n,&p,&x,&y,&r),n||p||x||y||r)
    {
        purple.o=Point(0,0);
        purple.r=(double)p;
        red.o.x=(double)x;
        red.o.y=(double)y;
        red.r=(double)r;
        arc.clear();
        for (i=0;i<n;i++)
            scanf("%lf%lf%lf",&c[i].o.x,&c[i].o.y,&c[i].r);
        for (i=0;i<n;i++)
        {
            get_InCommonTangent(red,c[i],s1,e1,s2,e2);
            if (s1==e1)
            {
                vec=c[i].o-red.o;
                e1=s1+vec.rotate(PI/2);
                e2=s2+vec.rotate(-PI/2);
            }
            inter_circle_ray(purple,s1,e1,p1);
            inter_circle_ray(purple,s2,e2,p2);
            u.s=get_angle(p1);
            u.e=get_angle(p2);
            if (u.s>u.e)
            {
                arc.push_back(node(u.s,PI));
                arc.push_back(node(-PI,u.e));
            }
            else
                arc.push_back(u);
        }
        sort(arc.begin(),arc.end(),cmp);
        sum=arc[0].e-arc[0].s;
        cur=arc[0].e;
        for (i=1;i<arc.size();i++)
        {
            if (dlcmp(arc[i].e-cur)<=0)
                continue;
            if (dlcmp(arc[i].s-cur)>0)
                sum+=arc[i].e-arc[i].s;
            else
                sum+=arc[i].e-cur;
            cur=arc[i].e;
        }
        ans=(2*PI-sum)/(2*PI);
        if (ans<0)
            ans=0;
        printf("%.4f\n",ans);
    }
    return 0;
}
