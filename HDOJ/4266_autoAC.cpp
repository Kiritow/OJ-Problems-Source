#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include <iostream>
using namespace std;
#define PR 1e-9
#define N 1100
struct TPoint
{
    double x,y,z;
    TPoint(){}
    TPoint(double _x,double _y,double _z):x(_x),y(_y),z(_z){}
    TPoint operator-(const TPoint p) {return TPoint(x-p.x,y-p.y,z-p.z);}
    TPoint operator*(const TPoint p) {return TPoint(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);}
    double operator^(const TPoint p) {return x*p.x+y*p.y+z*p.z;}
};
TPoint dd;
struct fac
{
    int a,b,c;
    bool ok;
};
TPoint xmult(TPoint u,TPoint v)
{
    return TPoint(u.y*v.z-v.y*u.z,u.z*v.x-u.x*v.z,u.x*v.y-u.y*v.x);
}
double dmult(TPoint u,TPoint v)
{
    return u.x*v.x+u.y*v.y+u.z*v.z;
}
TPoint subt(TPoint u,TPoint v)
{
    return TPoint(u.x-v.x,u.y-v.y,u.z-v.z);
}
double vlen(TPoint u)
{
    return sqrt(u.x*u.x+u.y*u.y+u.z*u.z);
}
TPoint pvec(TPoint a,TPoint b,TPoint c)
{
    return xmult(subt(a,b),subt(b,c));
}
double Dis(TPoint a,TPoint b,TPoint c,TPoint d)
{
    return fabs(dmult(pvec(a,b,c),subt(d,a)))/vlen(pvec(a,b,c));
}
struct T3dhull
{
    int n;
    TPoint ply[N];
    int trianglecnt;
    fac tri[N];
    int vis[N][N];
    double dist(TPoint a){return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);}
    double area(TPoint a,TPoint b,TPoint c){return dist((b-a)*(c-a));}
    double volume(TPoint a,TPoint b,TPoint c,TPoint d){return (b-a)*(c-a)^(d-a);}
    double ptoplane(TPoint &p,fac &f)
    {
         TPoint m=ply[f.b]-ply[f.a],n=ply[f.c]-ply[f.a],t=p-ply[f.a];
         return (m*n)^t;
    }
    void deal(int p,int a,int b)
    {
        int f=vis[a][b];
        fac add;
        if(tri[f].ok)
        {
            if((ptoplane(ply[p],tri[f]))>PR) dfs(p,f);
            else
            {
                 add.a=b,add.b=a,add.c=p,add.ok=1;
                 vis[p][b]=vis[a][p]=vis[b][a]=trianglecnt;
                 tri[trianglecnt++]=add;
            }
        }
    }
    void dfs(int p,int cnt)
    {
        tri[cnt].ok=0;
        deal(p,tri[cnt].b,tri[cnt].a);
        deal(p,tri[cnt].c,tri[cnt].b);
        deal(p,tri[cnt].a,tri[cnt].c);
    }
    bool same(int s,int e)
    {
        TPoint a=ply[tri[s].a],b=ply[tri[s].b],c=ply[tri[s].c];
        return fabs(volume(a,b,c,ply[tri[e].a]))<PR
            &&fabs(volume(a,b,c,ply[tri[e].b]))<PR
            &&fabs(volume(a,b,c,ply[tri[e].c]))<PR;
    }
    void construct()
    {
        int i,j;
        trianglecnt=0;
        if(n<4) return ;
        bool tmp=true;
        for(i=1;i<n;i++)
        {
            if((dist(ply[0]-ply[i]))>PR)
            {
                swap(ply[1],ply[i]); tmp=false; break;
            }
        }
        if(tmp) return;
        tmp=true;
        for(i=2;i<n;i++)
        {
            if((dist((ply[0]-ply[1])*(ply[1]-ply[i])))>PR)
            {
                swap(ply[2],ply[i]); tmp=false; break;
            }
        }
        if(tmp) return ;
        tmp=true;
        for(i=3;i<n;i++)
        {
            if(fabs((ply[0]-ply[1])*(ply[1]-ply[2])^(ply[0]-ply[i]))>PR)
            {
                swap(ply[3],ply[i]); tmp=false; break;
            }
        }
        if(tmp) return ;
        fac add;
        for(i=0;i<4;i++)
        {
            add.a=(i+1)%4,add.b=(i+2)%4,add.c=(i+3)%4,add.ok=1;
            if((ptoplane(ply[i],add))>0) swap(add.b,add.c);
            vis[add.a][add.b]=vis[add.b][add.c]=vis[add.c][add.a]=trianglecnt;
            tri[trianglecnt++]=add;
        }
        for(i=4;i<n;i++)
        {
            for(j=0;j<trianglecnt;j++)
            {
                if(tri[j].ok&&(ptoplane(ply[i],tri[j]))>PR)
                {
                    dfs(i,j); break;
                }
            }
        }
        int cnt=trianglecnt;
        trianglecnt=0;
        for(i=0;i<cnt;i++)
        {
            if(tri[i].ok)
                tri[trianglecnt++]=tri[i];
        }
    }
    double res()
    {
        double _min=1e300;
        for(int i=0;i<trianglecnt;i++)
        {
            double now=Dis(ply[tri[i].a],ply[tri[i].b],ply[tri[i].c],dd);
            if(_min>now) _min=now;
        }
        return _min;
    }
}hull;
int main()
{
    double now,_min;
    while(scanf("%d",&hull.n)!=EOF)
    {
        if(hull.n==0) break;
        int i,j,q;
        for(i=0;i<hull.n;i++)
            scanf("%lf%lf%lf",&hull.ply[i].x,&hull.ply[i].y,&hull.ply[i].z);
        hull.construct();
        scanf("%d",&q);
        for(j=0;j<q;j++)
        {
            scanf("%lf%lf%lf",&dd.x,&dd.y,&dd.z);
            printf("%.4lf\n",hull.res());
        }
    }
    return 0;
}
