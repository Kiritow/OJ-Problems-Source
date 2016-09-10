#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)
#define sqr(a) ((a) * (a))
#define dis(a, b) sqrt(sqr(a.x - b.x) + sqr(a.y - b.y))
const int MAXN = 1010;
const double PI = acos(-1.0);
int top;
struct Point {
    double x;
    double y;
    double v;
    int id;
    Point(double a = 0, double b = 0) : x(a), y(b) {}
    friend bool operator < (const Point &l, const Point &r) {
        return l.y < r.y || (l.y == r.y && l.x < r.x);
    }
} p[MAXN], res[MAXN], all[MAXN];
double mult(Point a, Point b, Point o) {
    return (a.x - o.x) * (b.y - o.y) > (b.x - o.x) * (a.y - o.y);
}
void Graham(int n) {
    top = 1;
    sort(p, p + n);
    if (n == 0) {
        top = 0;
        return;
    }
    res[0] = p[0];
    if (n == 1) {
        top = 1;
        return;
    }
    res[1] = p[1];
    if (n == 2) {
        top = 2;
        return;
    }
    res[2] = p[2];
    for (int i = 2; i < n; i++) {
        while (top && (mult(p[i], res[top], res[top - 1])))
            top--;
        res[++top] = p[i];
    }
    int len = top;
    res[++top] = p[n - 2];
    for (int i = n - 3; i >= 0; i--) {
        while (top != len && (mult(p[i], res[top], res[top - 1])))
            top--;
        res[++top] = p[i];
    }
}
int id[MAXN];
int n;
double mmax;
int main() {
    int cas = 1;
    while (~scanf("%d", &n) && n) {
        mmax = 0;
        repf (i, 0, n - 1) {
            scanf("%lf%lf%lf", &all[i].x, &all[i].y, &all[i].v);
            all[i].id = i;
            mmax = max(mmax, all[i].v);
        }
        memset(id, 0, sizeof(id));
        repf (i, 0, n - 1)
            repf (j, i + 1, n - 1) {
                if (all[i].x == all[j].x && all[i].y == all[j].y && all[i].v == all[j].v) {
                    all[j].v = 0;
                    id[i] = id[j] = -1;
                }
            }
        int cnt = 0;
        repf (i, 0, n - 1) {
            if (all[i].v == mmax)
                p[cnt++] = all[i];
        }
        if (mmax) {
            Graham(cnt);
            repf (i, 0, top - 1) {
                if (id[res[i].id] != -1)
                    id[res[i].id] = 1;
            }
        }
        printf("Case #%d: ", cas++);
        repf (i, 0, n - 1) {
            printf("%d", id[i] > 0);
        }
        puts("");
    }
    return 0;
}
