#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
const int MAX_N = 5 + 2;
int vis[MAX_N][MAX_N];
int n, m, q, _max;
bool decide(int i, int j)
{
    int flag = 0;
    if(vis[i][j] == 1)
        return false;
    for(int k = i - 1; k >= 0; k--)
    {
        if(vis[k][j] == 1)
            flag++;
        else if(vis[k][j] == 2)
        {
            if(flag == 1)
                return false;
            else
                flag++;
        }
    }
    flag = 0;
    for(int k = j - 1; k >= 0; k--)
    {
        if(vis[i][k] == 1)
            flag++;
        else if(vis[i][k] == 2)
        {
            if(flag == 1)
                return false;
            else
                flag++;
        }
    }
    return true;
}
void dfs(int cnt, int x, int y)
{
    for(int i = x; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(x == i && j < y)
                continue;
            if(decide(i, j))
            {
                vis[i][j] = 2;
                dfs(cnt + 1, i, j + 1);
                vis[i][j] = 0;
            }
        }
    }
    _max = max(_max, cnt);
}
int main()
{
    while(scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        int a, b;
        _max = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < q; i++)
        {
            scanf("%d%d", &a, &b);
            vis[a][b] = 1;
        }
        dfs(0, 0, 0);
        cout << _max << endl;
    }
    return 0;
}
