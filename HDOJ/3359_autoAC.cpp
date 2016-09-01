#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAXN 110
using namespace std;
double a[MAXN][MAXN], g[MAXN][MAXN], x[MAXN];
int pos[MAXN][MAXN];
int n, m, d, cnt;
int MHT(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}
void Gauss() {
    int i, j, k;
    double tmp, big;
    for (i = 0; i < cnt; i++) {
        for (big = 0, j = i; j < cnt; j++) {
            if (abs(g[j][i]) > big) {
                big = abs(g[j][i]);
                k = j;
            }
        }
        if (k != i) {
            for (j = 0; j <= cnt; j++)
                swap(g[i][j], g[k][j]);
        }
        for (j = i + 1; j < cnt; j++) {
            if (g[j][i]) {
                tmp = -g[j][i] / g[i][i];
                for (k = i; k <= cnt; k++)
                    g[j][k] += tmp * g[i][k];
            }
        }
    }
    for (i = cnt - 1; i >= 0; i--) {
        tmp = 0;
        for (j = i + 1; j < cnt; j++)
            tmp += g[i][j] * x[j];
        x[i] = (g[i][j] - tmp) / g[i][i];
    }
}
int main() {
    int i, j, k, l;
    bool flag = true;
    while (scanf("%d%d%d", &m, &n, &d), n) {
        if (flag)
            flag = false;
        else
            putchar('\n');
        for (i = cnt = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%lf", &a[i][j]);
                pos[i][j] = cnt++;
            }
        }
        memset(g, 0, sizeof(g));
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                for (k = 0; k < n; k++) {
                    for (l = 0; l < m; l++) {
                        if (MHT(i, j, k, l) <= d) {
                            g[pos[i][j]][pos[k][l]] = 1;
                            g[pos[i][j]][cnt] += a[i][j];
                        }
                    }
                }
            }
        }
        Gauss();
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++)
                printf("%8.2lf", x[i * m + j]);
            putchar('\n');
        }
    }
    return 0;
}
