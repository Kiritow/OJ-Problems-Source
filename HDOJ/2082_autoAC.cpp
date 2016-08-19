#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int a[27], b[27][51], N;
    memset(b, 0, sizeof(b));
    scanf("%d", &N);
    while (N--)
    {
        int i, j, k;
        for (i = 1; i <= 26; i++) scanf("%d", &a[i]);
        for (i = 0; i <= 26; i++) b[i][0] = 1;
        for (i = 1; i <= 26; i++)
        {
            for (j = 1; j <= 50; j++)
            {
                b[i][j] = b[i - 1][j];
                for (k = 1; k <= a[i]; k++)
                {
                    if (j - k * i >= 0)
                        b[i][j] += b[i - 1][j - k * i];
                }
            }
        }
        int ans = 0;
        for (i = 1; i <= 50; i++)
            ans += b[26][i];
        printf("%d\n", ans);
    }
    return 0;
}
