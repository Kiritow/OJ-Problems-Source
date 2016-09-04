#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <cstdlib>
#include <ctime>
#define eps 1e-5
#define MAXN 111111
#define MAXM 1111111
#define INF 1000000008
using namespace std;
int fa[55555];
int ans[15];
struct P
{
    int a, b, c, x, y;
    char op[15];
}p[55555];
int vis[55555];
int find(int x)
{
    if(fa[x] == -1) return x;
    int t = find(fa[x]);
    fa[x] = t;
    return t;
}
int main()
{
    int n, m, q;
    while(scanf("%d%d%d", &n, &m, &q) != EOF)
    {
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < q; i++)
        {
            scanf("%s%d%d%d%d", p[i].op, &p[i].x, &p[i].y, &p[i].a, &p[i].b);
            if(p[i].op[0] == 'R') scanf("%d", &p[i].c);
        }
        for(int k = 0; k < n; k++)
        {
            for(int i = 0; i <= m; i++) fa[i] = -1, vis[i] = 0;
            for(int i = q - 1; i >= 0; i--)
            {
                int co = p[i].b, a, b;
                if(p[i].op[0] == 'R')
                {
                    co = p[i].c;
                    if(k < p[i].x || k >= p[i].x + p[i].a) continue;
                    a = p[i].y;
                    b = p[i].y + p[i].b - 1;
                }
                else if(p[i].op[0] == 'C')
                {
                    if(abs(k - p[i].x) > p[i].a) continue;
                    int tmp = p[i].a * p[i].a - (k - p[i].x) * (k - p[i].x);
                    int tp = (int)(sqrt(tmp));
                    a = p[i].y - tp;
                    b = p[i].y + tp;
                }
                else if(p[i].op[0] == 'D')
                {
                    if(abs(k - p[i].x) > p[i].a) continue;
                    int tmp = p[i].a - abs(k - p[i].x);
                    a = p[i].y - tmp;
                    b = p[i].y + tmp;
                }
                else if(p[i].op[0] == 'T')
                {
                    if(k - p[i].x >= (p[i].a + 1) / 2 || k < p[i].x) continue;
                    int tmp = (p[i].a - 1) / 2 - (k - p[i].x);
                    a = p[i].y - tmp;
                    b = p[i].y + tmp;
                }
                a = max(a, 0);
                b = min(m - 1, b);
                int fx = find(a), fy;
                for(int j = b; j >= a; j = fy - 1)
                {
                    fy = find(j);
                    if(!vis[fy]) ans[co]++;
                    vis[fy] = 1;
                    if(fx != fy) fa[fy] = fx;
                }
            }
        }
        for(int i = 1; i < 9; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[9]);
    }
    return 0;
}
