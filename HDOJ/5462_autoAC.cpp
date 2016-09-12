#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
typedef long long LL;
const int maxn = 1005;
const double eps = 1e-7;
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) { }
    bool operator < (const Point &a) const {
        return a.x < x || (a.x == x && a.y < y);
    }
};
typedef Point Vector;
struct Line
{
    Point P;
    Vector v;
    double ang;
    Line() {}
    Line(Point P, Vector v) : P(P), v(v) { ang = atan2(v.y, v.x); }
    bool operator < (const Line &L) const {
        return ang < L.ang;
    }
};
Vector operator + (Vector A, Vector B) 
{
    return Vector(A.x + B.x, A.y + B.y);
}
Vector operator - (Vector A, Vector B)
{
    return Vector(A.x - B.x, A.y - B.y);
}
Vector operator * (Vector A, double p)
{
    return Vector(A.x * p, A.y * p);
}
Vector operator / (Vector A, double p)
{
    return Vector(A.x / p, A.y / p);
}
int dcmp(double x)
{
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
}
double Dot(Vector A, Vector B)
{
    return A.x * B.x + A.y * B.y;
}
double Length(Vector A)
{
    return sqrt(Dot(A, A));
}
double Angle(Vector A, Vector B)
{
    return acos(Dot(A, B) / Length(A) / Length(B));
}
double Cross(Vector A, Vector B)
{
    return A.x * B.y - A.y * B.x;
}
double Area2(Point A, Point B, Point C)
{
    return Cross(B - A, C - A);
}
double PolyonArea(Point *p, int n)
{
    double area = 0;
    for(int i = 1; i < n-1; i++)
        area += Cross(p[i] - p[0], p[i+1] - p[0]);
    return area / 2;
}
Vector Rotate(Vector A, double rad)
{
    return Vector(A.x * cos(rad) - A.y * sin(rad), A.x * sin(rad) + A.y * cos(rad));
}
Vector Normal(Vector A)
{
    double L = Length(A);
    return Vector(-A.y / L, A.x / L);
}
bool OnLeft(Line L, Point p)
{
    return Cross(L.v, p - L.P) > 0;
}
Point GetIntersection(Line a, Line b)
{
    Vector u = a.P - b.P;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.P + a.v * t;
}
int ConvexHull(Point *p, int n, Point *ch)
{
    sort(p, p+n);
    int m = 0;
    for(int i = 0; i < n; i++) {
        while(m > 1 && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    int k = m;
    for(int i = n-2; i >= 0; i--) {
        while(m > k && Cross(ch[m-1] - ch[m-2], p[i] - ch[m-2]) <= 0) m--;
        ch[m++] = p[i];
    }
    if(n > 1) m--;
    return m;
}
Point p[maxn];
Line q[maxn];
int HalfplaneInersection(Line* L, int n, Point* poly)
{
    sort(L, L+n);
    int first, last;
    q[first = last = 0] = L[0];
    for(int i = 1; i < n; i++) {
        while(first < last && !OnLeft(L[i], p[last - 1])) last--;
        while(first < last && !OnLeft(L[i], p[first])) first++;
        q[++last] = L[i];
        if(fabs(Cross(q[last].v, q[last-1].v)) < eps) {
            last--;
            if(OnLeft(q[last], L[i].P)) q[last] = L[i];
        }
        if(first < last) p[last-1] = GetIntersection(q[last-1], q[last]);
    }
    while(first < last && !OnLeft(q[first], p[last-1])) last--;
    if(last - first <= 1) return 0;
    p[last] = GetIntersection(q[last], q[first]);
    int m = 0;
    for(int i = first; i <= last; i++) poly[m++] = p[i];
    return m;
}
double PolygonArea(Point *p, int n) {
    double area = 0;
    for(int i = 1; i < n-1; i++)
        area += Cross(p[i] - p[0], p[i+1] - p[0]);
    return fabs(area / 2);
}
Point poly[1005];
Point g[105][2005];
Point P2[10];
Line line[105];
double twox[105][2005];
double twoy[105][2005];
double xx[105][2005];
double yy[105][2005];
int n, m;
void work()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        twox[i][0] = twoy[i][0] = xx[i][0] = yy[i][0] = 0;
        for(int j = 1; j <= m; j++) {
            scanf("%lf%lf", &g[i][j].x, &g[i][j].y);
            twox[i][j] = g[i][j].x * g[i][j].x;
            twoy[i][j] = g[i][j].y * g[i][j].y;
            twox[i][j] += twox[i][j-1];
            twoy[i][j] += twoy[i][j-1];
            xx[i][j] = g[i][j].x + xx[i][j-1];
            yy[i][j] = g[i][j].y + yy[i][j-1];
        }
    }
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            double a = 0, b = 0, c = 0;
            a = 2 * (xx[i][m] - xx[j][m]);
            b = 2 * (yy[i][m] - yy[j][m]);
            c += twox[j][m] + twoy[j][m];
            c -= twox[i][m] + twoy[i][m];
            Point P;
            Vector v(b, -a);
            if(fabs(a) > fabs(b)) P = Point(-c / a, 0);
            else P = Point(0, -c / b);
            line[cnt++] = Line(P, v);
        }
        for(int j = 0; j < 4; j++) {
            line[cnt++] = Line(P2[j], P2[(j+1)%4] - P2[j]);
        }
        int t = HalfplaneInersection(line, cnt, poly);
        double area = PolygonArea(poly, t);
        int ans = area + 0.5;
        printf("%d%c", ans, i == n ? '\n' : ' ');
    }
}
int main()
{
    P2[0] = Point(0, 0);
    P2[1] = Point(4095, 0);
    P2[2] = Point(4095, 4095);
    P2[3] = Point(0, 4095);
    int _;
    scanf("%d", &_);
    for(int i = 1; i <= _; i++) {
        printf("Case #%d: ", i);
        work();
    }
    return 0;
}
