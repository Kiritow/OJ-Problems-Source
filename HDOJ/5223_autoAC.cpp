#include<cstdio>
#include<string>
#include<queue>
#include<cstring>
#include<iostream>
#include<map>
#include<stack>
#include<malloc.h>
#include<algorithm>
using namespace std;
const int maxn = 1005;
int T, n, m, l[maxn], r[maxn], ans[maxn], x[maxn];
int gcd(int x, int y)
{
    if (x%y) return gcd(y, x%y);
    return y;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) x[i] = 1;
        int F = 1;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &l[i], &r[i], &ans[i]);
            for (int j = l[i]; j <= r[i]; j++)
            {
                x[j] = x[j] / gcd(ans[i], x[j]);
                if ((double)x[j] * ans[i] > 1e9) F = 0;
                x[j] = x[j] * ans[i];
            }
        }
        if (F)
        for (int i = 1, u; i <= m; i++)
        {
            u = x[l[i]];
            for (int j = l[i]; j <= r[i]; j++) u = gcd(u, x[j]);
            if (u != ans[i]) { F = 0; break; }
        }
        if (F)
        {
            for (int i = 1; i < n; i++) printf("%d ", x[i]);
            printf("%d\n", x[n]);
        }
        else printf("Stupid BrotherK!\n");
    }
    return 0;
}
