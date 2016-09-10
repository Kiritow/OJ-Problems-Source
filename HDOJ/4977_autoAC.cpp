#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#define next (i+1)%n
const double eps = 1e-8;
using namespace std;
const double PI = acos(-1);
const double sqrt3 = sqrt(3);
int dcmp(double x)
{
    if (x < -eps) return -1;
    else if (x > eps) return 1;
    else return 0;
}
double add(double a, double b)
{
    if (abs(a + b) < eps * (abs(a) + abs(b))) return 0;
    return a + b;
}
struct Point
{
    double x,y;
    Point() {}
    Point(double x,double y) : x(x),y(y){}
    Point operator + (Point p) {return Point(add(x, p.x),add(y, p.y)); }
    Point operator - (Point p) {return Point(add(x, -p.x),add(y, -p.y)); } 
    Point operator * (double a) {return Point(x * a, y * a); }
    Point operator / (double a) {return Point(x / a, y / a); }
    bool operator < (const Point p) const {return dcmp(x - p.x) < 0 || dcmp(x - p.x) == 0 && dcmp(y - p.y)<0; } 
    bool operator == (const Point p) const {return dcmp(x - p.x) == 0 && dcmp(y - p.y) == 0; }
    double dot(Point p) {return add(x * p.x, y * p.y); }
    double det(Point p) {return add(x * p.y, -y * p.x); }
    double length() {return sqrt(x*x + y*y); }
    double Angle() {return atan2(y,x);}
    Point Rotate(double rad) {return Point(add(x * cos(rad),- y * sin(rad)), add(x * sin(rad), y * cos(rad))); }
    Point Normal() {return Point(-y / length(), x / length()); }
};
typedef Point Vector;
int ConvexHull(Point* p,int n, Point* ch)
{
    sort(p,p+n);
    int m = 0;
    for (int i = 0; i < n ; i ++)
    {
        while (m > 1 && (ch[m-1] - ch[m-2]).det(p[i] - ch[m-2]) <= 0) m --;
        ch[m++] = p[i];
    }
    int k = m;
    for (int i = n-2; i >= 0; i--)
    {
        while (m > k &&(ch[m-1] - ch[m-2]).det(p[i] - ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if (n > 1) m--;
    return m;
}
struct Circle
{
    Point c;
    double r;
    Circle(){}
    Circle(Point c, double r): c(c),r(r){}
    Point point(double a)
    {
        return Point(c.x + cos(a)*r, c.y + sin(a)*r);
    }
}C;
int getLineCircleIntersection(Point p,Vector v,Circle C,Point sol[])
{
    double t1,t2;
    double a= v.x, b = p.x - C.c.x, c = v.y, d = p.y - C.c.y;
    double e = a*a + c*c, f = 2*(a*b + c*d), g = b*b + d*d -C.r*C.r;
    double delta = f*f - 4*e*g;
    if (dcmp(delta) < 0) return 0;
    if (dcmp(delta) == 0)
    {
        t1 = t2 = -f / (2 * e); sol[0] = sol[1] = p + v*t1;
        return 1;
    }
    t1 = (-f - sqrt(delta)) / (2*e); sol[0] = p + v*t1;
    t2 = (-f + sqrt(delta)) / (2*e); sol[1] = p + v*t2;
    return 2;
}
double getAngle(double R, double l)
{
    return asin(R * sin( PI/6 ) / l) - PI/6;
}
bool OnSegment(Point p, Point a1, Point a2)
{
    return dcmp((a1 - p).det(a2 - p)) == 0 && dcmp((a1 - p).dot(a2 - p)) < 0;
}
int cnt;
vector <pair<double,int> > ans;
bool Section(Point a,Point b,double R)
{
    double aa = a.Angle(), bb = b.Angle();
    double da = getAngle(R, a.length()), db = getAngle(R, b.length());
    if (dcmp(aa-bb-PI) > 0) aa-=2*PI;
    else if(dcmp(bb-aa-PI) > 0) bb-=2*PI;
    double l=max(aa-da,bb-db), r = min(aa+da,bb+db);
    if (dcmp(r-l)<0)
        return false;
    cnt++;
    for(int i=0;i<6;i++)
    {
        l+=PI/3,r+=PI/3;
        if(dcmp(l-PI)>=0) l -= 2*PI;
        if(dcmp(r-PI)>=0) r -= 2*PI;
        ans.push_back(make_pair(l,-1));
        ans.push_back(make_pair(r,1) );
        if(r < l) cnt--;
    }
    return true;
}
bool getSection(Point a, Point b, Circle C)
{
    double lena = a.length(),lenb = b.length();
    if (dcmp(lena-C.r) <= 0 && dcmp(lenb-C.r) <= 0)
        return true;
    Point sol[2];
    int n = getLineCircleIntersection(a,b-a,C,sol);
    double R = C.r*sqrt3;
    if (dcmp(lena-C.r) > 0 && dcmp(lenb - C.r) > 0)
    {
        if (n == 0) return Section(a,b,R);
        bool judge0 = OnSegment(sol[0],a,b);
        bool judge1 = OnSegment(sol[1],a,b);
        if (judge0 || judge1)
            return Section(a,sol[0],R) && Section(sol[1],b,R);
        return Section(a, b, R);
    }
    if (dcmp(lena - C.r) > 0)
        return Section(a,sol[0],R);
    return Section(sol[1],b,R);
}
Point P[2000],Hull[2000];
int main()
{
    int T;
    scanf("%d",&T);
    for (int kase = 1; kase <= T; kase ++)
    {
        int m,r;
        Circle C = Circle(Point(0,0),0);
        scanf("%d%lf", &m, &C.r);
        const double R = C.r*sqrt3;
        bool flag = true;
        for (int i = 0; i < m; i++)
            scanf("%lf%lf", &P[i].x, &P[i].y);
        int n = ConvexHull(P, m, Hull);
        ans.clear();
        cnt = 0;
        for (int i = 0; i < n && flag; i++)
        {
            if (dcmp(Hull[i].length()-R) > 0 || dcmp(Hull[next].length()-R) > 0)
            {
                flag = false;
                break;
            }
            flag = getSection(Hull[i],Hull[next],C);
        }
        if (flag)
        {
            sort(ans.begin(), ans.end());
            int now = 0,h = 0;
            for (int i = 0; i < ans.size(); i++)
            {
                now -= ans[i].second;
                if (h == cnt)
                    break;
                h = max(h, now);
            }
            if (h!=cnt)
                flag = false;
        }
        printf("Case #%d: ", kase);
        if (flag) printf("Succeeded.\n");
        else printf("Failed.\n");
    }
}
