#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MOD = 1000000007;
int n, m, c, d, pre = 0, now = 1;
long long dp[2][25][1222];
char g[105][15];
int main() {
    while (~scanf("%d%d%d%d", &n, &m, &c, &d)) {
        int maxs = (1<<m);
        memset(dp[now], 0, sizeof(dp[now]));
        dp[now][0][maxs - 1] = 1;
        for (int i = 0; i < n; i++)
            scanf("%s", g[i]);
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                swap(pre, now);
                memset(dp[now], 0, sizeof(dp[now]));
                int tmp = g[i][j] - '0';
                if (tmp) {
                    for (int k = 0; k <= d; k++) {
                        for (int s = 0; s < maxs; s++) {
                            if (k && (s&1<<j))
                                dp[now][k][s] = (dp[now][k][s] + dp[pre][k - 1][s]) % MOD;
                            if (j && !(s&1<<(j-1)) && (s&1<<j))
                                dp[now][k][s|1<<(j-1)] = (dp[now][k][s|1<<(j-1)] + dp[pre][k][s]) % MOD;
                              dp[now][k][s^1<<j] = (dp[now][k][s^1<<j] + dp[pre][k][s]) % MOD;
                        }
                    }
                }
                else {
                    for (int k = 0; k <= d; k++) {
                        for (int s = 0; s < maxs; s++) {
                            if ((s&1<<j))
                                dp[now][k][s] = (dp[now][k][s] + dp[pre][k][s]) % MOD;
                         }
                    }
                   }
               }
          }
          long long ans = 0;
          for (int i = c; i <= d; i++)
              ans = (ans + dp[now][i][maxs - 1]) % MOD;
          printf("%lld\n", ans);
     }
    return 0;
}
