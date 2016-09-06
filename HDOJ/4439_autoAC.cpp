#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn = 1011;
const double eps = 1e-8;
const double pi = acos(-1.0);
inline double dcmp(double x) {return (x > eps) - (x < -eps);}
inline double Sqr(double x) {return x * x;}
struct Point
{
    double x, y, v;
    Point(){}
    Point(double x_, double y_){x = x_, y = y_;}
    double Dis(Point &b){return sqrt(Sqr(x - b.x) + Sqr(y - b.y));}
};
Point p[maxn], th;
int n;
void AngManage(double &x)
{
    while(x + pi < -eps) x += pi + pi;
    while(x - pi > -eps) x -= pi + pi;
}
inline double CounterAng(double s, double e)
{return e > s + eps ? e - s : pi + pi + e - s;}
struct Cov
{
    double s, e;
    void Read(double s_, double e_)
    {
        AngManage(s_), AngManage(e_);
        s = s_, e = e_;
    }
    bool operator<(const Cov &b)const
    {
        if(!dcmp(s - b.s)) return CounterAng(s, e) > CounterAng(b.s, b.e);
        return s < b.s;
    }
} cover[maxn], cc[maxn];
int main()
{
    int t, i, j, k, ans, cnt;
    bool flag;
    for(scanf("%d", &t); t --; )
    {
        flag = false;
        scanf("%d", &n);
        scanf("%lf%lf%lf", &th.v, &th.x, &th.y);
        for(i = 0; i < n; ++ i)
        {
            scanf("%lf%lf%lf", &p[i].v, &p[i].x, &p[i].y);
            if(p[i].v > th.v + eps || !dcmp(p[i].Dis(th))) flag = true;
        }
        if(flag) {printf("1\n"); continue;}
        if(!dcmp(th.v)) {printf("0\n"); continue;}
        for(i = 0; i < n; ++ i)
        {
            double ang = atan2(p[i].y - th.y, p[i].x - th.x);
            if(p[i].v > th.v - eps)
            {
                cover[i].Read(ang - pi * 0.5, ang + pi * 0.5);
                continue;
            }
            double c = p[i].Dis(th);
            double T = sqrt(Sqr(c) / (Sqr(th.v) - Sqr(p[i].v)));
            double cs = acos(c / T / th.v);
            cover[i].Read(ang - cs, ang + cs);
        }
        sort(cover, cover + n);
        for(i = k = 1; i < n; ++ i)
            if(dcmp(cover[i].s - cover[i - 1].s)) cover[k ++] = cover[i];
        n = k;
        for(i = 0, ans = 0x3f3f3f3f; i < n; ++ i)
        {
            for(j = i, k = 0; ; j = (j + 1) % n)
            {
                cc[k].Read(cover[j].s - cover[i].s - pi, cover[j].e - cover[i].s - pi);
                if(cc[k].s > cc[k].e) cc[k].e = pi + pi;
                ++ k;
                if(j == (i + n - 1) % n) break;
            }
            double now = -pi - pi, nex = -pi;
            flag = false;
            for(j = cnt = 0; j < n; ++ j)
            {
                if(cc[j].e < now + eps) continue;
                if(cc[j].s > nex + eps) break;
                if(cc[j].s > now + eps)
                {
                    ++ cnt;
                    now = nex;
                }
                if(cc[j].e > nex + eps) nex = cc[j].e;
                if(nex > pi - eps) {flag = true; break;}
            }
            if(flag) ans = min(ans, cnt);
        }
        if(ans == 0x3f3f3f3f) ans = 0;
        printf("%d\n", ans);
    }
    return 0;
}
