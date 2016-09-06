#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;
int x[20][20][15][15], n, m, p, q, need[20][20][2], small[20][20];
int dp[20][20][2], match[20], g[20][20];
bool vst[20], equ[20][20];
int find(int u, int m)
{
    for(int i = 0; i < m; i++)
        if (!vst[i] && g[u][i])
        {
            vst[i] = 1;
            if (match[i] == -1 || find(match[i], m) == 1)
            {
                match[i] = u;
                return 1;
            }
        }
    return 0;
}
int solve(int n)
{
    memset(match, -1, sizeof(match));
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        memset(vst, 0, sizeof(vst));
        ans += find(i, n);
    }
    return ans;
}
int main()
{
    while(scanf("%d%d%d%d", &n, &m, &p, &q) != EOF)
    {
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int i2 = 0; i2 < m; i2++)
                    for(int j2 = 0; j2 < m; j2++)
                        scanf("%d", &x[i][j][i2][j2]);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                for(int i2 = 0; i2 < m; i2++)
                    for(int j2 = 0; j2 < m; j2++)
                    {
                        if (x[i][j][i2][j2]) g[i2][j2] = 1;
                        else g[i2][j2] = 0;
                    }
                small[i][j] = solve(m) * p;
            }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                need[i][j][0] = need[i][j][1] = 0;
                dp[i][j][0] = dp[i][j][1] = 0x7fffffff;
                for(int i2 = 0; i2 < m; i2++)
                {
                    bool flag = false;
                    for(int j2 = 0; j2 < m; j2++)
                        if (x[i][j][i2][j2])
                        {flag = true; break;}
                    need[i][j][0] += flag;
                }
                need[i][j][0] *= p;
                for(int j2 = 0; j2 < m; j2++)
                {
                    bool flag = false;
                    for(int i2 = 0; i2 < m; i2++)
                        if (x[i][j][i2][j2])
                        {flag = true; break;}
                    need[i][j][1] += flag;
                }
                need[i][j][1] *= p;
                if (small[i][j] < need[i][j][0] && small[i][j] < need[i][j][1])
                    equ[i][j] = true;
                else equ[i][j] = false;
            }
        dp[0][0][0] = min(need[0][0][0], need[0][0][1] + q);
        if (equ[0][0]) dp[0][0][0] = min(dp[0][0][0], small[0][0] + q);
        dp[0][0][1] = min(need[0][0][1], need[0][0][0] + q);
        if (equ[0][0]) dp[0][0][1] = min(dp[0][0][1], small[0][0] + q);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                int tmpa, tmpb;
                tmpa = i - 1; tmpb = j;
                if (tmpa >= 0 && tmpa < n && tmpb >= 0 && tmpb < n)
                {
                    int val = dp[tmpa][tmpb][0];
                    int val1 = min(need[i][j][0], need[i][j][1] + q + q);
                    if (equ[i][j]) val1 = min(val1, small[i][j] + q + q);
                    int val2 = min(need[i][j][0] + q, need[i][j][1] + q);
                    if (equ[i][j]) val2 = min(val2, small[i][j] + q);
                    dp[i][j][0] = min(dp[i][j][0], val + val1);
                    dp[i][j][1] = min(dp[i][j][1], val + val2);
                }
                tmpa = i; tmpb = j - 1;
                if (tmpa >= 0 && tmpa < n && tmpb >= 0 && tmpb < n)
                {
                    int val = dp[tmpa][tmpb][1];
                    int val1 = min(need[i][j][1], need[i][j][0] + q + q);
                    if (equ[i][j]) val1 = min(val1, small[i][j] + q + q);
                    int val2 = min(need[i][j][1] + q, need[i][j][0] + q);
                    if (equ[i][j]) val2 = min(val2, small[i][j] + q);
                    dp[i][j][1] = min(dp[i][j][1], val + val1);
                    dp[i][j][0] = min(dp[i][j][0], val + val2);
                }
            }
        printf("%d\n", min(dp[n - 1][n - 1][0], dp[n - 1][n - 1][1]));
    }
    return 0;
}
