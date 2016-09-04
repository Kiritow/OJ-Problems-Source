#include<stdio.h>
#include<math.h>
#include<algorithm>
#define eps 1e-8
#define PI 3.14159265358979323846
using namespace std;
struct pt
{
    double x, y;
    double ang;
    double p;
};
int n;
int idx[1010];
pt p[1010];
inline double toAng(double a, double b)
{
    double ret = b - a;
    if (ret > 2*PI - eps)
        ret -= 2*PI;
    return ret < -eps ? (ret + 2*PI) : ret;
}
bool cmp(int a, int b)
{
    return p[a].ang < p[b].ang;
}
double calc(int a)
{
    if (p[a].p < eps)
        return 0.0;
    double tp = 0.0;    
    int m = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (i != a)tp += log(1.0 - p[i].p);
        p[i].ang = (i == a) ? 10.0 : atan2(p[i].y - p[a].y, p[i].x - p[a].x);
    }
    sort(idx, idx + n, cmp);
    double noP = 0.0, ret = 0.0;
    int r = 0;
    for (int i = 0; i < n - 1; i++)
    {
        while (r - i < m && toAng(p[idx[i]].ang, p[idx[r%m]].ang) < PI)
        {
            noP += log(1.0 - p[idx[r%m]].p);
            r++;
        }
        noP -= log(1.0 - p[idx[i]].p);
        ret += p[idx[i]].p * exp(noP);
    }
    return p[a].p * (ret + exp(tp));
}
double solve()
{
    if (n == 1)
        return p[0].p;
    double ans = 0.0;
    for (int i = 0; i < n; i++)
    {
        ans += calc(i);
    }
    return ans;
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].p);
            p[i].p /= 100.0;
            idx[i] = i;
        }
        printf("%.2lf\n", solve());
    }
    return 0;
}
