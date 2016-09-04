#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define MAX 1<<30
using namespace std;
const double eps=1e-8;
typedef long long ll;
int main()
{
    typedef struct
    {
    double x;
    double y;
    double z;
    } plus; 
    plus r[100],xa[100],p[100];
   int t,i,j,k,ca=0;
   double temp[6],pp[100];
   plus o,v,m,f;
   scanf("%d",&t);
   while(t--)
   {
    scanf("%lf%lf%lf",&o.x,&o.y,&o.z);
    scanf("%lf%lf%lf",&v.x,&v.y,&v.z);
    printf("Case %d: ",++ca);
    for(i=0;i<8;i++)
     scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
    m.x=p[4].x-p[0].x;
    m.y=p[4].y-p[0].y;
    m.z=p[4].z-p[0].z; 
    if(m.x*v.x+m.y*v.y+m.z*v.z<=eps)
     {
      printf("Intelligent Larrionda!!!\n");
      continue;
     } 
    temp[0] =( (p[0].x-o.x)*m.x+(p[0].y-o.y)*m.y+(p[0].z-o.z)*m.z )/(m.x*v.x+m.y*v.y+m.z*v.z);
    temp[1] =( (p[4].x-o.x)*m.x+(p[4].y-o.y)*m.y+(p[4].z-o.z)*m.z )/(m.x*v.x+m.y*v.y+m.z*v.z);
    if(temp[0]<=eps&&temp[1]<=eps)
     {
      printf("Intelligent Larrionda!!!\n");
      continue;
     }
    f.x = o.x + temp[0]*v.x;
    f.y = o.y + temp[0]*v.y;
    f.z = o.z + temp[0]*v.z;
    for(i=0;i<4;i++)
    {
     r[i].x = p[i].x - f.x;
     r[i].y = p[i].y - f.y;
     r[i].z = p[i].z - f.z;
    }
    for(i=0;i<3;i++)
    {
     xa[i].x= r[i+1].z*r[i].y-r[i+1].y*r[i].z;
     xa[i].y= r[i+1].x*r[i].z-r[i+1].z*r[i].x;
     xa[i].z= r[i+1].y*r[i].x-r[i+1].x*r[i].y;
    }
    xa[3].x=-( r[3].z*r[0].y-r[3].y*r[0].z);
    xa[3].y=-( r[3].x*r[0].z-r[3].z*r[0].x);
    xa[3].z=-( r[3].y*r[0].x-r[3].x*r[0].y);
    for(i=0;i<3;i++)
     {
      if(xa[i].x*xa[i+1].x+xa[i].y*xa[i+1].y+xa[i].z*xa[i+1].z>0);
      else
       {printf("Intelligent Larrionda!!!\n");break;}
     }
     if(i==3)
      printf("Stupid Larrionda!!!\n");
   }
   return 0;
}
