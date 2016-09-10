#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[10][200000], mx[10];
int dfs(int len, int pre, bool flag)
{
    if (len < 0) return pre >= 0;
    if (pre < 0) return 0;
    if (!flag && dp[len][pre] != -1) return dp[len][pre];
    int end = flag?mx[len]:9, ans = 0;
    for (int i = 0; i <= end; ++i) {
        ans += dfs(len-1, pre-i*(1<<len), flag&&i==end);
    }
    if (!flag) dp[len][pre] = ans;
    return ans;
}
int f(int x)
{
    int tmp = 1, ans = 0;
    while (x) {
        ans += x%10*tmp;
        x /= 10;
        tmp *= 2;
    }
    return ans;
}
int cal(int a, int b)
{
    int top = 0;
    while (b) {
        mx[top++] = b%10;
        b /= 10;
    }
    return dfs(top-1, f(a), true);
}
int main()
{
    int iCase = 1, nCase;
    int a, b;
    scanf("%d", &nCase);
    memset(dp, 0xff, sizeof(dp));
    while (nCase--) {
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d\n", iCase++, cal(a, b));
    }
    return 0;
}
