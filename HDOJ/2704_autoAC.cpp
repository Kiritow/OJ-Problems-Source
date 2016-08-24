#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 210
#define MAXD 40010
int N, W, H, dep[4 * MAXD], ml[4 * MAXD], cnt[4 * MAXD], len[4 * MAXD];
struct Seg
{
    int x, y1, y2, c;
    bool operator < (const Seg &t) const
    {
        if(x == t.x) return c < t.c;
        return x < t.x;    
    }
    Seg(){}
    Seg(int _x, int _y1, int _y2, int _c) : x(_x), y1(_y1), y2(_y2), c(_c){}
}seg[MAXN];
void build(int cur, int x, int y)
{
    int mid = x + y >> 1, ls = cur << 1, rs = cur << 1 | 1;
    cnt[cur] = dep[cur] = len[cur] = 0, ml[cur] = y - x + 1;
    if(x == y) return ;
    build(ls, x, mid), build(rs, mid + 1, y);
}
void init()
{
    int i, x1, x2, y1, y2;
    scanf("%d%d", &W, &H);
    for(i = 0; i < N; i ++)
    {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        seg[i << 1] = Seg(x1, y1, y2, 1), seg[i << 1 | 1] = Seg(x2, y1, y2, -1);
    }
    std::sort(seg, seg + 2 * N);
    build(1, 1, H);
}
void update(int cur, int x, int y)
{
    int ls = cur << 1, rs = cur << 1 | 1;
    if(dep[ls] > dep[rs]) dep[cur] = dep[ls], ml[cur] = ml[ls];
    else if(dep[rs] > dep[ls]) dep[cur] = dep[rs], ml[cur] = ml[rs];
    else dep[cur] = dep[ls], ml[cur] = ml[ls] + ml[rs];
    dep[cur] += cnt[cur];
    if(cnt[cur]) len[cur] = y - x + 1;
    else len[cur] = len[ls] + len[rs];
}
void refresh(int cur, int x, int y, int s, int t, int c)
{
    int mid = x + y >> 1, ls = cur << 1, rs = cur << 1 | 1;
    if(x >= s && y <= t)
    {
        cnt[cur] += c;
        if(c > 0) ++ dep[cur], len[cur] = y - x + 1;
        else
        {
            -- dep[cur];
            if(cnt[cur]) len[cur] = y - x + 1;
            else
            {
                if(x == y) len[cur] = 0;
                else len[cur] = len[ls] + len[rs];    
            }
        }
        return ;
    }
    if(mid >= s) refresh(ls, x, mid, s, t, c);
    if(mid + 1 <= t) refresh(rs, mid + 1, y, s, t, c);
    update(cur, x, y);
}
void solve()
{
    int i, md, ans, area;
    area = md = ans = 0;
    seg[2 * N].x = seg[2 * N - 1].x;
    for(i = 0; i < 2 * N; i ++)
    {
        refresh(1, 1, H, seg[i].y1 + 1, seg[i].y2, seg[i].c);
        area += len[1] * (seg[i + 1].x - seg[i].x);
        if(dep[1] > md) md = dep[1], ans = ml[1] * (seg[i + 1].x - seg[i].x);
        else if(dep[1] == md) ans += ml[1] * (seg[i + 1].x - seg[i].x);
    }
    printf("%d %d %d\n", W * H - area, md, ans);
}
int main()
{
    while(scanf("%d", &N), N)
    {
        init();
        solve();
    }
    return 0;    
}
