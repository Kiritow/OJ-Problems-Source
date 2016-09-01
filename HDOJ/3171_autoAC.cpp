#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
inline
double solve(double S, double T, double C, double t)
{
    return T / C * (-log(S / C - t)) - 9.8 * t;
}
const double E = 1e-12;
inline
int dblcmp(double x)
{
    if (x > -E && x < E)
        return 0;
    return x > 0 ? 1 : -1;
}
struct NN {
    long long S, L, T, C;
};
NN aa[1010];
double dp[2][10100];
int main()
{
    int cn, cns;
    while (scanf("%d", &cns) == 1) {
        for (cn = 0; cn < cns; cn++) {
            int n;
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) {
                scanf("%I64d%I64d%I64d%I64d", &aa[i].S, &aa[i].L, &aa[i].T, &aa[i].C);
            }
            for (int j = 0; j <= 10000; j++) {
                dp[0][j] = 0;
            }
            double maxv = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j <= 10000; j++) {
                    int xx = i % 2, yy = (i - 1) % 2;
                    dp[xx][j] = 0;
                    dp[xx][j] = max(dp[xx][j], dp[yy][j]);
                    if (j >= aa[i].S + aa[i].L && (aa[i].T - 9.8 * j) >= 0)
                        dp[xx][j] = max(dp[xx][j], dp[yy][j - aa[i].S - aa[i].L]
                                       + solve(j, aa[i].T, aa[i].C, (double)aa[i].L / aa[i].C) - solve(j, aa[i].T, aa[i].C, 0));
                    if (maxv < dp[xx][j]) {
                        maxv = dp[xx][j];
                    }
                }
            }
            printf("%.0lf\n", floor(maxv + 0.5));
        }
    }
    return 0;
}
