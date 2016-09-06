#include <cstdio>
#include <cstring>
typedef long long Long;
const int MOD = 1000000007;
int C[11111][111];
void init() {
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= 10101; i++) {
        for (int j = 0; j <= i && j <= 100; j++) {
            if (j == 0) C[i][j] = 1;
            else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
        }
    }
}
int dp[111][11111];
int a[111];
int main() {
    init();
    for (int ii = 1;;ii++) {
        int n; if (scanf("%d",&n) == -1) break;
        memset(dp,0,sizeof(dp));
        memset(a,0,sizeof(a));
        for (int i = 0; i < n; i++) {
            scanf("%d",a + i);
        }
        for (int i = 0; i <= a[0]; i++) dp[0][i] = 1;
        int maxlen = a[0];
        for (int now = 0; now < n - 1; now ++) {
            int next = now + 1;
            for (int len = 0; len <= maxlen; len++) {
                if (dp[now][len] == 0) continue;
                dp[next][len] += dp[now][len];
                if (dp[next][len] >= MOD) dp[next][len] -= MOD;
                Long tmp = dp[now][len];
                for (int put = 1; put <= a[next]; put++) {
                    Long tt = tmp * C[len + put][put] % MOD;
                    dp[next][len + put] += tt;
                    if (dp[next][len + put] >= MOD) dp[next][len + put] -= MOD;
                }
            }
            maxlen += a[next];
        }
        int ans = 0;
        for (int i = 1; i <= maxlen; i++) ans = (ans + dp[n - 1][i]) % MOD;
        printf("Case %d: %d\n",ii,ans);
    }    
    return 0;
}
