#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
const int maxn = 555;
const int maxisn = 10;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x)
{
    if(x > eps) return 1;
    return x < -eps ? -1 : 0;
}
inline double min(double a, double b)
{return a < b ? a : b;}
inline double max(double a, double b)
{return a > b ? a : b;}
inline double Sqr(double x)
{return x * x;}
struct Point
{
    double x, y;
    Point(){x = y = 0;}
    Point(double a, double b)
    {x = a, y = b;}
    inline Point operator-(const Point &b)const
    {return Point(x - b.x, y - b.y);}
    inline Point operator+(const Point &b)const
    {return Point(x + b.x, y + b.y);}
    inline double dot(const Point &b)const
    {return x * b.x + y * b.y;}
    inline double cross(const Point &b, const Point &c)const
    {return (b.x - x) * (c.y - y) - (c.x - x) * (b.y - y);}
};
Point LineCross(const Point &a, const Point &b, const Point &c, const Point &d)
{
    double u = a.cross(b, c), v = b.cross(a, d);
    return Point((c.x * v + d.x * u) / (u + v), (c.y * v + d.y * u) / (u + v));
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
double CPIA(Point a[], Point b[], int na, int nb)//ConvexPolygonIntersectArea
{
    Point p[maxisn], tmp[maxisn];
    int i, j, tn, sflag, eflag;
    a[na] = a[0], b[nb] = b[0];
    memcpy(p, b, sizeof(Point) * (nb + 1));
    for(i = 0; i < na && nb > 2; ++ i)
    {
        sflag = dcmp(a[i].cross(a[i + 1], p[0]));
        for(j = tn = 0; j < nb; ++ j, sflag = eflag)
        {
            if(sflag >= 0) tmp[tn ++] = p[j];
            eflag = dcmp(a[i].cross(a[i + 1], p[j + 1]));
            if((sflag ^ eflag) == -2)
                tmp[tn ++] = LineCross(a[i], a[i + 1], p[j], p[j + 1]);
        }
        memcpy(p, tmp, sizeof(Point) * tn);
        nb = tn, p[nb] = p[0];
    }
    if(nb < 3) return 0.0;
    return PolygonArea(p, nb);
}
double SPIA(Point a[], Point b[], int na, int nb)//SimplePolygonIntersectArea
{
    int i, j;
    Point t1[4], t2[4];
    double res = 0, if_clock_t1, if_clock_t2;
    a[na] = t1[0] = a[0], b[nb] = t2[0] = b[0];
    for(i = 2; i < na; ++ i)
    {
        t1[1] = a[i - 1], t1[2] = a[i];
        if_clock_t1 = dcmp(t1[0].cross(t1[1], t1[2]));
        if(if_clock_t1 < 0) std::swap(t1[1], t1[2]);
        for(j = 2; j < nb; ++ j)
        {
            t2[1] = b[j - 1], t2[2] = b[j];
            if_clock_t2 = dcmp(t2[0].cross(t2[1], t2[2]));
            if(if_clock_t2 < 0) std::swap(t2[1], t2[2]);
            res += CPIA(t1, t2, 3, 3) * if_clock_t1 * if_clock_t2;
        }
    }
    return PolygonArea(a, na) + PolygonArea(b, nb) - res;
}
Point p1[maxn], p2[maxn];
int n1, n2;
int main()
{
    int i;
    while(scanf("%d%d", &n1, &n2) != EOF)
    {
        for(i = 0; i < n1; ++ i) scanf("%lf%lf", &p1[i].x, &p1[i].y);
        for(i = 0; i < n2; ++ i) scanf("%lf%lf", &p2[i].x, &p2[i].y);
        printf("%.2f\n", SPIA(p1, p2, n1, n2) + eps);
    }
    return 0;
}
