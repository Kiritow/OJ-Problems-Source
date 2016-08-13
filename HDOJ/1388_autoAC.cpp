#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
struct Tile
{
int x1,y1;
int x2,y2;
int s;
}p[101];
int main()
{
int n,i,j,k;
int t1,t2,t3;
int a,b,sum,m,c1,c2,t;
while(scanf("%d",&n)!=EOF)
{ 
 while(n--)
 {
t1=t2=t3=0;
sum=0;
scanf("%d%d",&a,&b);
scanf("%d",&m);
  t=(a>b? a:b);
  for(i=0;i<m;i++)
  {
  scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
  c1=abs(p[i].x1-p[i].x2);
  c2=abs(p[i].y1-p[i].y2);
  p[i].s=c1*c2;
  sum+=p[i].s;
  if(p[i].x1<0||p[i].x2<0||p[i].y1 <0||p[i].y2 <0)
  t2=1;
  if(p[i].x1>t||p[i].x2>t||p[i].y1>t||p[i].y2>t)
  t2=1;
  }
  if(sum<a*b)
  t3=1;
   for(i=0;i<m;i++)
   { if(t1)break;
   for(j=i+1;j<m;j++)
   {
   if((p[j].x1>=p[i].x2)||(p[j].x2<=p[i].x1)||(p[j].y1>=p[i].y2)||(p[j].y2<=p[i].y1))
     continue;
     else
     {t1=1;
     break;
     }
    }
   }
if(t1)
 printf("NONDISJOINT\n");
else if(t2)
 printf("NONCONTAINED\n");
else if(t3)
 printf("NONCOVERING\n");
else
printf("OK\n");
 }
}
return 0;
}
