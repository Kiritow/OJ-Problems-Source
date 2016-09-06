#include <set>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits.h>
#include <string.h>
#include <string>
#include <algorithm>
#define MID(x,y) ( ( x + y ) >> 1 )
#define L(x) ( x << 1 )
#define R(x) ( x << 1 | 1 )
#define FOR(i,s,t) for(int i=(s); i<(t); i++)
#define BUG puts("here!!!")
#define STOP system("pause")
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
const int MAX = 1000;
const double eps = 1e-6;
const double inf = 1e50;
struct point{
    double x, y;
    void get()
    {
        scanf("%lf%lf", &x, &y);
    }
};
bool dy(double x,double y)    {    return x > y + eps;}    
bool xy(double x,double y)    {    return x < y - eps;}    
bool dyd(double x,double y)    {     return x > y - eps;}    
bool xyd(double x,double y)    {    return x < y + eps;}     
bool dd(double x,double y)     {    return fabs( x - y ) < eps;}  
double disp2p(point a,point b) 
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
bool operator==(point a, point b)
{
    return dd(a.x, b.x) && dd(a.y, b.y);
}
typedef struct NODE{
    int to;
    double len;
    NODE *next;
}NODE;
NODE *p[MAX],node[MAX*MAX];
struct circle{
    point c;
    double r;
};
circle c[MAX];
int cou;
void init()
{
    cou = 0;
    memset(p, 0, sizeof(p));
}
void Add(int from,int to,double len)
{
    node[cou].next = p[from];
    node[cou].to = to;
    node[cou].len = len;
    p[from] = &node[cou++];
}
queue<int> q;
double SPFA_List(int from,int to,int n)
{
    while( !q.empty() ) q.pop();
    double dis[MAX];
    bool inq[MAX];
    for(int i=0; i<n; i++)
        dis[i] = inf;
    memset(inq,false,sizeof(inq));
    dis[from] = 0;
    q.push(from);
    inq[from] = 1;
    while( !q.empty() )
    {
        int now = q.front();
        q.pop();
        inq[now] = false;
        NODE *head = p[now];
        while( head != NULL )
        {
            int v = head->to;
            double len = head->len;
            if( dy(dis[v], dis[now] + len) )
            {
                dis[v] = dis[now] + len;
                if( !inq[v] )
                {
                    inq[v] = true;
                    q.push(v);
                }
            }
            head = head->next;
        }
    }
    if( dd(dis[to], inf) ) return -1;
    return dis[to];
}
point l2l_inst_p(point u1,point u2,point v1,point v2)
{
    point ans = u1;
    double t = ((u1.x - v1.x)*(v1.y - v2.y) - (u1.y - v1.y)*(v1.x - v2.x))/
                ((u1.x - u2.x)*(v1.y - v2.y) - (u1.y - u2.y)*(v1.x - v2.x));
    ans.x += (u2.x - u1.x)*t;
    ans.y += (u2.y - u1.y)*t;
    return ans;
}
void l2c_inst_p(point c,double r,point l1,point l2,point &p1,point &p2)
{
    point p = c;
    double t;
    p.x += l1.y - l2.y;
    p.y += l2.x - l1.x;
    p = l2l_inst_p(p,c,l1,l2);
    t = sqrt(r*r - disp2p(p,c)*disp2p(p,c))/disp2p(l1,l2);
    p1.x = p.x + (l2.x - l1.x)*t;
    p1.y = p.y + (l2.y - l1.y)*t;
    p2.x = p.x - (l2.x - l1.x)*t;
    p2.y = p.y - (l2.y - l1.y)*t;
}
void c2c_inst_p(point c1,double r1,point c2,double r2,point &p1,point &p2)
{
    point u,v;
    double t;
    t = (1 + (r1*r1 - r2*r2)/disp2p(c1,c2)/disp2p(c1,c2))/2;
    u.x = c1.x + (c2.x - c1.x)*t;
    u.y = c1.y + (c2.y - c1.y)*t;
    v.x = u.x + c1.y - c2.y;
    v.y = u.y - c1.x + c2.x;
    l2c_inst_p(c1,r1,u,v,p1,p2);
}
bool c2c_tangent(point a,double r1,point b,double r2)
{
    if( dd(disp2p(a,b),r1+r2) || dd(disp2p(a,b),fabs(r1-r2)) )
        return true;
    return false;
}
point c2c_tangent_p(point a,double r1,point b,double r2)
{
    point t;
    if( dd(disp2p(a,b),r1 + r2)  )
    {
        t.x = (r1*b.x + r2*a.x)/(r1 + r2);
        t.y = (r1*b.y + r2*a.y)/(r1 + r2);
        return t;
    }
    t.x = (r1*b.x - r2*a.x)/(r1 - r2);
    t.y = (r1*b.y - r2*a.y)/(r1 - r2);
    return t;
}
point g[MAX];
bool f[MAX][MAX];
double crossProduct(point a,point b,point c)
{
    return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);
}
double disp2l(point a,point l1,point l2)
{
    return fabs( crossProduct(a,l1,l2) )/disp2p(l1,l2);
}
bool onSegment(point a, point b, point c)
{
    if( dd(crossProduct(a,b,c),0.0) && dyd(c.x,min(a.x,b.x)) && 
        xyd(c.x,max(a.x,b.x)) && dyd(c.y,min(a.y,b.y)) && xyd(c.y,max(a.y,b.y)) )
        return true;
    return false;
}
bool cmp(point a, point b)
{
    if( dd(a.x, b.x) )    return xy(a.y, b.y);
    return xy(a.x, b.x);
}
point tp[MAX];
bool check(int cnt, int n)
{
    FOR(i, 1, cnt)
    {
        point tt;
        tt.x = (tp[i].x + tp[i-1].x)/2;
        tt.y = (tp[i].y + tp[i-1].y)/2;
        bool f = false;
        FOR(k, 0, n)
            if( xyd(disp2p(c[k].c, tt), c[k].r) )
            {
                f = true;
                break;
            }
        if( !f )
            return false;
    }
    return true;
}
double solve(int n)
{
    int l = 0;
    int s = 0, t = n-1;
    FOR(i, 0, n)
        g[l++] = c[i].c;
    FOR(i, 0, n)
    {
        FOR(k, i+1, n)
        {
            if( dy(disp2p(c[i].c, c[k].c), c[i].r + c[k].r) 
                    || c[i].c == c[k].c )
                continue;
            if( c2c_tangent(c[i].c, c[i].r, c[k].c, c[k].r) )
            {
                point tt = c2c_tangent_p(c[i].c, c[i].r, c[k].c, c[k].r);
                g[l++] = tt;
                continue;
            }
            point t1, t2;
            c2c_inst_p(c[i].c, c[i].r, c[k].c, c[k].r, t1, t2);
            g[l++] = t1;
            g[l++] = t2;
        }
    }
    memset(f, false, sizeof(f));
    int tmp[MAX];
    FOR(i, 0, n)
    {
        int cnt = 0;
        FOR(k, 0, l)
            if( xyd(disp2p(c[i].c, g[k]), c[i].r) )
                tmp[cnt++] = k;
        FOR(k, 0, cnt)
            FOR(j, k+1, cnt)
            {
                int x = tmp[k], y = tmp[j];
                if( f[x][y] ) continue;
                double dis = disp2p(g[x], g[y]);
                Add(x, y, dis);
                Add(y, x, dis);
                f[x][y] = f[y][x] = true;
            }        
    }
    FOR(i, 0, l)
        FOR(k, i+1, l)
        {
            if( f[i][k] ) continue;
            int cnt = 0;
            tp[cnt++] = g[i];
            tp[cnt++] = g[k];
            FOR(j, 0, n)
                if( xyd(disp2l(c[j].c, g[i], g[k]),c[j].r) )
                {
                    point t1, t2;
                    l2c_inst_p(c[j].c, c[j].r, g[i], g[k], t1, t2);
                    if( onSegment(g[i], g[k], t1) )
                        tp[cnt++] = t1;
                    if( onSegment(g[i], g[k], t2) )
                        tp[cnt++] = t2;        
                }
            sort(tp, tp+cnt, cmp);
            if( check(cnt, n) )
            {
                Add(i, k, disp2p(g[i], g[k]));
                Add(k, i, disp2p(g[k], g[i]));
            }
        }
    return SPFA_List(s, t, l);
}
int main()
{
    int ncases, n, ind = 1;
    scanf("%d", &ncases);
    while( ncases-- )
    {
        scanf("%d", &n);
        init();
        FOR(i, 0, n)
        {
            c[i].c.get();
            scanf("%lf", &c[i].r);
        }
        double ans = solve(n);
        printf("Case %d: ",ind++);
        if( ans < -eps )
            puts("No such path.");
        else
            printf("%.4lf\n", ans);
    }
return 0;
}
