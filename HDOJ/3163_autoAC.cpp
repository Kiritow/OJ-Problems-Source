#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
template<class T> inline void checkmax(T &a, T b)
{if (b > a) a = b;}
template<class T> inline void checkmin(T &a, T b)
{if (b < a) a = b;}
inline double sqr(double x)
{return x * x;}
struct Point {
    double x, y;
} pt[35];
int n;
double tx, ty, v, c, sx, sy, dx, dy;
double get(double p)
{
    double cx = sx + dx * p;
    double cy = sy + dy * p;
    double cur = cy / v + sqrt(sqr(cx - tx) + sqr(cy - ty)) / c;
    return cur;
}
int ansidx;
double ansp;
void work()
{
    for (int i = 1; i <= n; ++i) scanf("%lf%lf", &pt[i].x, &pt[i].y);
    pt[n + 1] = pt[1];
    double ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        dx = pt[i + 1].x - pt[i].x;
        dy = pt[i + 1].y - pt[i].y;
        sx = pt[i].x;
        sy = pt[i].y;
        for (int iter = 1; iter <= 35; ++iter) {
            double p = 0;
            for (double len = 1; len > 1e-9; len /= 1.5) for (int iter1 = 1; iter1 <= 35; ++iter1) {
                if (rand() & 1) p += len; else p -= len;
                checkmax(p, 0.0);
                checkmin(p, 1.0);
                double tmp = get(p);
                if (tmp < ans) {
                    ans = tmp;
                    ansidx = i;
                    ansp = p;
                }
            }
        }
    }
    double trueans = ans;
    ansp -= 5000 * 1e-7;
    for (int i = 0; i < 10000; ++i, ansp += 1e-7) {
        dx = pt[ansidx + 1].x - pt[ansidx].x;
        dy = pt[ansidx + 1].y - pt[ansidx].y;
        sx = pt[ansidx].x;
        sy = pt[ansidx].y;
        if (ansp > -1e-7 && ansp < 1 + 1e-7) checkmin(trueans, get(ansp));
    }
    printf("%0.4lf\n", trueans);
}
int main()
{
    while (scanf("%d%lf%lf%lf%lf", &n, &tx, &ty, &v, &c), n) work();
}
