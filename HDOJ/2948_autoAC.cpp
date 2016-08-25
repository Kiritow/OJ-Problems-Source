#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define eps 1e-12
#define MAXN 55
#define INF 1e30
#define mem0(a) memset(a,0, sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
double MAX(double a, double b) {return a > b ? a : b;}
double MIn(double a, double b) {return a < b ? a : b;}
typedef long long LL;
struct Point{
    double x,y;
    Point(double x=0, double y=0):x(x),y(y){}
};
struct Polygon
{
    Point p[MAXN];
    int Size;
};
struct Circle
{
    Point o;
    double r;
    Circle(){}
    Circle(Point _o, double _r):o(_o),r(_r){}
};
Point operator + (Point A, Point B) {return Point(A.x+B.x, A.y+B.y);}
Point operator - (Point A, Point B) {return Point(A.x-B.x, A.y-B.y);}
Point operator * (Point A, double p) {return Point(A.x*p, A.y*p);}
Point operator / (Point A, double p) {return Point(A.x/p, A.y/p);}
int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
bool operator == (const Point &A, const Point &B) {
    return dcmp(A.x-B.x) == 0 && dcmp(A.y-B.y) == 0;
}
double Dot(Point A, Point B) { return A.x*B.x + B.y*B.y;}    
double Length(Point A) { return sqrt(Dot(A,A));}             
double Angle(Point A, Point B) {return acos(Dot(A,B) / Length(A) / Length(B));}
double cross(Point A, Point B) {return A.x*B.y - A.y*B.x;}
bool crossed(Point a, Point b, Point c, Point d)
{
    if(cross(a-c, d-c)*cross(b-c, d-c)<=0 && cross(c-a, b-a)*cross(d-a, b-a)<=0)
    {
        return true;
    }
    return false;
}
bool isPointOnSegent(Point p, Point s, Point e)
{
    double d = (p.x-s.x) * (e.x-p.x);
    double a = (p.y-s.y) / (p.x-s.x);
    double b = (e.y-p.y) / (e.x-p.x);
    if(dcmp(d)==1 && dcmp(a-b)==0)return true;
    return false;
}
int isPointInPolygon(Point p, Polygon poly)
{
    int w = 0;
    int n = poly.Size;
    for(int i=0;i<n;i++)
    {
        if(isPointOnSegent(p, poly.p[i], poly.p[(i+1)%n])) return 1;
        int k = dcmp(cross(poly.p[(i+1)%n]-poly.p[i], p-poly.p[i]));
        int d1 = dcmp(poly.p[i].y - p.y);
        int d2 = dcmp(poly.p[(i+1)%n].y - p.y);
        if(k > 0 && d1 <= 0 && d2 > 0) w++;
        if(k < 0 && d2 <= 0 && d1 > 0) w--;
    }
    if(w != 0) return 1;
    return 0;
}
struct R
{
    Point a, b;
    R(){}
    R(Point _a, Point _b)
    {
        a = _a;
        b = _b;
    }
}r[1001];
struct T
{
    Point a, b, c;
    T(){}
    T(Point _a, Point _b, Point _c) {
        a = _a; b = _b; c = _c;
    }
}t[1001];
Circle c[1001];
int S, N;
int cntC = 0, cntT = 0, cntR = 0;
int calc(double x, double y)
{
    Point p = Point(x, y);
    int ans = 0;
    for(int i=0;i<cntC;i++)
    {
        if(Length(p-c[i].o) <= c[i].r) ans ++;
    }
    for(int i=0;i<cntT;i++)
    {
        if(   cross(t[i].c-t[i].a, p-t[i].a)*cross(t[i].b-t[i].a, p-t[i].a)<=0
           && cross(t[i].a-t[i].b, p-t[i].b)*cross(t[i].c-t[i].b, p-t[i].b)<=0 ) ans ++;
    }
    for(int i=0;i<cntR;i++)
    {
        if(x>=r[i].a.x&&x<=r[i].b.x && y>=r[i].a.y&&y<=r[i].b.y) ans ++;
    }
    return ans;
}
int main()
{
    char ch;double x, y, rr;
    while(~scanf("%d%*c", &S))
    {
        cntT = cntC = cntR = 0;
        for(int i=0;i<S;i++)
        {
            scanf("%c", &ch);
            if(ch == 'C')
            {
                scanf("%lf %lf %lf%*c", &x, &y, &rr);
                c[cntC++] = Circle(Point(x, y), rr);
                continue;
            }
            else if(ch == 'T')
            {
                Point aa[3];
                for(int j=0;j<3;j++)
                {
                    scanf("%lf%*c%lf%*c", &x, &y);
                    aa[j] = Point(x, y);
                }
                t[cntT++] = T(aa[0],aa[1],aa[2]);
            }
            else
            {
                Point aa[2];
                for(int j=0;j<2;j++)
                {
                    scanf("%lf%*c%lf%*c", &x, &y);
                    aa[j] = Point(x, y);
                }
                r[cntR++] = R(aa[0], aa[1]);
            }
        }
        scanf("%d", &N);
        for(int i=0;i<N;i++)
        {
            int cntA = 0, cntB = 0;
            for(int j=0;j<3;j++)
            {
                scanf("%lf %lf", &x, &y);
                cntA += calc(x, y);
            }
            for(int j=0;j<3;j++)
            {
                scanf("%lf %lf", &x, &y);
                cntB += calc(x, y);
            }
            printf("%s\n", cntA > cntB ? "Bob" : (cntA == cntB ? "Tied" : "Hannah"));
        }
    }
    return 0;
}
