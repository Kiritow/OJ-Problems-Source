#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
double r,w,t;
char buf[500];
const double eps = 1e-8;
const double pi = acos(-1.0);
struct Point
{
 double x,y;
 Point() {}
 Point(double _x,double _y)
 {
 x = _x;
 y = _y;
 }
 Point(Point _a,Point _b)
 {
 x = _b.x-_a.x;
 y = _b.y-_a.y;
 }
 void transXY(double B)
 {
 double tx = x,ty = y;
 x = tx*cos(B) - ty*sin(B);
 y = tx*sin(B) + ty*cos(B);
 }
 double Length()
 {
 return sqrt(eps+x*x+y*y);
 }
};
int cmp(double a,double b)
{
 if (fabs(a-b) < eps) return 0;
 if (a < b) return -1;
 return 1;
}
double sqr(double a)
{
 return a*a;
}
Point p[4],res[4];
int main()
{
 int ft = 0;
 while (true)
 {
 gets(buf);
 if (strlen(buf) == 1) break;
 sscanf(buf,"%lf%lf%lf%lf%lf%lf%lf%lf",&p[0].x,&p[0].y,&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y);
 scanf("%lf%lf%lf",&r,&t,&w);
 gets(buf);
 w = pi*w/180;
 double theta = w*t;
 theta = theta-2*pi*floor(theta/(2*pi));
 double l = r*w*t;
 double totl = 0;
 Point tv;
 for (int i = 0; i < 4; i++)
 {
 tv = Point(p[i],p[(i+1)%4]);
 totl += tv.Length()-2*r;
 }
 res[0] = p[0];
 for (int i = 1;i < 4;i++)
 {
 tv = Point(p[i-1],p[i]);
 tv.transXY(-theta);
 res[i] = Point(res[i-1].x+tv.x,res[i-1].y+tv.y);
 }
 l = l-totl*floor(l/totl);
 double pre = 0.0,len;
 Point prep,nowp,xp;
 tv = Point(p[0],p[1]);
 len = tv.Length();
 xp = Point(p[0].x+tv.x*r/len,p[0].y+tv.y*r/len);
 prep = Point(xp.x+tv.y*r/len,xp.y-tv.x*r/len);
 for (int i = 0; i < 4; i++)
 {
 tv = Point(res[i],res[(i+1)%4]);
 len = tv.Length();
 if (cmp(pre+len-2*r,l) >= 0)
 {
 l -= pre;
 l += r;
 xp = Point(res[i].x+tv.x*l/len,res[i].y+tv.y*l/len);
 nowp = Point(xp.x+tv.y*r/len,xp.y-tv.x*r/len);
 tv = Point(nowp,prep);
 for (int j = 0;j < 4;j++)
 res[j] = Point(res[j].x+tv.x,res[j].y+tv.y);
 break;
 }
 pre += len-2*r;
 }
 ft++;
 printf("Case %d:",ft);
 for (int i = 0;i < 4;i++)
 printf(" %.3f %.3f",res[i].x,res[i].y);
 printf("\n");
 }
 return 0;
}
