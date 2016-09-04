#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int dp[55][205], a[205], b[205];
int _, n, x, y, kase = 0;
bool check(int t)
{
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(dp[i][x] >= y)    return true;    
        for(int j = 0; j <= x; ++j)
        {
            if(dp[i - 1][j] != -1)
            {
                int temp = min(t/a[i], x-j);    
                for(int k = 0; k <= temp; ++k)
                {
                    int t1 = (t - a[i] * k) / b[i];   
                    dp[i][j + k] = max(dp[i][j + k], dp[i - 1][j] + t1);    
                }
            }
        }
    }
    if(dp[n][x] >= y)    return true;
    return false;
}
int main(void)
{
    scanf("%d", &_);
    while(_--)
    {
        scanf("%d%d%d", &n, &x, &y);
        for(int i = 1; i <= n; ++i)
            scanf("%d%d", &a[i], &b[i]);
        int l = 0, r = a[1] * x + b[1] * y;
        int ans = r;
        while(l <= r)
        {
            int mid = (l + r) >> 1;
            if(check(mid))
            {
                ans = mid;
                r = mid - 1;
            }
            else    l = mid + 1;
        }
        printf("Case %d: %d\n", ++kase, ans);
    }
    return 0;
}
