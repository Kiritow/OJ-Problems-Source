#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int MAXN = 20;
const int MAXM = 820;
int ans, n, d[MAXN][MAXN], m, ns;
int used[210][210];
struct point
{
    int x, y;
}p[MAXN];
struct triangle
{
    int a, b, c;
}t[MAXM];
int dist(point p1, point p2)
{
    int x, y;
    x = p1.x - p2.x;
    y = p1.y - p2.y;
    return x * x + y * y;
}
bool ponls(point p0, point p1, point p2)
{
    int x1, x2, y1, y2;
    x1 = p0.x - p2.x;
    y1 = p0.y - p2.y;
    x2 = p1.x - p2.x;
    y2 = p1.y - p2.y;
    if(x1 * y2 == x2 * y1)
        return true;
    return false;
}
bool similar(triangle t1, triangle t2) 
{
    int a1, a2, b1, b2, c1, c2;
    a1 = t1.a, b1 = t1.b, c1 = t1.c;
    a2 = t2.a, b2 = t2.b, c2 = t2.c;
    if(a1 * b2 == b1 * a2 && a1 * c2 == c1 * a2 && b1 * c2 == c1 * b2)
        return true;
    return false;
}
void ReadGraph()
{
    int i, j, k, s, v;
    n = 0;
    memset(used, 0, sizeof used);
    for(i = 1; i <= ns; i ++)
    {
        scanf("%d%d", &s, &v);
        s += 100, v += 100; 
        if(used[s][v]) continue;
        used[s][v] = 1;
        p[++ n].x = s;
        p[n]. y = v;
    }
    for(i = 1; i <= n; i ++)
        for(j = 1; j <= n; j ++)
            d[i][j] = d[j][i] = dist(p[i], p[j]);
}
void MakeTriangle()
{
    int i, j, k, temp[3];
    m = 0;
    for(i = 1; i <= n; i ++)
        for(j = i + 1; j <= n; j ++)
            for(k = j + 1; k <= n; k ++)
            {
                if(ponls(p[i], p[j], p[k]))
                    continue;
                temp[0] = d[i][j];
                temp[1] = d[j][k];
                temp[2] = d[i][k];
                sort(temp, temp + 3);
                t[++ m].a = temp[0];
                t[m].b = temp[1];
                t[m].c = temp[2];
            }
}
void cal()
{
    int cnt, i, j;
    ans = 0;
    for(i = 1; i <= m; i ++)
    {
        cnt = 1;
        for(j = i + 1; j <= m; j ++)
        {
            if( similar(t[i], t[j]))
                ++ cnt;
        }
        ans = max(ans, cnt);
    }
}
int main()
{
    while(scanf("%d", &ns), ns)
    {
        ReadGraph();
        MakeTriangle();
        cal();
        printf("%d\n", ans);
    }
    return 0;
}
