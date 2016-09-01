#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const double PI = acos(-1.0);
int l1, l2, l3, m1, m2, m3;
int hh, mm, ss;
int st, ed;
struct point_t {
    double x, y;
    point_t() {}
    point_t(double _x, double _y) { x = _x, y = _y; }
};
double dist(const point_t &a, const point_t &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
point_t calc(int t) {
    double a = 2.0 * PI * t / 43200.0;
    double b = 2.0 * PI * t / 3600.0;
    double c = 2.0 * PI * t / 60.0;
    double ra = m1 * 1.0 / (m1 + m2 + m3);
    double rb = m2 * 1.0 / (m1 + m2 + m3);
    double rc = m3 * 1.0 / (m1 + m2 + m3);
    point_ A(l1 * ra * cos(a), l1 * ra * sin(a));
    point_ B(l2 * rb * cos(b), l2 * rb * sin(b));
    point_ C(l3 * rc * cos(c), l3 * rc * sin(c));
    return point_t(A.x + B.x + C.x, A.y + B.y + C.y);
}
int main() {
    while (scanf("%d", &l1) != EOF && l1 != -1) {
        scanf("%d%d%d%d%d", &l2, &l3, &m1, &m2, &m3);
        scanf("%d:%d:%d", &hh, &mm, &ss);
        st = hh * 3600 + mm * 60 + ss;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        ed = hh * 3600 + mm * 60 + ss;
        double ans = 0.0;
        point_t pre = calc(st);
        for (int t = st + 1; t <= ed; t ++) {
            point_t now = calc(t);
            ans += dist(pre, now);
            pre = now;
        }
        printf("%.2lf\n", ans * 0.5);
    }
    return 0;
}
