#include<stdio.h>
#include<string.h>
#include<algorithm>
#define HASH 100007
#define MAXD 100010
#define INF 0x3f3f3f3f
int N, M, pre[65][MAXD], a[10][10];
char op[65][MAXD], g[10][10];
struct HashMap
{
    int head[HASH], size, next[MAXD], st[MAXD], dif[MAXD], col[MAXD], dp[MAXD];
    void init()
    {
        memset(head, -1, sizeof(head)), size = 0;
    }
    void push(int _st, int _dif, int _col, int _dp, int id, int p, char ch)
    {
        int i, h = ((_st << 6) + _col + 2000 + _dif) % HASH;
        for(i = head[h]; i != -1; i = next[i])
            if(st[i] == _st && dif[i] == _dif && col[i] == _col)
            {
                dp[i] += _dp;
                return ;
            }
        st[size] = _st, dif[size] = _dif, col[size] = _col, dp[size] = _dp;
        pre[id][size] = p, op[id][size] = ch;
        next[size] = head[h], head[h] = size ++;
    }
}hm[2];
void init()
{
    int i, j;
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i ++) scanf("%s", g[i]);
    for(i = 0; i < N; i ++)
        for(j = 0; j < M; j ++) scanf("%d", &a[i][j]);
}
int code[10], h[10];
inline void decode(int *code, int m, int st)
{
    for(int i = m - 1; i >= 0; i --) code[i] = st & 7, st >>= 3;    
}
inline int encode(int *code, int m)
{
    int i, st = 0, cnt = -1;
    memset(h, -1, sizeof(h));
    for(i = 0; i < m; i ++)
    {
        if(h[code[i]] == -1) h[code[i]] = ++ cnt;
        st = st << 3 | h[code[i]];    
    }
    return st;
}
void dp(int i, int j, int c, int cur)
{
    int k;
    for(k = 0; k < hm[cur].size; k ++)
    {
        int col = hm[cur].col[k], u = i ? (col >> j & 1) == c : 0, l = j ? (col >> j - 1 & 1) == c : 0, lu = i && j ? (col >> M) == c : 0;
        if(u && l && lu) continue;
        if(i == N - 1 && j == M - 1 && !u && !l && lu) continue;
        decode(code, M, hm[cur].st[k]);
        if(i && !u)
        {
            int t, s1 = 0, s2 = 0;
            for(t = 0; t < M; t ++)
            {
                if(code[t] == code[j]) ++ s1;
                if((col >> t & 1) != c) ++ s2;
            }
            if(s1 == 1)
            {
                if(s2 > 1) continue;
                if(i < N - 1 || j < M - 2) continue;
            }
        }
        if(l && u)
        {
            if(code[j] != code[j - 1])
                for(int t = 0, x = code[j]; t < M; t ++)
                    if(code[t] == x) code[t] = code[j - 1];
        }
        else if(l && !u) code[j] = code[j - 1];
        else if(!l && !u) code[j] = M;
        if(col & 1 << j) col |= 1 << M;
        else col &= ~(1 << M);
        if(c) col |= 1 << j;
        else col &= ~(1 << j);
        hm[cur ^ 1].push(encode(code, M), hm[cur].dif[k] + (c ? a[i][j] : -a[i][j]), col, hm[cur].dp[k], i * M + j, k, c ? 'x' : 'o');
    }    
}
void print(int k)
{
    int i, j;
    for(i = N - 1; i >= 0; i --)
        for(j = M - 1; j >= 0; j --)
            g[i][j] = op[i * M + j][k], k = pre[i * M + j][k];
    for(i = 0; i < N; i ++) printf("%s\n", g[i]);
}
void solve()
{
    int i, j, k, cur = 0, ans = 0, min = INF;
    hm[0].init();
    hm[0].push(0, 0, 0, 1, 0, 0, 0);
    for(i = 0; i < N; i ++)
        for(j = 0; j < M; j ++)
        {
            hm[cur ^ 1].init();
            if(g[i][j] != 'x') dp(i, j, 0, cur);
            if(g[i][j] != 'o') dp(i, j, 1, cur);
            cur ^= 1;    
        }
    for(i = 0; i < hm[cur].size; i ++)
    {
        int s1 = 0;
        memset(h, 0, sizeof(h));
        decode(code, M, hm[cur].st[i]);
        for(j = 0; j < M; j ++) if(!h[code[j]]) ++ s1, h[code[j]] = 1;
        if(s1 <= 2)
        {
            if(std::abs(hm[cur].dif[i]) < min)
                min = std::abs(hm[cur].dif[i]), ans = hm[cur].dp[i], k = i;
            else if(std::abs(hm[cur].dif[i]) == min)
                ans += hm[cur].dp[i];
        }
    }
    if(min == INF) printf("0 0\n");
    else
    {
        printf("%d %d\n", min, ans);
        print(k);
    }
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
        printf("\n");
    }
    return 0;    
}
