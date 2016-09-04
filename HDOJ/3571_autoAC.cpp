#include<cstdio>
#include<cstring>
#include<algorithm>
typedef long long LL;
#define MAXN 60
#define P 200000000000000003LL
#define S 100000000000000000LL
using namespace std;
LL x[MAXN], g[MAXN][MAXN], a[MAXN][MAXN], b[MAXN][MAXN];
int n;
inline LL Mod(LL x) {
    if (x >= P)
        return x - P;
    return x;
}
LL MulMod(LL a, LL b) {
    LL res;
    for (res = 0; b; b >>= 1) {
        if (b & 1)
            res = Mod(res + a);
        a = Mod(a + a);
    }
    return res;
}
LL ExtGcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    LL t, d;
    d = ExtGcd(b, a % b, x, y);
    t = x;
    x = y;
    y = t - a / b * y;
    return d;
}
LL InvMod(LL a, LL n) {
    LL x, y;
    ExtGcd(a, n, x, y);
    return (x % n + n) % n;
}
void Gauss() {
    int i, j, k;
    LL inv, tmp;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            if (g[j][i])
                break;
        }
        if (i != j) {
            for (k = i; k <= n; k++)
                swap(g[i][k], g[j][k]);
        }
        inv = InvMod(g[i][i], P);
        for (j = i + 1; j < n; j++) {
            if (g[j][i]) {
                tmp = MulMod(g[j][i], inv);
                for (k = i; k <= n; k++) {
                    g[j][k] -= MulMod(tmp, g[i][k]);
                    g[j][k] = (g[j][k] % P + P) % P;
                }
            }
        }
    }
    for (i = n - 1; i >= 0; i--) {
        tmp = 0;
        for (j = i + 1; j < n; j++) {
            tmp += MulMod(x[j], g[i][j]);
            if (tmp >= P)
                tmp -= P;
        }
        tmp = g[i][n] - tmp;
        tmp = (tmp % P + P) % P;
        x[i] = MulMod(tmp, InvMod(g[i][i], P));
    }
}
int main() {
    int c, ca = 1;
    int i, j;
    LL tmp;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        memset(g, 0, sizeof(g));
        memset(b, 0, sizeof(b));
        for (i = 0; i <= n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%I64d", &a[i][j]);
                a[i][j] += S;
                b[i][n] += MulMod(a[i][j], a[i][j]);
                if (b[i][n] >= P)
                    b[i][n] -= P;
            }
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                tmp = a[i + 1][j] - a[i][j];
                tmp = (tmp % P + P) % P;
                g[i][j] = MulMod(tmp, 2);
            }
            g[i][n] = b[i + 1][n] - b[i][n];
            g[i][n] = (g[i][n] % P + P) % P;
        }
        Gauss();
        printf("Case %d:\n", ca++);
        printf("%I64d", x[0] - S);
        for (i = 1; i < n; i++)
            printf(" %I64d", x[i] - S);
        putchar('\n');
    }
    return 0;
}
