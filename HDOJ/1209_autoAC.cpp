#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<set>
#include<map>
#include<string>
#include<cstdlib>
using namespace std;
struct node
{
    int x,y;
    double z;
};
node a[10];
bool cmp(node a,node b)
{
    if(a.z==b.z)
    {
        if(a.x==b.x)return a.y<b.y;
        return a.x<b.x;
    }
        return a.z<b.z;
}
int main()
{
    int c,d,n,i,j,k,t,x,y;
    double z;
    while(~scanf("%d",&n))
    {
      while(n--)
      {
          for(i=0;i<5;i++)
          {
             scanf("%d:%d",&x,&y);
              a[i].y=y;a[i].x=x;
              if(x>=12)x%=12;
              z=fabs(1.0*x*30+1.0*y/2-1.0*6*y);
              a[i].z=min(360-z,z);
          }
          sort(a,a+5,cmp);
          printf("%02d:%02d\n",a[2].x,a[2].y);
      }
    }
    return 0;
}
