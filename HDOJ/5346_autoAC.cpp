#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const long long PIVOT = 258280327;
long long P;
long long inv(long long x)
{
    if(x <= 1)
        return 1;
    return (PIVOT - PIVOT/x)*inv(PIVOT%x)%PIVOT;
}
long long n, x, y;
long long alive_K[2010];
long long dp[2010][2010];
int main()
{
    int T, i, j;
    scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld%lld", &n, &x, &y);
        P = x * inv(y) % PIVOT;
        alive_K[0] = 1;
        for (i = 1; i <= n; ++i) {
            alive_K[i] = alive_K[i - 1] * (1 - P + PIVOT) % PIVOT;
        }
        dp[1][0] = 1;
        for (i = 2; i <= n; ++i) {
            for (j = 1; j < i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] * alive_K[j - 1] % PIVOT + dp[i - 1][j] * (1 - alive_K[j] + PIVOT) % PIVOT;
                dp[i][j] %= PIVOT;
            }
        }
        long long res;
        int k;
        printf("%lld", inv(n));
        for (k = 1; k <= n - 1; ++k) {
            res = 0;
            for (i = 1; i <= n; ++i) {
                res += dp[i][k];
                res %= PIVOT;
            }
            res = res * alive_K[k] % PIVOT * inv(n) % PIVOT;
            printf(" %lld", res);
        }
        printf("\n");
    }
}
