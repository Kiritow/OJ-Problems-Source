#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 10;
struct state {
    double dis;
    int r, y, g;
}d[N];
struct can {
    int l, r;
    void put() {
        if (l == r)
            printf("%d", l);
        else
            printf("%d-%d", l, r);
    }
}s[6*N];
int n, m;
bool judge (double v) {
    v /= 3600;
    for (int i = 0; i < n; i++) {
        int sum = d[i].r + d[i].y + d[i].g;
        double t = d[i].dis / v;
        int ti = (int)t;
        int k = ti / sum;
        t = t - k * sum;
        if (t > d[i].g + d[i].y)
            return false;
    }
    return true;
}
int main () {
    int cas = 1;
    while (scanf("%d", &n) == 1 && n != -1) {
        for (int i = 0; i < n; i++)
            scanf("%lf%d%d%d", &d[i].dis, &d[i].g, &d[i].y, &d[i].r);
        m = 0;
        for (int i = 30; i <= 60; i++) {
            if (judge(i)) {
                if (m == 0 || s[m-1].r + 1 < i) {
                    s[m].l = s[m].r = i;
                    m++;
                } else {
                    s[m-1].r++;
                }
            }
        }
        printf("Case %d: ", cas++);
        if (m) {
            for (int i = 0; i < m - 1; i++) {
                s[i].put();
                printf(", ");
            }
            s[m-1].put();
            printf("\n");
        } else
            printf("No acceptable speeds.\n");
    }
    return 0;
}
