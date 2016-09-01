#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX_N = 8, MAX_S = 1 << MAX_N;
int n, m, t, dp[MAX_S][MAX_S];
char g[MAX_N][MAX_N + 1];
int main() {
    while (scanf("%d", &n) != EOF) {
        if (!n) break;
        for (int i = 0; i < n; i ++) {
            scanf("%s", g[i]);
            for (int j = 0; j < n; j ++) g[i][j] -= '0';
        }
        int upper = 1 << n, ans = 0;
        for (int i = 0; i < n; i ++) {
            memset(dp, 0, sizeof(dp));
            dp[1 << i][1 << i] = 1;
            for (int mask = 0; mask < upper; mask ++)
                for (int s = mask; s; s = (s - 1) & mask)
                    for (int u = 0; u < n; u ++) if (mask & (1 << u))
                        for (int v = 0; v < n; v ++) if ((mask & (1 << v)) == 0 && g[u][v]) {
                            int m1 = mask | (1 << v);
                            int m2 = (s | (1 << v)) & (~(1 << u));
                            if (((1 << (v + 1)) - 1) >= m2) dp[m1][m2] += dp[mask][s];
                        }
            for (int s = 0; s < upper; s ++) ans += dp[upper - 1][s];
        }
        printf("%d\n", ans);
    }
    return 0;
}
