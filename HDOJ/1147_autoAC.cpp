#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100009;
struct Point{
    double x, y;
};
struct Line {
    Point p1, p2;
};
Line line[N];
vector<int> v;
bool vis[N];
double direction (Point p0, Point p1, Point p2) {
    return ((p2.x - p0.x)*(p1.y - p0.y) - (p1.x - p0.x)*(p2.y - p0.y));
}
bool on_segment (Point p0, Point p1, Point p2) {
    double minx, maxx, miny, maxy;
    minx = min(p0.x, p1.x);
    maxx = max(p0.x, p1.x);
    miny = min(p0.y, p1.y);
    maxy = max(p0.y, p1.y);
    if (p2.x >= minx && p2.x <= maxx && p2.y >= miny && p2.y <= maxy)
        return true;
    else
        return false;
}
bool segments_intersect (Point p1, Point p2, Point p3, Point p4) {
    double d1, d2, d3, d4;
    d1 = direction(p3, p4, p1);
    d2 = direction(p3, p4, p2);
    d3 = direction(p1, p2, p3);
    d4 = direction(p1, p2, p4);
    if (((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0)) && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0)))
        return true;
    else
        return false;
}
int main()
{
    int i, j, n;
    while (scanf("%d", &n)!=EOF && n) {
        v.clear();
        memset(vis, 0, sizeof(vis));
        for (i = 1; i <= n; ++i)
            scanf("%lf %lf %lf %lf", &line[i].p1.x, &line[i].p1.y, &line[i].p2.x, &line[i].p2.y);
        v.push_back(n);
        for (j = n-1; j >= 1; j--) {
            if (vis[j])
                continue;
            for (i = n; i > j; --i) {
                if (vis[i])
                    continue;
                if (segments_intersect(line[j].p1, line[j].p2, line[i].p1, line[i].p2))
                    break;
            }
            if (i <= j)
                v.push_back(j);
        }
        int len = (int)v.size();
        printf("Top sticks: ");
        for (i = len -1; i > 0; --i)
            printf("%d, ", v[i]);
        printf("%d.\n", v[0]);
    }
    return 0;
}
