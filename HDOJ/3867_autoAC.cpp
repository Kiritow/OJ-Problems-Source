#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;
#define EPS 1e-8
#define LS0(a) (a << 1)
#define LS1(a) ((a << 1) | 1)
const int MAXN = 20010;
struct Point { 
    double x, y;
    Point(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}
    Point operator + (const Point &b) const {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (const Point &b) const {
        return Point(x - b.x, y - b.y);
    }
    double operator ^ (const Point &b) const {
        return x * b.y - y * b.x;
    }
    bool operator < (const Point &b) const {  
        return x * b.y < y * b.x;
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    double diso() {
        return sqrt(x * x + y * y);
    }
}cur,ps[MAXN];
Point lnlncross_pt(Point aa, Point ad, Point ba, Point bd) { 
    ad = ad - aa;
    bd = bd - ba;
    double tmp = bd ^ ad;
    return Point(
        (ad.x * bd.x * (ba.y - aa.y) + aa.x * bd.x * ad.y - ba.x * ad.x * bd.y) / tmp,
        (ad.y * bd.y * (aa.x - ba.x) + ba.y * ad.y * bd.x - aa.y * bd.y * ad.x) / tmp);
}
struct Item {
    Point *u, *v;
    int type; 
    int sgid; 
    Item(Point *_u = NULL, Point *_v = NULL, int _ty = 0, int _id = 0)
        : u(_u), v(_v), type(_ty), sgid(_id) {}
    bool operator < (const Item &b) const {
        if(u == b.u && v == b.v)
            return false;
        Point au = lnlncross_pt(Point(0.0, 0.0), cur, *u, *v);
        Point bu = lnlncross_pt(Point(0.0, 0.0), cur, *b.u, *b.v);
        return au.diso() < bu.diso();
    }
}item[MAXN];
bool flag[MAXN];
set<Item> Scan;
bool cmp(const Item &a, const Item &b) { 
        return atan2(a.u->y, a.u->x) < atan2(b.u->y, b.u->x);
}
void inputps(int n) {
    Point src, a, b;
    src.input();
    for(int i = 0; i < n; ++i) {
        a.input(); a = a - src;
        b.input(); b = b - src;
        if(b < a) swap(a, b);
        ps[LS0(i)] = a;
        ps[LS1(i)] = b;
        item[LS0(i)] = Item(&ps[LS0(i)], &ps[LS1(i)], 0, i);
        item[LS1(i)] = Item(&ps[LS1(i)], &ps[LS0(i)], 1, i);
    }
    sort(item, item + 2 * n, cmp);
}
bool sgcross_with_ax(Item &a) {   
    Point tmp(-1.0, 0.0);
    return (*a.u ^ *a.v) * (*a.u ^ tmp) > 0.0
        && (*a.u ^ tmp) * (tmp ^ *a.v) > 0.0;
}
int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        inputps(n);
        memset(flag,0,sizeof(flag));
        Scan.clear();
        for(int i = 0; i < 2 * n; ++i) {
        cur = *item[i].u;
            if(item[i].type == 1 && sgcross_with_ax(item[i]))
                Scan.insert(item[i]);
        }
        for(int i = 0; i < 2 * n; ++i) {
        cur = *item[i].u;
            if(item[i].type == 1)
                Scan.insert(item[i]);
            else
                Scan.erase(Item(item[i].v, item[i].u, 1, item[i].sgid));
            if(!Scan.empty())
                flag[Scan.begin()->sgid] = true;
        }
        int ans = 0;
        for(int i = 0; i < n; ++i)
            if(flag[i])ans ++;
        printf("%d\n", ans);
    }
    return 0;
}
