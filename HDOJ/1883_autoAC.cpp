#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
const int maxn = 2111;
const double eps = 1e-8;
const double pi = acos(-1.0);
int n, R, ctp;
inline int dcmp(double x) {return (x > eps) - (x < -eps);}
inline double Sqr(double x){return x * x;}
struct Point {int x, y;} p[maxn];
inline double CalDis(const Point &a, const Point &b)
{return sqrt(Sqr(a.x - b.x) + Sqr(a.y - b.y));}
struct Cov { double site; int se;}cover[maxn <<2];
int AScomp(const void *a, const void *b)
{
    if(!dcmp((*(Cov*)a).site - (*(Cov*)b).site))
        return -((*(Cov*)a).se - (*(Cov*)b).se);
    return dcmp((*(Cov*)a).site - (*(Cov*)b).site);
}
void AngManage(double &x)
{
    while(x + pi < eps) x += 2 * pi;
    while(x - pi > eps) x -= 2 * pi;
}
void AddAnSeg(double start, double end)
{
    AngManage(start), AngManage(end);
    if(start - end > eps) AddAnSeg(start, pi), AddAnSeg(-pi + eps * 2, end);
    else
    {
        cover[ctp].site = start, cover[ctp].se = 1;++ ctp;
        cover[ctp].site = end, cover[ctp].se = -1;++ ctp;
    }
}
int MakeAns()
{
    int i, j, ans = 0, cnt;
    double dis, ang, ac, RR = 2 * (R + 0.001);
    for(i = 0 ; i < n; ++ i)
    {
        for(j = ctp = 0; j < n; ++ j)
            if(j != i && (dis = CalDis(p[i], p[j])) < RR)
            {
                ang = atan2((double)p[j].y - p[i].y, (double)p[j].x - p[i].x);
                ac = acos(dis * 0.5 / R);
                AddAnSeg(ang - ac, ang + ac);
            }
        qsort(cover, ctp, sizeof(Cov), AScomp);
        for(j = cnt = 0; j < ctp; ++ j)
            ans = std::max(ans, cnt += cover[j].se);
    }
    return ans + 1;
}
int main()
{
    while(scanf("%d%d", &n, &R), n | R)
    {
        for(int i = 0; i < n; ++ i)
            scanf("%d%d", &p[i].x, &p[i].y);
        printf("It is possible to cover %d points.\n", MakeAns());
    }
    return 0;
}
