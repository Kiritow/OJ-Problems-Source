#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define eps 1e-5
#define MAXN 105
#define MAXM 11111
#define INF 1000000000
#define lch(x) x<<1
#define rch(x) x<<1|1
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int n, m, x, t;
int in()
{
    int flag = 1;
    char ch;
    int a = 0;
    while((ch = getchar()) == ' ' || ch == '\n');
    if(ch == '-') flag = -1;
    else
    a += ch - '0';
    while((ch = getchar()) != ' ' && ch != '\n')
    {
        a *= 10;
        a += ch - '0';
    }
    return flag * a;
}
int dp[MAXN][MAXM];
int sum[MAXN][MAXM];
int lmx[4 * MAXM];
int rmx[4 * MAXM];
int a[MAXN][MAXM];
int q[MAXM];
int main()
{
    while(scanf("%d%d%d%d", &n, &m, &x, &t) != EOF)
    {
        for(int i = 1; i <= n + 2; i++)
            for(int j = 1; j <= m; j++)
                sum[i][j] = 0, dp[i][j] = -INF, a[i][j] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
            {
                a[i][j] = in();
                sum[i][j] = sum[i][j - 1] + a[i][j];
            }
        int tmp = 0;
        for(int i = x; i <= x + t; i++)
        {
            tmp += a[1][i];
            dp[1][i] = tmp;
            dp[2][i] = dp[1][i] + a[2][i];
        }
        tmp = 0;
        for(int i = x; i >= x - t; i--)
        {
            tmp += a[1][i];
            dp[1][i] = tmp;
            dp[2][i] = dp[1][i] + a[2][i];
        }
        for(int i = 3; i <= n + 1; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                lmx[j] = dp[i - 1][j] - sum[i - 1][j];
                rmx[j] = dp[i - 1][j] + sum[i - 1][j - 1];
            }
            int head = 1, rear = 0;
            for(int j = 1; j <= m; j++)
            {
                while(head <= rear && lmx[q[rear]] <= lmx[j]) rear--;
                q[++rear] = j;
                while(head <= rear && q[head] < j - t) head++;
                dp[i][j] = max(lmx[q[head]] + sum[i - 1][j] + a[i][j], dp[i][j]);
            }
            head = 1, rear = 0;
            for(int j = m; j >= 1; j--)
            {
                while(head <= rear && rmx[q[rear]] <= rmx[j]) rear--;
                q[++rear] = j;
                while(head <= rear && q[head] > j + t) head++;
                dp[i][j] = max(rmx[q[head]] - sum[i - 1][j - 1] + a[i][j], dp[i][j]);
            }
        }
        int ans = -INF;
        for(int i = 1; i <= m; i++)
            if(dp[n + 1][i] > ans) ans = dp[n + 1][i];
        printf("%d\n", ans);
    }
    return 0;
}
