#include<stdio.h>
#include<math.h>
#include<algorithm>
#define PI 3.14159265358979323846
#define eps 1e-8
using namespace std;
inline int SGN(double x){return x < -eps ? -1 : x < eps ? 0 : 1;}
inline double SQR(double x){return x * x;}
struct pt
{
    double x, y;
    pt(){}
    pt(double _x, double _y):x(_x), y(_y){}
    pt operator - (const pt p1){return pt(x - p1.x, y - p1.y);}
    pt operator + (const pt p1){return pt(x + p1.x, y + p1.y);}
    pt operator * (double r){return pt(x * r, y * r);}
    pt operator / (double r){return pt(x / r, y / r);}
    void read(){scanf("%lf %lf", &x, &y);}
};
inline double cpr(const pt &a,const pt &b){return a.x*b.y-a.y*b.x;}
inline double dis(const pt &a, const pt &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
inline double dis2(const pt &a, const pt &b){return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);}
inline void intersection_circle_circle(pt &c1, double r1, pt &c2, double r2, pt &p1, pt &p2)
{
    double d2 = (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
    double cos = (r1 * r1 + d2 - r2 * r2) / (2 * r1 * sqrt(d2));
    pt v1 = (c2 - c1) / dis(c1, c2), v2 = pt(-v1.y, v1.x) * (r1 * sqrt(1 - cos * cos));
    pt X = c1 + v1 * (r1 * cos);
    p1 = X + v2;
    p2 = X - v2;
}
struct Event
{
    double pos;
    int del;
    pt X;
    bool operator < (const Event e)const{return pos < e.pos;}
};
int n;
pt o[400];
double r[400];
Event e[800];
int cnt;
double ans[10];
int sc[400];
inline int rlt(int a, int b)
{
    double d = dis2(o[a], o[b]), df = SGN(d - SQR(r[a] - r[b]));
    if (df <= 0)return !SGN(r[a] - r[b]) ? a < b : r[a] < r[b];
    return d < SQR(r[a] + r[b]) - eps ? 2 : 3;
}
inline double arcArea(double r, Event e1, Event e2)
{
    double dif = e2.pos - e1.pos;
    return (cpr(e1.X, e2.X) + (dif - sin(dif)) * r * r) * 0.5;
}
void solve()
{
    double center, d2, ang, angX, angY;
    pt X, Y, L;
    Event last;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < n; i++) if (r[i] > eps)
    {
        int acc[4] = {0};
        cnt = 0;
        L = pt(o[i].x - r[i], o[i].y);
        e[cnt].pos = -PI, e[cnt].del = sc[i], e[cnt++].X = L;
        e[cnt].pos = PI, e[cnt].del = -sc[i], e[cnt++].X = L;
        for (int j = 0; j < n; j++) if (i != j && r[j] > eps)
        {
            int rel = rlt(i, j);
            if (rel == 1)
            {
                e[cnt].pos = -PI, e[cnt].del = sc[j], e[cnt++].X = L;
                e[cnt].pos = PI, e[cnt].del = -sc[j], e[cnt++].X = L;
            } else if (rel == 2)
            {
                intersection_circle_circle(o[i], r[i], o[j], r[j], X, Y);
                angX = atan2(X.y - o[i].y, X.x - o[i].x);
                angY = atan2(Y.y - o[i].y, Y.x - o[i].x);
                if (angX < angY) acc[sc[j]]++;
                e[cnt].pos = angY, e[cnt].del = sc[j], e[cnt++].X = Y;
                e[cnt].pos = angX, e[cnt].del = -sc[j], e[cnt++].X = X;
            }
        }
        sort(e, e + cnt);
        last.pos = -PI, last.X = pt(o[i].x - r[i], o[i].y);
        for (int j = 0; j < cnt; j++)
        {
            double tmp = arcArea(r[i], last, e[j]);
            ans[!!acc[1] + 2 * !!acc[2] + 4 * !!acc[3]] += tmp;
            ans[!!(acc[1] - (sc[i] == 1)) + 2 * !!(acc[2] - (sc[i] == 2)) + 4 * !!(acc[3] - (sc[i] == 3))] -= tmp;
            acc[abs(e[j].del)] += SGN(e[j].del);
            last = e[j];
        }
    }
}
void fun()
{
    int n1, n2, n3;
    scanf("%d %d %d", &n1, &n2, &n3);
    n = n1 + n2 + n3;
    for (int i = 0; i < n; i++)
    {
        o[i].read();
        scanf("%lf", &r[i]);
        sc[i] = i < n1 ? 1 : i < n1 + n2 ? 2 : 3;
    }
    solve();
    printf("%.2f %.2f %.2f %.2f %.2f %.2f %.2f\n", fabs(ans[1]), fabs(ans[2]), fabs(ans[4]), fabs(ans[7]), fabs(ans[3]), fabs(ans[5]), fabs(ans[6]));
}
int main()
{
    int tc;
    scanf ("%d", &tc);
    while (tc--)fun();
    return 0;
}
