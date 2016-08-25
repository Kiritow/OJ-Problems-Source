#include <cstdio>
#include <algorithm>
using namespace std;
int const N = 200010;
int m, n, c[N], l, dp[N], i, j;
int main() {
  while(~scanf("%d%d", &m, &n)) {
    for(j=1; j<=m; c[j++]=dp[n])
      for(i=2, scanf("%d", &dp[1]); i<=n && scanf("%d", &l); i++)
        dp[i] = max(dp[i-2]+l, dp[i-1]);
    for(i=2, dp[1]=c[1]; i<=m; i++)
      dp[i] = max(dp[i-2]+c[i], dp[i-1]);
    printf("%d\n", dp[m]);
  }
  return 0;
}
