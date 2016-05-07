#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int M = 32768 + 10;

int dp[M];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= 3; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[j] += dp[j - i];
            }
        }

        printf("%d\n", dp[n]);
    }
    return 0;
}
