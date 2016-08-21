#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <queue>
using namespace std;
#define SZ(v) ((int)(v).size())
#define SQR(x) ((x) * (x))
const int maxint = -1u>>1;
const int maxn = 100 + 4;
const double eps = 1e-9;
const double inf = 1e10;
int sgn(double x) {
 return (x > eps) - (x < -eps);
}
struct P {
 double x, y;
 P() {}
 P(double _x, double _y): x(_x), y(_y) {}
 bool operator != (const P &a) const {
 return sgn(x - a.x) || sgn(y - a.y);
 }
 P operator + (const P &a) const {
 return P(x + a.x, y + a.y);
 }
 P operator - (const P &a) const {
 return P(x - a.x, y - a.y);
 }
 P operator * (const double &m) const {
 return P(x * m, y * m);
 }
 double length() const {
 return sqrt(SQR(x) + SQR(y));
 }
 P set(const double &m) const {
 double len = length();
 return P(x * m / len, y * m / len);
 }
 P turn_left() const {
 return P(-y, x);
 }
 double dot(const P &a, const P &b) const {
 return (a.x - x) * (b.x - x) + (a.y - y) * (b.y - y);
 }
 double cross(const P &a, const P &b) const {
 return (a.x - x) * (b.y - y) - (a.y - y) * (b.x - x);
 }
 double dist(const P &a) const {
 return sqrt(sqrdist(a));
 }
 double sqrdist(const P &a) const {
 return SQR(a.x - x) + SQR(a.y - y);
 }
 void input() {
 scanf("%lf%lf", &x, &y);
 }
 void output() const {
 printf("%lf %lf\n", x, y);
 }
};
struct node {
 int x;
 double val;
 node() {}
 node(int _x, double _val): x(_x), val(_val) {}
 bool operator < (const node &a) const {
 return val > a.val;
 }
};
int n, m;
double r;
P cen[maxn];
vector<P> rec;
vector<vector<pair<int, double> > > v;
vector<double> dist;
vector<bool> used;
bool in_cir(const P &p) {
 for (int i = 0; i < n; ++i) {
 if (sgn(cen[i].dist(p) - r) < 0) return true;
 }
 return false;
}
void cir_cross(const P &c1, const P &c2) {
 if (sgn(c1.dist(c2) - r * 2) > 0) return ;
 P mid = (c1 + c2) * 0.5;
 P dir = (c2 - c1).turn_left().set(sqrt(SQR(r) - c1.sqrdist(c2) / 4));
 P p1 = mid + dir, p2 = mid - dir;
 if (!in_cir(p1)) {
 rec.push_back(p1);
 }
 if (p1 != p2 && !in_cir(p2)) {
 rec.push_back(p2);
 }
}
void spfa(int s) {
 dist.resize(m);
 used.resize(m);
 for (int i = 0; i < m; ++i) {
 dist[i] = inf;
 used[i] = false;
 }
 priority_queue<node> que;
 que.push(node(s, 0));
 dist[s] = 0;
 used[s] = false;
 while (!que.empty()) {
 node top = que.top();
 que.pop();
 used[top.x] = false;
 for (int i = 0; i < (int)v[top.x].size(); ++i) {
 int x = v[top.x][i].first;
 if (dist[x] > dist[top.x] + v[top.x][i].second) {
 dist[x] = dist[top.x] + v[top.x][i].second;
 if (!used[x]) {
 used[x] = true;
 que.push(node(x, dist[x]));
 }
 }
 }
 }
}
int calc_init(const P &pt1) {
 int res = 0;
 for (int i = 0; i < n; ++i) {
 if (sgn(pt1.dist(cen[i]) - r) <= 0) ++res;
 }
 return res;
}
void line_cross_cir(vector<pair<double, int> > &s, const P &p1, const P &p2, const P &c) {
 double d = fabs(p1.cross(p2, c)) / p1.dist(p2);
 if (sgn(d - r) > 0) return;
 double s1 = sqrt(p1.sqrdist(c) - SQR(d));
 if (sgn(p1.dot(c, p2)) < 0) s1 = -s1;
 double s2 = sqrt(SQR(r) - SQR(d));
 P pt1 = p1 + (p2 - p1).set(s1 - s2), pt2 = p1 + (p2 - p1).set(s1 + s2);
 if (sgn(pt1.dot(p1, p2)) < 0) {
 s.push_back(make_pair(pt1.dist(p1), 1));
 }
 if (sgn(pt2.dot(p1, p2)) < 0) {
 s.push_back(make_pair(pt2.dist(p1), -1));
 }
}
bool cmp(const pair<double, int> &x1, const pair<double, int> &x2) {
 if (sgn(x1.first - x2.first) != 0) return x1.first < x2.first;
 return x1.second > x2.second;
}
bool ok_line(const P &p1, const P &p2) {
 P pt1 = p1 + (p2 - p1)*0.001;
 vector<pair<double, int> > s;
 for (int i = 0; i < n; ++i) {
 line_cross_cir(s, pt1, p2, cen[i]);
 }
 sort(s.begin(), s.end());
 int cnt = calc_init(pt1);
 if (cnt == 0) return false;
 for (int i = 0; i < (int)s.size(); ++i) {
 cnt += s[i].second;
 if (cnt == 0) return false;
 }
 return true;
}
int main() {
 int t;
 scanf("%d", &t);
 while (t--) {
 scanf("%lf%d", &r, &n);
 P st, ed;
 st.input();
 ed.input();
 for (int i = 0; i < n; ++i) {
 cen[i].input();
 }
 rec.clear();
 rec.push_back(st);
 rec.push_back(ed);
 for (int i = 0; i < n; ++i) {
 for (int j = 0; j < i; ++j) {
 cir_cross(cen[i], cen[j]);
 }
 }
 m = rec.size();
 v.resize(m);
 for (int i = 0; i < m; ++i) v[i].clear();
 for (int i = 0; i < m; ++i) {
 for (int j = 0; j < i; ++j) {
 if (ok_line(rec[i], rec[j])) {
 v[i].push_back(make_pair(j, rec[i].dist(rec[j])));
 v[j].push_back(make_pair(i, rec[i].dist(rec[j])));
 }
 }
 }
 spfa(0);
 if (sgn(dist[1] - inf) == 0) printf("-1\n");
 else printf("%.12lf\n", dist[1]);
 }
 return 0;
}
