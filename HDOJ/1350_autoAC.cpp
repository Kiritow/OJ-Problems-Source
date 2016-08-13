#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
#define maxn 505
struct Elem
{
    int x1, y1, x2, y2;
    int s, e;
} ride[maxn];
int n;
int uN, vN;
bool g[maxn][maxn];
int xM[maxn], yM[maxn];
bool chk[maxn];
int cal(int h, int m)
{
    return h * 60 + m;
}
int dist(int x1, int y1, int x2, int y2)
{
    return abs(x1 - x2) + abs(y1 - y2);
}
void input()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int h, m;
        scanf("%d:%d", &h, &m);
        ride[i].s = cal(h, m);
        scanf("%d%d%d%d", &ride[i].x1, &ride[i].y1, &ride[i].x2, &ride[i].y2);
        ride[i].e = ride[i].s + dist(ride[i].x1, ride[i].y1, ride[i].x2, ride[i].y2);
    }
}
bool ok(Elem &a, Elem &b)
{
    return dist(a.x2, a.y2, b.x1, b.y1) + a.e < b.s;
}
void make()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = ok(ride[i], ride[j]);
}
bool SearchPath(int u)
{
    int v;
    for (v = 0; v < vN; v++)
        if (g[u][v] && !chk[v])
        {
            chk[v] = true;
            if (yM[v] == -1 || SearchPath(yM[v]))
            {
                yM[v] = u;
                xM[u] = v;
                return true;
            }
        }
    return false;
}
int MaxMatch()
{
    int u, ret = 0;
    memset(xM, -1, sizeof(xM));
    memset(yM, -1, sizeof(yM));
    for (u = 0; u < uN; u++)
        if (xM[u] == -1)
        {
            memset(chk, false, sizeof(chk));
            if (SearchPath(u))
                ret++;
        }
    return ret;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        make();
        uN = vN = n;
        printf("%d\n", n - MaxMatch());
    }
    return 0;
}
