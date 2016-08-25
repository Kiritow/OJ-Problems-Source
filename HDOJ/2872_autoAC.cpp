#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <set>
#include <stack>
#include <cmath>
using namespace std;
#define N 20
#define inf 0x3f3f3f3f
#define eps 1e-16
#define LL long long
#define Pi acos(-1)
struct Point{
 double x, y;
};
Point p[N], pnt[N];
int res, t, n;
bool mark[N];
double dot(double x1, double y1, double x2, double y2){
 return x1 * x2 + y1 * y2;
}
double cross(double x1, double y1, double x2, double y2){
 return x1 * y2 - x2 * y1;
}
int dblcmp(double n) {
 if (fabs(n) < eps) {
 return 0;
 } else {
 return n > 0 ? +1 : -1;
 }
}
bool segXseg(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){
 double c1 = cross(x1 - x3, y1 - y3, x2 - x3, y2 - y3);
 double c2 = cross(x1 - x4, y1 - y4, x2 - x4, y2 - y4);
 double c3 = cross(x3 - x1, y3 - y1, x4 - x1, y4 - y1);
 double c4 = cross(x3 - x2, y3 - y2, x4 - x2, y4 - y2);
 if (c1 * c2 < -eps && c3 * c4 < -eps) return true;
 if ((dblcmp(c1) == 0 && dblcmp(dot(x1 - x3, y1 - y3, x2 - x3, y2 - y3)) <= 0) ||
 (dblcmp(c2) == 0 && dblcmp(dot(x1 - x4, y1 - y4, x2 - x4, y2 - y4)) <= 0) ||
 (dblcmp(c3) == 0 && dblcmp(dot(x3 - x1, y3 - y1, x4 - x1, y4 - y1)) <= 0) ||
 (dblcmp(c4) == 0 && dblcmp(dot(x3 - x2, y3 - y2, x4 - x2, y4 - y2)) <= 0)) {
 return true;
 }
 return false;
}
bool ok(int k){
 double c = cross(pnt[t].x - pnt[t - 1].x, pnt[t].y - pnt[t - 1].y, p[k].x - pnt[t].x, p[k].y - pnt[t].y);
 double d = dot(pnt[t].x - pnt[t - 1].x, pnt[t].y - pnt[t - 1].y, p[k].x - pnt[t].x, p[k].y - pnt[t].y);
 if (!((c > eps || (fabs(c) < eps && d > 0)))){
 return false;
 }
 Point tmp;
 for (int i = 0; i <= t - 2; ++i){
 tmp.x = pnt[t].x + (p[k].x - pnt[t].x) * 100000000.0;
 tmp.y = pnt[t].y + (p[k].y - pnt[t].y) * 100000000.0;
 if (segXseg(pnt[i].x, pnt[i].y, pnt[i + 1].x, pnt[i + 1].y, pnt[t].x, pnt[t].y, tmp.x, tmp.y)){
 return false;
 }
 }
 return true;
}
void DFS(){
 int i;
 for (i = 1; i <= n; ++i){
 if (res == n) return ;
 if (!mark[i] && (t < 1 || ok(i))){
 pnt[++t] = p[i];
 mark[i] = true;
 if (t > res) res = t;
 DFS();
 t--;
 mark[i] = false;
 }
 }
}
int main(){
 int i;
 while (scanf("%d", &n) != EOF){
 for (i = 1; i <= n; ++i){
 scanf("%lf%lf", &p[i].x, &p[i].y);
 }
 memset(mark, false, sizeof(mark));
 pnt[0].x = pnt[0].y = 0;
 t = 0;
 res = 0;
 DFS();
 printf("%d\n", res);
 }
 return 0;
}
