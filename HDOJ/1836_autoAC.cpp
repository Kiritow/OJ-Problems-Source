#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;
#define maxn 210
#define LL long long
#define eps 1e-6
#define PI acos(-1.0)
int n,m,tot;
struct Point{
 double x,y;
 Point(){}
 Point(double _x,double _y)
 {
 x=_x; y=_y;
 }
};
bool operator < (const Point& a,const Point& b)
{
 if(fabs(a.x-b.x)>eps)
 return a.x<b.x;
 else if(fabs(a.y-b.y)>eps)
 return a.y<b.y;
 return false;
}
bool operator==(const Point& a, const Point& b)
{
 return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps;
}
struct Line{
 Point a,b;
 Line(){}
 Line(Point _a,Point _b)
 {
 a=_a; b=_b;
 }
};
bool parallel(const Line& ll,const Line& rr)
{
 return fabs((ll.a.x-ll.b.x)*(rr.a.y-rr.b.y)-(ll.a.y-ll.b.y)*(rr.a.x-rr.b.x))<eps;
}
Point intesection(const Line& ll, const Line& rr) {
    Point ret = ll.a;
    double r =
        ((ll.a.x - rr.a.x) * (rr.a.y - rr.b.y) - (ll.a.y - rr.a.y) * (rr.a.x - rr.b.x)) /
        ((ll.a.x - ll.b.x) * (rr.a.y - rr.b.y) - (ll.a.y - ll.b.y) * (rr.a.x - rr.b.x));
    ret.x += (ll.b.x - ll.a.x) * r;
    ret.y += (ll.b.y - ll.a.y) * r;
    return ret;
}
struct Edge{
 double w;
 int v;
 bool vis;
 Edge(){}
 Edge(int _v,double _w,bool _vis=false)
 {
 v=_v; w=_w; vis=_vis;
 }
 bool operator <(const Edge& b)const
 {
 return w<b.w;
 }
};
map<Point,int>g;
vector<Point>vp,p[maxn];
Line lines[maxn];
vector<Edge>E[maxn*maxn/2];
vector<double>ans;
Point pts[maxn];
bool check(double a,double b)
{
 if(b>a+eps) return b+eps<a+PI;
 return b+eps<a-PI;
}
int search(vector<Edge>&E,double w)
{
 double d=w+PI;
 if(d>PI+eps) d-=2*PI;
 int id;
 for(id=0;id<E.size();id++)
 {
 if(fabs(E[id].w-d)<eps)
 {
 if(id) id--;
 else id=E.size()-1;
 break;
 }
 }
 return check(E[id].w,d)?id:-1;
}
int sig(double d)
{
    return (d>eps) - (d<-eps);
}
double cross(const Point & o, const Point & a, const Point & b)
{
    return (a.x-o.x)*(b.y-o.y) - (b.x-o.x)*(a.y-o.y);
}
int inside_convex(Point * ps, int n, Point q)
{
    bool s[3] = {1, 1, 1};
    ps[n] = ps[0];
    for(int i = 0; i < n && (s[0] | s[2]); i ++) {
        s[ 1+sig(cross(ps[i+1], q, ps[i])) ] = 0;
    }
    if(s[0] | s[2])    return s[1]+1;    
    return 0;
}
void init()
{
 int i,j;
 for(i=0;i<n;i++)
 scanf("%lf %lf",&pts[i].x,&pts[i].y);
 g.clear();
 vp.clear();
 for(i=1;i<=n;i++)
 lines[i-1]=Line(pts[i%n],pts[i-1]);
 for(i=n;i<n+m;i++)
 scanf("%lf %lf %lf %lf",&lines[i].a.x,&lines[i].a.y,&lines[i].b.x,&lines[i].b.y);
 for(i=0;i<n+m;i++)
 {
 p[i].clear();
 for(j=0;j<i;j++)
 {
 if(parallel(lines[i],lines[j])) continue;
 Point pt=intesection(lines[i],lines[j]);
 g[pt];
 p[i].push_back(pt);
 p[j].push_back(pt);
 }
 }
 tot=0;
 for(map<Point,int>::iterator it=g.begin();it!=g.end();it++)
 {
 vp.push_back(it->first);
 it->second=tot;
 E[tot++].clear();
 }
 for(i=0;i<n+m;i++)
 {
 if(p[i].size()<2) continue;
 sort(p[i].begin(),p[i].end());
 p[i].erase(unique(p[i].begin(),p[i].end()),p[i].end());
 double ab=atan2(p[i].back().y-p[i].front().y,p[i].back().x-p[i].front().x);
 double ba=atan2(p[i].front().y-p[i].back().y,p[i].front().x-p[i].back().x);
 for(int j=1;j<p[i].size();j++)
 {
 int a=g[p[i][j-1]],b=g[p[i][j]];
 E[a].push_back(Edge(b,ab));
 E[b].push_back(Edge(a,ba));
 }
 }
 for(int i=0;i<tot;i++)
 sort(E[i].begin(),E[i].end());
}
void gao()
{
 int i,j,s,ans=0;
 for(i=0;i<tot;i++)
 {
        if(!inside_convex(pts,n,vp[i])) continue;
 for(j=0;j<E[i].size();j++)
 {
 if(E[i][j].vis) continue;
 int a=i,b=j,c;
 E[i][j].vis=true;
 double S=vp[a].x*vp[E[i][j].v].y-vp[a].y*vp[E[i][j].v].x;
 while(E[a][b].v!=i)
 {
 c=search(E[E[a][b].v],E[a][b].w);
 if(c==-1)
 {
 S=0; break;
 }
 a=E[a][b].v,b=c;
 if(E[a][b].vis)
 {
 S=0; break;
 }
 if(!inside_convex(pts,n,vp[a]))
 {
 S=0; break;
 }
 E[a][b].vis=true;
 S+=vp[a].x*vp[E[a][b].v].y-vp[a].y*vp[E[a][b].v].x;
 }
 if(S>2*eps) ans++;
 }
 }
 printf("Number of regions=%d.\n",ans);
}
int main()
{
 int ncase;
 scanf("%d",&ncase);
 while(ncase--)
 {
 scanf("%d %d",&n,&m);
 init();
 gao();
 }
 return 0;
}
