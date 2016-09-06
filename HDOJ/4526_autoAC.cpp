#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
const int MaX = 105;
int N, K, D, S;
struct Node {
    int ti;
    int qz;
}seq[MaX];
int dp[MaX][MaX];
void solve() {
    memset(dp, 0xff, sizeof (dp));
    dp[0][N] = 0;
    for (int i = 1; i <= K; ++i) {
        const int &ti = seq[i].ti;
        const int &qz = seq[i].qz;
        for (int j = 0; j <= N; ++j) {
            if (dp[i-1][j] != -1) dp[i][j] = dp[i-1][j] + j*(ti-seq[i-1].ti);
            if (j == 0) { 
                for (int k = 1; k <= qz; ++k) {
                    if (k <= N && dp[i-1][k] != -1) {
                        if (dp[i][0] == -1) {
                            dp[i][0] = D + dp[i-1][k] + k*(ti-seq[i-1].ti);
                        } else {
                            dp[i][0] = min(dp[i][0], D + dp[i-1][k] + k*(ti-seq[i-1].ti));
                        }
                    }
                }
            } else {
                if ((j+qz) <= N && dp[i-1][j+qz] != -1) {
                    if (dp[i][j] == -1) {
                        dp[i][j] = D + dp[i-1][j+qz] + (j+qz)*(ti-seq[i-1].ti);
                    } else {
                        dp[i][j] = min(dp[i][j], D + dp[i-1][j+qz] + (j+qz)*(ti-seq[i-1].ti));
                    }
                }
            }
        }
    }
    printf("%d\n", dp[K][0]);
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &N, &K, &D, &S);
        int sum = 0;
        for (int i = 1; i <= K; ++i) {
            scanf("%d %d", &seq[i].ti, &seq[i].qz);
            sum += seq[i].qz;
        }
        if (sum < N) {
            puts("impossible");
            continue;
        }
        solve();
    }
    return 0;
}
