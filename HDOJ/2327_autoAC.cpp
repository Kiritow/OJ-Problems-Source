#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <sstream>
#include <queue>
#include <vector>
#define MAXN 100005
#define MAXM 211111
#define eps 1e-8
#define INF 50000001
using namespace std;
inline int dblcmp(double d)
{
    if(fabs(d) < eps) return 0;
    return d > eps ? 1 : -1;
}
struct point
{
    double x, y;
    point(){}
    point(double _x, double _y): x(_x), y(_y) {}
    void input()
    {
        scanf("%lf%lf", &x, &y);
    }
    bool operator ==(point a)const
    {
        return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
    }
    point sub(point p)
    {
        return point(x - p.x, y - p.y);
    }
    double dot(point p)
    {
        return x * p.x + y * p.y;
    }
    double det(point p)
    {
        return x * p.y - y * p.x;
    }
    double distance(point p)
    {
        return hypot(x - p.x, y - p.y);
    }
}p[33];
struct line
{
    point a, b;
    line(){}
    line(point _a, point _b){ a = _a; b = _b;}
    void input()
    {
        a.input();
        b.input();
    }
    int segcrossseg(line v)
    {
        int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3 = dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4 = dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1 ^ d2) == -2 && (d3 ^ d4) == -2)return 2;
        return (d1 == 0 && dblcmp(v.a.sub(a).dot(v.a.sub(b))) <= 0||
                d2 == 0 && dblcmp(v.b.sub(a).dot(v.b.sub(b))) <= 0||
                d3 == 0 && dblcmp(a.sub(v.a).dot(a.sub(v.b))) <= 0||
                d4 == 0 && dblcmp(b.sub(v.a).dot(b.sub(v.b))) <= 0);
    }
    int linecrossseg(line v)//v is seg
    {
        int d1 = dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2 = dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1 ^ d2) == -2) return 2;
        return (d1 == 0 || d2 == 0);
    }
    point crosspoint(line v)
    {
        double a1 = v.b.sub(v.a).det(a.sub(v.a));
        double a2 = v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x * a2 - b.x * a1) / (a2 - a1), (a.y * a2 - b.y * a1) / (a2 - a1));
    }
};
struct node
{
    string name;
    vector<line>seg;
};
char sa[55], sb[55];
vector<node>g;
vector<string>ans[55];
bool cmp(node x, node y)
{
    return x.name < y.name;
}
bool ok(int k1, int k2)
{
    int sz1 = g[k1].seg.size();
    int sz2 = g[k2].seg.size();
    for(int i = 0; i < sz1; i++)
        for(int j = 0; j < sz2; j++)
            if(g[k1].seg[i].segcrossseg(g[k2].seg[j])) return true;
    return false;
}
void solve()
{
    for(int i = 0; i < 50; i++) ans[i].clear();
    sort(g.begin(), g.end(), cmp);
    int sz = g.size();
    for(int i = 0; i < sz; i++)
    {
        for(int j = 0; j < sz; j++)
        {
            if(i == j) continue;
            if(ok(i, j)) ans[i].push_back(g[j].name);
        }
    }
    for(int i = 0; i < sz; i++)
    {
        if(ans[i].size() == 0) printf("%s has no intersections\n", g[i].name.c_str());
        else
        {
            if(ans[i].size() == 1)
            {
                printf("%s intersects with %s\n", g[i].name.c_str(), ans[i][0].c_str());
            }
            else if(ans[i].size() == 2)
            {
                printf("%s intersects with %s and %s\n", g[i].name.c_str(), ans[i][0].c_str(), ans[i][1].c_str());
            }
            else
            {
                printf("%s intersects with ", g[i].name.c_str());
                for(int j = 0; j < ans[i].size() - 1; j++) printf("%s, ", ans[i][j].c_str());
                printf("and %s\n", ans[i][ans[i].size() - 1].c_str());
            }
        }
    }
    g.clear();
    printf("\n");
}
int main()
{
    double xa, ya, xb, yb;
    while(scanf("%s", sa) != EOF)
    {
        if(strcmp(sa, "-") == 0)
        {
            solve();
            continue;
        }
        if(strcmp(sa, ".") == 0) break;
        node tmp;
        tmp.name = sa;
        scanf("%s", sb);
        if(sb[0] == 's')
        {
            point a, c;
            scanf(" (%lf,%lf)", &a.x, &a.y);
            scanf(" (%lf,%lf)", &c.x, &c.y);
            point b, d;
            double x, y, mx, my;
            mx = (a.x + c.x)/2.0, my = (a.y + c.y) / 2.0;
            x = a.x - mx;    y = a.y - my;
            b.x = -y + mx;   b.y = x + my;
            x = c.x - mx;    y = c.y - my;
            d.x = - y + mx; d.y = x + my;
            tmp.seg.push_back(line(a, b));
            tmp.seg.push_back(line(b, c));
            tmp.seg.push_back(line(a, d));
            tmp.seg.push_back(line(c, d));
        }
        else if(sb[0] == 'l')
        {
            point a, b;
            scanf(" (%lf,%lf)", &a.x, &a.y);
            scanf(" (%lf,%lf)", &b.x, &b.y);
            tmp.seg.push_back(line(a, b));
        }
        else if(sb[0] == 't')
        {
            point a, b, c;
            scanf(" (%lf,%lf)", &a.x, &a.y);
            scanf(" (%lf,%lf)", &b.x, &b.y);
            scanf(" (%lf,%lf)", &c.x, &c.y);
            tmp.seg.push_back(line(a, b));
            tmp.seg.push_back(line(a, c));
            tmp.seg.push_back(line(b, c));
        }
        else if(sb[0] == 'r')
        {
            point a, b, c, d;
            scanf(" (%lf,%lf)", &a.x, &a.y);
            scanf(" (%lf,%lf)", &b.x, &b.y);
            scanf(" (%lf,%lf)", &c.x, &c.y);
            double dx = b.x - a.x;
            d.x = c.x - dx;
            double dy = b.y - a.y;
            d.y = c.y - dy;
            tmp.seg.push_back(line(a, b));
            tmp.seg.push_back(line(b, c));
            tmp.seg.push_back(line(a, d));
            tmp.seg.push_back(line(c, d));
        }
        else
        {
            int t;
            scanf("%d", &t);
            for(int i = 0; i < t; i++) scanf(" (%lf,%lf)", &p[i].x, &p[i].y);
            for(int i = 0; i < t; i++) tmp.seg.push_back(line(p[i], p[(i + 1) % t]));
        }
        g.push_back(tmp);
    }
    return 0;
}
