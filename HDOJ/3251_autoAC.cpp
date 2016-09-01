#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 1010
#define MAXM 202010
#define INF 0x3f3f3f3f
int N, M, F, first[MAXD], e, next[MAXM], v[MAXM], flow[MAXM], id[MAXM], MAX;
int S, T, d[MAXD], q[MAXD], work[MAXD], Q;
void add(int x, int y, int z, int i)
{
    v[e] = y, flow[e] = z, id[e] = i;
    next[e] = first[x], first[x] = e ++;
}
void init()
{
    int i, x, y, z;
    scanf("%d%d%d", &N, &M, &F);
    S = 1, T = N + 1;
    memset(first, -1, sizeof(first[0]) * (T + 1)), e = 0;
    for(i = 1; i <= M; i ++)
    {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z, i), add(y, x, 0, i);
    }
    MAX = 0;
    for(i = 0; i < F; i ++)
    {
        scanf("%d%d", &x, &y), MAX += y;
        add(x, T, y, 0), add(T, x, 0, 0);    
    }
}
int bfs()
{
    int i, j, rear = 0;
    memset(d, -1, sizeof(d[0]) * (T + 1));
    d[S] = 0, q[rear ++] = S;
    for(i = 0; i < rear; i ++)
        for(j = first[q[i]]; j != -1; j = next[j])
            if(flow[j] && d[v[j]] == -1)
            {
                d[v[j]] = d[q[i]] + 1, q[rear ++] = v[j];
                if(v[j] == T) return 1;    
            }
    return 0;
}
int dfs(int cur, int a)
{
    if(cur == T) return a;
    for(int &i = work[cur]; i != -1; i = next[i])
        if(flow[i] && d[v[i]] == d[cur] + 1)
            if(int t = dfs(v[i], std::min(a, flow[i])))
            {
                flow[i] -= t, flow[i ^ 1] += t;
                return t;    
            }
    return 0;
}
int dinic()
{
    int ans = 0, t;
    while(bfs())
    {
        memcpy(work, first, sizeof(first[0]) * (T + 1));
        while(t = dfs(S, INF)) ans += t;
    }
    return ans;
}
void DFS(int cur)
{
    int i;
    d[cur] = 1;
    for(i = first[cur]; i != -1; i = next[i])
        if(flow[i] && !d[v[i]])
            DFS(v[i]);
}
void solve()
{
    int i, ans = dinic(), n = 0;
    printf("%d\n", MAX - ans);
    memset(d, 0, sizeof(d[0]) * (T + 1));
    DFS(S);
    for(i = 0; i < M; i ++)
        if(d[v[i << 1 | 1]] && !d[v[i << 1]])
            q[n ++] = id[i << 1];
    std::sort(q, q + n);
    printf("%d", n);
    for(i = 0; i < n; i ++) printf(" %d", q[i]);
    printf("\n");
}
int main()
{
    int t, tt;
    scanf("%d", &t);
    for(tt = 1; tt <= t; tt ++)
    {
        init();
        printf("Case %d: ", tt);
        solve();
    }
    return 0;    
}
