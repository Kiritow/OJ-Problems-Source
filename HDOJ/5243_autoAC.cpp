#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define V P
const double eps = 1e-6;
inline int dcmp (double x) {
    return x < -eps ? -1 : x > eps;
}
struct P {
    double x, y;
    void scan() {
        scanf("%lf%lf", &x, &y);
    }
    P(double _x = 0, double _y = 0) : x(_x), y(_y) { }
    V operator + (V a) const {
        return V(x + a.x, y + a.y);
    }
    V operator - (V a) const {
        return V(x - a.x, y - a.y);
    }
    V operator * (double p) const {
        return V(p * x, p * y);
    }
    V operator / (double p) const {
        return V(x / p, y / p);
    }
    bool operator < (P a) const {
        return x < a.x || (dcmp(x - a.x) == 0 && y < a.y);
    }
    bool operator == (P a) const {
        return dcmp(x - a.x) == 0 && dcmp(y - a.y) == 0;
    }
};
inline double dot(V a, V b) {
    return a.x * b.x + a.y * b.y;
}
inline double len(V a) {
    return sqrt(dot(a, a));
}
inline double dis(P a, P b) {
    return len(b - a);
}
inline double ang(V a, V b) {
    return acos(dot(a, b) / len(a) / len(b));
}
inline double cross(V a, V b) {
    return a.x * b.y - a.y * b.x;
}
inline double area(P a, P b, P c) {
    return cross(b - a, c - a);
}
V rot(V a, double p) {
    return V(a.x * cos(p) - a.y * sin(p), a.x * sin(p) + a.y * cos(p));
}
V normal(V a) {
    double L = len(a);
    return V(-a.y / L, a.x / L);
}
P inter(P p, V v, P q, V w) {
    V u = p - q;
    double t = cross(w, u) / cross(v, w);
    return p + v * t;
}
double dis(P p, P a, P b) {
    V v1 = b - a, v2 = p - a;
    return fabs(cross(v1, v2)) / len(v1);
}
double dis2(P p, P a, P b) {
    if (a == b) return len(p - a);
    V v1 = b - a, v2 = p - a, v3 = p - b;
    if (dcmp(dot(v1, v2)) < 0) return len(v2);
    else if (dcmp(dot(v1, v3)) > 0) return len(v3);
    else return fabs(cross(v1, v2)) / len(v1);
}
P proj(P p, P a, P b) {
    V v = b - a;
    return a + v * (dot(v, p - a) / dot(v, v));
}
bool isInter(P a1, P a2, P b1, P b2) {
    double c1 = cross(a2 - a1, b1 - a1), c2 = cross(a2 - a1, b2 - a1),
           c3 = cross(b2 - b1, a1 - b1), c4 = cross(b2 - b1, a2 - b1);
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
bool onSeg(P p, P a1, P a2) {
    return dcmp(cross(a1 - p, a2 - p)) == 0 && dcmp(dot(a1 - p, a2 - p)) < 0;
}
double area(P* p, int n) {
    double s = 0;
    p[n] = p[0];
    for (int i = 1; i < n; i ++)
        s += cross(p[i] - p[0], p[i + 1] - p[0]);
    return s / 2;
}
int graham(P* p, int n, P* ch) {
    sort(p, p + n);
    int m = 0;
    for (int i = 0; i < n; i ++) {
        while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m --;
        ch[m ++] = p[i];
    }
    int k = m;
    for (int i = n - 2; i >= 0; i --) {
        while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m --;
        ch[m ++] = p[i];
    }
    if (n > 1) m --;
    return m;
}
struct L {
    P p;
    V v;
    double ang;
    L() {}
    L(P _p, V _v) : p(_p), v(_v) { ang = atan2(v.y, v.y); }
    bool operator < (const L& L) const {
        return ang < L.ang;
    }
};
inline int get(P a) {
    if( a.x > 0 && a.y >= 0) return 1;
    if( a.x <= 0 && a.y > 0) return 2;
    if( a.x < 0 && a.y <= 0) return 3;
    if( a.x >= 0 && a.y < 0) return 4;
    return 0;
}
inline bool cmp2 (L a, L b) {
    return get(a.v) < get(b.v) || (get(a.v) == get(b.v) && dcmp( cross(a.v, b.v) ) >0);
}
bool onLeft(L l, P p) {
    return cross(l.v, p - l.p) > 0;
}
P inter(L a, L b) {
    return inter(a.p, a.v, b.p, b.v);
}
int half(L* l, int n, P* po) {
    sort(l, l + n, cmp2);
    int h, t;
    P *p = new P[n];
    L *q = new L[n];
    q[h = t = 0] = l[0];
    for (int i = 1; i < n; i ++) {
        while (h < t && !onLeft(l[i], p[t - 1])) t --;
        while (h < t && !onLeft(l[i], p[h])) h ++;
        q[++ t] = l[i];
        if (dcmp(cross(q[t].v, q[t - 1].v)) == 0) {
            t --;
            if (onLeft(q[t], l[i].p)) q[t] = l[i];
        }
        if (h < t) p[t - 1] = inter(q[t - 1], q[t]);
    }
    while (h < t && !onLeft(q[h], p[t - 1])) t --;
    if (t - h <= 1) return 0;
    p[t] = inter(q[t], q[h]);
    int m = 0;
    for (int i = h; i <= t; i ++) po[m ++] = p[i];
    return m;
}
inline bool cmp (V a, V b) {
    return get(a) < get(b) || (get(a) == get(b) && dcmp( cross(a, b) ) >0);
}
const int N = 101000;
int n;
P a[N], b[N], res[N];
L l[N];
int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas ++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i ++)
            a[i].scan();
        int bound = n / 3 - 1, l_c = 0;
        for (int i = 0; i < n; i ++) {
            int cnt = 0;
            for (int j = 0; j < n; j ++)
                if (j != i)
                    b[cnt ++] = a[j] - a[i];
            sort(b, b + cnt, cmp);
            int t = 0, sum = 0;
            for (int j = 0; j < cnt; j ++) {
                while ((dcmp(cross(b[j], b[(t + 1) % cnt])) == 1) ||
                        (dcmp(cross(b[j], b[(t + 1) % cnt])) == 0 &&
                         dcmp(dot(b[j], b[(t + 1) % cnt])) == -1)) t = (t + 1) % cnt, sum ++;
                if (cnt - (sum + 1) == bound) l[l_c ++] = L(a[i], b[j]);
                if (t == j) t ++;
                else {
                    while (dcmp(cross(b[j], b[(j + 1) % cnt])) == 0) j ++, sum --;
                    sum --;
                }
            }
        }
        int ans = half(l, l_c, res);
        printf("Case #%d: %.6lf\n", cas, area(res, ans));
    }
    return 0;
}
