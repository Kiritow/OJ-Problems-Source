#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 1010
#define MAXM 2004010
#define INF 0x7fffffff
int N, first[MAXD], e, v[MAXM], next[MAXM], flow[MAXM];
int S, T, d[MAXD], q[MAXD], work[MAXD];
long long SUM;
void add(int x, int y, int z)
{
    v[e] = y, flow[e] = z;
    next[e] = first[x], first[x] = e ++;    
}
void init()
{
    int i, j, x, a;
    scanf("%d", &N);
    S = 0, T = N + 1;
    memset(first, -1, sizeof(first[0]) * (T + 1));
    SUM = e = 0;
    for(i = 1; i <= N; i ++)
    {
        a = 0;
        for(j = 1; j <= N; j ++)
        {
            scanf("%d", &x), a += x;
            add(i, j, x), add(j, i, 0);
        }
        SUM += a;
        add(S, i, a), add(i, S, 0);
    }
    for(i = 1; i <= N; i ++)
    {
        scanf("%d", &x);
        add(i, T, x), add(T, i, 0);
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
    if(cur == T)
        return a;
    for(int &i = work[cur]; i != -1; i = next[i])
        if(flow[i] && d[v[i]] == d[cur] + 1)
            if(int t = dfs(v[i], std::min(a, flow[i])))
            {
                flow[i] -= t, flow[i ^ 1] += t;
                return t;    
            }
    return 0;
}
long long dinic()
{
    long long ans = 0;
    while(bfs())
    {
        memcpy(work, first, sizeof(first[0]) * (T + 1));
        while(int t = dfs(S, INF))
            ans += t;
    }
    return ans;
}
void solve()
{
    printf("%lld\n", SUM - dinic());
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t --)
    {
        init();
        solve();    
    }
    return 0;    
}
