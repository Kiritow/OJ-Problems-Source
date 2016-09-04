#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define eps 1e-6
const double pi = acos(-1.0);
struct Point {
    double x, y, z;
    double v, h;
    void SCANF() {
        scanf("%lf %lf %lf", &x, &y, &z);
        v = z;
        h = sqrt(x*x + y*y);
    }
}pt[ 10001 ];
int n;
double MaxH, MaxV;
double Calc(double R) {
    int i;
    double Max = 0;
    int idx = 0;
    for(i = 0; i < n; i++) {
        double nv = pt[i].v / (R - pt[i].h);
        if(nv > Max) {
            Max = nv;
            idx = i;
        }
    }
    return Max * R;
}
int main() {
    int t;
    int i;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        MaxH = MaxV = 0;
        for(i = 0; i < n; i++) {
            pt[i].SCANF();
            if(pt[i].h > MaxH)
                MaxH = pt[i].h;
            if(pt[i].v > MaxV)
                MaxV = pt[i].v;
        }
        double l = MaxH + eps, r = 1e6;
        double ml, mr;
        while(l + 1e-6 < r) {
            ml = (2 * l + r) / 3;
            mr = (l + 2 * r) / 3;
            double lans = Calc(ml) * ml * ml;
            double rans = Calc(mr) * mr * mr;
            if( lans > rans ) {
                l = ml + 1e-5;
            }else
                r = mr - 1e-5;
        }
        double ans = (l + r) / 2;
        printf("%.3lf %.3lf\n", Calc(ans), ans);
    }
    return 0;
}
