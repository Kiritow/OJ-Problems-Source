#include <stdlib.h>
#include<iostream>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;
struct point{int x,y;};
point a[100],b[100];
int xmult(point p1,point p2,point p0){
 return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
point p1,p2;
int graham_cp(const void* a,const void* b){
 int ret=xmult(*((point*)a),*((point*)b),p1);
 return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
 int i,k=0;
 for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
  if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
   p1=p[k=i];
 p2.x/=n,p2.y/=n;
 p[k]=p[0],p[0]=p1;
 qsort(p+1,n-1,sizeof(point),graham_cp);
 for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
  for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}
int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
 point* temp=new point[n];
 int s,i;
 _graham(n,p,s,temp);
 for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
  if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
   convex[n++]=temp[i];
 delete []temp;
 return n;
}
int main()
{
    int t,ii,n,i,maxx,maxy,min1,max1,m,miny,g;
    bool d;
    scanf("%d",&t);
    for(ii=1;ii<=t;ii++)
    {
        scanf("%d%d",&m,&n);
        for(i=0;i<n;i++)
          scanf("%d%d",&a[i].x,&a[i].y);
       d=true;
        for(i=2;i<n;i++)
          if (xmult(a[0],a[i],a[1])!=0) {d=false;break;}
        if (d)
        {
            maxx=1000000000;
            maxy=-1000000000;
            for(i=0;i<n;i++)
              if ((a[i].y>maxy)||(a[i].y==maxy&&a[i].x<maxx))
              {
                    max1=i;
                    maxx=a[i].x;
                    maxy=a[i].y;
                }
            miny=1000000000;
            for(i=0;i<n;i++)
              if (a[i].y<miny)
              {
                    miny=a[i].y;
                    min1=i;
                }
            printf("%d 2\n%d %d\n%d %d\n",ii,maxx,maxy,a[min1].x,a[min1].y);
            continue;
        }
        g=graham(n,a,b,0);
        maxx=1000000000;
        maxy=-1000000000;
        for(i=0;i<g;i++)
          if ((b[i].y>maxy)||(b[i].y==maxy&&b[i].x<maxx))
          {
                    max1=i;
                    maxx=b[i].x;
                    maxy=b[i].y;
            }
        printf("%d %d\n",ii,g);
        for(i=0;i<g;i++)
          printf("%d %d\n",b[(i+max1)%g].x,b[(i+max1)%g].y);
    }
    return 0;
}
