#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int VMAXN = 2e4 + 10;
const int TMAXN = 100 + 10;
const int INF = 0x3f3f3f3f;
 
int num[TMAXN], dp[VMAXN], k, n, m;
int ans[TMAXN];
 
bool Check(int sum)
{
    int &cur = dp[sum];
    if (cur != -1)
        return cur;
    if (sum == 0)
        return cur = 1;
    for (int i = 0; i < k; i++)
        if (sum >= ans[i] && Check(sum - ans[i]))
            return cur = 1;
    return cur = 0;
}
 
void DFSID(int cur, int dep)
{
    if (dep == k)
    {
        memset(dp, -1, sizeof dp);
        if (Check(n))
        {
            printf("%d", k);
            for (int i = 0; i < dep; i++)
                printf(" %d", ans[i]);
            puts("");
            exit(0);
        }
        return;
    }
    if (cur >= m)
        return;
    ans[dep] = num[cur];
    DFSID(cur + 1, dep + 1);
    DFSID(cur + 1, dep);
}
 
int main()
{
    //freopen("input.txt", "r", stdin);
    int i, j;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++)
        scanf("%d", &num[i]);
    sort(num, num + m);
    for (k = 1; k <= m; k++)
        DFSID(0, 0);
    return 0;
}
