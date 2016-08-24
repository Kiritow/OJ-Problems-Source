#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 111111;
struct Point {
    LL x[3];
} p[N], ori[N];
int split[20], cur, dim;
bool cmp(Point a, Point b) {
    return a.x[cur] < b.x[cur];
}
#define lson l, m - 1, depth + 1
#define rson m + 1, r, depth + 1
void build(int l, int r, int depth) {
    if (l >= r) return ;
    int m = l + r >> 1;
    cur = depth % dim;
    nth_element(p + l, p + m, p + r + 1, cmp);
    build(lson);
    build(rson);
}
template <class T> T sqr(T x) { return x * x;}
const LL inf = 0x7777777777777777ll;
LL dist(Point x, Point y) {
    LL ret = 0;
    for (int i = 0; i < dim; i++) {
        ret += sqr(x.x[i] - y.x[i]);
    }
    return ret ? ret : inf;
}
LL find(Point x, int l, int r, int depth) {
    int cur = depth % dim;
    if (l >= r) {
        if (l == r) return dist(x, p[l]);
        return inf;
    }
    int m = l + r >> 1;
    LL ret = dist(x, p[m]), tmp;
    if (x.x[cur] < p[m].x[cur]) {
        tmp = find(x, lson);
        if (tmp > sqr(x.x[cur] - p[m].x[cur])) {
            tmp = min(tmp, find(x, rson));
        }
    } else {
        tmp = find(x, rson);
        if (tmp > sqr(x.x[cur] - p[m].x[cur])) {
            tmp = min(tmp, find(x, lson));
        }
    }
    return min(ret, tmp);
}
int main() {
    int n, T;
    scanf("%d", &T);
    while (T-- && scanf("%d", &n)) {
        dim = 2;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                scanf("%I64d", &ori[i].x[j]);
            }
            p[i] = ori[i];
        }
        build(0, n - 1, 0);
        for (int i = 0; i < n; i++) {
            printf("%I64d\n", find(ori[i], 0, n - 1, 0));
        }
    }
    return 0;
}
