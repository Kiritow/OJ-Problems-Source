#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
const double eps = 1e-8;
const double pi = acos(-1.0);
int sgn(double d) {
    if (d > eps)
        return 1;
    if (d < -eps)
        return -1;
    return 0;
}
struct point {
    double x, y;
    point(double _x = 0, double _y = 0): x(_x), y(_y) {
    }
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    double len() const {
        return sqrt(x * x + y * y);
    }
    point trunc(double l) const {
        double r = l / len();
        return point(x * r, y * r);
    }
    point rotate_left() const {
        return point(-y, x);
    }
    point rotate_right() const {
        return point(y, -x);
    }
};
bool operator==(const point& p1, const point& p2) {
    return sgn(p1.x - p2.x) == 0 && sgn(p1.y - p2.y) == 0;
}
bool operator<(const point& p1, const point& p2) {
    return sgn(p1.x - p2.x) == 0 ? sgn(p1.y - p2.y) < 0 : p1.x < p2.x;
}
point operator+(const point& p1, const point& p2) {
    return point(p1.x + p2.x, p1.y + p2.y);
}
point operator-(const point& p1, const point& p2) {
    return point(p1.x - p2.x, p1.y - p2.y);
}
double operator^(const point& p1, const point& p2) {
    return p1.x * p2.x + p1.y * p2.y;
}
double operator*(const point& p1, const point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}
bool get_intersection(const point& p1, const point& p2, const point& p3, const point& p4, point& c) {
    double d1 = (p2 - p1) * (p3 - p1), d2 = (p2 - p1) * (p4 - p1);
    if (sgn(d1 - d2) == 0)
        return false;
    c = point((p3.x * d2 - p4.x * d1) / (d2 - d1), (p3.y * d2 - p4.y * d1) / (d2 - d1));
    return true;
}
int n;
point p[16];
pair<int, double> dp[1 << 11][11][11], ans;
bool solve();
void compute();
int main() {
    while (solve());
    return 0;
}
bool solve() {
    scanf("%d", &n);
    if (n == 0)
        return false;
    for (int i = 0; i < n; ++i)
        p[i].input();
    sort(p, p + n);
    n = unique(p, p + n) - p;
    if (n < 2) {
        puts("0 0.0000000");
        return true;
    }
    compute();
    printf("%d %.8lf\n", ans.first, ans.second);
    return true;
}
void compute() {
    for (int i = 0; i < (1 << n); ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                dp[i][j][k].first = 256;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            dp[(1 << i) | (1 << j)][i][j] = make_pair(0, (p[j] - p[i]).len());
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        for (int x = 0; x < n; ++x) {
            if (((i >> x) & 1) == 0)
                continue;
            for (int y = 0; y < n; ++y) {
                if (y == x || ((i >> y) & 1) == 0)
                    continue;
                if (dp[i][x][y].first == 256)
                    continue;
                pair<int, double>& cur = dp[i][x][y];
                for (int j = 0; j < n; ++j) {
                    if (((i >> j) & 1) == 1)
                        continue;
                    pair<int, double>& res = dp[i | (1 << j)][y][j];
                    if (sgn((p[j] - p[x]) * (p[y] - p[x])) == 0) {
                        if (sgn((p[j] - p[y]) ^ (p[x] - p[y])) < 0) {
                            res = min(res, make_pair(cur.first, cur.second + (p[j] - p[y]).len()));
                        } else {
                            res = min(res, make_pair(cur.first + 1, cur.second + (p[j] - p[y]).len()));
                        }
                    } else {
                        res = min(res, make_pair(cur.first + 1, cur.second + (p[j] - p[y]).len()));
                    }
                }
                for (int j = 0; j < n; ++j) {
                    if (((i >> j) & 1) == 1)
                        continue;
                    for (int k = 0; k < n; ++k) {
                        if (k == j || ((i >> k) & 1) == 1)
                            continue;
                        pair<int, double>& res = dp[i | (1 << j) | (1 << k)][j][k];
                        point c;
                        if (get_intersection(p[x], p[y], p[j], p[k], c)) {
                            if (sgn((p[x] - p[y]) ^ (c - p[y])) < 0 && sgn((p[k] - p[j]) ^ (c - p[j])) < 0) {
                                res = min(res, make_pair(cur.first + 1, cur.second + (c - p[y]).len() + (c - p[k]).len()));
                            }
                        }
                    }
                }
            }
        }
    }
    ans.first = 256;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans = min(ans, dp[(1 << n) - 1][i][j]);
}
