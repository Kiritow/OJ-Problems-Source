#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 3003;
const int maxm = maxn * maxn;
const int inf = 1000000000;
int n, m;
__int64 mst;
int map[maxn][maxn];
int dp[maxn][maxn];
int dis[maxn], pre[maxn];
bool vis[maxn];
vector<int> edge[maxn];
int minz(int a, int b)
{
    return a < b ? a : b;
}
void init()
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            map[i][j] = dp[i][j] = inf;
        edge[i].clear();
        vis[i] = 0;
        pre[i] = -1;
        dis[i] = inf;
    }
}
void input()
{
    int x, y, z;
    while(m--)
    {
        scanf("%d%d%d", &x, &y, &z);
        map[x][y] = map[y][x] = z;
    }
}
void prim()
{
    int i, j, k;
    for(i = 1; i < n; i++)
    {
        dis[i] = map[0][i];
        pre[i] = 0;
    }
    dis[0] = inf;
    vis[0] = 1;
    pre[0] = -1;
    mst = 0;
    for(i = 0; i < n-1; i++)
    {
        k = 0;
        for(j = 1; j < n; j++)
            if(!vis[j] && dis[k] > dis[j])
                k = j;
        vis[k] = 1;
        mst += dis[k];
        if(pre[k] != -1)
            edge[k].push_back(pre[k]),
            edge[pre[k]].push_back(k);
        for(j = 1; j < n; j++)
            if(!vis[j] && dis[j] > map[k][j] )
                dis[j] = map[k][j], pre[j] = k;
    }
}
int dfs(int pos, int u, int fa) 
{
    int i, ans = inf;
    for(i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if(v == fa) continue;
        int tmp = dfs(pos, v, u);
        ans = minz(ans, tmp);
        dp[u][v] = dp[v][u] = minz(dp[u][v], tmp); 
    }
    if(pos != fa) 
        ans = minz(ans, map[pos][u]);
    return ans;
}
void solve()
{
    int i;
    for(i = 0; i < n; i++)
        dfs(i, i, -1);
}
void query()
{
    int x, y, z;
    double sum = 0;
    scanf("%d", &m);
    for(int ii = 1; ii <= m; ii++)
    {
        scanf("%d%d%d", &x, &y, &z);
        if(pre[x] != y && pre[y] != x)
            sum += mst * 1.0;
        else
            sum += mst * 1.0 - map[x][y] + minz(dp[x][y], z);
    }
    printf("%.4f\n", sum/m);
}
int main()
{
    while( ~scanf("%d%d", &n, &m) && n + m)
    {
        init();
        input();
        prim();
        solve();
        query();
    }
    return 0;
}
