#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int M=50005;
typedef struct Point
{
double x;
double y;
}Point;
Point p[M];
Point pp[M];
bool bo[M];
int stack[M];
double dis(Point A,Point B)
{
return sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
}
bool cmp(Point a,Point b)
{
if(a.x<b.x)
    return true;
if(a.x>b.x)
    return false;
if(a.y<b.y)
    return true;
return false;
}
double Xdet(Point A,Point B,Point C)
{
double x1,x2,y1,y2;
x1=B.x-A.x;
y1=B.y-A.y;
x2=C.x-A.x;
y2=C.y-A.y;
return x1*y2-x2*y1;
}
void Gram_Scan(Point *p,int &n)
{
int i,t;
sort(p+1,p+1+n,cmp);
for(t=0,i=1;i<=n;i++)
{
    if(i>1&&p[i].x==p[i-1].x&&p[i].y==p[i-1].y)
      continue;
    p[++t]=p[i];
}
n=t;
t=0;
memset(bo+1,true,n*sizeof(bo[0]));
if(n>0)
{
    stack[++t]=1;
    bo[stack[t]]=false;
}
if(n>1)
{
    stack[++t]=2;
    bo[stack[t]]=false;
}
if(n>2)
{
    for(i=3;i<n;i++)
      if(bo[i]&&Xdet(p[stack[t-1]],p[stack[t]],p[i])>=0)
      {
        stack[++t]=i;
        bo[i]=false;
      }
      else
      {
        while(t>=2&&Xdet(p[stack[t-1]],p[stack[t]],p[i])<0)
        {
          bo[stack[t]]=true;
          t--;
        }
        stack[++t]=i;
        bo[stack[t]]=false;
      }
   for(i=n;i>=1;i--)
     if(bo[i]&&Xdet(p[stack[t-1]],p[stack[t]],p[i])>=0)
     {
       stack[++t]=i;
       bo[i]=false;
     }
     else
     {
       while(t>=2&&Xdet(p[stack[t-1]],p[stack[t]],p[i])<0)
       {
         bo[stack[t]]=true;
         t--;
       }
       stack[++t]=i;
       bo[stack[t]]=false;
     }
     t--;
}
for(i=1;i<=t;i++)
    pp[i]=p[stack[i]];
memcpy(p+1,pp+1,t*sizeof(Point));
n=t;
}
int n,o[M],on;
int dcmp(double a,double b)
{
    if(a-b<1e-10&&b-a<1e-10)
        return 0;
    if(a>b)
        return 1;
    return -1;
}
bool cmp1(const Point &a,Point &b)
{
    return dcmp(a.x,b.x)<0;
}
bool cmp2(const int&a,const int&b)
{
    return dcmp(p[a].y,p[b].y)<0;
}
double min(double a,double b)
{
    return a<b?a:b;
}
double search(int s,int t)
{
    int mid=(s+t)/2,i,j;
    double ret=1e300;
    if(s>=t)
        return ret;
    for(i=mid;i>=s&&!dcmp(p[i].x,p[mid].x);i--);ret=search(s,i);
    for(i=mid;i<=t&&!dcmp(p[i].x,p[mid].x);i++);ret=min(ret,search(i,t));on=0;
    for(i=mid;i>=s&&dcmp(p[mid].x-p[i].x,ret)<=0;i--)o[++on]=i;
    for(i=mid+1;i<=t&&dcmp(p[i].x-p[mid].x,ret)<=0;i++)o[++on]=i;
    sort(o+1,o+on+1,cmp2);
    for(i=1;i<=on;i++)
        for(j=1;j<=10;j++)
            if(i+j<=on)
                ret=min(ret,dis(p[o[i]],p[o[i+j]]));
    return ret;
}
int main()
{
    int n,i,count=0,j;
    double shortdis,longdis;
    while(scanf("%d",&n),n)
    {
        for(i=1;i<=n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p+1,p+n+1,cmp1);
        shortdis=search(1,n);
        longdis=0;
        Gram_Scan(p,n);
        for(i=1;i<=n-1;i++)
            for(j=i+1;j<=n;j++)
                if(dis(p[i],p[j])>longdis)
                    longdis=dis(p[i],p[j]);
        printf("Case %d:\n",++count);
        printf("Distance of the nearest couple is %.3lf\n",shortdis);
        printf("Distance of the most distant couple is %.3lf\n\n",longdis);
    }
    return 0;
}
