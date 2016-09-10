#include<iostream>
#include<math.h>
#include<cstring>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define offset 100
#define eps 1e-8
#define PI acos(-1.0)
#define MAXN 105
#define zero(x) (((x)>0? (x):-(x))<eps) 
#define _sign(x) ((x)>eps? 1:((x)<-eps? 2:0))
struct point
{
    double x;
    double y;
    point(const double &x = 0, const double &y = 0):x(x), y(y) {}
    void in()
    {
        scanf("%lf %lf", &x, &y);
    }
    void out()const
    {
        printf("%.2f %.2f\n",x, y);
    }
};
double xmult(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
double dis(point a, point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) ) ;
}
point p1,p2;
int graham_cp(const void* a,const void* b)
{
    double ret=xmult(*((point*)a),*((point*)b),p1);
    return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch)
{
    int i,k=0;
    for (p1=p2=p[0],i=1; i<n; p2.x+=p[i].x,p2.y+=p[i].y,i++)
        if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
            p1=p[k=i];
    p2.x/=n,p2.y/=n;
    p[k]=p[0],p[0]=p1;
    qsort(p+1,n-1,sizeof(point),graham_cp);
    for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3; i<n; ch[s++]=p[i++])
        for (; s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps; s--);
}
int graham(int n,point* p,point* convex,int maxsize=1,int dir=1)  
{
    point* temp=new point[n];
    int s,i;
    _graham(n,p,s,temp);
    for (convex[0]=temp[0],n=1,i=(dir?1:(s-1)); dir?(i<s):i; i+=(dir?1:-1))
        if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
            convex[n++]=temp[i];
    delete []temp;
    return n;
}
int main()
{
    int T, N, D, cas = 1;
    scanf("%d",&T);
    while(T--)
    {
        point P[MAXN];
        point c[MAXN];
        scanf("%d%d",&N,&D);
        for(int i = 0; i < N; i ++)
            P[i].in();
        double ans = 0 ;
        if(N>2)
        {
            int num = graham(N,P,c);
            for(int i = 0; i < num-1; i ++)
            {
                ans+=dis(c[i],c[i+1]);
            }
            ans+=dis(c[0],c[num-1]);
        }
        else ans = dis(P[0],P[1])*2;
        printf("Case #%d: %.4lf\n",cas++,ans/(PI*D));
    }
}
