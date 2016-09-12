#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL base = 1e9 + 7;
const int maxn = 105;
LL T, n, m, f[maxn], a[maxn][maxn];
inline void read(int &x)
{
    char ch;
    while ((ch = getchar())<'0' || ch>'9');
    x = ch - '0';
    while ((ch = getchar()) >= '0' && ch <= '9') x = x * 10 + ch - '0';
}
int main()
{
    for (int i = f[0] = 1; i <= 100; i++) f[i] = f[i - 1] * i % base;
    while (scanf("%I64d%I64d", &n, &m) != EOF)
    {
        LL tot = 0, ans = 1;
        for (int i = 1; i <= m; i++)
        {
            scanf("%I64d", &a[i][1]);
            if (a[i][1] == -1) tot++;
            else for (int j = 2; j <= n; j++)
            {
                scanf("%I64d", &a[i][j]);
                for (int k = j - 1; k; k--) if (a[i][j] == a[i][k]) ans = 0;
            }
        }
        for (int i = 1; i < tot; i++) ans = ans * f[n] % base;
        if (tot == 0)
        {
            for (int i = 1; i <= n; i++) a[0][i] = i;
            for (int i = m; i; i--)
                for (int j = 1; j <= n; j++) a[0][j] = a[i][a[0][j]];
            for (int i = 1; i <= n; i++) if (a[0][i] != i) ans = 0;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
