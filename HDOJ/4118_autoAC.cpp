#pragma comment(linker, "/STACK:10240000000000,10240000000000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#define MAXN 101005
#define MAXM 400005
#define INF 1000000000
using namespace std;
struct EDGE
{
    int v, next;
    long long w;
}edge[MAXM];
int head[MAXN], e;
int n;
int num[MAXN];
long long ans;
void init()
{
    ans = 0;
    memset(head, -1, sizeof(head));
    e = 0;
    memset(num, 0, sizeof(num));
}
void add(int u, int v, long long w)
{
    edge[e].v = v;
    edge[e].w = w;
    edge[e].next = head[u];
    head[u] = e++;
}
void dfs(int u, int fa)
{
    num[u] = 1;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].v;
        if(v != fa)
        {
            dfs(v, u);
            num[u] += num[v];
            long long tmp = min(num[v], n - num[v]);
            ans += tmp * edge[i].w * 2LL;
        }
    }
}
int main()
{
    int T, cas = 0, x, y, z;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        init();
        for(int i = 1; i < n; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
        }
        dfs(1, 0);
        printf("Case #%d: %I64d\n", ++cas, ans);
    }
    return 0;
}
