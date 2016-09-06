#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 100005
int a[MAXN * 2];
struct Rem{
    int left;
    int right;
}rem;
int odd[2 * MAXN];
int min(int a, int b)
{
    return (a < b) ? a : b;
}
int fun(int i, int m, int N)
{
    int l = i - m - 1, r = i + m + 1;
    int ret = 0;
    for(;(l > 0)&&(r <= N);--l, ++r)
    {
        if((a[r] == -1) ||  ((a[l] == a[r]) && ((r - l == 2)||(a[r] <= a[r - 2])  )))
            ++ret;
        else break;
    }
    return ret;
}
int main()
{
    int T, N;
    for(scanf("%d", &T); T--; )
    {
        scanf("%d", &N);
        int i = 0;
        a[++i] = -1;
        while(N--)
        {
            scanf("%d", &a[++i]);
            a[++i] = -1;
        }
        N = i;
        rem.left = rem.right = 0;
        int ans = 1;
        memset(odd, 0, sizeof(odd));
        for(int i = 1; i <= N; ++i)
        {
            int m = 0;
            if(rem.right > i)
                m = min(rem.right - i, odd[rem.left + (rem.right - i)]);
            odd[i] = m + fun(i, m, N);
            if(i + odd[i] > rem.right)
            {
                rem.left = i - odd[i];
                rem.right = i + odd[i];
            }
            if(odd[i] > ans)
                ans = odd[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}
