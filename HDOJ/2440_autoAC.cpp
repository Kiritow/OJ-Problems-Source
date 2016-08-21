#include<cstdio>
#include<cstring>
#include<iostream>
#include<utility>
#include<string>
#include<set>
#include<vector>
#include<stack>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<map>
#include<cmath>
using namespace std;
#define FOR(i,a,b) for(int i(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define CL(a,b) memset(a,b,sizeof(a))
const int M=200; 
const int N=2000;
const double inf=1e250;
const double eps=1e-20;
const double pi=acos(-1.0);
struct point
{
    double x,y;
    bool operator < (const point a)const
    {
        if(y==a.y)
            return x<a.x;
        return y<a.y;
    }
}p[M],stac[M];
int n,top;
int xmult(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}
int cross(point p0,point p1,point p2)
{
    double x1=p1.x-p0.x,y1=p1.y-p0.y;
    double x2=p2.x-p0.x,y2=p2.y-p0.y;
    return xmult(x1,y1,x2,y2);
}
void covex_hull()
{
    sort(p,p+n);
    stac[0]=p[0];
    stac[1]=p[1];
    top=1;
    for(int i=2;i<n;i++)
    {
        while(top>0 && cross(stac[top],p[i],stac[top-1])<=0)
            top--;
        stac[++top]=p[i];
    }
    int temp=top;
    for(int i=n-2;i>=0;i--)
    {
        while(top>temp && cross(stac[top],p[i],stac[top-1])<=0)
            top--;
        stac[++top]=p[i];
    }
    --top;
}
point getpoint(double x,double y)
{
    point temp;
    temp.x=x;temp.y=y;
    return temp;
}
double dist(point a,point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)*1.0+(b.y-a.y)*(b.y-a.y));
}
double alldis(point a)
{
    double dis=0;
    for(int i=0;i<=top;i++)
    {
        dis+=dist(a,stac[i]);
    }
    return dis;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        covex_hull();
        point pp=stac[0];
        double ans=inf,step=100;
        ans=alldis(pp);
        while(step>0.2)
        {
            bool flag=true;
            while(flag)
            {
                flag=false;
                point qq=getpoint(pp.x,pp.y+step),tt=pp;
                double temp=alldis(qq);
                if(temp<ans)
                {
                    ans=temp;
                    tt=qq;
                    flag=true;
                }
                qq=getpoint(pp.x,pp.y-step);
                temp=alldis(qq);
                if(temp<ans)
                {
                    ans=temp;
                    tt=qq;
                    flag=true;
                }
                qq=getpoint(pp.x+step,pp.y);
                temp=alldis(qq);
                if(temp<ans)
                {
                    ans=temp;
                    tt=qq;
                    flag=true;
                }
                qq=getpoint(pp.x-step,pp.y);
                temp=alldis(qq);
                if(temp<ans)
                {
                    ans=temp;
                    tt=qq;
                    flag=true;
                }
                pp=tt;
            }
            step=step/2.0;
        }
        int dis=(int)(ans+0.5)*100/100;
        printf("%d\n",dis);
        if(T>0) puts("");
    }
    return 0;
}
