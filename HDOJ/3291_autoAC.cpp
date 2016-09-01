#include <algorithm>
#include <cmath>
using namespace std;
const double eps=1e-9;
const double maxl=1e10;
const double pi=3.1415926535897932384626433832795;
const int maxv=20;
template <class T>
T Max(T a,T b){return a>b?a:b;}
template <class T>
T Min(T a,T b){return a<b?a:b;}
double sqr(double a){return a*a;}
int sgn(double a){if (a>eps) return 1;if (a<-eps) return -1;return 0;}
struct Point
{
double x,y;
Point(){};
Point(double dx,double dy){x=dx;y=dy;}
inline int init(){ return scanf("%lf%lf",&x,&y); }
};
double dis(Point a,Point b);
Point operator -(Point a,Point b){Point c;c.x=a.x-b.x;c.y=a.y-b.y;return c;}
Point operator +(Point a,Point b){Point c;c.x=a.x+b.x;c.y=a.y+b.y;return c;}
Point operator *(Point a,double d){Point c;c.x=a.x*d;c.y=a.y*d;return c;}
Point operator *(double d,Point a){Point c;c.x=a.x*d;c.y=a.y*d;return c;}
Point operator /(Point a,double d){Point c;c.x=a.x/d;c.y=a.y/d;return c;}
double operator *(Point a,Point b){return a.x*b.x+a.y*b.y;}
int operator ==(Point a,Point b){return dis(a,b)<eps;}
int operator !=(Point a,Point b){return dis(a,b)>=eps;}
bool operator < (const Point &l, const Point &r){return sgn(l.y-r.y)<0 ||( sgn(l.y-r.y)==0 && sgn(l.x-r.x)<0 );}
double dis(Point a,Point b){a=a-b;return sqrt(sqr(a.x)+sqr(a.y));}
double crossmuti(Point a,Point b){return a.x*b.y-a.y*b.x;}
struct LineSegment
{
Point pt1,pt2;
LineSegment(){};
LineSegment(Point p1,Point p2){pt1=p1;pt2=p2;}
};
struct Polygon
{
Point vertex[maxv];
int numv;
Polygon(){numv=0;}
Polygon(Point *s,int num){numv=num;memcpy(vertex,s,num*sizeof(Point));}
Point &operator [](int k){return vertex[k];}
};
struct Line
{
double a,b,c;   
Line(){};
Line(double p,double q,double r){a=p;b=q;c=r;}
Line(Point p,Point q) 
{
   a=q.y-p.y;
   b=p.x-q.x;
   c=p.y*q.x-p.x*q.y;
   double one=sqrt(sqr(a)+sqr(b));
   if (one>0) {a/=one;b/=one;c/=one;}
}  
Line(LineSegment l)
{
   Line ls(l.pt1,l.pt2);
   a=ls.a;b=ls.b;c=ls.c;
}
double func(Point &p){return a*p.x+b*p.y+c;}
};
int ondiffside(Line l,Point a,Point b)
{
return sgn(l.func(a))*sgn(l.func(b))<0;
}
int PntonSeg(LineSegment ls,Point p)
{
Line l(ls.pt1,ls.pt2);
if (ls.pt1==p||ls.pt2==p) return 1;
if (sgn(l.func(p))==0&&((ls.pt1<p&&p<ls.pt2)||(ls.pt2<p&&p<ls.pt1))) return 1;
return 0;
}
int Intersect(LineSegment L1, LineSegment L2)
{
if (ondiffside(L1,L2.pt1,L2.pt2)&&ondiffside(L2,L1.pt1,L1.pt2))
   return 1;
if (PntonSeg(L1,L2.pt1)||PntonSeg(L1,L2.pt2)||PntonSeg(L2,L1.pt1)||PntonSeg(L2,L1.pt2))
   return -1;
return 0;
}
int intersection(Line p,Line q,Point &s)
{
if (sgn(p.a*q.b-p.b*q.a)==0) return 0;
s.y=(p.a*q.c-p.c*q.a)/(q.a*p.b-p.a*q.b);
s.x=(p.b*q.c-p.c*q.b)/(p.a*q.b-p.b*q.a);
return 1;
}
int poly_lineSg_cross(Polygon &p,LineSegment l,Point &s)
{
int i;
int n=p.numv;
if (n==0) return 0;
p[n]=p[0];
Point t;
int find=0;
for (i=0;i<n;i++)
   if (Intersect(LineSegment(p[i],p[i+1]),l))
   {
    if (intersection(Line(p[i],p[i+1]),Line(l.pt1,l.pt2),t)==0)
     t=p[i];
    if (find==0||dis(Point(0,0),t)<dis(Point(0,0),s))
     s=t;
    find=1;
   }
return find;
}
Polygon p[50];
int w[50];
int n,m;
int cat[50];
Point ins[50];
void work()
{
int i,j,k;
int tot=0;
for (i=0;i<n;i++)
{
   scanf("%d%d",&p[i].numv,w+i);
   for (j=0;j<p[i].numv;j++) p[i][j].init();
}
scanf("%d",&m);
while (m--)
{
   scanf("%d",&k);
   LineSegment l;
   l.pt1=Point(0,0);
   l.pt2=maxl*Point(cos((double)-k/180.0*pi),sin((double)-k/180.0*pi));
   for (i=0;i<n;i++)
    cat[i]=poly_lineSg_cross(p[i],l,ins[i]);
   int t=-1;
   for (i=0;i<n;i++)
    if (cat[i])
     if (t==-1||dis(Point(0,0),ins[i])<dis(Point(0,0),ins[t]))
      t=i;
   if (t>=0)
   {
    p[t].numv=0;
    tot+=w[t];
    w[t]=0;
   }
}
printf("%d\n",tot);
}
int main()
{
while (scanf("%d",&n)!=EOF)
   work();
return 0;
}
