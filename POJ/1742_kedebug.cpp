#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 110;
const int MAXD = 100010;

int A[MAXN], C[MAXN];
bool dp[MAXD], deq[MAXD];

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) && n && m >= 0)
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", &A[i]);
        for (int i = 0; i < n; ++i)
            scanf("%d", &C[i]);
        for (int v = 0; v <= m; ++v)
            dp[v] = false;

        int ret = 0;
        dp[0] = true;

        for (int i = 0; i < n; ++i)
        {
            if (C[i] == 1)
            {
                for (int v = m; v >= A[i]; --v)
                    if (!dp[v] && dp[v - A[i]])
                        dp[v] = true, ++ret;
                continue;
            }

            if (A[i] * C[i] >= m)
            {
                for (int v = A[i]; v <= m; ++v)
                    if (dp[v - A[i]] && !dp[v])
                        dp[v] = true, ++ret;
                continue;
            }

            for (int rem = 0; rem < A[i]; ++rem)
            {
                int s = 0, e = -1, sum = 0;
                for (int v = rem; v <= m; v += A[i])
                {
                    if (s + C[i] == e)
                        sum -= deq[s++];

                    deq[++e] = dp[v];
                    sum += dp[v];

                    if (!dp[v] && sum)
                        dp[v] = true, ++ret;
                }
            }
        }
        printf("%d\n", ret);
    }
    return 0;
}
