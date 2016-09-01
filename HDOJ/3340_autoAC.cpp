#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXD 125010
double dl[4 * MAXD], dr[4 * MAXD], volume[4 * MAXD];
int N, tx[MAXD], X, flag[4 * MAXD];
struct Question
{
    char b[5];
    int n, x[10], y[10];
}question[MAXD];
int cmpint(const void *_p, const void *_q)
{
    int *p = (int *)_p, *q = (int *)_q;
    return *p < *q ? -1 : 1;
}
void build(int cur, int x, int y)
{
    int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
    dl[cur] = dr[cur] = volume[cur] = flag[cur] = 0;
    if(x == y)
        return ;
    build(ls, x, mid);
    build(rs, mid + 1, y);
}
void init()
{
    int i, j, k, n;
    scanf("%d", &N);
    k = 0;
    for(i = 0; i < N; i ++)
    {
        scanf("%s", question[i].b);
        if(question[i].b[0] == 'Q')
        {
            scanf("%d%d", &question[i].x[0], &question[i].y[0]);
            tx[k ++] = question[i].x[0], tx[k ++] = question[i].y[0];
        }
        else
        {
            scanf("%d", &n);
            question[i].n = n;
            for(j = 0; j < n; j ++)
            {
                scanf("%d%d", &question[i].x[j], &question[i].y[j]);
                tx[k ++] = question[i].x[j];
            }
            question[i].x[n] = question[i].x[0], question[i].y[n] = question[i].y[0];
        }
    }
    qsort(tx, k, sizeof(tx[0]), cmpint);
    X = -1;
    for(i = 0; i < k; i ++)
        if(i == 0 || tx[i] != tx[i - 1])
            tx[++ X] = tx[i];
    build(1, 0, X - 1);
}
int BS(int x)
{
    int mid, min = 0, max = X + 1;
    for(;;)
    {
        mid = (min + max) >> 1;
        if(mid == min)
            break;
        if(tx[mid] <= x)
            min = mid;
        else
            max = mid;
    }
    return mid;
}
double calculate(double x1, double y1, double x2, double y2, double x)
{
    return ((x2 - x) * y1 + (x - x1) * y2) / (x2 - x1);
}
void pushdown(int cur, int x, int y)
{
    int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
    if(flag[cur])
    {
        flag[ls] = flag[rs] = 1;
        double delta = calculate(tx[x], dl[cur], tx[y + 1], dr[cur], tx[mid + 1]);
        dl[ls] += dl[cur], dr[ls] += delta, volume[ls] += (dl[cur] + delta) * (tx[mid + 1] - tx[x]) / 2;
        dl[rs] += delta, dr[rs] += dr[cur], volume[rs] += (delta + dr[cur]) * (tx[y + 1] - tx[mid + 1]) / 2;
        dl[cur] = dr[cur] = flag[cur] = 0;
    }
}
void update(int cur)
{
    volume[cur] = volume[cur << 1] + volume[(cur << 1) | 1];
}
double query(int cur, int x, int y, int s, int t)
{
    int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
    if(x >= s && y <= t)
        return volume[cur];
    pushdown(cur, x, y);
    if(mid >= t)
        return query(ls, x, mid, s, t);
    else if(mid + 1 <= s)
        return query(rs, mid + 1, y, s, t);
    else
        return query(ls, x, mid, s, t) + query(rs, mid + 1, y, s, t);
}
void refresh(int cur, int x, int y, int s, int t, double ys, double yt)
{
    int mid = (x + y) >> 1, ls = cur << 1, rs = (cur << 1) | 1;
    if(x >= s && y <= t)
    {
        flag[cur] = 1;
        double dleft, dright;
        dleft = calculate(tx[s], ys, tx[t + 1], yt, tx[x]);
        dright = calculate(tx[s], ys, tx[t + 1], yt, tx[y + 1]);
        dl[cur] += dleft, dr[cur] += dright, volume[cur] += (dleft + dright) * (tx[y + 1] - tx[x]) / 2;
        return ;
    }
    pushdown(cur, x, y);
    if(mid >= s)
        refresh(ls, x, mid, s, t, ys, yt);
    if(mid + 1 <= t)
        refresh(rs, mid + 1, y, s, t, ys, yt);
    update(cur);
}
void solve()
{
    int i, j, k, e, x1, y1, x2, y2;
    for(i = 0; i < N; i ++)
    {
        if(question[i].b[0] == 'Q')
        {
            j = BS(question[i].x[0]), k = BS(question[i].y[0]);
            if(j < k)
                printf("%.3f\n", query(1, 0, X - 1, j, k - 1));
            else
                printf("0.000\n");
        }
        else
        {
            for(e = 0; e < question[i].n; e ++)
            {
                j = BS(question[i].x[e]), k = BS(question[i].x[e + 1]);
                if(j < k)
                    refresh(1, 0, X - 1, j, k - 1, -question[i].y[e], -question[i].y[e + 1]);
                else if(j > k)
                    refresh(1, 0, X - 1, k, j - 1, question[i].y[e + 1], question[i].y[e]);
            }
        }
    }
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
