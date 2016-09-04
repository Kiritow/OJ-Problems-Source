#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXK 20
#define MAXD 100010
int N, M, sa[MAXD], a[MAXD], rank[MAXK][MAXD], h[MAXK][MAXD];
long long int A[MAXK][MAXD], ans;
int cmp(const void *_p, const void *_q)
{
    int *p = (int *)_p, *q = (int *)_q;
    if(a[*p] == a[*q])
        return *p - *q;
    return a[*p] - a[*q];
}
void init()
{
    int i, j, k;
    scanf("%d", &N);
    for(i = 1; i <= N; i ++)
    {
        scanf("%d", &a[i]);
        sa[i] = i;
    }
}
void build(int lx, int rx, int d)
{
    if(lx == rx)
    {
        A[d][lx] = a[sa[rank[d][lx]]];
        return ;
    }
    int i, j, k, p = 0, mid = (lx + rx) / 2;
    for(i = lx; i <= rx; i ++)
    {
        if(rank[d][i] <= mid)
            rank[d + 1][lx + p ++] = rank[d][i];
        else
            rank[d + 1][mid + i - lx + 1 - p] = rank[d][i];
        h[d][i] = p;
        A[d][i] = a[sa[rank[d][i]]] + (i == lx ? 0 : A[d][i - 1]);
    }
    build(lx, mid, d + 1);
    build(mid + 1, rx, d + 1);
}
int search(int lx, int rx, int x, int y, int k, int d)
{
    if(lx == rx)
        return sa[rank[d][lx]];
    int j, n, m, mid = (lx + rx) / 2, tx, ty;
    n = h[d][y], m = x == lx ? 0 : h[d][x - 1];
    if(n - m >= k)
    {
        j =  search(lx, mid, lx + m, lx + n - 1, k, d + 1);
        tx = mid + 1 + x - lx - m, ty = mid + 1 + y - lx - n;
        if(tx <= ty)
            ans += A[d + 1][ty] - (tx == mid + 1 ? 0 : A[d + 1][tx - 1]) - (long long int)(ty - tx + 1) * a[j];
    }
    else
    {
        j = search(mid + 1, rx, mid + 1 + x - lx - m, mid + 1 + y - lx - n, k - n + m, d + 1);
        tx = lx + m, ty = lx + n - 1;
        if(tx <= ty)
            ans += (long long int)(ty - tx + 1) * a[j] - A[d + 1][ty] + (tx == lx ? 0 : A[d + 1][tx - 1]);
    }
    return j;
}
void solve()
{
    int i, j, k, x, y;
    qsort(sa + 1, N, sizeof(sa[0]), cmp);
    for(i = 1; i <= N; i ++)
        rank[0][sa[i]] = i;
    build(1, N, 0);
    scanf("%d", &M);
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d", &x, &y);
        ++ x, ++ y;
        k = (y - x) / 2 + 1;
        ans = 0;
        search(1, N, x, y, k, 0);
        printf("%I64d\n", ans);
    }
}
int main()
{
    int t, tt;
    scanf("%d", &t);
    for(tt = 0; tt < t; tt ++)
    {
        init();
        printf("Case #%d:\n", tt + 1);
        solve();
        printf("\n");
    }
    return 0;
}
