#include <stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
using namespace std;
#define N 8005
#define EPS 1e-8
struct TPoint {
    int x, y;
    TPoint() {
    }
    TPoint(const int &_x, const int &_y) :
        x(_x), y(_y) {
    }
    bool operator ==(const TPoint &b) const {
        return (x == b.x && y == b.y);
    }
    TPoint operator-(const TPoint &b) const {
        return TPoint(x - b.x, y - b.y);
    }
};
TPoint p[N], hull[N],r;
int tn;
double cross(const TPoint & a, const TPoint & b, const TPoint & c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
double len(const TPoint &a) {
    return sqrt((double) (a.x * a.x + a.y * a.y));
}
double dis(const TPoint &a, const TPoint &b) {
    return len(b - a);
}
bool graham_cmp(const TPoint &b, const TPoint &c) {
    double tmp = cross(b, c, p[0]);
    if (tmp > EPS)
        return true;
    if (fabs(tmp) < EPS && (dis(b, p[0]) < dis(c, p[0])))
        return true;
    return false;
}
int graham_scan(int n) {
    int top, i, k = 0;
    for (i = 1; i < n; ++i) {
        if ((p[k].y - p[i].y < EPS) || (fabs((double)p[i].y - p[k].y) < EPS && p[k].x
                - p[i].x > EPS))
            k = i;
    }
    swap(p[0], p[k]);
    sort(p + 1, p + n, graham_cmp);
    hull[0] = p[0], hull[1] = p[1], hull[2] = p[2];
    if (n < 3)
        return n;
    else
        top = 3;
    for (i = 3; i < n; ++i) {
        while (top >= 2 && cross(hull[top - 2], hull[top - 1], p[i]) < EPS)
            --top;
        hull[top++] = p[i];
    }
    return top;
}
inline double dis_p2_line(TPoint & a,TPoint & b,TPoint & p)
{ return fabs(cross(a,p,b))/dis(a,b); }
struct node {
    int x1, x2, y1, y2;
    int level;
    bool flag;
} a[2005];
int Max(int a, int b) {
    return a > b ? a : b;
}
int Min(int a, int b) {
    return a < b ? a : b;
}
int main() {
    int i, j, n;
    int level, t, x, y;
    while (scanf("%d", &n) != EOF) {
        for (i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
            a[i].flag = false;
            a[i].x1 *= 2;
            a[i].y1 *= 2;
            a[i].x2 *= 2;
            a[i].y2 *= 2;
            if (a[i].x1 > a[i].x2) {
                t = a[i].x1;
                a[i].x1 = a[i].x2;
                a[i].x2 = t;
            }
            if (a[i].y1 > a[i].y2) {
                t = a[i].y1;
                a[i].y1 = a[i].y2;
                a[i].y2 = t;
            }
        }
        a[0].level = 1;
        a[0].flag = true;
        for (i = 1; i < n; ++i) {
            level = 1;
            for (j = i-1; j >= 0; --j) {
                if (level >= a[j].level + 1)
                    continue;
                if (a[i].x2 <= a[j].x1)
                    continue;
                if (a[j].x2 <= a[i].x1)
                    continue;
                if (a[i].y2 <= a[j].y1)
                    continue;
                if (a[j].y2 <= a[i].y1)
                    continue;
                level = a[j].level + 1;
            }
            a[i].level = level;
            tn = 0;
            for (j = 0; j < i; ++j) {
                if (level != a[j].level + 1)
                    continue;
                if (a[i].x2 <= a[j].x1)
                    continue;
                if (a[j].x2 <= a[i].x1)
                    continue;
                if (a[i].y2 <= a[j].y1)
                    continue;
                if (a[j].y2 <= a[i].y1)
                    continue;
                int x1,x2,y1,y2;
                x1 = Max(a[i].x1,a[j].x1);
                x2 = Min(a[i].x2,a[j].x2);
                y1 = Max(a[i].y1,a[j].y1);
                y2 = Min(a[i].y2,a[j].y2);
                p[tn].x = x1;
                p[tn++].y = y1;
                p[tn].x = x1;
                p[tn++].y = y2;
                p[tn].x = x2;
                p[tn++].y = y1;
                p[tn].x = x2;
                p[tn++].y = y2;
            }
            if(tn==0)
            {
                a[i].flag=true;
                continue;
            }
            p[tn].x=((a[i].x1+a[i].x2)>>1);
            p[tn++].y=((a[i].y1+a[i].y2)>>1);
            tn=graham_scan(tn);
            a[i].flag=true;
            for(j=0;j<tn;++j)
            {
                if(hull[j]==TPoint(((a[i].x1+a[i].x2)>>1),((a[i].y1+a[i].y2)>>1)))
                {
                    a[i].flag=false;
                    a[i].level=-1;
                    break;
                }
                r=TPoint(((a[i].x1+a[i].x2)>>1),((a[i].y1+a[i].y2)>>1));
                double s=fabs(dis_p2_line(hull[j],hull[(j+1)%tn],r));
                if(s<EPS)
                {
                    a[i].flag=false;
                    a[i].level=-1;
                    break;
                }
            }
        }
        int ans=0;
        for(i=0;i<n;++i)
        {
            if(a[i].flag)
                ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
