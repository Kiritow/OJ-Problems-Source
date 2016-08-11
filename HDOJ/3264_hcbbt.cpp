/*
*  Author:      illuz <iilluzen[at]gmail.com>
*  Blog:        http://blog.csdn.net/hcbbt
*  File:        3264.cpp
*  Create Date: 2014-08-12 20:25:57
*  Descripton:  Geometry, the insection of two round, binary
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define repf(i,a,b) for(int i=(a);i<=(b);i++)

typedef long long ll;

const int N = 21;
const double PI = acos(-1.0);
const double EPS = 1e-8;

int t, n;

struct Round {
    double x, y;
    double r;
} r[N], ori;

double dis(const Round &a, const Round &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double insection_of_rounds(Round &a, Round &b) {
    double d = dis(a, b);
    if (d >= a.r + b.r)
        return 0;
    if (d <= fabs(a.r - b.r)) {
        double r = a.r < b.r ? a.r : b.r;
        return PI * r * r;
    }
    double ang1 = acos((a.r * a.r + d * d - b.r * b.r) / 2. / a.r / d);
    double ang2 = acos((b.r * b.r + d * d - a.r * a.r) / 2. / b.r / d);
    double ret = ang1 * a.r * a.r + ang2 * b.r * b.r - d * a.r * sin(ang1);
    return ret;
}

bool check(Round& ori) {
    repf (i, 0, n - 1) {
        if (insection_of_rounds(ori, r[i]) * 2 < PI * r[i].r * r[i].r)
            return false;
    }
    return true;
};

double bin(double l, double r, Round& ori) {
    double mid;
    while (fabs(l - r) >= EPS) {
        mid = (l + r) / 2;
        ori.r = mid;
        if (check(ori)) {
            r = mid;
        } else {
            l = mid + EPS;
        }
    }
    return mid;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        repf (i, 0, n - 1) {
            scanf("%lf%lf%lf", &r[i].x, &r[i].y, &r[i].r);
        }
        double ans = 1e10;
        repf (i, 0, n - 1) {
            ori.x = r[i].x;
            ori.y = r[i].y;
            double right = 0;
            repf (j, 0, n - 1) {
                right = max(right, dis(ori, r[j]) + r[j].r);
            }
            ans = min(ans, bin(0, right, ori));
        }
        printf("%.4f\n", ans);
    }
    return 0;
}
