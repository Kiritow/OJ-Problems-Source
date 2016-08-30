#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;
#define MAXN 2000010
int r, n, m, cnt[10010], p[10010];
int fa[10010], rt[2], s[2];
int tot, x, sh, sw, h, w;
char op[4];
struct Node
{
    int v, l, r, dis;
    Node() {}
    Node(int _v, int _l, int _r, int _d):
        v(_v), l(_l), r(_r), dis(_d) {}
}nn[MAXN];
int merge(int x, int y)
{
    if(!x) return y;
    if(!y) return x;
    if(nn[x].v < nn[y].v) swap(x, y);
    nn[x].r = merge(nn[x].r, y);
    if(nn[nn[x].l].dis < nn[nn[x].r].dis) swap(nn[x].l, nn[x].r);
    nn[x].dis = nn[nn[x].r].dis + 1;
    return x;
}
int main()
{
//    freopen("G.in", "r", stdin);
    while(~scanf("%d", &r))
    {
        h = w = 0;
        while(r--)
        {
            tot = 1;
            s[0] = s[1] = rt[0] = rt[1] = 0;
            memset(fa, 0, sizeof(fa));
            scanf("%d%d", &n, &m);
            for(int i = 1; i <= m; i++) scanf("%d", cnt + i);
            for(int i = 1; i <= m; i++) for(int j = 1; j <= cnt[i]; j++)
            {
                scanf("%d", &x);
                nn[tot] = Node(x, 0, 0, 0);
                fa[i] = merge(fa[i], tot);
                tot++;
            }
            for(int i = 1; i <= n; i++)
            {
                scanf("%s", op);
                if(op[0] == 'T')
                {
                    scanf("%d", &x);
                    rt[1 & i] = merge(rt[1 & i], fa[x]);
                    s[1 & i] += cnt[x];
                }
                if(op[0] == 'C')
                {
                    if(nn[rt[0]].v > nn[rt[1]].v)
                    {
                        rt[0] = merge(rt[0], rt[1]);
                        s[0] += s[1]; rt[1] = s[1] = 0;
                    }
                    if(nn[rt[0]].v < nn[rt[1]].v)
                    {
                        rt[1] = merge(rt[0], rt[1]);
                        s[1] += s[0]; rt[0] = s[0] = 0;
                    }
                }
                if(op[0] == 'L')
                {
                    rt[1 & i] = merge(nn[rt[1 & i]].l, nn[rt[1 & i]].r);
                    s[1 & i]--;
                }
                if(op[0] == 'A')
                {
                    scanf("%d", &x);
                    nn[rt[1 & i]].v += x;
                }
                if(op[0] == 'E')
                {
                    scanf("%d", &x);
                    int lson = nn[rt[1 & i]].l;
                    int rson = nn[rt[1 & i]].r;
                    nn[rt[1 & i]] = Node(x, 0, 0, 0);
                    rt[1 & i] = merge(merge(lson, rson), rt[1 & i]);
                }
            }
            if(s[0] > s[1]) h++; else w++;
            printf("%d:%d\n", s[1], s[0]);
        }
        if(h > w) puts("I will be back!!"); else puts("Hahaha...I win!!");
    }
    return 0;
}
