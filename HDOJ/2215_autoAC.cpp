#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct aa
{
   int x,y;
}a1[105],a2[105];
double maxx(double x,double y)
{
  return x>y?x:y;
}
double abss(double x)
{
   return x>0?x:-x;
}
double x_y(aa a,aa b)
{
   return sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y)*1.0);
}
double sss(aa A,aa B,aa C)
{
    return (B.x - A.x)*(C.y - B.y) - (C.x - B.x)*(B.y - A.y);
}
bool camp(aa a,aa b)
{
  return a.y<b.y||a.y==b.y&&a.x<b.x;
}
bool fx(aa A,aa B,aa C)
{
  return (A.x - B.x)*(C.y - B.y) > (C.x - B.x)*(A.y - B.y);
}
int main ()
{
   int i,j,k,n,t,tt;
   double a,b,c,r,s,maxr;
   while(~scanf("%d",&n)&&n)
   {
      for(i=1;i<=n;i++)
      scanf("%d%d",&a1[i].x,&a1[i].y);
      if(n==1)
      {
        printf("0.50\n");
        continue;
      }
      if(n==2)
      {
         printf("%.2f\n",x_y(a1[1],a1[2])/2+0.5);
         continue;
      }
      sort(a1+1,a1+n+1,camp);
      a2[1]=a1[1];
      a2[2]=a1[2];
      for(t=2,i=3;i<=n;i++)
      {
           while(t!=1&&!fx(a2[t],a2[t-1],a1[i]))
    t--;
    a2[++t]=a1[i];
      }
      a2[t+1]=a1[n-1];
      for(tt=t+1,i=n-2;i>=1;i--)
      {
         while(t!=tt&&!fx(a2[tt],a2[tt-1],a1[i]))
    tt--;
    a2[++tt]=a1[i];
      }
      for(maxr=0,i=1;i<tt;i++)
      for(j=i+1;j<tt;j++)
      for(k=j+1;k<tt;k++)
      {
         a=x_y(a2[i],a2[j]);
         b=x_y(a2[i],a2[k]);
         c=x_y(a2[j],a2[k]);
         if(a*a+b*b<c*c||a*a+c*c<b*b||b*b+c*c<a*a)
         r=max(max(a,b),c)/2.0;
         else
         {
           s=abss(sss(a2[i],a2[j],a2[k]))/2.0;
           r=a*b*c/4.0/s;
         }
         maxr=max(r,maxr);
       }
      printf("%.2f\n",maxr+0.5);
   }
   return 0;
}
