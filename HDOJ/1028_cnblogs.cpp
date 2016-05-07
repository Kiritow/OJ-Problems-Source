#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int M = 120 + 10;

int dp[M];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                dp[j] += dp[j - i];
            }
        }

        printf("%d\n", dp[n]);
    }
    return 0;
}
