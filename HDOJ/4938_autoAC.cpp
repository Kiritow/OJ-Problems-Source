#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<time.h>
#include<string>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define REP2(i,a,b) for(int i=a;i>=b;--i)
#define MP make_pair
#define LL long long
#define X first
#define Y second
#define MAXN 100050
#define eps 1e-8
using namespace std;
struct Point {
    double x, y;
} p1[MAXN], p2[MAXN];
struct Line {
    Point p, q;
};
Point Intersect(Line u, Line v) 
        {
    Point ret = u.p;
    double t = ((u.p.x - v.p.x) * (v.p.y - v.q.y)
            - (u.p.y - v.p.y) * (v.p.x - v.q.x))
            / ((u.p.x - u.q.x) * (v.p.y - v.q.y)
                    - (u.p.y - u.q.y) * (v.p.x - v.q.x));
    ret.x += (u.q.x - u.p.x) * t;
    ret.y += (u.q.y - u.p.y) * t;
    return ret;
}
struct node {
    double x, w;
    int id, type;
} s[MAXN];
bool cmp1(node a, node b) {
    return a.x < b.x - eps || (fabs(a.x - b.x) < eps && a.type < b.type);
}
bool cmp2(node a, node b) {
    return a.x < b.x - eps || (fabs(a.x - b.x) < eps && a.type > b.type);
}
int d[MAXN];
int ans[MAXN];
int main() {
    int tt, ri = 0, n;
    scanf("%d", &tt);
    while (tt--) {
        Line L;
        L.p.x = L.p.y = L.q.y = 0;
        L.q.x = 100;
        double v1, v2;
        scanf("%d%lf%lf", &n, &v1, &v2);
        double si = v1 / sqrt(v1 * v1 + v2 * v2);
        REP(i,n)
        {
            double a, t, p, w;
            scanf("%lf%lf%lf%lf", &a, &t, &p, &w);
            Line L1;
            if (a == 1) {
                L1.p.x = 1.0*p;
                L1.p.y = -1.0*t * v1;
                L1.q.x = 1.0*p - v2;
                L1.q.y = -1.0*t * v1 + v1;
            } else {
                L1.p.x = -1.0*t * v2;
                L1.p.y = 1.0*p;
                L1.q.x = -1.0*t * v2 - v2;
                L1.q.y = 1.0*p + v1;
            }
            Point e = Intersect(L, L1);
            s[i].x = e.x;
            s[i].type = a;
            if(a==1)
                s[i].w = w ;
            else
                s[i].w=w*1.0*v2/v1;
            s[i].id = i;
        }
        sort(s, s + n, cmp1);
        d[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            d[i] = d[i + 1];
            if (s[i].type == 2) {
                d[i]++;
                continue;
            }
            int l, r;
            l = i;
            r = n - 1;
            while (r - l > 1) {
                int mid = (l + r) >> 1;
                if (s[mid].x - s[i].x > s[i].w + eps)
                    r = mid;
                else
                    l = mid;
            }
            if (s[r].x - s[i].x < s[i].w + eps)
                ans[s[i].id] = d[i]-d[r+1];
            else
                ans[s[i].id] = d[i] - d[r];
        }
        sort(s, s + n, cmp2);
        d[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            d[i] = d[i + 1];
            if (s[i].type == 1) {
                d[i]++;
                continue;
            }
            int l, r;
            l = i;
            r = n - 1;
            while (r - l > 1) {
                int mid = (l + r) >> 1;
                if (s[mid].x - s[i].x > s[i].w + eps)
                    r = mid;
                else
                    l = mid;
            }
            if (s[r].x - s[i].x < s[i].w + eps)
                ans[s[i].id] = d[i]-d[r+1];
            else
                ans[s[i].id] = d[i] - d[r];
        }
        printf("Case #%d:\n",++ri);
        for(int i=0;i<n;++i)
            printf("%d\n",ans[i]);
    }
    return 0;
}
