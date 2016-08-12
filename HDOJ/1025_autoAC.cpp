#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[500001];
int dp[500001];
int f[500001];
int binary_search(int k, int l, int h)
{
    int mid;
    while (l <= h)
    {
        mid = (l + h)/2;
        if (f[mid] <= k)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}
int main()
{
    int n;
    int t = 0;
    while (scanf("%d", &n) != EOF)
    {
        ++t;
        memset(f, -1, sizeof(f));
        int i;
        int tmp1,tmp2;
        for (i = 0; i < n; ++i)
        {
            scanf("%d %d", &tmp1, &tmp2);
            a[tmp1] = tmp2;
        }
        dp[1] = 1;
        f[1] = a[1];
        int len = 1;
        for (i = 2; i <= n; ++i)
        {
            int x = binary_search(a[i], 1, len);
            dp[i] = x + 1;
            if ( f[i] == -1 || a[i] < f[dp[i]] )
                f[dp[i]] = a[i];
            if (dp[i] > len)
                len = dp[i];
        }
        if (len == 1)
            printf("Case %d:\nMy king, at most %d road can be built.\n\n", t, len);
        else
            printf("Case %d:\nMy king, at most %d roads can be built.\n\n", t, len);
    }
    return 0;
}
