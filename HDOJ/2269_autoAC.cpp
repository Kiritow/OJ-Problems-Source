#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define MAXD 15
#define ST 2048
#define INF 0x3f3f3f3f
char name[MAXD][25];
int N, M, T, f[2][ST], vis[2][ST], danger[ST];
char b[1010];
void init()
{
    int i, j, k, n, st;
    for(i = 0; i < N; i ++) scanf("%s", name[i]);
    memset(danger, 0, sizeof(danger));
    gets(b);
    for(i = 0; i < M; i ++)
    {
        gets(b);
        st = 0;
        char *p = strtok(b, " ");
        for(j = 0; j < N; j ++) if(strcmp(name[j], p) == 0) st |= 1 << j;
        while((p = strtok(NULL, " ")) != NULL)
            for(j = 0; j < N; j ++) if(strcmp(name[j], p) == 0) st |= 1 << j;
        danger[st] = 1;
    }
}
int can(int st)
{
    int i, n = 0;
    for(i = 0; i < N; i ++)
        if(st & 1 << i) ++ n;
    return n <= T;
}
int check(int st)
{
    for(int i = st; i > 0; i = i - 1 & st)
        if(danger[i]) return 0;
    return 1;    
}
void solve()
{
    int i, j, k, cur, st, ans = -1, D = (1 << N) - 1;
    std::queue <int> q;
    memset(vis, 0, sizeof(vis));
    f[0][0] = 0, vis[0][0] = 1;
    q.push(0);
    while(!q.empty())
    {
        cur = q.front() & 1, st = q.front() >> 1, q.pop();
        if(cur == 1 && st == D)
        {
            ans = f[cur][st];
            break;    
        }
        if(cur == 1 && check(st) && !vis[0][st])
            f[0][st] = f[1][st] + 1, vis[0][st] = 1, q.push(st << 1);
        if(cur == 0) st = ~st & D;
        for(i = st; i > 0; i = i - 1 & st)
            if(can(i) && check(st - i))
            {
                if(cur == 0)
                {
                    int t = ~(st - i) & D;
                    if(!vis[1][t])
                        f[1][t] = f[0][~st & D] + 1, vis[1][t] = 1, q.push(t << 1 | 1);
                }
                else
                {
                    int t = st - i;
                    if(!vis[0][t])
                        f[0][t] = f[1][st] + 1, vis[0][t] = 1, q.push(t << 1);
                }
            }
    }
    printf("%d\n", ans);
}
int main()
{
    while(scanf("%d%d%d", &N, &M, &T) == 3)
    {
        init();
        solve();
    }
    return 0;    
}
