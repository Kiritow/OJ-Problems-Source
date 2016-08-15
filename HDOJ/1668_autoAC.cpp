#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define N 13
#define M 8192
int f[M][N][N];
ll g[M][N][N];
int a[N][N];
int v[N];
int t, n, m;
void dp()
{
    if (n == 1)
    {
        cout << v[0] << " " << 1 << endl;
        return ;
    }
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    for (int i = 0; i < n; ++i)
    {
        f[1 << i][i][i] = v[i];
        g[1 << i][i][i] = 1;
    }
    m = (1 << n) - 1;
    for (int s = 0; s < m; ++s)
        for (int i = 0; 1 << i <= s; ++i)
            if ((s >> i) & 1)
                for (int j = 0; 1 << j <= s; ++j)
                    if (((s >> j) & 1) && f[s][i][j])
                        for (int k = 0; k < n; ++k)
                            if (!((s >> k) & 1) && a[j][k])
                            {
                                int temp = f[s][i][j] + v[k] + v[j] * v[k];
                                if (i != j && a[i][k])
                                    temp += v[i] * v[j] * v[k];
                                int ss = s + (1 << k);
                                if (temp > f[ss][j][k])
                                {
                                    f[ss][j][k] = temp;
                                    g[ss][j][k] = g[s][i][j];
                                }
                                else if (temp == f[ss][j][k])
                                {
                                    g[ss][j][k] += g[s][i][j];
                                }
                            }
    int ans = 0;
    ll ans2 = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (f[m][i][j] > ans)
            {
                ans = f[m][i][j];
                ans2 = g[m][i][j];
            }
            else if (f[m][i][j] == ans)
            {
                ans2 += g[m][i][j];
            }
    cout << ans << " " << ans2 / 2 << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    scanf("%d", &t);
    while (t--)
    {
        memset(a, 0, sizeof(a));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
            scanf("%d", &v[i]);
        while (m--)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            --x, --y;
            a[x][y] = a[y][x] = 1;
        }
        dp();
    }
    return 0;
}
