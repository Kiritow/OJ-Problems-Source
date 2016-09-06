#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#define eps 1e-6
#define INF 0x1f1f1f1f
#define PI acos(-1.0)
#define ll __int64
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
using namespace std;
struct Point
{
   double x,y;
}pp[22],p1,p2,p3;
Point oa,ob; 
double dis(Point a) 
{
   return sqrt(a.x*a.x+a.y*a.y);
}
double dmult(Point a,Point b)
{
   return a.x*b.x+a.y*b.y;
}
double xmult(Point a,Point b) 
{
   return a.x*b.y-a.y*b.x;
}
int main()
{
   int t,d,m,s,be,aa;
   double an;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%d%d%d%d%lf",&d,&m,&s,&be,&an);
      an=(an/180.0)*PI;
      for(int i=1;i<=m;i++)
         scanf("%d%lf%lf",&aa,&pp[i].x,&pp[i].y);
      int la=be;
      oa.x=cos(an),oa.y=sin(an);
      ob.x=-oa.x,ob.y=-oa.y;
      int flag,find;
      double Max;
      printf("%d ",d);
      while(s--)
      {
         Max=-120;
         for(int i=1;i<=m;i++)
         {
            if(i==be||i==la) 
               continue;
            Point tmp;
            tmp.x=pp[i].x-pp[be].x;
            tmp.y=pp[i].y-pp[be].y;
            double tt=xmult(oa,tmp);
            if(tt>0) 
            {
               double t=dmult(oa,tmp)/dis(oa)/dis(tmp);
               if(t>Max) 
               {
                  Max=t;
                  flag=1;
                  find=i;
               }
            }
            else if(tt<0)
            {
               double t=dmult(ob,tmp)/dis(ob)/dis(tmp);
               if(t>Max)
               {
                  Max=t;flag=2;find=i;
               }
            }
         }
         printf("%d",find);
         la=be;
         be=find;
         if(s)
            putchar(' ');
         else
            putchar('\n');
         if(flag==1) 
         {
            ob.x=pp[la].x-pp[be].x; 
            ob.y=pp[la].y-pp[be].y;
            oa.x=-ob.x;  
            oa.y=-ob.y;
         }
         else
         {
            oa.x=pp[la].x-pp[be].x;
            oa.y=pp[la].y-pp[be].y;
            ob.x=-oa.x;
            ob.y=-oa.y;
         }
      }
   }
   return 0;
}
