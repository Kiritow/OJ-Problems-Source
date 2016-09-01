#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iostream>
#include <cmath>
using namespace std;
const int MAXN = 100005;
int main()
{
    int n;
    double a, p, b;
    double f0, f1, p0, p1;
    while (scanf("%d%lf%lf%lf", &n, &p, &a, &b))
    {
        if (n==0 && a==0 && p==0 && b==0) break;
        p /= 100.0;
        f0 = min(a, b);
        f1 = 0.0;
        for (int i = 1; i< n; ++i)
        {
            p0 = min(f0+b, a+p*f0+(1.0-p)*f1);
            p1 = p*f0+(1.0-p)*f1;
            f0 = p0;
            f1 = p1;
        }
        printf("%.4lf\n", f1);
    }
    return 0;
}
