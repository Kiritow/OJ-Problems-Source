#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAXN 205
int a[MAXN];
int f[MAXN][MAXN];
int main()
{
    int T, N;
    for(scanf("%d", &T); T--; )
    {
        scanf("%d", &N);
        for(int i = 1; i <= N; ++i)
            scanf("%d", &a[i]);
        memset(f, 0, sizeof(f));
        int ans = 1;
        for(int i = 1; i <= N; ++i)
        {
            int max = 0;
            for(int j = N; i < j;  --j)
            {
                f[i][j] = f[i-1][j];
                if((a[i] == a[j]) && (f[i][j] < max + 1))
                    f[i][j] = max + 1;
                else if((a[i] > a[j]) &&(f[i-1][j] > max)) max = f[i-1][j];
                if(f[i][j] * 2 > ans) ans = f[i][j] * 2;
                for(int k = i + 1; k < j; ++k)
                {
                    if(a[k] > a[j])
                    {
                        if(2 * f[i][j] + 1 > ans)
                            ans = 2 * f[i][j] + 1;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
