#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define PR 1e-8
#define N 50015
struct TPoint
{
    double x,y;
    TPoint(){}
    TPoint(double _x,double _y):x(_x),y(_y){}
    TPoint operator-(const TPoint p) {return TPoint(x-p.x,y-p.y);}
}ply[N];
int n;
double MAX(double a,double b) {return a>b?a:b;}
double dist(TPoint a,TPoint b)
{
    TPoint c(b-a);
    return sqrt(c.x*c.x+c.y*c.y);
}
double cross(TPoint a,TPoint b,TPoint c)
{
    TPoint s(b-a),t(c-a);
    return s.x*t.y-s.y*t.x;
}
int dblcmp(double a)
{
    if(fabs(a)<PR) return 0;
    return a>0?1:-1;
}
bool cmpx(TPoint a,TPoint b) 
{
    if(fabs(a.x-b.x)<PR) return a.y<b.y;
    return a.x<b.x;
}
bool cmp(TPoint a,TPoint b)
{
    int d1=dblcmp(cross(ply[0],a,b));
    return d1>0||(d1==0&&dist(ply[0],a)<dist(ply[0],b));
}
double diss(TPoint a,TPoint b)
{
    return dist(a,b)*dist(a,b);
}
int main()
{
    while(~scanf("%d",&n))
    {
        int i,top=2,j,p,q,r;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&ply[i].x,&ply[i].y);
        sort(ply,ply+n,cmpx);
        sort(ply+1,ply+n,cmp);
        for(i=2;i<n;i++)
        {
            while(top>1&&(dblcmp(cross(ply[top-2],ply[i],ply[top-1])))>=0) top--;
            ply[top++]=ply[i];
        }
        double max1=-1e20,tmp;
        n=top; ply[n]=ply[0]; ply[n+1]=ply[1]; ply[n+2]=ply[2];
        p=0; q=1; r=2;
        while(1)
        {
            int pp=p,qq=q,rr=r;
            while(cross(ply[p],ply[q],ply[r+1])-(tmp=cross(ply[p],ply[q],ply[r]))>PR)
                r=(r+1)%n;
            max1=MAX(max1,fabs(tmp)*0.5);
            while(cross(ply[p],ply[q+1],ply[r])-(tmp=cross(ply[p],ply[q],ply[r]))>PR)
                q=(q+1)%n;
            max1=MAX(max1,fabs(tmp)*0.5);
            while(cross(ply[p+1],ply[q],ply[r])-(tmp=cross(ply[p],ply[q],ply[r]))>PR)
                p=(p+1)%n;
            max1=MAX(max1,fabs(tmp)*0.5);
            if(pp==p&&qq==q&&rr==r) r=(r+1)%n;
            if(r==0) break;
        }
        if(n<3) max1=0;
        printf("%.2lf\n",max1);
    }
    return 0;
}
