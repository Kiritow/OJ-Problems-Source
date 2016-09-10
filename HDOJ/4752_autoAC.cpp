#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
const int maxn = 20005;
const double eps = 1e-8;
int n, a, b, c, l, r;
int x[maxn], y[maxn];
double p[maxn*2];
int tot;
int dcmp(double x) {if (fabs(x) < eps) return 0; return x > 0 ? 1 : -1;}
double func(double x)
{
    return (a * x + b) * x + c;
}
bool between(double a, double b, double c) {return dcmp(a - b) > 0 && dcmp(c - a) > 0;}
bool solve(double a, double b, double c, double &x1, double &x2)
{
    double d = b*b - 4*a*c;
    if (dcmp(d) <= 0) return 0;
    d = sqrt(d);
    x1 = (-b - d) / a * 0.5;
    x2 = (-b + d) / a * 0.5;
    return 1;
}
void get(int x1, int y1, int x2, int y2)
{
    if (x1 == x2)
    {
        double y = func(x1);
        if (y1 > y2) swap(y1, y2);
        if (between(y, y1, y2)) p[tot++] = x1;
    }
    else
    {
        double k = (double)(y2 - y1) / (x2 - x1), r1, r2;
        if (solve(a, b - k, c + k * x1 - y1, r1, r2))
        {
            if (x1 > x2) swap(x1, x2);
            if (between(r1, x1, x2)) p[tot++] = r1;
            if (between(r2, x1, x2)) p[tot++] = r2;
        }
    }
}
double sqr(double x) {return x * x;}
double f(double x)
{
    return sqrt(sqr(2*a*x + b) + 1);
}
double simpson(double p1, double p2)
{
    double mid = (p1 + p2) / 2, mid1 = (p1 + mid) / 2, mid2 = (mid + p2) / 2;
    double f1 = f(p1), f2 = f(p2), fm = f(mid), fm1 = f(mid1), fm2 = f(mid2);
    double tmp = (f1 + fm * 4 + f2) * (p2 - p1) / 6;
    if (dcmp(tmp - (f1 + fm1 * 4 + fm) * (mid - p1) / 6 - (fm + fm2 * 4 + f2) * (p2 - mid) / 6) == 0) return tmp;
    return simpson(p1, mid) + simpson(mid, p2);
}
int main()
{
    int nr;
    double r1, r2;
    while (scanf("%d", &n) == 1)
    {
        scanf("%d%d%d%d%d", &a, &b, &c, &l, &r);
        for (int i=0;i<n;i++) scanf("%d%d", &x[i], &y[i]);
        x[n] = x[0]; y[n] = y[0]; x[n+1] = x[1]; y[n+1] = y[1];
        tot = 0;
        for (int i=0;i<n;i++) get(x[i], y[i], x[i+1], y[i+1]);
        for (int i=1;i<=n;i++)
        {
            double x1 = (x[i-1] - x[i]) * 1e-3 + x[i], y1 = (y[i-1] - y[i]) * 1e-3 + y[i];
            double x2 = (x[i+1] - x[i]) * 1e-3 + x[i], y2 = (y[i+1] - y[i]) * 1e-3 + y[i];
            if (dcmp(func(x1) - y1) * dcmp(func(x2) - y2) < 0) p[tot++] = x[i];
        }
        sort(p, p+tot);
        double ans = 0;
        tot--;
        for (int i=0;i<tot;i++)
            if (!(i&1)) ans += simpson(max((double)l, p[i]), min((double)r, p[i+1]));
        printf("%.2lf\n", ans);
    }
    return 0;
}
