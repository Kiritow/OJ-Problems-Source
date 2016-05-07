#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

const int M = 300 + 10;

int dp[111][M];
int c[] = {0, 1, 5, 10, 25, 50};

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n))
    {

        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;

        for (int i = 1; i <= 5; i++)//枚举硬币总类
        {
            for (int num = 1; num <= 100; num++)//枚举硬币个数
            {
                for (int j = c[i]; j <= n; j++)//枚举容量
                {

                    dp[num][j] += dp[num - 1][j - c[i]];
                }
            }
        }


        int ans = 0;
        for (int i = 0; i <= 100; i++)//累加答案
        {
            ans += dp[i][n];
        }

        printf("%d\n", ans);
    }
    return 0;
}
