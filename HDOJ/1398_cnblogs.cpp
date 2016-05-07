#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

const int M = 300 + 10;

int dp[M];

int main()
{
    int n;
    while (~scanf("%d", &n), n)
    {

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;

        int max = (int)sqrt(n * 1.0);
        for (int i = 1; i <= max; i++)
        {
            for (int j = i * i; j <= n; j++)
            {
                dp[j] += dp[j - i * i];
            }
        }

        printf("%d\n", dp[n]);
    }
    return 0;
}
