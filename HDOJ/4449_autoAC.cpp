#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include <algorithm>
using namespace std;
#define INF (1<<30)
#define PI acos(-1)
#define SET(a,b) memset(a,b,sizeof(a))
#define M 10010
#define N 505
#define EPS 1e-8
struct pt
{
    double x,y,z;
    pt() {}
    pt(double _x,double _y,double _z): x(_x),y(_y),z(_z) {}
    pt operator - (const pt p1)
    {
        return pt(x-p1.x,y-p1.y,z-p1.z);
    }
    pt operator * (pt p)
    {
        return pt(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
    }
    double operator ^ (pt p)
    {
        return x*p.x+y*p.y+z*p.z;
    }
};
struct _3DCH
{
    struct fac
    {
        int a,b,c;
        bool ok;
    };
    int n;
    pt P[N];
    int cnt;
    fac  F[N*8];
    int to[N][N];
    double vlen(pt a)
    {
        return sqrt(a.x*a.x+a.y*a.y+a.z*a.z);
    }
    double area(pt a,pt b,pt c)
    {
        return vlen((b-a)*(c-a));
    }
    double volume(pt a,pt b,pt c,pt d)
    {
        return (b-a)*(c-a)^(d-a);
    }
    double ptof(pt &p,fac &f)
    {
        pt m=P[f.b]-P[f.a],n=P[f.c]-P[f.a],t=p-P[f.a];
        return (m*n)^t;
    }
    void deal (int p,int a,int b)
    {
        int f=to[a][b];
        fac add;
        if(F[f].ok)
        if(ptof(P[p],F[f])>EPS) dfs(p,f);
        else
        {
            add.a=b; add.b=a; add.c=p; add.ok=1;
            to[p][b]=to[a][p]=to[b][a]=cnt;
            F[cnt++]=add;
        }
    }
    void dfs(int p,int cur)
    {
        F[cur].ok=0;
        deal(p,F[cur].b,F[cur].a);
        deal(p,F[cur].c,F[cur].b);
        deal(p,F[cur].a,F[cur].c);
    }
    bool same(int s,int t)
    {
        pt &a=P[F[s].a],&b=P[F[s].b],&c=P[F[s].c];
        return fabs(volume(a,b,c,P[F[t].a]))<EPS && fabs(volume(a,b,c,P[F[t].b]))<EPS && fabs(volume(a,b,c,P[F[t].c]))<EPS;
    }
    void construct()
    {
        cnt=0;
        if(n<4) return;
        bool sb=1;
        for(int i=1;i<n;i++)
            if(vlen(P[0]-P[i])>EPS)
            {
                swap(P[1],P[i]);
                sb=0;
                break;
            }
        if(sb) return; sb=1;
        for(int i=2;i<n;i++)
            if(vlen((P[0]-P[1])*(P[1]-P[i]))>EPS)
            {
                swap(P[2],P[i]);
                sb=0;
                break;
            }
        if(sb) return; sb=1;    
        for(int i=3;i<n;i++)
            if(fabs((P[0]-P[1])*(P[1]-P[2])^(P[0]-P[i]))>EPS)
            {
                swap(P[3],P[i]);
                sb=0;
                break;
            }
        if(sb) return;
        fac add;
        for(int i=0;i<4;i++)
        {
            add.a=(i+1)%4;
            add.b=(i+2)%4;
            add.c=(i+3)%4;
            add.ok=1;
            if(ptof(P[i],add)>0) swap(add.b,add.c);
            to[add.a][add.b]=to[add.b][add.c]=to[add.c][add.a]=cnt;
            F[cnt++]=add;
        }
        for(int i=4;i<n;i++)
        for(int j=0;j<cnt;j++)
            if(F[j].ok && ptof(P[i],F[j])>EPS)
            {
                dfs(i,j);
                break;
            }
        int tmp=cnt;
        cnt=0;
        for(int i=0;i<tmp;i++)
        if(F[i].ok) F[cnt++]=F[i];
    }
    double ptoface(pt p,int i)
    {
        return fabs(volume(P[F[i].a],P[F[i].b],P[F[i].c],p)/vlen((P[F[i].b]-P[F[i].a])*(P[F[i].c]-P[F[i].a])));
    }
    void get_panel(double &a,double &b,double &c,double &d,pt p1,pt p2,pt p3)
    {
        a=(p2.y-p1.y)*(p3.z-p1.z)-(p2.z-p1.z)*(p3.y-p1.y);
        b=(p2.z-p1.z)*(p3.x-p1.x)-(p2.x-p1.x)*(p3.z-p1.z);
        c=(p2.x-p1.x)*(p3.y-p1.y)-(p2.y-p1.y)*(p3.x-p1.x);
        d=-(a*p1.x+b*p1.y+c*p1.z);
    }
    inline double dist(pt p1, pt p2)
    {
        return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
    }
}hull;
inline int sign(double d)
{
    if(d>EPS) return 1;
    if(d<-EPS) return -1;
    return 0;
}
struct point
{
    double x,y,z;
    point(double x=0,double y=0,double z=0): x(x),y(y),z(z) {}
    point operator - (point p)
    {
        return point(x-p.x,y-p.y,z-p.z);
    }
    point operator + (point p)
    {
        return point(x+p.x,y+p.y,z+p.z);
    }
    point operator / (double len)
    {
        return point(x/len,y/len,z/len);
    }
    point operator * (double len)
    {
        return point(x*len,y*len,z*len);
    }
    double operator ^ (point p)
    {
        return x*p.x+y*p.y+z*p.z;
    }
    point operator * (point p)
    {
        return point(y*p.z-z*p.y,z*p.x-x*p.z,x*p.y-y*p.x);
    }
    double getlen()
    {
        return sqrt(x*x+y*y+z*z);
    }
}con[N],ps[N],org;
double a,b,c,d;
int n;
inline point get_point(point u,point v,point p)
{
    double a,b,t;
    a=(v.x-u.x)*(v.x-u.x)+(v.y-u.y)*(v.y-u.y)+(v.z-u.z)*(v.z-u.z);
    b=(p.x-u.x)*(v.x-u.x)+(p.y-u.y)*(v.y-u.y)+(p.z-u.z)*(v.z-u.z);
    t=b/a;
    point ans;
    ans.x=v.x*t+(1-t)*u.x;
    ans.y=v.y*t+(1-t)*u.y;
    ans.z=v.z*t+(1-t)*u.z;
    return ans;
}
inline double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
point rotate(point u,point v,point p,double ang)
{
    point root=get_point(u,v,p),e,r;
    point ans;
    e=(v-u)/dist(u,v);
    r=p-root;
    e=e*r;
    ans=r*cos(ang)+e*sin(ang)+root;
    return ans;
}
double inter_pro(point u1,point v1,point u2,point v2)
{
    return (v1.x-u1.x)*(v2.y-u2.y)-(v1.y-u1.y)*(v2.x-u2.x);
}
bool cmp(point a,point b)
{
    return a.y<b.y || a.y==b.y && a.x<b.x;
}
void Graham(point* pol, int n, point* con, int& len){  
 sort(pol, pol+ n, cmp);
 con[0] = pol[0];
 con[1] = pol[1];
 int top = 1;
 for(int i = 2; i < n; i++){
  while(top > 0 && inter_pro(con[top - 1], con[top], con[top - 1], pol[i]) <= 0) top--;
  con[++top] = pol[i];
 }
 int tmp = top;  
 for(int i = n - 2; i >= 0; i--){
  while(top > tmp && inter_pro(con[top - 1], con[top], con[top - 1], pol[i]) <= 0) top--;
  con[++top] = pol[i]; 
 }
 len = top;
}
double polyArea(point* ps, int n){
 ps[n] = ps[0];
 int i;
 double ans=0;
 for(i = 0; i < n; i++){
  ans += (ps[i].x*ps[i+1].y-ps[i].y*ps[i+1].x);
 }
 return fabs(ans/2.0);
}
double solve()
{
    point tp(0,0,0),end(0,0,1),vec;
    double ang;
    int i,cn;
    if(sign(a)) tp.x=d/a;
    else if(sign(b)) tp.y=d/b;
    else if(sign(c)) tp.z=d/c;
    ps[n+1]=tp;
    vec=(point(a,b,c))*(end);
    if(sign(vec.x)==0) vec.x=0;
    if(sign(vec.y)==0) vec.y=0;
    if(sign(vec.z)==0) vec.z=0;
    ang=(a*end.x+b*end.y+c*end.z)/(point(a,b,c).getlen());
    ang=acos(ang);
    if(sign(ang)!=-0 && sign(ang-PI)!=0)
        for(i=0;i<n;i++)
            ps[i]=rotate(org,vec,ps[i],ang);
    for(int i=0;i<n;i++) ps[i].z=0;
    Graham(ps,n,con,cn);
    double ans=fabs(polyArea(con,cn));
    return ans;
}
int main()
{
    while (scanf("%d",&hull.n) && hull.n)
    {
        for(int i=0;i<hull.n;i++)
            scanf("%lf%lf%lf",&hull.P[i].x,&hull.P[i].y,&hull.P[i].z);
        if(n==1)
        {
            printf("0.000 0.000\n");
            continue;
        }
        if(n==2)
        {
            printf("%.3lf 0.000\n",hull.dist(hull.P[0],hull.P[1]));
            continue;
        }
        hull.construct();
        n=hull.n;
        double ans1=0,ans2=1e100;
        if(hull.cnt==0)
        {
            double max0=0;
            for(int i=0;i<hull.n;i++)
            for(int j=0;j<hull.n;j++)
                max0=max(max0,hull.dist(hull.P[i],hull.P[j]));
            printf("%.3lf 0.000\n",max0);
            continue;
        }
        n=hull.n;
        for(int i=0;i<hull.cnt;i++)
        {
            for(int j=0;j<hull.n;j++)
                ps[j].x=hull.P[j].x,
                ps[j].y=hull.P[j].y,
                ps[j].z=hull.P[j].z;
            hull.get_panel(a,b,c,d,hull.P[hull.F[i].a],hull.P[hull.F[i].b],hull.P[hull.F[i].c]);
            d=-d;
            double dist=0;
            for(int j=0;j<hull.n;j++)
                dist=max(dist,hull.ptoface(hull.P[j],i));
            double ans=solve();
            if(dist>ans1) ans1=dist,ans2=ans;
            else if(fabs(dist-ans1)<EPS) if(ans2>ans) ans1=dist,ans2=ans;
        }
        printf("%.3f %.3f\n",ans1,ans2);
    }
    return 0;
}
