#include<stdio.h>
#include<math.h>
#include<algorithm>
#define eps 1e-6
using namespace std;
struct point
{
    int x,y;
}a[10],v[10],s;
double t,ans;
int N,sv,i,p[10],T[3],js=1;
double crosstime(double x0,double y0,double v0,double x1,double y1,double vx,double vy)
{ 
    double a,b,c,t;
    a=vx*vx+vy*vy-v0*v0;
    b=2*(vx*(x1-x0)+vy*(y1-y0));
    c=(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0);
    if(a<eps&&a>-eps) return -c/b;
    if(a<eps) {a=-a;b=-b;c=-c;}
    return (-b+sqrt(b*b-4*a*c))/(2*a);
}
double back(double x0,double y0,double x1,double y1,double sv)
{
    return sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0))/sv;
}
void trs(double ans,int T[3])
{
    T[0]=(int)ans;
    ans-=T[0];
    T[1]=(int)(ans*=60.0);ans-=T[1];
    T[2]=(int)(ans*60.0+0.9999999);
    if(T[2]==60) {T[2]=0;T[1]++;}
    if(T[1]==60) {T[1]=0;T[0]++;}
}
int main()
{
    while(scanf("%d",&N),N)
    {
        for(i=0;i<N;i++) scanf("%d%d%d%d",&a[i].x,&a[i].y,&v[i].x,&v[i].y);
        scanf("%d%d%d",&s.x,&s.y,&sv);
        for(i=0;i<=N;i++) p[i]=i;
        ans=1e9;
        do
        {
            t=crosstime(s.x*1.0,s.y*1.0,sv*1.0,a[p[0]].x,a[p[0]].y,v[p[0]].x,v[p[0]].y)+1.0;
            for(i=1;i<N;i++)
                t+=1.0+crosstime(a[p[i-1]].x*1.0+t*v[p[i-1]].x,a[p[i-1]].y*1.0+t*v[p[i-1]].y,sv*1.0,a[p[i]].x*1.0+t*v[p[i]].x,a[p[i]].y*1.0+t*v[p[i]].y,v[p[i]].x*1.0,v[p[i]].y*1.0);
            t+=back(a[p[N-1]].x*1.0+t*v[p[N-1]].x,a[p[N-1]].y*1.0+t*v[p[N-1]].y,s.x,s.y,sv);
            if(t<ans) ans=t;
        }
        while(next_permutation(p,p+N));
        trs(ans,T);
        printf("Case %d: %d hour(s) %d minute(s) %d second(s)\n",js++,T[0],T[1],T[2]);
    }
    return 0;
}
