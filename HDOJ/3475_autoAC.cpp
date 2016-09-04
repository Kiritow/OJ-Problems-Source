#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 110
#define MAXM 15
#define MAXD 10010
#define HASH 10007
#define ST 1030
#define INF 0x3f3f3f3f
int N, M, D, d[MAXN][MAXM][8], g[MAXN][MAXM], first[ST], e, next[ST], v[ST];
char b[MAXN];
struct HashMap
{
    int head[HASH], size, next[MAXD], st[MAXD], ans[MAXD];
    void init()
    {
        memset(head, -1, sizeof(head)), size = 0;    
    }
    void push(int _st, int _ans)
    {
        int i, h = _st % HASH;
        for(i = head[h]; i != -1; i = next[i])
            if(st[i] == _st) break;
        if(i == -1)
        {
            if(_st == -1) for(;;);
            st[size] = _st, ans[size] = _ans;
            next[size] = head[h], head[h] = size ++;
        }
        else ans[i] = std::min(ans[i], _ans);
    }
}hm[2];
void add(int x, int y)
{
    v[e] = y;
    next[e] = first[x], first[x] = e ++;
}
void prepare(int i)
{
    int j, k, st;
    memset(first, -1, sizeof(first)), e = 0;
    for(j = 0; j <= D; j ++)
    {
        st = 0;
        for(k = 0; k < M; k ++)
            if(j & 1 << k)
            {
                if(d[i][k][5]) st ^= 1 << k - 1;
                if(d[i][k][4]) st ^= 1 << k;
                if(d[i][k][3]) st ^= 1 << k + 1;    
            }
        add(st, j);
    }
}
void init()
{
    int i, j, k;
    scanf("%d%d", &N, &M);
    memset(d, 0, sizeof(d));
    memset(g, 0, sizeof(g));
    gets(b);
    for(i = 0; i < N; i ++)
    {
        gets(b);
        for(j = 0; j < M; j ++)
        {
            g[i][j] = b[2 * j] == 'o';
            if(j < M - 1 && b[2 * j + 1] == '-') d[i][j][2] = d[i][j + 1][6] = 1;
        }
        if(i < N - 1)
        {
            gets(b);
            for(j = 0; j < M; j ++)
            {
                if(b[2 * j] == '|') d[i][j][0] = d[i + 1][j][4] = 1;
                if(j < M - 1)
                {
                    if(b[2 * j + 1] == '\\' || b[2 * j + 1] == 'X') d[i][j][1] = d[i + 1][j + 1][5] = 1;
                    if(b[2 * j + 1] == '/' || b[2 * j + 1] == 'X') d[i][j + 1][7] = d[i + 1][j][3] = 1;
                }
            }
        }
    }
    D = (1 << M) - 1;
}
void solve()
{
    int i, j, k, t, cur = 0, st, tc, td, nl, ust, cst, cnt, ans = INF;
    hm[0].init();
    for(i = st = 0; i < M; i ++) if(g[0][i]) st |= 1 << i;
    hm[0].push(st, 0);
    for(i = 0; i < N; i ++)
    {
        hm[cur ^ 1].init();
        prepare(i);
        for(j = nl = 0; j < M; j ++) if(g[i + 1][j]) nl |= 1 << j;
        for(j = 0; j < hm[cur].size; j ++)    
        {
            ust = hm[cur].st[j] >> M, cst = hm[cur].st[j] & D, td = nl;
            for(k = first[ust]; k != -1; k = next[k])
            {
                st = v[k], cnt = 0;
                tc = cst ^ st, td = nl;
                for(t = 0; t < M; t ++)
                    if(st & 1 << t)
                    {
                        ++ cnt;
                        if(d[i][t][0]) td ^= 1 << t;
                        if(d[i][t][1]) td ^= 1 << t + 1;
                        if(d[i][t][2]) tc ^= 1 << t + 1;
                        if(d[i][t][6]) tc ^= 1 << t - 1;
                        if(d[i][t][7]) td ^= 1 << t - 1;    
                    }
                hm[cur ^ 1].push(tc << M | td, hm[cur].ans[j] + cnt);
            }
        }
        cur ^= 1;
    }
    for(i = 0; i < hm[cur].size; i ++)
        if((hm[cur].st[i] >> M) == 0) ans = std::min(ans, hm[cur].ans[i]);
    printf("%d\n", ans == INF ? -1 : ans);
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
