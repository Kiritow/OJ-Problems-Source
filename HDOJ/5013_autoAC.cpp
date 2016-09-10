#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
#define RD(x) scanf("%d",&x)
#define RD2(x,y) scanf("%d%d",&x,&y)
#define RD3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define clr0(x) memset(x,0,sizeof(x))
typedef long long LL;
const int maxn = 20;
int n, m;
double p[maxn][maxn],h[maxn][maxn],f[maxn][maxn][maxn],g[maxn][maxn][maxn];
int main() {
    while (~RD2(m,n)) {
        for (int i = 1; i <= m; i++) {
            scanf("%lf", &p[i][1]);
            p[i][0] = 1.0;
            for (int j = 2; j <= n; j++) {
                p[i][j] = p[i][j - 1] * p[i][1];
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%lf", &h[i][j]);
            }
        }
        clr0(f),clr0(g);
        double ans = 0;
        for (int i = 2; i <= n; i++) {
            f[i][0][0] = 1;
            for (int j = 1; j <= m; j++) {
                for (int x = m; x >= 0; x--) {
                    for (int y = x; y >= 0; y--) {
                        f[i][x][y] *= (1.0 - p[j][i - 2]);
                        if (x > 0) {
                            f[i][x][y] += f[i][x - 1][y] * p[j][i - 2] * (1.0 - p[j][1]);
                            if (y > 0) {
                                f[i][x][y] += f[i][x - 1][y - 1] * p[j][i - 1];
                            }
                        }
                        g[i][x][y] *= (1.0 - p[j][i - 2]);
                        if (x > 0) {
                            g[i][x][y] += g[i][x - 1][y] * p[j][i - 2] * (1.0 - p[j][1]);
                            if (y > 0) {
                                g[i][x][y] += (g[i][x - 1][y - 1] + f[i][x - 1][y - 1] * h[j][i]) * p[j][i - 1];
                            }
                        }
                    }
                }
            }
            for (int x = 1; x <= m; x++) {
                for (int y = 1; y <= x; y++) {
                    ans += g[i][x][y] * ((double)y / x + 1.0);
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            ans += h[i][1];
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
