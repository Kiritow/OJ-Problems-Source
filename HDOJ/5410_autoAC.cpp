#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
int w[N], a[N], b[N];
int dp[N][2005][2];
int main(){
    int t; scanf("%d", &t);
    while (t--){
        int m, n; scanf("%d %d", &m, &n);
        for (int i = 1; i <= n; i++){
            scanf("%d %d %d", w + i, a + i, b + i);
        }
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++){
            for (int j = 0; j < w[i]; j++){
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                dp[i][j][1] = 0;
            }
            for (int j = w[i]; j <= m; j++){
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1]);
                dp[i][j][1] = max(dp[i][j - w[i]][0] + a[i] + b[i], dp[i][j - w[i]][1] + a[i]);
            }
        }
        int ans = max(dp[n][m][0], dp[n][m][1]);
        printf("%d\n", ans);
    }
    return 0;
}
