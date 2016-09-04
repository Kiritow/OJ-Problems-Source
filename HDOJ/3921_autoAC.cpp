#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
struct Point
{
    double x, y;
} node[201];
struct T_T
{
    int id;
    double dis;
} que[201];
double sx, sy;
double ans;
double dis[201];
double map[201][201];
int q[201][201], q2[201][201];
int n;
int m;
bool vis[201];
int ra, rb, rc, rd;
double rmin;
double rdis;
double dist(int i, int j)
{
    return sqrt((node[i].x - node[j].x) * (node[i].x - node[j].x)
                + (node[i].y - node[j].y) * (node[i].y - node[j].y));
}
bool cmp(T_ a, T_ b)
{
    return a.dis < b.dis;
}
void init()
{
    for(int i = 0; i < m; i++)  dis[i] = dist(i, m);
    for(int i = 0; i < m; i++)
        for(int j = i + 1; j < m; j++)
            map[i][j] = map[j][i] = dist(i, j);
    for(int i = 0; i < m; i++)
    {
        int temp = 0;
        for(int j = 0; j < m; j++)
            if(i != j)
            {
                que[temp].id = j;
                que[temp].dis = dis[j] + map[j][i];
                temp++;
            }
        sort(que, que + temp, cmp);
        for(int j = 0; j < temp; j++)
            q[i][j] = que[j].id;
    }
    for(int i = 0; i < m; i++)
    {
        int temp = 0;
        for(int j = 0; j < m; j++)
            if(i != j)
            {
                que[temp].id = j;
                que[temp].dis = map[i][j];
                temp++;
            }
        sort(que, que + temp, cmp);
        for(int j = 0; j < temp; j++)
            q2[i][j] = que[j].id;
    }
}
void solve()
{
    rmin = -1;
    int a, b, c, d;
    for(b = 0; b < m; b++)
        if(!vis[b])
        {
            for(c = 0; c < m; c++)
                if(!vis[c] && b != c)
                {
                    int t = 0;
                    a = q[b][t];
                    while(vis[a] || a == c)
                    {
                        t++;
                        a = q[b][t];
                    }
                    t = 0;
                    d = q2[c][t];
                    while(vis[d] || d == a || d == b)
                    {
                        t++;
                        d = q2[c][t];
                    }
                    double cou = dis[a] + map[a][b] + map[b][c] + map[c][d];
                    double cdis = (dis[a] + dis[b] + dis[c] + dis[d]) / 4.0;
                    if(rmin < 0 || cou < rmin || (rmin == cou && cdis < rdis))
                    {
                        rmin = cou;
                        rdis = cdis;
                        ra = a, rb = b, rc = c, rd = d;
                    }
                    t = 0;
                    d = q2[c][t];
                    while(vis[d] || d == b)
                    {
                        t++;
                        d = q2[c][t];
                    }
                    t = 0;
                    a = q[b][t];
                    while(vis[a] || a == c || a == d)
                    {
                        t++;
                        a = q[b][t];
                    }
                    cou = dis[a] + map[a][b] + map[b][c] + map[c][d];
                    cdis = (dis[a] + dis[b] + dis[c] + dis[d]) / 4.0;
                    if(rmin < 0 || cou < rmin || (rmin == cou && cdis < rdis))
                    {
                        rmin = cou;
                        rdis = cdis;
                        ra = a, rb = b, rc = c, rd = d;
                    }
                }
        }
    vis[ra] = 1;
    vis[rb] = 1;
    vis[rc] = 1;
    vis[rd] = 1;
    ans += rmin;
}
int main()
{
    int T;
    int cas = 1;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lf%lf", &sx, &sy);
        scanf("%d", &n);
        m = 4 * n;
        for(int i = 0; i < m; i++)  scanf("%lf%lf", &node[i].x, &node[i].y);
        node[m].x = sx;
        node[m].y = sy;
        init();
        ans = 0;
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < n; i++)
        {
        solve();
        }
        printf("Case #%d: %0.2lf\n", cas++, ans);
    }
    return 0;
}
