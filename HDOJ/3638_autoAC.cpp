#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define MAXN 60
int trans[] = {0, 2, 1, 4, 3};
int dx[] = {0, -1, 1, 0, 0}, dy[] = {0, 0, 0, -1, 1};
int ex[][9] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, -1, -1, -2, -2, -2, -2, -2},
    {0, 1, 1, 1, 2, 2, 2, 2, 2},
    {0, -1, 0, 1, -2, -1, 0, 1, 2},
    {0, -1, 0, 1, -2, -1, 0, 1, 2}
};
int ey[][9] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, 0, 1, -2, -1, 0, 1, 2},
    {0, -1, 0, 1, -2, -1, 0, 1, 2},
    {0, -1, -1, -1, -2, -2, -2, -2, -2},
    {0, 1, 1, 1, 2, 2, 2, 2, 2}
};
struct Monster
{
    int x, y, d;
}mon[MAXN];
char b[MAXN];
int N, M, K, sx, sy, tx, ty, g[MAXN][MAXN], del[MAXN][MAXN], vis[MAXN][MAXN];
struct Point
{
    int x, y, t;
    Point(){}
    Point(int _x, int _y, int _t) : x(_x), y(_y), t(_t){}
};
inline int inside(int x, int y)
{
    return x >= 1 && x <= N && y >= 1 && y <= M;
}
void moveall()
{
    int i, x, y;
    for(i = 0; i < K; i ++)
    {
        x = mon[i].x + dx[mon[i].d], y = mon[i].y + dy[mon[i].d];
        if(inside(x, y) && g[x][y]) mon[i].x = x, mon[i].y = y;
        else mon[i].d = trans[mon[i].d];
    }
}
void delblock()
{
    int i, j, x, y;
    for(i = 1; i <= N; i ++)
        for(j = 1; j <= M; j ++) del[i][j] = 1 - g[i][j];
    for(i = 0; i < K; i ++)
        for(j = 0; j < 9; j ++)
        {
            x = mon[i].x + ex[mon[i].d][j], y = mon[i].y + ey[mon[i].d][j];
            if(inside(x, y)) del[x][y] = 1;
        }
}
void init()
{
    int i, j;
    scanf("%d%d", &N, &M);
    for(i = 1; i <= N; i ++)
    {
        scanf("%s", b + 1);
        for(j = 1; j <= M; j ++)
        {
            g[i][j] = b[j] != '*';
            if(b[j]== 'A') sx = i, sy = j;
            else if(b[j] == 'B') tx = i, ty = j;
        }
    }
    scanf("%d", &K);
    for(i = 0; i < K; i ++) scanf("%d%d%d", &mon[i].x, &mon[i].y, &mon[i].d);
}
void solve()
{
    int i, j, x, y, cur, ans = -1;
    cur = -1;
    delblock();
    if(del[sx][sy])
    {
        printf("璐ュ靛朵涓 峰ユ澶т\n");
        return ;
    }
    std::queue <Point> q;
    q.push(Point(sx, sy, 0));
    while(!q.empty())
    {
        Point p = q.front();
        q.pop();
        if(p.t > 1000) break;
        if(p.x == tx && p.y == ty)
        {
            ans = p.t;
            break;
        }
        if(p.t > cur)
        {
            cur = p.t;
            for(i = 1; i <= N; i ++)
                for(j = 1; j <= M; j ++) vis[i][j] = 0;
            moveall(), delblock();
        }
        for(i = 0; i < 5; i ++)
        {
            x = p.x + dx[i], y = p.y + dy[i];
            if(inside(x, y) && !del[x][y] && !vis[x][y])
                vis[x][y] = 1, q.push(Point(x, y, p.t + 1));
        }
    }
    if(ans == -1) printf("璐ュ靛朵涓 峰ユ澶т\n");
    else printf("%d\n", ans);
}
int main()
{
    int t, tt;
    scanf("%d", &t);
    for(tt = 1; tt <= t; tt ++)
    {
        init();
        printf("Case %d: ", tt);
        solve();
    }
    return 0;
}
