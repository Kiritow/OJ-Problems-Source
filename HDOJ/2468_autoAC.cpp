#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn = 5111;
const double eps = 1e-12;
const double pi = acos(-1.0);
typedef struct{double x, y;}Point;
int dcmp(double x) {return (x > eps) - (x < -eps);}
inline double det(double x1, double y1, double x2, double y2)
{return x1 * y2 - x2 * y1;}
double cross(Point a, Point b, Point c)
{return det(b.x -a.x, b.y - a.y, c.x - a.x, c.y - a.y);}
bool EqualPoint(Point a, Point b)
{return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;}
typedef struct{Point s, e;double ang, d;}Line;
Point MakePoint(double xx, double yy)
{Point res;res.x = xx, res.y = yy;return res;}
void SetLine(Point a, Point b, Line &l)
{
    l.s = a;
    l.e = b;
    l.ang = atan2(b.y - a.y, b.x - a.x);
    if(dcmp(a.x - b.x)) l.d = (a.x * b.y - b.x * a.y) / fabs(a.x - b.x);
    else l.d = (a.x * b.y - b.x * a.y) / fabs(a.y - b.y);
}
bool Parallel(const Line &la, const Line &lb)
{
    return !dcmp( (la.e.x - la.s.x) * (lb.e.y - lb.s.y) -
            (la.e.y - la.s.y) * (lb.e.x - lb.s.x) );
}
Point CrossPoint(const Line &la, const Line &lb)
{
    Point res;
    double u = cross(la.s, la.e, lb.s), v = cross(la.e, la.s, lb.e);
    res.x = (lb.s.x * v + lb.e.x * u) / (u + v);
    res.y = (lb.s.y * v + lb.e.y * u) / (u + v);
    return res;
}
int CompL(const void *a, const void *b)
{
    Line la = *(Line*)a, lb = *(Line*)b;
    if(dcmp(la.ang - lb.ang)) return la.ang > lb.ang ? 1 : -1;
    return la.d > lb.d ? 1 : -1;
}
Line deq[maxn];
bool HalfPanelCross(Line l[], int n, Point cp[], int &m)
{
    int i, tn;
    m = 0;
    qsort(l, n, sizeof(Line), CompL);
    for(i = tn = 1; i < n; ++ i)
        if(dcmp(l[i].ang - l[i - 1].ang))
            l[tn ++] = l[i];
    n = tn;
    int front = 0, rear = 1;
    deq[0] = l[0], deq[1] = l[1];
    for(i = 2; i < n; ++ i)
    {
        if(Parallel(deq[rear], deq[rear - 1]) ||
            Parallel(deq[front], deq[front + 1]))
            return false;
        while(front < rear && dcmp( cross(l[i].s, l[i].e,
            CrossPoint(deq[rear], deq[rear - 1])) ) < 0) -- rear;
        while(front < rear && dcmp( cross(l[i].s, l[i].e,
            CrossPoint(deq[front], deq[front + 1])) ) < 0) ++ front;
        deq[++ rear] = l[i];
    }
    while(front < rear && dcmp( cross(deq[front].s, deq[front].e,
        CrossPoint(deq[rear], deq[rear - 1])) ) < 0) -- rear;
    while(front < rear && dcmp( cross(deq[rear].s, deq[rear].e,
        CrossPoint(deq[front], deq[front + 1])) ) < 0) ++ front;
    if(rear <= front + 1) return false;
    for(i = front; i < rear; ++ i)
        cp[m ++] = CrossPoint(deq[i], deq[i + 1]);
    if(front < rear + 1)
        cp[m ++] = CrossPoint(deq[front], deq[rear]);
    m = unique(cp, cp + m, EqualPoint) - cp;
    for(i = 0; i < m; ++ i)
    {
        if(dcmp(cp[i].x) == 0) cp[i].x = 0;
        if(dcmp(cp[i].y) == 0) cp[i].y = 0;
    }
    return true;
}
double PolygonArea(Point p[], int n)
{
    if(n < 3) return 0.0;
    double s = p[0].y * (p[n - 1].x - p[1].x);
    p[n] = p[0];
    for(int i = 1; i < n; ++ i)
        s += p[i].y * (p[i - 1].x - p[i + 1].x);
    return fabs(s * 0.5);
}
Line l[maxn << 2];
Point p[maxn << 2];
double len;
int n, m, ltp;
double maxv, minv, ti;
double start, en, v;
int main()
{
    int ca = 0;
    while(scanf("%lf", &len), dcmp(len))
    {
        ltp = 0;
        scanf("%d", &n);
        while(n --)
        {
            scanf("%lf%lf%lf", &minv, &maxv, &ti);
            SetLine(MakePoint(ti, 0), MakePoint(ti + 1, minv), l[ltp ++]);
            SetLine(MakePoint(ti + 1, maxv), MakePoint(ti, 0), l[ltp ++]);
        }
        scanf("%d", &m);
        while(m --)
        {
            scanf("%lf%lf%lf", &minv, &maxv, &ti);
            SetLine(MakePoint(ti + 1, len - minv), MakePoint(ti, len), l[ltp ++]);
            SetLine(MakePoint(ti, len), MakePoint(ti + 1, len - maxv), l[ltp ++]);
        }
        scanf("%lf%lf%lf", &start, &en, &v);
        printf("Case #%d: ", ++ ca);
        SetLine(MakePoint(0, 0), MakePoint(1, 0), l[ltp ++]);
        SetLine(MakePoint(1, len), MakePoint(0, len), l[ltp ++]);
        SetLine(MakePoint(start + 1, v), MakePoint(start, 0), l[ltp ++]);
        SetLine(MakePoint(en, 0), MakePoint(en + 1, v), l[ltp ++]);
        if(!HalfPanelCross(l, ltp, p, n)){printf("0.00000\n"); continue;}
        printf("%.5f\n", PolygonArea(p, n) / (en - start) / len + eps);
    }
    return 0;
}
