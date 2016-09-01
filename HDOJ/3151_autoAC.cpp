#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
#define INF 1000000000
const double eps = 1e-8;
const double pi = acos(-1.0);
int cmp(double x)
{
    if (fabs(x) < eps) return 0;
    if (x > 0) return 1;
    return -1;
}
inline double sqr(double x){return x*x;}
struct point
{
    double x,y;
    point(){}
    point(double a,double b):x(a),y(b){}
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    friend point operator + (const point &a, const point &b)
    {
        return point(a.x+b.x, a.y+b.y);
    }
    friend point operator - (const point &a, const point &b)
    {
        return point(a.x-b.x, a.y-b.y);
    }
    friend bool operator == (const point &a, const point &b)
    {
        return cmp(a.x-b.x)==0 && cmp(a.y-b.y)==0;
    }
    friend point operator * (const point &a, const double &b)
    {
        return point(a.x*b, a.y*b);
    }
    friend point operator * (const double &a, const point &b)
    {
        return point(a*b.x, a*b.y);
    }
    friend point operator / (const point &a, const double &b)
    {
        return point(a.x/b, a.y/b);
    }
    bool operator<(const point& a)const
    {
        if (cmp(x-a.x)!=0) return x<a.x;
        return y<a.y;
    }
    double norm()
    {
        return sqrt(sqr(x) + sqr(y));
    }
};
double det(const point &a, const point &b)
{
    return a.x*b.y-a.y*b.x;
}
double dot(const point &a,const point &b)
{
    return a.x*b.x+a.y*b.y;
}
double dis_point_segment(point p, point s, point t)
{
    if (cmp(dot(p-s, t-s)) < 0) return (p-s).norm();
    if (cmp(dot(p-t, s-t)) < 0) return (p-t).norm();
    return fabs(det(s-p, t-p)) / (s-t).norm();
}
double caldis(point a, point b, point c, point d)
{
    if (cmp(det(a-c, d-c) * det(b-c, d-c)) < 0 && 
        cmp(det(c-a, b-a) * det(d-a, b-a)) < 0) return 0.0;
    double t1 = min(dis_point_segment(a, c, d), dis_point_segment(b, c, d));
    double t2 = min(dis_point_segment(c, a, b), dis_point_segment(d, a, b));
    return min(t1, t2);
}
int W, n;
vector<point> con[110];
double dis[110][110];
int fa[110];
int get_fa(int x)
{
    if (fa[x] == x) return x;
    fa[x] = get_fa(fa[x]);
    return fa[x];
}
void merge(int x,int y)
{
    x=get_fa(x);y=get_fa(y);
    fa[x] = y;
}
bool check(double d)
{
    for (int i=0; i<n+2; i++) fa[i]=i;
    for (int i=0; i<n+2; i++)
    {
        for (int j=i+1; j<n+2; j++)
        if (cmp(dis[i][j] - d)<0)
            merge(i,j);
    }
    int x=get_fa(n), y=get_fa(n+1);
    if (x==y) return false;
    return true;
}
int main()
{
    while(scanf("%d%d",&W,&n)!=EOF)
    {
        if (W==0 && n==0) break;
        double w = W/2.0;
        for (int i=0;i<n;i++)
        {
            int k;
            scanf("%d",&k);
            con[i].clear();
            for (int j=1; j<=k; j++)
            {
                double x,y;
                scanf("%lf%lf",&x,&y);
                con[i].push_back(point(x,y));
            }
            con[i].push_back(con[i][0]);
            for (int j=0; j<i; j++)
            {
                dis[i][j]=INF;
                for (int k=0; k+1<con[i].size(); k++)
                for (int d=0; d+1<con[j].size(); d++)
                    dis[i][j]=min(dis[i][j], caldis(con[i][k],con[i][k+1], con[j][d],con[j][d+1]));
                dis[j][i] = dis[i][j];
            }
            dis[i][n] = dis[i][n+1] = INF;
            for (int j=0; j<con[i].size(); j++)
            {
                dis[i][n] = min(dis[i][n], w-con[i][j].y);
                dis[i][n+1] = min(dis[i][n+1], w+con[i][j].y);
            }
            dis[n][i] = dis[i][n];
            dis[n+1][i] = dis[i][n+1];
        }
        dis[n][n+1]=dis[n+1][n] = w * 2.0;
        double L=0.0, r=w, mid;
        for (int i=0; i<n; i++)
        for (int j=0; j+1<con[i].size(); j++)
            r = min(r, dis_point_segment(point(0,0), con[i][j], con[i][j+1]));
        r*=2.0;
        while((r-L)>eps)
        {
            mid=(L+r)/2.0;
            if (check(mid)) L=mid;
            else r=mid;
        }
        if (cmp(L)>0) printf("%.2lf\n",L/2.0);
        else printf("impossible\n");
    }
    return 0;
}
