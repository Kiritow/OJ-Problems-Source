#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<map>
#define pi (2*acos(0))
#define maxn 1000000
using namespace std;
int main()
{
    int t;
    scanf("%d", &t);
    for (int k=1;k<=t;k++)
    {
        double ax, ay, bx, by, cx, cy;
        scanf("%lf%lf%lf%lf%lf%lf", &ax, &ay, &bx, &by, &cx, &cy);
        double t1 = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
        double ab = sqrt(t1);
        double t2 = (bx - cx) * (bx - cx) + (by - cy) * (by - cy);
        double bc = sqrt(t2);
        double h = sqrt(t1 - t2/4);
        double angle = acos(bc/(2.0*ab));
        double d = bc / sin(angle);
        double ans = 0;
        ans = d * angle;
        ans = ans + h;
        printf("Case #%d: %.4f\n", k, ans);
    }
    return 0;
}
