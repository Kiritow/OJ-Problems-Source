#include <iostream>
using namespace std;
const int maxn = 100005;
const int maxm = 400005;
const int inf  = 1000000005;
int head[maxn], vert[maxm], colo[maxm], noxt[maxm], cunt;
int sdis[maxn], edis[maxn], path[maxn], leng;
int queue[maxn], qhead, qtail;
bool vis[maxn], rit[maxn];
void init(int n)
{
    cunt = 0;
    for (int i = 0; i <= n; i++)
    {
        head[i] = -1;
        sdis[i] = -1;
        edis[i] = -1;
        vis[i] = 0;
        rit[i] = 0;
        path[i] = inf;
    }
}
void addedge(int x, int y, int c)
{
    vert[cunt] = y;
    colo[cunt] = c;
    noxt[cunt] = head[x];
    head[x] = cunt++;
}
void BFS(int start, int *dis)
{
    dis[start] = 0;
    qhead = qtail = 0;
    queue[qtail++] = start;
    while (qhead < qtail)
    {
        int x = queue[qhead++];
        for (int p = head[x]; p != -1; p = noxt[p])
        {
            int y = vert[p];
            if (-1 == dis[y])
            {
                dis[y] = dis[x] + 1;
                queue[qtail++] = y;
            }
        }
    }
}
void IdeadPath()
{
    qhead = qtail = 0;
    queue[qtail++] = 1;
    int step = 0;
    while (qhead < qtail)
    {
        int ttail = qtail;
        while (qhead < ttail)
        {
            int x = queue[qhead++];
            for (int p = head[x]; p != -1; p = noxt[p])
            {
                int y = vert[p];
                int c = colo[p];
                if (rit[y] && sdis[y] == step + 1)
                {
                    if (c < path[step])
                    {
                        path[step] = c;
                        for (int i = ttail; i < qtail; i++)
                            vis[queue[i]] = 0;
                        qtail = ttail;
                        vis[y] = 1;
                        queue[qtail++] = y;
                    }
                    else if (c == path[step] && !vis[y])
                    {
                        vis[y] = 1;
                        queue[qtail++] = y;
                    }
                }
            }
        }
        step++;
    }
}
int main()
{
    int test, cas;
    int n, m, a, b, c;
    scanf("%d", &test);
    for (cas = 1; cas <= test; cas++)
    {
        scanf("%d %d", &n, &m);
        init(n);
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            if (a == b) continue;
            addedge(a, b, c);
            addedge(b, a, c);
        }
        BFS(1, sdis);
        BFS(n, edis);
        leng = sdis[n];
        for (int i = 1; i <= n; i++)
        {
            if (sdis[i] + edis[i] == leng)
                rit[i] = 1;
        }
        IdeadPath();
        printf("%d\n", leng);
        for (int i = 0; i < leng; i++)
        {
            if (i) printf(" ");
            printf("%d", path[i]);
        }
        printf("\n");
    }
    return 0;
}
