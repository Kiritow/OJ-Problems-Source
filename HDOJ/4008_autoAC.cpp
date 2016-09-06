#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100000 + 1234;
struct EDGE
{
    int u, v;
} edge[MAXN * 2];
int cnt;
int minchild[MAXN][2];
int mindown[MAXN];
int fa[MAXN][20];
int head[MAXN];
int n;
int depth[MAXN], maxdepth, topk;
bool cmp(EDGE a, EDGE b)
{
    if(a. u != b.u)  return a.u < b.u;
    return a.v < b.v;
}
void insert(int *s, int x)
{
    if(x < s[0])
    {
        s[1] = s[0];
        s[0] = x;
    }
    else if(x < s[1])  s[1] = x;
}
void dfs(int root)
{
    minchild[root][0] = minchild[root][1] = mindown[root] = n + 1;
    for(int p = head[root]; p < cnt && edge[p].u == root; p++)
    {
        int v = edge[p].v;
        if(v == fa[root][0])  continue;
        fa[v][0] = root;
        insert(minchild[root], v);
        depth[v] = depth[root] + 1;
        dfs(v);
        mindown[root] = min(mindown[root], mindown[v]);
    }
    maxdepth = max(maxdepth, depth[root]);
    mindown[root] = min(mindown[root], minchild[root][0]);
}
int findfather(int x, int step)
{
    int k = topk - 1;
    while(step > 0)
    {
        while((1 << k) > step) k--;
        x = fa[x][k];
        step -= (1 << k);
    }
    return x;
}
int main()
{
    int T;
    int q, x, y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &q);
        cnt = n - 1;
        for(int i = 0; i < cnt; i++)
        {
            scanf("%d%d", &edge[i].u, &edge[i].v);
            edge[i + cnt].u = edge[i].v;
            edge[i + cnt].v = edge[i].u;
        }
        cnt = cnt + cnt;
        sort(edge, edge + cnt, cmp);
        head[1] = 0;
        for(int i = 1; i < cnt; i++)
            if(edge[i].u != edge[i-1].u)  head[edge[i].u] = i;
        fa[1][0] = 0;
        depth[1] = maxdepth = 0;
        dfs(1);
        topk = 0;
        while((1 << topk) <= maxdepth)  topk++;
        for(int k = 1; k < topk; k++)
            for(int i = 1; i <= n; i++)
                if(fa[i][k - 1] != 0)  fa[i][k] = fa[fa[i][k-1]][k-1];
        int mindown1[2];
        mindown1[0] = mindown1[1] = n + 1;
        for(int p = head[1]; p < cnt && edge[p].u == 1; p++)
        {
            int v = edge[p].v;
            int rv = min(mindown[v], v);
            insert(mindown1, rv);
        }
        while(q--)
        {
            scanf("%d%d", &x, &y);
            int ans1 = n + 1, ans2 =n + 1;
            if(y == 1)
            {
                int z = findfather(x, depth[x] - depth[y] - 1);
                int rz = min(z, mindown[z]);
                ans1 = (z == minchild[1][0] ? minchild[1][1] : minchild[1][0]);
                ans2 = (rz == mindown1[0] ? mindown1[1] : mindown1[0]);
            }
            else
            {
                bool flag = false;
                int z;
                if(depth[y] < depth[x])
                {
                    z = findfather(x, depth[x] - depth[y] - 1);
                    if(fa[z][0] == y)  flag = true;
                }
                if(flag)
                {
                    ans1 = (z == minchild[y][0] ? min(minchild[y][1], fa[y][0]) : min(minchild[y][0], fa[y][0]));
                    ans2 = 1;
                }
                else
                {
                    ans1 = minchild[y][0];
                    ans2 = mindown[y];
                }
            }
            if (ans1 > n) printf("no answers!\n");
            else printf("%d %d\n", ans1, ans2);
        }
        puts("");
    }
    return 0;
}
