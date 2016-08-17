#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
struct circle
{
  double x,y,r;
};
double dist(circle a,circle b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
   circle a,b;
   double d,p,area,sb,sa;
  while(scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&a.r,&b.x,&b.y,&b.r)!=EOF)
  {
    d=dist(a,b);
    double rr=min(a.r,b.r);
    if(d<=abs(a.r-b.r))   
       area=acos(-1.0)*rr*rr;
    else
       if(d>=a.r+b.r)
          area=0.0;
    else{
         p=(a.r+b.r+d)/2.0;
      sa=acos((a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d));
      sb=acos((b.r*b.r+d*d-a.r*a.r)/(2.0*b.r*d));
        area=sa*a.r*a.r+sb*b.r*b.r-2*sqrt(p*(p-a.r)*(p-b.r)*(p-d));
    }
    printf("%.3lf\n",area);
  }
 return 0;
}
