#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
int const maxn = 51 + 51 * 50 / 2;
int n, m;
long long dp[55][55];
bool triangle[maxn];

long long gcd(long long a, long long b)
{
    if(b)
        return gcd(b, a % b);
    return a;
}

int main()
{
    scanf("%d %d", &n, &m);
    char s[5];
    int index = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            scanf("%s", s);
            if(s[0] == '*')
                triangle[index++] = true;
            else
                triangle[index++] = false;
        }
    }
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
        dp[1][1] <<= 1;
    for(int i = 1; i <= n; i++)
    {
        int id = i * (i - 1) / 2;
        for(int j = 1; j <= i; j++)
        {
            if(triangle[id + j])
            {
                dp[i+1][j] += dp[i][j] >> 1;
                dp[i+1][j+1] += dp[i][j] >> 1;
            }
            else
            {
                dp[i+2][j+1] += dp[i][j];
            }
        }
    }
    long long ans1 = dp[n+1][m+1];
    long long ans2 = 0;
    for(int i = 1; i <= n + 1; i++)
        ans2 += dp[n+1][i];

    long long k = gcd(ans1,ans2);
    if(ans1 == 0)
    {
        ans2 = 1;
        k = 1;
    }
    printf("%lld/%lld\n", ans1 / k, ans2 / k);

}
