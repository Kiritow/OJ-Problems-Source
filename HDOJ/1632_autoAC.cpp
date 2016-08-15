#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define N 155
#define eps 1e-8
struct TPoint
{
 double x,y;
}s;
struct TPolygon
{
 int n;
 TPoint p[N];
}ply1,ply2,ans;
double maxdist;
int dblcmp(double a) {return a<-eps?-1:a>eps?1:0;}
double MAX(double a,double b) {return a>b?a:b;}
double cross(TPoint a,TPoint b,TPoint c)
{
 return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
double plyarea(TPolygon res)
{
 int i;
 double area=0;
 res.p[res.n]=res.p[0];
 for(i=0;i<res.n;i++)
  area+=cross(s,res.p[i],res.p[i+1]);
 return area;
}
TPolygon cut(TPolygon res,TPoint s,TPoint e)
{
 int d1,d2,i,t;
 double s1,s2;
 TPoint a;
 TPolygon b;
 b.n=0;
 res.p[res.n]=res.p[0];
 for(i=0,t=0;i<res.n;i++)
 {
  d1=dblcmp(s1=cross(res.p[i],s,e));
  d2=dblcmp(s2=cross(res.p[i+1],s,e));
  if(d1>=0) b.p[t++]=res.p[i];
  if(d1*d2<0)
  {
   a.x=(s2*res.p[i].x-s1*res.p[i+1].x)/(s2-s1);
   a.y=(s2*res.p[i].y-s1*res.p[i+1].y)/(s2-s1);
   b.p[t++]=a;
  }
 }
 b.n=t;
 return b;
}
int main()
{
 while(scanf("%d",&ply1.n),ply1.n)
 {
  int i;
  double sumarea,area;
  for(i=0;i<ply1.n;i++) scanf("%lf%lf",&ply1.p[i].x,&ply1.p[i].y);
  s.x=0; s.y=0;
  if((dblcmp(sumarea=plyarea(ply1)))<0) reverse(ply1.p,ply1.p+ply1.n);
  ply1.p[ply1.n]=ply1.p[0];
  sumarea=fabs(sumarea);
  scanf("%d",&ply2.n);
  for(i=0;i<ply2.n;i++) scanf("%lf%lf",&ply2.p[i].x,&ply2.p[i].y);
  if((dblcmp(area=plyarea(ply2)))<0) reverse(ply2.p,ply2.p+ply2.n);
  sumarea+=fabs(area);
  ply2.p[ply2.n]=ply2.p[0];
  ans=ply1;
  for(i=0;i<ply2.n;i++)
   ans=cut(ans,ply2.p[i],ply2.p[i+1]);
  area=fabs(plyarea(ans));
  printf("%8.2lf",sumarea/2-area);
 }
 puts("");
 return 0;
}
