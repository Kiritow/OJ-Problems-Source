#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define maxn 15
#define maxk 1005
#define maxd 35
#define inf 0x3f3f3f3f
int n, m;
int f[maxn][maxk];
int flight_num[maxn][maxn];
int flight[maxn][maxn][maxd];
void input()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
            {
                scanf("%d", &flight_num[i][j]);
                for (int k = 0; k < flight_num[i][j]; k++)
                    scanf("%d", &flight[i][j][k]);
            }
}
void cal(int day, int u, int v)
{
    if (f[u][day] == -1)
        return;
    if (flight_num[u][v] == 0)
        return;
    if (flight[u][v][day % flight_num[u][v]] != 0
            && (f[v][day + 1] == -1 || f[v][day + 1] > f[u][day] + flight[u][v][day % flight_num[u][v]]))
        f[v][day + 1] = f[u][day] + flight[u][v][day % flight_num[u][v]];
}
int work()
{
    memset(f, -1, sizeof(f));
    f[0][0] = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (j != k)
                    cal(i, j, k);
    return f[n - 1][m];
}
void output()
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", f[j][i]);
        puts("");
    }
}
int main()
{
    int t = 0;
    while (scanf("%d%d", &n, &m), n | m)
    {
        input();
        int ans = work();
        printf("Scenario #%d\n", ++t);
        if (ans == -1)
            puts("No flight possible.");
        else
            printf("The best flight costs %d.\n", ans);
        puts("");
    }
    return 0;
}
