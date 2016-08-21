#include<iostream>
using namespace std;
#include<cstdio>
#include<cstring>
#define MAXN 1005
#define INF 0x7f7f7f7f
typedef __int64 type;
struct node
{
    int u, v;
    type w;
}edge[MAXN * MAXN];
int pre[MAXN], id[MAXN], vis[MAXN], n, m, pos;
type in[MAXN];
type Directed_MST(int root, int V, int E)
{
    type ret = 0;
    while(true)
    {
        int i;
        for( i = 0; i < V; i++)
            in[i] = INF;
        for( i = 0; i < E; i++)
        {
            int u = edge[i].u;
            int v = edge[i].v;
            if(edge[i].w < in[v] && u != v)
            {
                pre[v] = u;
                in[v] = edge[i].w;
                if(u == root)
                    pos = i;
            }
        }
        for( i = 0; i < V; i++)
        {
            if(i == root)
                continue;
            if(in[i] == INF) 
                return -1;
        }
        int cnt = 0;
        memset(id, -1, sizeof(id));
        memset(vis, -1, sizeof(vis));
        in[root] = 0;
        for( i = 0; i < V; i++) 
        {
            ret += in[i];
            int v = i;
            while(vis[v] != i && id[v] == -1 && v != root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if(v != root && id[v] == -1)
            {
                for(int u = pre[v]; u != v; u = pre[u])
                    id[u] = cnt;
                id[v] = cnt++;
            }
        }
        if(cnt == 0)
            break; 
        for( i = 0; i < V; i++)
            if(id[i] == -1)
                id[i] = cnt++;
            for( i = 0; i < E; i++)
            {
                int u = edge[i].u;
                int v = edge[i].v;
                edge[i].u = id[u];
                edge[i].v = id[v];
                if(id[u] != id[v])
                    edge[i].w -= in[v];
            }
            V = cnt;
            root = id[root];
    }
    return ret;
}
int main()
{
    int i;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        type sum = 0;
        for( i = 0; i < m; i++)
        {
            scanf("%d%d%I64d", &edge[i].u, &edge[i].v, &edge[i].w);
            edge[i].u++; edge[i].v++;
            sum += edge[i].w;
        }
      sum ++;
        for( i = m; i < m + n; i++)
        {
            edge[i].u = 0;
            edge[i].v = i - m + 1;
            edge[i].w = sum;
        }
        type ans = Directed_MST(0, n + 1, m + n);
        if(ans == -1 || ans - sum >= sum)
            puts("impossible");
        else
            printf("%I64d %d\n",ans - sum, pos - m);
        puts("");
    }
    return 0;
}
