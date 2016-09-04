#include<stdio.h>
#include<string.h>
#define MAXD 7776
double f[MAXD][5], a[MAXD];
int vis[MAXD][5];
int N, D, limit[5], code[5], q[5];
const int M = 7776;
struct Point
{
    int x, y;
}p[5];
int sqr(int x)
{
    return x * x;
}
int dis(Point x, Point y)
{
    return sqr(x.x - y.x) + sqr(x.y - y.y);
}
void init()
{
    int i;
    for(i = 0; i < 5; i ++) scanf("%d%d", &p[i].x, &p[i].y);
    for(i = 0; i < 5; i ++) scanf("%d", &limit[i]);
}
int encode(int *code)
{
    int i, ans = 0;
    for(i = 0; i < 5; i ++) ans = ans * 6 + code[i];
    return ans;
}
void decode(int st)
{
    for(int i = 4; i >= 0; i --) code[i] = st % 6, st /= 6;
}
void count(double p)
{
    for(int i = 0; i < 5; i ++) if(code[i] == limit[i]) a[i] += p;
}
int chains()
{
    int i, n = 0;
    for(i = 0; i < 5; i ++) n += code[i];
    return n;
}
void solve()
{
    int i, j, k, x, st, t, n;
    memset(a, 0, sizeof(a));
    memset(code, 0, sizeof(code));
    memset(vis, 0, sizeof(vis));
    memset(f, 0, sizeof(f));
    for(i = 0; i < 5; i ++)
    {
        code[i] = 1;
        st = encode(code);
        vis[st][i] = 1, f[st][i] = 0.2;
        code[i] = 0;
    }
    for(i = 0; i < M; i ++)
        for(j = 0; j < 5; j ++)
            if(vis[i][j])
            {
                decode(i);
                if(chains() > N)
                {
                    vis[i][j] = -1;
                    continue;    
                }
                n = 0;
                for(k = 0; k < 5; k ++)
                    if(k != j && code[k] < limit[k] && dis(p[j], p[k]) <= D * D) q[n ++] = k;
                if(n == 0) vis[i][j] = -1;
                for(k = 0; k < n; k ++)
                {
                    x = q[k];
                    ++ code[x];
                    st = encode(code);
                    vis[st][x] = 1, f[st][x] += f[i][j] / n;
                    -- code[x];    
                }
            }
    for(i = 0; i < M; i ++)
        for(j = 0; j < 5; j ++)
            if(vis[i][j] == -1) decode(i), count(f[i][j]);
    printf("%.3f", a[0]);
    for(i = 1; i < 5; i ++) printf(" %.3f", a[i]);
    printf("\n");
}
int main()
{
    while(scanf("%d%d", &N, &D) == 2)
    {
        init();
        solve();
    }
    return 0;    
}
