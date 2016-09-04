#include <iostream>
#include <cmath>
using namespace std;
#define max(a,b) ((a)>=(b)?(a):(b))
const int maxn = 50000;
struct node
{
    double x, y;
}pt[maxn+5];
bool set(double &tl, double &tr, double cl, double cr)
{
    if (cl>tr || tl>cr) return false;
    if (tr>cr) tr = cr;
    if (tl<cl) tl = cl;
    return true;
}
bool ok(double r, int n, double &p)
{
    int i;
    double r2 = r*r;
    double td, tl, tr;
    td = sqrt(r2-pt[0].y*pt[0].y);
    tl = pt[0].x - td;
    tr = pt[0].x + td;
    for (i=1; i<n; i++)
    {
        td = sqrt(r2-pt[i].y*pt[i].y);
        if (!set(tl, tr, pt[i].x-td, pt[i].x+td))
            return false;
    }
    p = (tl+tr)/2;
    return true;
}
void solve(int n, double &p, double &d)
{
    double low = 0, high = 3e5;
    int i;
    for (i=0; i<n; i++) low = max(low, fabs(pt[i].y));
    double mid;
    while(fabs(high-low)>1e-9)
    {
        mid = (low+high)/2;
        if (ok(mid, n, p))
        {
            d = mid;
            high = mid;
        }
        else low = mid;
    }
}
int main()
{
    int n;
    int i;
    double p, d;
    while(scanf("%d", &n)!=EOF)
    {
        if (n==0) break;
        for (i=0; i<n; i++) scanf("%lf %lf", &pt[i].x, &pt[i].y);
        solve(n, p, d);
        printf("%.9lf %.9lf\n", p, d);
    }
    return 0;
}
