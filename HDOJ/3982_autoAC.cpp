#include <set>
#include <map>
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
#define FOR(i,s,t) for(int i=s; i<t; i++)
#define BUG puts("here!!!")
using namespace std;
const int MAX = 2010;
struct point { 
    double x,y;
    void P(double xx, double yy){ x = xx; y = yy;}
    void get(){ scanf("%lf%lf",&x, &y);}
};
struct line { point a,b; double ang;};  
point s[MAX*2], ch, p[MAX*2];  
line l[MAX*2],deq[MAX*2];  
const double eps = 1e-6;  
const double pi = acos(-1.0);
bool dy(double x,double y)  {   return x > y + eps;} 
bool xy(double x,double y)  {   return x < y - eps;}  
bool dyd(double x,double y) {   return x > y - eps;}   
bool xyd(double x,double y) {   return x < y + eps;}     
bool dd(double x,double y)  {   return fabs( x - y ) < eps;}   
double crossProduct(point a,point b,point c)  
{  
    return (c.x - a.x)*(b.y - a.y) - (b.x - a.x)*(c.y - a.y);  
}  
double disp2p(point a,point b) 
{
    return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
bool parallel(line u,line v)  
{  
    return dd( (u.a.x - u.b.x)*(v.a.y - v.b.y) - (v.a.x - v.b.x)*(u.a.y - u.b.y) , 0.0 );  
}  
point l2l_inst_p(line l1,line l2)  
{  
    point ans = l1.a;  
    double t = ((l1.a.x - l2.a.x)*(l2.a.y - l2.b.y) - (l1.a.y - l2.a.y)*(l2.a.x - l2.b.x))/  
               ((l1.a.x - l1.b.x)*(l2.a.y - l2.b.y) - (l1.a.y - l1.b.y)*(l2.a.x - l2.b.x));  
    ans.x += (l1.b.x - l1.a.x)*t;  
    ans.y += (l1.b.y - l1.a.y)*t;  
    return ans;  
}  
bool equal_ang(line a,line b)  
{  
    return dd(a.ang,b.ang);  
}  
bool cmphp(line a,line b)  
{  
    if( dd(a.ang,b.ang) ) return xy(crossProduct(b.a,b.b,a.a),0.0);  
    return xy(a.ang,b.ang);  
}  
bool equal_p(point a,point b)
{  
    return dd(a.x,b.x) && dd(a.y,b.y);  
}
void makeline_hp(double x1,double y1,double x2,double y2,line &l)
{
    l.a.x = x1; l.a.y = y1; l.b.x = x2; l.b.y = y2;
    l.ang = atan2(y2 - y1,x2 - x1);
}
void inst_hp_nlogn(line *ln,int n,point *s,int &len)  
{  
    len = 0;  
    sort(ln,ln+n,cmphp);  
    n = unique(ln,ln+n,equal_ang) - ln;  
    int bot = 0,top = 1;  
    deq[0] = ln[0]; deq[1] = ln[1];  
    for(int i=2; i<n; i++)  
    {  
        if( parallel(deq[top],deq[top-1]) || parallel(deq[bot],deq[bot+1]) )  
            return ;  
        while( bot < top && dy(crossProduct(ln[i].a,ln[i].b,  
            l2l_inst_p(deq[top],deq[top-1])),0.0) )  
            top--;  
        while( bot < top && dy(crossProduct(ln[i].a,ln[i].b,  
            l2l_inst_p(deq[bot],deq[bot+1])),0.0) )  
            bot++;  
        deq[++top] = ln[i];  
    }  
    while( bot < top && dy(crossProduct(deq[bot].a,deq[bot].b,  
        l2l_inst_p(deq[top],deq[top-1])),0.0) ) top--;  
    while( bot < top && dy(crossProduct(deq[top].a,deq[top].b,  
        l2l_inst_p(deq[bot],deq[bot+1])),0.0) ) bot++;  
    if( top <= bot + 1 ) return ;  
    for(int i=bot; i<top; i++)  
        s[len++] = l2l_inst_p(deq[i],deq[i+1]);  
    if( bot < top + 1 ) s[len++] = l2l_inst_p(deq[bot],deq[top]);  
    len = unique(s,s+len,equal_p) - s;  
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
bool cmp(point a,point b)
{
    double t1 = atan2(a.y - ch.y, a.x - ch.x);
    double t2 = atan2(b.y - ch.y, b.x - ch.x);
    return xy(t1, t2);
}
double area_triangle(point a,point b,point c)
{
    return fabs( crossProduct(a,b,c) )/2.0;
}
double gong_area(point c,point a,point b,double r)
{
    if( dd(crossProduct(c,a,b), 0.0) )
        return r*r*pi/2;
    double area = area_triangle(a, b, c);
    double ang = acos(1-disp2p(a,b)*disp2p(a,b)/(r*r*2));
    return ang*r*r/2 - area;
}
bool incircle(point a,point c, double r)
{
    return xy(disp2p(a, c), r);
}
bool pin_convexh(point *p,int n,point a)
{
    p[n] = p[0]; p[n+1] = p[1];
    for(int i=0; i<n; i++)
        if( xy(crossProduct(p[i],p[i+1],a)*
            crossProduct(p[i+1],p[i+2],a),0.0) )
            return false;
    return true;
}
point foot_line(point a,point l1,point l2)
{                                        
    point c;
    c.x = a.x - l2.y + l1.y;
    c.y = a.y + l2.x - l1.x;
    return c;    
}
double solve(point *s, int len, double r)
{
    point c; c.x = c.y = 0;
    point a, b;
    int cnt = 0;
    s[len] = s[0];
    FOR(i, 0, len)    
    {    
        if( xy(disp2l(c, s[i], s[i+1]), r) )
        {
            l2c_inst_p(c, r, s[i], s[i+1], a, b);
            if( onSegment(s[i], s[i+1], a) )
                p[cnt++] = a;
            if( onSegment(s[i], s[i+1], b) )
                p[cnt++] = b;
        }
        if( incircle(s[i], c, r) )
            p[cnt++] = s[i];
        if( incircle(s[i+1], c, r) )
            p[cnt++] = s[i+1];
    }
    sort(p, p+cnt, cmp);
    cnt = unique(p, p+cnt, equal_p) - p;
    p[cnt] = p[0];
    double area = 0.0;
    if( cnt == 2 )     
    {
        if( xy(crossProduct(p[0],p[1],ch), 0.0) )
            swap(p[0], p[1]);
        cnt--;
    }
    FOR(i, 0, cnt)
    {
        area += area_triangle(p[0], p[i], p[i+1]);
        if( !dd(disp2p(p[i], c), r) || !dd(disp2p(p[i+1], c), r) )
            continue; 
        point mid;
        mid.P((p[i].x + p[i+1].x)/2, (p[i].y + p[i+1].y)/2);
        point a, b, k;
        k = foot_line(c, p[i], p[i+1]);
        l2c_inst_p(c, r, k, c, a, b);
        bool flag = false;
        if( dyd(crossProduct(p[i], p[i+1], a), 0.0) && pin_convexh(s, len, a) )
            flag = true; 
        if( dyd(crossProduct(p[i], p[i+1], b), 0.0) && pin_convexh(s, len, b) )
            flag = true; 
        if( !flag ) continue;
        double area_gong = gong_area(c, p[i], p[i+1], r);
        if( dy(crossProduct(p[i], p[i+1], c), 0.0) )
            area_gong = pi*r*r - area_gong;
        area += area_gong;
    }
    return area/(pi*r*r);
}
int main()
{
    int ncases, ind = 1, n;
    double r;
    scanf("%d", &ncases);
    while( ncases-- )
    {
        scanf("%lf%d",&r, &n);
        FOR(i, 0, n)
        {
            l[i].a.get();
            l[i].b.get();
        }
        ch.get();
        bool f = false;
        point c; c.P(0,0);
        FOR(i, 0, n)
        {
            if( dy(crossProduct(l[i].a, l[i].b, ch), 0.0) )
                swap(l[i].a, l[i].b);
            l[i].ang = atan2(l[i].b.y - l[i].a.y, l[i].b.x - l[i].a.x);
            if( xy(disp2l(c,l[i].a, l[i].b), r) )
                f = true;         
        }
        if( !f )        
        {
            printf("Case %d: %.5lf%%\n",ind++, 100.0);
            continue;
        }
        makeline_hp(-2*r, -2*r, 2*r, -2*r, l[n++]); 
        makeline_hp(2*r, -2*r, 2*r, 2*r, l[n++]);
        makeline_hp(2*r, 2*r, -2*r, 2*r, l[n++]);
        makeline_hp(-2*r, 2*r, -2*r, -2*r, l[n++]);
        int len;
        inst_hp_nlogn(l, n, s, len); 
        double ans = solve(s, len, r);
        printf("Case %d: %.5lf%%\n",ind++, ans*100);
    }
return 0;
}
