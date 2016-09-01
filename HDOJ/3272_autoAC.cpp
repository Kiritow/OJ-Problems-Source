#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
typedef long long ll;
const int N = 0;
struct Point {
    double x;
    double y;
} h, o, p[3];
double dis(const Point& a, const Point& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double calc(int a, int b) {
    double ret = dis(h, p[a]) + dis(p[a], p[b]) + dis(p[b], h);
    double ha, ab, bh;
    bool cx = 0, cy = 0;
    if (h.x * p[a].x <= 0 || p[a].x * p[b].x <= 0 || p[b].x * h.x <= 0)
        cx = 1;
    if (h.y * p[a].y <= 0 || p[a].y * p[b].y <= 0 || p[b].y * h.y <= 0)
        cy = 1;
    if (cx == 0 && cy == 0) {
        Point t1, t2;
        t1.x = h.x;
        t1.y = -h.y;
        t2.x = -p[a].x;
        t2.y = p[a].y;
        ha = ret - dis(h, p[a]) + dis(t1, t2);
        t1.x = p[b].x;
        t1.y = -p[b].y;
        t2.x = -p[a].x;
        t2.y = p[a].y;
        ab = ret - dis(p[a], p[b]) + dis(t1, t2);
        t1.x = p[b].x;
        t1.y = -p[b].y;
        t2.x = -h.x;
        t2.y = h.y;
        bh = ret - dis(h, p[b]) + dis(t1, t2);
        double ans = min(ha, min(ab, bh));
        t1.x = p[a].x;
        t1.y = -p[a].y;
        t2.x = -p[a].x;
        t2.y = p[a].y;
        ans = min(ans, ret - dis(p[a], h) + dis(t1, h) - dis(p[a], p[b]) + dis(t2, p[b]));
        t1.x = h.x;
        t1.y = -h.y;
        t2.x = -h.x;
        t2.y = h.y;
        ans = min(ans, ret - dis(p[a], h) + dis(p[a], t1) - dis(h, p[b]) + dis(t2, p[b]));
        t1.x = p[a].x;
        t1.y = -p[a].y;
        t2.x = -p[a].x;
        t2.y = p[a].y;
        ans = min(ans, ret - dis(p[a], p[b]) + dis(t1, p[b]) - dis(p[a], h) + dis(t2, h));
        t1.x = p[b].x;
        t1.y = -p[b].y;
        t2.x = -p[b].x;
        t2.y = p[b].y;
        ans = min(ans, ret - dis(p[a], p[b]) + dis(t1, p[a]) - dis(p[b], h) + dis(t2, h));
        t1.x = h.x;
        t1.y = -h.y;
        t2.x = -h.x;
        t2.y = h.y;
        ans = min(ans, ret - dis(p[b], h) + dis(p[b], t1) - dis(h, p[a]) + dis(t2, p[a]));
        t1.x = p[b].x;
        t1.y = -p[b].y;
        t2.x = -p[b].x;
        t2.y = p[b].y;
        ans = min(ans, ret - dis(h, p[b]) + dis(t1, h) - dis(p[b], p[a]) + dis(t2, p[a]));
        ret = ans;
    } else if (cx == 1 && cy == 0) {
        Point tmp;
        tmp.x = p[a].x;
        tmp.y = -p[a].y;
        ha = ret - dis(h, p[a]) + dis(h, tmp);
        ab = ret - dis(p[a], p[b]) + dis(tmp, p[b]);
        tmp.x = p[b].x;
        tmp.y = -p[b].y;
        bh = ret - dis(h, p[b]) + dis(h, tmp);
        ret = min(ha, min(ab, bh));
    } else if (cx == 0 && cy == 1) {
        Point tmp;
        tmp.x = -p[a].x;
        tmp.y = p[a].y;
        ha = ret - dis(h, p[a]) + dis(h, tmp);
        ab = ret - dis(p[a], p[b]) + dis(tmp, p[b]);
        tmp.x = -p[b].x;
        tmp.y = p[b].y;
        bh = ret - dis(h, p[b]) + dis(h, tmp);
        ret = min(ha, min(ab, bh));
    }
    return ret;
}
int main() {
    o.x = 0;
    o.y = 0;
    int t;
    cin >> t;
    while (cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >> h.x >> h.y) {
        printf("%.2f\n", calc(0, 1));
    }
    return 0;
}
