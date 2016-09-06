#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
const double eps = 1e-6;
const double PI = acos(-1.0);
double cx, cy, cr; 
inline int sign(double x) {
    return x < -eps ? -1 : x > eps ? 1 : 0;
}
struct Point {
    double x, y;
    Point (double xx = 0, double yy = 0) : x(xx), y(yy) {}
    Point operator - (const Point &ot) const { 
        return Point(x - ot.x , y - ot.y);
    }
    double operator * (const Point &ot) const {
        return x * ot.x + y * ot.y;
    }
    double operator ^ (const Point &ot) const { 
        return x * ot.y - y * ot.x;
    }
    bool operator < (const Point &ot) const {
        if (sign(x - ot.x)) {
            return sign(x - ot.x) < 0; 
        } else {  
            return sign(y - ot.y) < 0;
        }
    }
    void show() {
        printf("x = %.2f, y = %.2f\n", x, y);
    }
};
Point it, rp[4];
double dist(const Point &a, const Point &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double dtoL(const Point &np, const Point &st, const Point &ed) {
    double ret; 
    if (sign((ed-st)*(np-st)) > 0 && sign((st-ed)*(np-ed) > 0)) { 
        ret = fabs((st-np)^(ed-np)) / dist(st, ed);
    } else {
        ret = min(dist(np, st), dist(np, ed)); 
    }
    return ret;
}
double dtoR(const Point &np) { 
    double d1 = min(dtoL(np, rp[0], rp[1]), dtoL(np, rp[0], rp[2]));
    double d2 = min(dtoL(np, rp[1], rp[3]), dtoL(np, rp[2], rp[3]));
    return min(d1, d2);
}
double tsearch(double l, double r) {
    double delta;
    while (r - l >= eps) {
        delta = (r - l) / 3.0; 
        Point Lp(cr*cos(l+delta), cr*sin(l+delta));
        Point Rp(cr*cos(r-delta), cr*sin(r-delta));
        double d1 = dist(it, Lp) + dtoR(Lp);
        double d2 = dist(it, Rp) + dtoR(Rp);
        if (sign(d1 - d2) > 0) {
            l += delta;
        } else {
            r -= delta;
        }
    }
    Point fp(cr*cos(r), cr*sin(r));
    return dist(it, fp) + dtoR(fp);
}
void solve() {
    printf("%.2f\n", min(tsearch(0, PI), tsearch(PI, 2*PI)));
}
int main() {
    while (scanf("%lf %lf", &it.x, &it.y), sign(it.x) | sign(it.y)) {
        scanf("%lf %lf %lf", &cx, &cy, &cr);
        it.x -= cx, it.y -= cy;           
        scanf("%lf %lf", &rp[0].x, &rp[0].y);
        rp[0].x -= cx, rp[0].y -= cy;
        scanf("%lf %lf", &rp[1].x, &rp[1].y);
        rp[1].x -= cx, rp[1].y -= cy;
        rp[2].x = rp[0].x, rp[2].y = rp[1].y;
        rp[3].x = rp[1].x, rp[3].y = rp[0].y;
        sort(rp, rp+4); 
        double t = sqrt(2.0) / 2;
        solve();
    }
    return 0;
}
