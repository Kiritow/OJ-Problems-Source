#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <set>
#include <vector>
#include <map>
#define MAXN 11111
#define MAXM 55555
#define INF 1000000007
using namespace std;
long long f[111111];
struct node {
    int d, p, g, r;
}p[111111];
bool cmp(node x, node y) {
    return x.d < y.d;
}
int n, d;
typedef pair<int, long long> PA;
PA A[111111], C[111111];
long long h(int j) {
    return f[j] + (long long)p[j].r - (long long)p[j].p - (long long)p[j].g * (long long)(p[j].d + 1);
}
int slopecomp(PA a, PA b, PA c) {
    long long xa = b.first - a.first;
    long long xb = c.first - a.first;
    long long ya = b.second - a.second;
    long long yb = c.second - a.second;
    double tmp = (double)xa * yb - (double)xb * ya;
    return tmp < 0;
}
void cdq(int l, int r) {
    if(l + 1 <= r) {
        int m = (l + r) >> 1;
        cdq(l, m);
        int na = 0, nb = 0, nc = 0;
        for(int j = l; j <= m; j++) {
            if(f[j] >= p[j].p) A[na++] = PA(p[j].g, h(j));
        }
        sort(A, A + na);
        for(int i = 0; i < na; i++) {
            while(nc > 1 && !slopecomp(C[nc - 1], C[nc], A[i])) nc--;
            C[++nc] = A[i];
        }
        int j = 0;
        for(int i = m + 1; i <= r; i++) {
            long long a1, a2, b1, b2, x;
            x = p[i].d;
            while(j < nc) {
                a1 = C[j].first;
                a2 = C[j + 1].first;
                b1 = C[j].second;
                b2 = C[j + 1].second;
                if(a1 * x + b1 >= a2 * x + b2) break;
                j++;
            }
            f[i] = max(f[i], (long long)C[j].first * x + C[j].second);
        }
        cdq(m + 1, r);
    }
}
int main() {
    int cas = 0;
    while(scanf("%d%I64d%d", &n, &f[0], &d) != EOF) {
        if(n == 0 && f[0] == 0 && d == 0) break;
        for(int i = 1; i <= n; i++) scanf("%d%d%d%d", &p[i].d, &p[i].p, &p[i].r, &p[i].g);
        sort(p + 1, p + n + 1, cmp);
        ++n;
        p[n].d = d + 1;
        p[n].g = p[n].p = 0;
        for(int i = 1; i <= n; i++) f[i] = f[0];
        cdq(0, n);
        printf("Case %d: %I64d\n", ++cas, f[n]);
    }
    return 0;
}
