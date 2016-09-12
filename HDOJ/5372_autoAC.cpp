#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int low(int x) { return x&-x; }
const int maxn = 400005;
int n, m, x[maxn], y[maxn], z[maxn], a[maxn], tot, f[2][maxn], tt = 0, u, v;
void add(int x, int y, int z)
{
    for (int i = y; i <= m; i += low(i)) f[x][i] += z;
}
int get(int x, int y)
{
    int ans = 0;
    for (int i = y; i; i -= low(i)) ans += f[x][i];
    return ans;
}
int main()
{
    while (scanf("%d", &n) != EOF)
    {
        tot = 0;
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &z[i], &x[i]);
            if (!z[i]) {
                a[++tot] = x[i];
                y[i] = x[i] + (++tot) / 2;
                a[tot] = y[i];
            }
            else
            {
                y[i] = a[x[i] + x[i]];
                x[i] = a[x[i] + x[i] - 1];
            }
        }
        sort(a + 1, a + tot + 1);
        m = unique(a + 1, a + tot + 1) - a;
        printf("Case #%d:\n", ++tt);
        for (int i = 1; i <= n; i++)
        {
            u = lower_bound(a + 1, a + m, x[i]) - a;
            v = lower_bound(a + 1, a + m, y[i]) - a;    
            if (!z[i]) printf("%d\n", get(1, v) - get(0, u - 1));
            add(0, u, z[i] ? -1 : 1);
            add(1, v, z[i] ? -1 : 1);
        }
    } 
    return 0;
}
