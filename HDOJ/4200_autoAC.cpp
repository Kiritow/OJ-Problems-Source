#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
#define INF 1000000000
#define N 110
#define M 210
int n, d;
bool mat[N][N], val[N];
void print(bool a[N][N], int n)
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n+1; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int dfs(int col, int cnt)
{
    if(col == n+1)
    {
        int res = cnt;
        for(int i = 1; i <= n; i++)
        {
            if(val[i] ^ mat[i][n+1]) res++;
        }
        return res;
    }
    int res = 0;
    for(int i = 1; i <= n; i++)
        val[i] ^= mat[i][col];
    res = dfs(col+1, cnt+1);
    for(int i = 1; i <= n; i++)
        val[i] ^= mat[i][col];
    res = min(dfs(col+1, cnt), res);
    return res;
}
int gauss()
{
    int row = 1;
    int r = n;
    for(int i = 1; i <= r; i++, row++)
    {
        int p = -1;
        for(int j = row; j <= n; j++)
        {
            if(mat[j][i] == 1)
            {
                p = j;
                break;
            }
        }
        if(p == -1)
        {
            for(int j = 1; j <= n; j++)
            {
                swap(mat[j][i], mat[j][r]);
            }
            //print(mat, n);
            r--;
            i--;
            row--;
            continue;
        }
        if(p != row)
        {
            for(int j = i; j <= n+1; j++)
            {
                swap(mat[row][j], mat[p][j]);
            }
        }
        for(int j = 1; j <= n; j++)
        {
            if(mat[j][i] == 1 && j != row)
            for(int k = i; k <= n+1; k++)
            {
                mat[j][k] ^= mat[row][k];
            }
        }
    }
    for(int i = row; i <= n; i++)
    {
        if(mat[i][n+1] == 1)
        {
            return -1;
        }
    }
    memset(val, 0, sizeof(val));
    int ans = dfs(row, 0);
    return ans;
}
int main()
{
    int t; scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &d);
        memset(mat, 0, sizeof(mat));
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &mat[i][n+1]);
        }
        for(int i = 1; i <= n; i++)
        {
            int st = max(1, i-d), ed = min(n, i+d);
            for(int j = st; j <= ed; j++)
            {
                mat[i][j] = 1;
            }
        }
        int ans = gauss();
        if(ans != -1)
            printf("%d\n", ans);
        else printf("impossible\n");
    }
    return 0;
}
