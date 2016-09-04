#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int dcmp(double x) {
    if(fabs(x) < eps)
        return 0;
    return x > eps ? 1 : -1;
}
struct point {
    double x, y;
    point(double x = 0, double y = 0) :
            x(x), y(y) {
    }
    point operator-(const point &t) const {
        return point(x - t.x, y - t.y);
    }
    point operator*(const double &t) const {
        return point(x * t, y * t);
    }
    void in() {
        scanf("%lf%lf", &x, &y);
    }
} p[4];
double dis(point a, point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double angle(double a, double b, double c) {
    return acos((b * b + c * c - a * a) / (2 * b * c));
}
struct tri {
    point p[3];
    double d[3], jiao[3];
    void in() {
        int i;
        for(i = 0; i < 3; i++)
            p[i].in();
        for(i = 0; i < 3; i++)
            d[i] = dis(p[i], p[(i + 1) % 3]);
        sort(d, d + 3);
        for(i = 0; i < 3; i++)
            jiao[i] = angle(d[i], d[(i + 1) % 3], d[(i + 2) % 3]);
    }
} t1, t2;
double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}
bool judge(int x, int y, int a, int b) {
    int f1 = dcmp(cross(p[y] - p[x], p[a] - p[x]));
    int f2 = dcmp(cross(p[y] - p[x], p[b] - p[x]));
    if(!f1 || !f2)
        return 0;
    if(f1 != f2)
        return 1;
    return 0;
}
bool equal(point a, point b, point c, tri t) {
    point p[3];
    double d[3];
    p[0] = a;
    p[1] = b;
    p[2] = c;
    int i;
    for(i = 0; i < 3; i++)
        d[i] = dis(p[i], p[(i + 1) % 3]);
    sort(d, d + 3);
    for(i = 0; i < 3; i++)
        if(d[i] != t.d[i])
            return 0;
    return 1;
}
bool Cao(double a, double b, double c, double *dd) {
    double d[4];
    d[0] = a;
    d[1] = b;
    d[2] = c;
    sort(d, d + 3);
    for(int i = 0; i < 3; i++)
        if(dcmp(d[i] - dd[i]))
            return 0;
    return 1;
}
typedef pair <double, double> pii;
int main() {
    int i, j, cas, ca = 1;
    scanf("%d", &cas);
    while(cas--) {
        t1.in();
        t2.in();
        for(i = 0; i < 4; i++)
            p[i].in();
        printf("Case #%d: ", ca++);
        bool ok = 0;
        if(judge(0, 2, 1, 3)) {
            if(!ok && equal(p[0], p[1], p[2], t1)
                    && equal(p[0], p[3], p[2], t2))
                ok = 1;
            if(!ok && equal(p[0], p[1], p[2], t2)
                    && equal(p[0], p[3], p[2], t1))
                ok = 1;
        }
        if(judge(1, 3, 0, 2)) {
            if(!ok && equal(p[1], p[0], p[3], t1)
                    && equal(p[1], p[2], p[3], t2))
                ok = 1;
            if(!ok && equal(p[1], p[0], p[3], t2)
                    && equal(p[1], p[2], p[3], t1))
                ok = 1;
        }
        if(!ok) {
            int i, j, k;
            point q[4];
            int pos = -1;
            for(i = 0; i < 4; i++)
                if(!dcmp(
                        cross(p[i] - p[(i + 2) % 4],
                                p[(i + 1) % 4] - p[(i + 2) % 4]))) {
                    pos = (i + 1) % 4; 
                    break;
                }
            loop: int tot = 0;
            if(pos != -1) {
                for(i = 0; i < 4; i++)
                    if(i != pos) {
                        q[tot++] = p[i];
                    }
                for(i = 0; i < 3; i++)
                    p[i] = q[i];
                double area1 = fabs(cross(t1.p[0] - t1.p[1], t1.p[0] - t1.p[2]))
                        + fabs(cross(t2.p[0] - t2.p[1], t2.p[0] - t2.p[2]));
                double area2 = fabs(cross(p[0] - p[1], p[2] - p[1]));
                if(!dcmp(area1 - area2)) {
                    double dd[4]; 
                    for(i = 0; i < 3; i++)
                        dd[i] = dis(p[i], p[(i + 1) % 3]);
                    sort(dd, dd + 3);
                    for(i = 0; i < 3; i++)
                        for(j = 0; j < 3; j++)
                            if(!dcmp(t1.d[i] - t2.d[j])) {    
                                int x, y;
                                vector <pii> la, lb;
                                for(x = 0; x < 3; x++)
                                    if(x != i)
                                        la.push_back(
                                                make_pair(t1.d[x], t1.jiao[x]));
                                for(x = 0; x < 3; x++)
                                    if(x != j)
                                        lb.push_back(
                                                make_pair(t2.d[x], t2.jiao[x]));
                                for(x = 0; x < 2; x++)     
                                    for(y = 0; y < 2; y++) {
                                        if(!dcmp(la[x].second + lb[y].second- pi)
                                                && Cao(la[x].first, lb[y].first, la[x ^ 1].first + lb[y ^ 1].first, dd))
                                            ok = 1;
                                    }
                            }
                }
            }
        }
        if(ok)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
