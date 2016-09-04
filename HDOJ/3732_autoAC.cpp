#include <iostream>
#include <string.h>
using namespace std;
const int maxc = 10005;
int dp[maxc], re[11][11], cost;
void Pack(int v, int c, int k)
{
    for (int m = 1; k > 0; m += m)
    {
        if (m > k)
            m = k;
        k -= m;
        int vv = v * m, cc = c * m;
        for (int j = cost; j - cc >= 0; j--)
        {
            if (dp[j] < dp[j-cc] + vv)
                dp[j] = dp[j-cc] + vv;
        }
    }
}
int main()
{
    int n, i, j;
    int v, c;
    while (scanf("%d %d", &n, &cost) != EOF)
    {
        memset(dp, 0, (cost + 1) * 4);
        memset(re, 0, sizeof(re));
        for (i = 0; i < n; i++)
        {
            scanf("%*c%*s %d %d", &v, &c);
            re[v][c]++;
        }
        for (i = 1; i <= 10; i++)
            for (j = 0; j <= 10; j++)
            {
                if (re[i][j] > 0)
                {
                    Pack(i, j, re[i][j]);
                }
            }
        printf("%d\n", dp[cost]);
    }
    return 0;
}
