#include <stdio.h>
#include <string.h>
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define INF 0x7fffffff
#define MAXN 2010
#define MAXM 600000
int pt[MAXM], head[MAXN], next[MAXM], flow[MAXM], lvl[MAXN], queue[MAXN];
int pos;
int arr[MAXN], stage[MAXN];
int n;
void AddEdge(int a, int b, int c)
{
    pt[++pos] = b;
    next[pos] = head[a];
    head[a] = pos;
    flow[pos] = c;
}
void Connect(int a, int b, int c)
{
    AddEdge(a, b, c);
    AddEdge(b, a, 0);
}
bool bfs(int s, int t)
{
    int qs, qe, v, e;
    memset (lvl, 0, sizeof lvl);
    lvl[s] = 1;
    qs = qe = 0;
    queue[qe++] = s;
    while (qs < qe)
    {
        v = queue[qs++];
        for (e = head[v]; e != -1; e = next[e])
            if (flow[e] > 0 && lvl[pt[e]] == 0)
            {
                lvl[pt[e]] = lvl[v] + 1;
                queue[qe++] = pt[e];
            }
    }
    return lvl[t] > 0;
}
int Update(int v, int t, int tmpflow)
{
    int tmp, res = 0, e;
    if (v == t) return tmpflow;
    for (e = head[v]; e != -1; e = next[e])
        if (flow[e] > 0 && lvl[pt[e]] == lvl[v] + 1)
        {
            tmp = Update(pt[e], t, MIN(flow[e], tmpflow));
            flow[e] -= tmp; flow[e^1] += tmp;
            res += tmp;
            tmpflow -= tmp;
            if (tmpflow == 0) {break;}
        }
    lvl[v] = -1;
    return res;
}
int dinic(int s, int t)
{
    int res = 0;
    while (bfs(s, t))
        res += Update(s, t, INF);
    return res;
}
void GenStage(int n)
{
    int i, j, mx = -1;
    memset (stage, 0, sizeof stage);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (arr[j] > arr[i])
                stage[j] = MAX(stage[j], stage[i] + 1);
    for (i = 0; i < n; i++)
        for (j = i + 1; j < n; j++)
            if (stage[i] + 1 == stage[j] && arr[i] < arr[j])
                Connect(2 * i + 1, 2 * j, INF);
    for (i = 0; i < n; i++)
    {
        mx = MAX(mx, stage[i]);
    }
    for (i = 0; i < n; i++)
    {
        Connect(2 * i, 2 * i + 1, 1);
        if (stage[i] == 0)
            Connect(2 * n, 2 * i, INF);
        if (stage[i] == mx)
            Connect(2 * i + 1, 2 * n + 1, INF);
    }
}
void Solve()
{
    int i, res;
    memset (head, -1, sizeof head);
    pos = -1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", arr + i);
    GenStage(n);
    res = dinic(2 * n, 2 * n + 1);
    printf("%d\n", res);
}
int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
        Solve();
    return 0;
}
