/*
 *  解法: 很明显是几何 + 最小费用最大流, 关键是如何建图.
 *        1. 设置一个源点和汇点.
 *        2. 每个lich和每个wisp分别用一个点来表示.
 *        3. 如果第i个lich能攻击到第j个wisp, 那么在图中从lich[i]到wisp[j]增加一条边, 容量为1, 费用为0.
 *        4. 每个wisp连一条边到汇点, 容量为1, 费用为0.
 *        5. 源点到每个lich连k条边, k为每个lich能攻击到的wisp数量, 每条边的容量为1, 第i条边的费用为i * t (i为0 - k-1, t为lich的cooldown时间)
 *        运行最小费用最大流, 答案就是从源点到lich满流的边, 且费用最大的那条边的费用值.
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <math.h>
using namespace std;
const int maxn = 205;
const double eps = 1e-8;
typedef int typef;
typedef int typec;
#define inff 0x0fffffff
#define infc 0x0fffffff
#define V    500
#define E    200000
struct network
{
    int nv, ne, pnt[E], nxt[E];
    int vis[V], que[V], head[V], pv[V], pe[V];
    typef flow, cap[E]; typec cost, dis[E], d[V];
    void addedge(int u, int v, typef c, typec w)
    {
        pnt[ne] = v; cap[ne] = c;
        dis[ne] = w; nxt[ne] = head[u]; head[u] = ne++;
        pnt[ne] = u; cap[ne] = 0;
        dis[ne] = -w; nxt[ne] = head[v]; head[v] = ne++;
    }
    int mincost(int src, int sink)
    {
        int i, k, f, r; typef mxf;
        for(flow = 0, cost = 0; ; )
        {
            memset(pv, -1, sizeof(pv));
            memset(vis, 0, sizeof(vis));
            for(i = 0; i < nv; ++i) d[i] = infc;
            d[src] = 0; pv[src] = src; vis[src] = 1;
            for(f = 0, r = 1, que[0] = src; r != f; )
            {
                i = que[f++]; vis[i] = 0;
                if(V == f) f = 0;
                for(k = head[i]; k != -1; k = nxt[k])
                    if(cap[k] && dis[k]+d[i] < d[pnt[k]])
                    {
                        d[pnt[k]] = dis[k] + d[i];
                        if(0 == vis[pnt[k]])
                        {
                            vis[pnt[k]] = 1;
                            que[r++] = pnt[k];
                            if(V == r) r = 0;
                        }
                        pv[pnt[k]] = i; pe[pnt[k]] = k;
                    }
            }
            if(-1 == pv[sink]) break;
            for(k = sink, mxf = inff; k != src; k = pv[k])
                if(cap[pe[k]] < mxf) mxf = cap[pe[k]];
            flow += mxf; cost += d[sink] * mxf;
            for(k = sink; k != src; k = pv[k])
            {
                cap[pe[k]] -= mxf; cap[pe[k]^1] += mxf;
            }
        }
        return cost;
    }
    void init(int v)
    {
        nv = v; ne = 0;
        memset(head, -1, 4 * v);
    }
} nw;
struct Lich
{
    double x, y, r;
    int t;
    void input()
    {
        scanf("%lf %lf %lf %d", &x, &y, &r, &t);
    }
} lich[maxn];
struct Wisp
{
    double x, y;
    void input()
    {
        scanf("%lf %lf", &x, &y);
    }
} wisp[maxn];
struct Tree
{
    double x, y, r;
    void input()
    {
        scanf("%lf %lf %lf", &x, &y, &r);
    }
} tree[maxn];
int T, N, M, K;
int ecnt[maxn];
double Dot(double dx1, double dy1, double dx2, double dy2)
{
    return dx1 * dx2 + dy1 * dy2;
}
double Dis(double x0, double y0, double x1, double y1, double x2, double y2)
{
    double a, b, c;
    if (fabs(x1 - x2) > fabs(y1 - y2))
    {
        b = 1.0;
        a = b * (y2 - y1) / (x1 - x2);
        c = -(a * x1 + b * y1);
    }
    else
    {
        a = 1.0;
        b = a * (x2 - x1) / (y1 - y2);
        c = -(a * x1 + b * y1);
    }
    return fabs(a * x0 + b * y0 + c) / sqrt(a * a + b * b);
}
bool NoCross(int a, int b)
{
    int i;
    for (i = 0; i < K; i++)
    {
        if (Dot(tree[i].x - lich[a].x, tree[i].y - lich[a].y, wisp[b].x - lich[a].x, wisp[b].y - lich[a].y) > 0.0 &&
            Dot(tree[i].x - wisp[b].x, tree[i].y - wisp[b].y, lich[a].x - wisp[b].x, lich[a].y - wisp[b].y) > 0.0 &&
            Dis(tree[i].x, tree[i].y, lich[a].x, lich[a].y, wisp[b].x, wisp[b].y) < tree[i].r + eps)
            return false;
    }
    return true;
}
bool InRound(int i, int j)
{
    double dx = lich[i].x - wisp[j].x;
    double dy = lich[i].y - wisp[j].y;
    return sqrt(dx * dx + dy * dy) < lich[i].r + eps;
}
void BuildGraph()
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        ecnt[i] = 0;
        for (j = 0; j < M; j++)
        {
            if (InRound(i, j) && NoCross(i, j))
            {
                ecnt[i]++;
                nw.addedge(i, N + j, 1, 0);
            }
        }
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < ecnt[i]; j++)
            nw.addedge(N + M, i, 1, lich[i].t * j);
    }
    for (i = 0; i < M; i++)
        nw.addedge(N + i, N + M + 1, 1, 0);
}
void Solve()
{
    nw.mincost(N + M, N + M + 1);
    if (nw.flow != M)
    {
        printf("-1\n");
        return;
    }
    int ans = 0;
    for (int p = nw.head[N+M]; p != -1; p = nw.nxt[p])
    {
        if (nw.cap[p] == 0 && nw.dis[p] > ans)
            ans = nw.dis[p];
    }
    printf("%d\n", ans);
}
int main()
{
    int i;
    for (scanf("%d", &T); T; T--)
    {
        scanf("%d %d %d", &N, &M, &K);
        for (i = 0; i < N; i++)
            lich[i].input();
        for (i = 0; i < M; i++)
            wisp[i].input();
        for (i = 0; i < K; i++)
            tree[i].input();
        nw.init(N + M + 2);
        BuildGraph();
        Solve();
    }
    return 0;
}
