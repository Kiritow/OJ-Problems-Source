#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXD 50010
#define MAXM 200010
#define INF 0x3f3f3f3f
int N, M, first[MAXD], e, next[MAXM], v[MAXM], dgr[MAXD], isin[MAXD], r[MAXD];
bool cmp(const int &x, const int &y)
{
    return dgr[x] < dgr[y];    
}
void add(int x, int y)
{
    v[e] = y;
    next[e] = first[x], first[x] = e ++;    
}
void init()
{
    int i, x, y;
    memset(first, -1, sizeof(first[0]) * (N + 1)), e = 0;
    memset(dgr, 0, sizeof(dgr[0]) * (N + 1));
    for(i = 0; i < M; i ++)
    {
        scanf("%d%d", &x, &y);
        ++ dgr[x], ++ dgr[y];
        add(x, y), add(y, x);
    }
}
void solve()
{
    int i, j, x, cnt = 0, min = INF;
    memset(isin, 0, sizeof(isin[0]) * (N + 1));
    for(i = 1; i <= N; i ++) r[i] = i;
    std::sort(r + 1, r + 1 + N, cmp);
    for(i = 1; i <= N; i ++)
        if(!isin[x = r[i]])
        {
            for(j = first[x]; j != -1; j = next[j])
                -- dgr[v[j]], isin[v[j]] = 1;
        }
    for(i = 1; i <= N; i ++)
        if(isin[x = r[i]])
            ++ cnt, min = std::min(min, dgr[x]);
    printf("%s\n", cnt == min + 1 ? "Y" : "N");
}
int main()
{
    while(scanf("%d%d", &N, &M), N)
    {
        if(M == 0)
        {
            printf("Y\n");
            continue;    
        }
        init();
        solve();    
    }
    return 0;    
}
