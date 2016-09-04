#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
const int maxn = 10;
const double eps = 1e-8;
const double PI = acos(-1.0);
int dcmp(double x)
{ return (x > eps) - (x < -eps); }
struct Point
{
    double x, y;
    Point(double x=0, double y=0):x(x), y(y) {}
    void read() { scanf("%lf%lf", &x, &y); }
};
typedef Point Vector;
Point operator + (const Vector& a, const Vector& b)
{ return Point(a.x+b.x, a.y+b.y); }
Point operator - (const Vector& a, const Vector& b)
{ return Point(a.x-b.x, a.y-b.y); }
Vector operator * (const Vector& a, double p)
{ return Point(a.x*p, a.y*p); }
Vector operator / (const Vector& a, double p)
{ return Point(a.x/p, a.y/p); }
bool operator == (const Point& a, const Point& b)
{ return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0; }
double Dot(const Vector& a, const Vector& b)
{ return a.x*b.x + a.y*b.y; }
double Cross(const Vector& a, const Vector& b)
{ return a.x*b.y - a.y*b.x; }
double Length(const Vector& a)
{ return sqrt(Dot(a, a)); }
Vector unit(const Vector& a)
{ return a / Length(a); }
Vector Normal(const Vector& a)
{
    double l = Length(a);
    return Vector(-a.y/l, a.x/l);
}
double Angle(const Vector& a)
{ return atan2(a.y, a.x); }
Point Rotate(const Point& p, double angle, const Point& o = Point(0, 0))
{
    Vector t = p - o;
    t = Vector(t.x*cos(angle)-t.y*sin(angle), t.x*sin(angle)+t.y*cos(angle));
    return t + o;
}
struct Region
{
    double st, ed;
    Region(double s=0, double e=0):st(s), ed(e) {}
};
struct Circle
{
    Point c;
    double r;
    Circle() {}
    Circle(Point c, double r):c(c), r(r) {}
    void read() { c.read(); scanf("%lf", &r); }
    double area() const { return PI * r * r; }
    bool contain(const Circle& rhs) const
    { return dcmp(Length(c-rhs.c) + rhs.r - r) <= 0; }
    bool contain(const Point& p) const
    { return dcmp(Length(c-p) - r) <= 0; }
    bool intersect(const Circle& rhs) const
    { return dcmp(Length(c-rhs.c) - r - rhs.r) < 0; }
    bool tangency(const Circle& rhs) const
    { return dcmp(Length(c-rhs.c) - r - rhs.r) == 0; }
    Point get_point(double ang) const
    { return Point(c.x + r * cos(ang), c.y + r * sin(ang)); }
};
void IntersectionPoint(const Circle& c1, const Circle& c2, Point& p1, Point& p2)
{
    double d = Length(c1.c - c2.c);
    double l = (c1.r*c1.r + d*d - c2.r*c2.r) / (2 * d);
    double h = sqrt(c1.r*c1.r - l*l);
    Point mid = c1.c + unit(c2.c-c1.c) * l;
    Vector t = Normal(c2.c - c1.c) * h;
    p1 = mid + t;
    p2 = mid - t;
}
double IntersectionArea(const Circle& c1, const Circle& c2)
{
    double area = 0.0;
    const Circle& M = c1.r > c2.r ? c1 : c2;
    const Circle& N = c1.r > c2.r ? c2 : c1;
    double d = Length(c1.c-c2.c);
    if(d < M.r + N.r && d > M.r - N.r)
    {
        double Alpha = 2.0 * acos((M.r*M.r + d*d - N.r*N.r) / (2 * M.r * d));
        double Beta  = 2.0 * acos((N.r*N.r + d*d - M.r*M.r) / (2 * N.r * d));
        area = ( M.r*M.r*(Alpha - sin(Alpha)) + N.r*N.r*(Beta - sin(Beta)) ) / 2.0;
    }
    else if(d <= M.r - N.r) area = N.area();
    return area;
}
struct Region_vector
{
    int n;
    Region v[5];
    void clear() { n = 0; }
    void add(const Region& r) { v[n++] = r; }
} *last, *cur;
Circle cir[maxn];
bool del[maxn];
double r;
int n = 5;
bool IsOnlyOnePoint()
{
    bool flag = false;
    Point t;
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(cir[i].tangency(cir[j]))
            {
                t = (cir[i].c + cir[j].c) / 2;
                flag = true;
                break;
            }
        }
    }
    if(!flag) return false;
    for(int i = 0; i < n; ++i)
        if(!cir[i].contain(t)) return false;
    printf("Only the point (%.2f, %.2f) is for victory.\n", t.x, t.y);
    return true;
}
bool solve()
{
    if(IsOnlyOnePoint()) return true;
    memset(del, false, sizeof(del));
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            if(del[j] || i == j) continue;
            if(cir[i].contain(cir[j]))
            {
                del[i] = true;
                break;
            }
        }
    double ans = 0.0;
    for(int i = 0; i < n; ++i)
    {
        if(del[i]) continue;
        last->clear();
        Point p1, p2;
        for(int j = 0; j < n; ++j)
        {
            if(del[j] || i == j) continue;
            if(!cir[i].intersect(cir[j])) return false;
            cur->clear();
            IntersectionPoint(cir[i], cir[j], p1, p2);
            double rs = Angle(p2 - cir[i].c);
            double rt = Angle(p1 - cir[i].c);
            if(dcmp(rs) < 0) rs += 2 * PI;
            if(dcmp(rt) < 0) rt += 2 * PI;
            if(last->n == 0)
            {
                if(dcmp(rt - rs) < 0)
                {
                    cur->add(Region(rs, 2*PI));
                    cur->add(Region(0,  rt));
                }
                else cur->add(Region(rs, rt));
            }
            else
            {
                for(int k = 0; k < last->n; ++k)
                {
                    if(dcmp(rt - rs) < 0)
                    {
                        if(dcmp(last->v[k].st-rt) >= 0 && dcmp(last->v[k].ed-rs) <= 0) continue;
                        if(dcmp(last->v[k].st-rt) < 0) cur->add(Region(last->v[k].st, std::min(last->v[k].ed, rt)));
                        if(dcmp(last->v[k].ed-rs) > 0) cur->add(Region(std::max(last->v[k].st, rs), last->v[k].ed));
                    }
                    else
                    {
                        if(dcmp(rt-last->v[k].st <= 0 || dcmp(rs-last->v[k].ed) >= 0)) continue;
                        cur->add(Region(std::max(rs, last->v[k].st), std::min(rt, last->v[k].ed)));
                    }
                }
            }
            std::swap(cur, last);
            if(last->n == 0) break;
        }
        for(int j = 0; j < last->n; ++j)
        {
            p1 = cir[i].get_point(last->v[j].st);
            p2 = cir[i].get_point(last->v[j].ed);
            ans += Cross(p1, p2) / 2;
            double ang = last->v[j].ed - last->v[j].st;
            ans += cir[i].r * cir[i].r * (ang - sin(ang)) / 2;
        }
    }
    if(dcmp(ans) == 0) return false;
    printf("The total possible area is %.2f.\n", ans);
    return true;
}
int main(void)
{
    last = new Region_vector;
    cur =  new Region_vector;
    while(scanf("%lf", &r) == 1)
    {
        Point t;
        for(int i = 0; i < n; ++i)
        {
            t.read();
            cir[i] = Circle(t, r);
        }
        if(!solve())
            puts("Poor iSea, maybe 2012 is coming!");
    }
    return 0;
}
