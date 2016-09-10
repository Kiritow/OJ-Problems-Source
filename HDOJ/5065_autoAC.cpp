#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int A,B,y;
double ans=0;
double inline f(double x)
{
   return A*x*x-(B*sin(x)+y);
}
double inline absf(double x)
{
    if(f(x)<0)return -f(x);
    return f(x);
}
bool findans(double l,double r)         
{
    if(f(l)*f(r)>0)return 0;
    while(r-l>0.00000001)      
    {
        double mid1=l+(r-l)/3,mid2=r-(r-l)/3;
        if(absf(mid1)<=absf(mid2))
            r=mid2;
        else
           l=mid1;
    }
    ans=l;
    return 1;
}
int main()
{
   int T;
   scanf("%d",&T);
   while(T--)
   {
      scanf("%d%d%d",&A,&B,&y);
      bool marks=0;ans=0;
      for(double x=0;x<50;x=x+0.3)
      {
          if(findans(x,x+0.3))
          {
              marks=1;break;
          }
      }
      if(marks)
          printf("%.5lf\n",ans);
      else
          printf("error\n");
   }
   return 0;
}
