#include<stdio.h>
#include<string.h>
#define HASH 10007
#define MAXD 10010
#define MAXN 55
typedef long long LL;
int S, N, M, sg[MAXD], g[MAXN][MAXN];
struct HashMap
{
    int head[HASH], size, next[MAXD];
    LL st[MAXD];
    void init()
    {
        memset(head, -1, sizeof(head)), size = 0;
    }
    int find(LL _st)
    {
        int i, h = _st % HASH;
        for(i = head[h]; i != -1; i = next[i])
            if(st[i] == _st) break;
        return i;
    }
    void push(LL _st)
    {
        int h = _st % HASH;
        st[size] = _st, sg[size] = -1;
        next[size] = head[h], head[h] = size ++;
    }
}hm;
LL encode(int code[][MAXN])
{
    int i, j;
    LL ans = 0;
    for(i = 0; i < N; i ++)
        for(j = 0; j < M; j ++) ans = ans << 1 | code[i][j];
    return ans;
}
void decode(int code[][MAXN], LL st)
{
    int i, j;
    for(i = N - 1; i >= 0; i --)
        for(j = M - 1; j >= 0; j --) code[i][j] = st & 1, st >>= 1;    
}
void init()
{
    char b[MAXN];
    int i, j;
    scanf("%d%d", &N, &M);
    for(i = 0; i < N; i ++)
    {
        scanf("%s", b);
        for(j = 0; j < M; j ++) g[i][j] = b[j] - '0';    
    }
}
int dfs(int cur, LL st)
{
    int i, j, k, g[MAXN][MAXN], h[MAXN];
    decode(g, st);
    memset(h, 0, sizeof(h));
    for(i = 0; i < N - 1; i ++)
        for(j = 0; j < M - 1; j ++)
            if(!g[i][j] && !g[i + 1][j] && !g[i][j + 1] && !g[i + 1][j + 1])
            {
                g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = 1;
                LL c = encode(g);
                k = hm.find(c);
                if(k != -1) h[sg[k]] = 1;
                else
                {
                    hm.push(c), k = hm.find(c);
                    h[dfs(k, c)] = 1;    
                }
                g[i][j] = g[i + 1][j] = g[i][j + 1] = g[i + 1][j + 1] = 0;
            }
    for(i = 0; h[i]; i ++);
    return sg[cur] = i;
}
void solve()
{
    int i, j, k, ans = 0, t;
    for(t = 0; t < S; t ++)
    {
        init(), hm.init();
        LL c = encode(g);
        hm.push(c), k = hm.find(c);
        dfs(k, c);
        ans ^= sg[k];
    }
    printf("%s\n", ans ? "Yes" : "No");
}
int main()
{
    while(scanf("%d", &S) == 1)
    {
        solve();    
    }
    return 0;    
}
