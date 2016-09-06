#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAXN = 1001;
const double eps = 1e-12;
int dblcmp(double x)
{
if(fabs(x) < eps)
{
return 0;
}
return x > 0 ? 1 : -1;
}
struct Point
{
double x, y, z;
inline void input2d()
{
scanf("%lf%lf",&x,&y);
z = 100.0;
}
inline void input3d()
{
scanf("%lf%lf%lf",&x,&y,&z);
}
bool operator < (const Point &point) const
{
if(y == point.y)
{
return x < point.x;
}
return y < point.y;
}
}machine[MAXN], light[3], shadow[3][MAXN], final[MAXN * 3];
int n, shadowNumber[3], shadowPoly[3][MAXN], shadowPolyTop[3], finalNumber;
double operator * (const Point &x, const Point &y)
{
return x.x * y.y - x.y * y.x;
}
Point operator - (const Point &x, const Point &y)
{
Point r;
r.x = x.x - y.x;
r.y = x.y - y.y;
return r;
}
bool operator == (const Point &a, const Point &b)
{
return fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps;
}
struct Line
{
Point a, b;
double ang;
}line[MAXN*3], stack[MAXN*3];
int lineNumber, stackTop;
bool operator < (const Line &x, const Line &y)
{
if(fabs(x.ang - y.ang) < eps)
{
return (y.b - x.a) * (x.b - y.a) > eps;
}
return x.ang < y.ang;
}
Point operator * (const Line &x, const Line &y)
{
double a1 = (y.b - x.a) * (y.a - x.a);
double a2 = (y.a - x.b) * (y.b - x.b);
Point r;
r.x = (x.a.x * a2 + x.b.x * a1) / (a1 + a2);
r.y = (x.a.y * a2 + x.b.y * a1) / (a1 + a2);
return r;
}
bool mult(const Point &s, const Point &e, const Point &o)
{
return (s.x - o.x) * (e.y - o.y) >= (e.x - o.x) * (s.y - o.y);
}
void graham(Point p[], int n, int res[], int &top)
{
int len;
top = 1;
sort(p, p + n);
if(n == 0) return;
res[0] = 0;
if(n == 1) return;
res[1] = 1;
if(n == 2) return;
res[2] = 2;
for(int i=2;i<n;++i)
{
while(top && mult(p[i], p[res[top]], p[res[top-1]]))
{
-- top;
}
res[++top] = i;
}
len = top;
res[++top] = n - 2;
for(int i=n-3;i>=0;--i)
{
while(top!=len && mult(p[i], p[res[top]], p[res[top-1]]))
{
-- top;
}
res[++top] = i;
}
}
double cross(Point &a, Point &b, Point &o)
{
return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool judgeOut(const Line &x, const Point &p)
{
return (p - x.a) * (x.b - x.a) > eps;
}
bool isParellel(const Line &x, const Line &y)
{
return fabs((x.b - x.a) * (y.b - y.a)) < eps;
}
double getArea(Point p[], int n)
{
double ans = 0.0;
for(int i=2;i<n;++i)
{
ans += fabs(cross(p[i], p[i-1], p[0]));
}
return ans * 0.5;
}
void halfPlane()
{
finalNumber = 0;
sort(line, line + lineNumber);
stackTop = 1;
int bottom = 0, tmp = 1;
for(int i=1;i<lineNumber;++i)
{
if(line[i].ang - line[i-1].ang > eps)
{
line[tmp++] = line[i];
}
}
lineNumber = tmp;
stack[0] = line[0], stack[1] = line[1];
for(int i=2;i<lineNumber;++i)
{
if(isParellel(stack[stackTop], stack[stackTop-1]) || isParellel(stack[bottom], stack[bottom+1]))
{
return;
}
while(bottom < stackTop && judgeOut(line[i], stack[stackTop] * stack[stackTop - 1]))
{
-- stackTop;
}
while(bottom < stackTop && judgeOut(line[i], stack[bottom] * stack[bottom + 1]))
{
++ bottom;
}
stack[++stackTop] = line[i];
}
while(bottom < stackTop && judgeOut(stack[bottom], stack[stackTop] * stack[stackTop - 1]))
{
-- stackTop;
}
while(bottom < stackTop && judgeOut(stack[stackTop], stack[bottom] * stack[bottom + 1]))
{
++ bottom;
}
if(stackTop <= bottom + 1)
{
return;
}
stack[++stackTop] = stack[bottom];
for(int i=bottom;i<stackTop;++i)
{
final[finalNumber ++] = stack[i] * stack[i+1];
}
}
int main()
{
while(~scanf("%d", &n))
{
for(int i=0;i<n;++i)
{
machine[i].input3d();
}
for(int i=0;i<3;++i)
{
light[i].input2d();
}
lineNumber = 0;
for(int i=0;i<3;++i)
{
shadowNumber[i] = 0;
for(int j=0;j<n;++j)
{
shadow[i][j].x = 100.0 * (light[i].x - machine[j].x) / (machine[j].z - 100.0) + light[i].x;
shadow[i][j].y = 100.0 * (light[i].y - machine[j].y) / (machine[j].z - 100.0) + light[i].y;
}
graham(shadow[i], n, shadowPoly[i], shadowPolyTop[i]);
shadowPoly[i][shadowPolyTop[i]] = shadowPoly[i][0];
for(int j=0;j<shadowPolyTop[i];++j)
{
line[lineNumber].a = shadow[i][shadowPoly[i][j]];
line[lineNumber].b = shadow[i][shadowPoly[i][j+1]];
line[lineNumber].ang = atan2(line[lineNumber].b.y - line[lineNumber].a.y,
line[lineNumber].b.x - line[lineNumber].a.x);
++ lineNumber;
}
}
halfPlane();
printf("%.2lf\n", getArea(final, finalNumber));
}
return 0;
}
