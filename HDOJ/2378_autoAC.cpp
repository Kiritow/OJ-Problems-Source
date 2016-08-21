#include <iostream>
#include <cstdio>
using namespace std;
const double eps = 1e-7;
int cases, m, c, gg;
double des, xs;
bool flag;
int gcd(int a, int b) {
    if (b == 0) return a; else return gcd(b, a%b);
}
double abs(double x) {
    if (x < 0) return -x; else return x;
}
int main() {
 scanf("%d", &cases);
 while (cases--) {
 scanf("%lf", &des);
 des = 4*des;
 xs = des-int(des);
 flag = true;if (abs(xs)>eps) flag = false;
 scanf("%d", &m);
 for (int i = 0; i < m; i++) {
 scanf("%d", &c);
 if (!i) gg = c; else gg = gcd(c, gg);
 }
 while ((gg&1)==0) gg>>=1;
 if (int(des)%gg!=0) flag = false;
        if (flag) puts("yes"); else puts("no");
 }
 return 0;
}
