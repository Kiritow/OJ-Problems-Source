#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define MAXN 4001003
#define MAXM 88888
using namespace std;
int n, m;
int W;
int h[MAXN], cnt;
int a[MAXN];
int pp[MAXN], xx[MAXN], yy[MAXN], zz[MAXN];
inline int lowbit(int x)
{
    return x & -x;
}
void ready(int x, int y)
{
    for (int i = x; i <= W; i += lowbit(i)){
        for (int j = y; j <= W; j += lowbit(j)) {
            h[cnt++] = i * W + j;
        }
    }
}
void add(int x, int y, int val)
{
    for(int i = x; i <= W; i += lowbit(i))
        for(int j = y; j <= W; j += lowbit(j))
        {
            int pos = lower_bound(h, h + cnt, i * W + j) - h;
            a[pos] += val;
        }
}
int getsum(int x, int y)
{
    int sum = 0;
    for(int i = x; i > 0; i -= lowbit(i))
        for(int j = y; j > 0; j -= lowbit(j))
        {
            int pos = lower_bound(h, h + cnt, i * W + j) - h;
            if(h[pos] == i * W + j)
                sum += a[pos];
        }
    return sum;
}
int main()
{
    int p, x, y, z, xa, xb, ya, yb, newx, newy;
    while(scanf("%d", &n) != EOF && n)
    {
        scanf("%d", &m);
        W = n * 2;
        cnt = 0;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &pp[i], &xx[i], &yy[i], &zz[i]);
            newx = xx[i] - yy[i] + n;
            newy = xx[i] + yy[i];
            if (pp[i] == 1)
                ready(newx, newy);
        }
        sort(h, h + cnt);
        cnt = unique(h, h + cnt) - h;
        for(int i = 0; i < m; i++)
        {
            newx = xx[i] - yy[i] + n;
            newy = xx[i] + yy[i];
            if(pp[i] == 1) add(newx, newy, zz[i]);
            else
            {
                xa = max(1, newx - zz[i]);
                ya = max(1, newy - zz[i]);
                xb = min(W, newx + zz[i]);
                yb = min(W, newy + zz[i]);
                printf("%d\n", getsum(xb, yb) - getsum(xa - 1, yb) - getsum(xb, ya - 1) + getsum(xa - 1, ya - 1));
            }
        }
    }
    return 0;
}
