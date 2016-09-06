#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
#define CLR(a, b) memset(a, b, sizeof(a))
using namespace std;
const int N = 205;
double dp[2][N][N];
int main()
{
    int t, n,cas;double L, R, ans;
    scanf("%d", &t);
    while(t --)
    {
        scanf("%d%d%lf%lf", &cas, &n, &L, &R);
        CLR(dp, 0);dp[0][0][100] = 1;
        for(int i = 1; i <= n; i ++)
        {
            CLR(dp[i&1], 0);
            for(int j = 0; j <= i; j ++)
            {
                for(int k = 100 - i; k <= 100 + j; k ++)
                {
                    dp[i&1][j][k] += dp[(i-1)&1][j][k-1] * R;
                    dp[i&1][j][k] += dp[(i-1)&1][j][k+1] * L;
                    dp[i&1][j][k] += dp[(i-1)&1][j][k] * (1.0 - L - R);
                }
                dp[i&1][j][100+j] += dp[(i-1)&1][j-1][99+j] * R;
            }
        }ans = 0;
        for(int i = 0; i <= n; i ++)
        {
            for(int j = 100 - n; j <= 100 + n; j ++)
            {
                ans += i * dp[n&1][i][j];
            }
        }
        printf("%d %.4lf\n", cas, ans);
    }
}
