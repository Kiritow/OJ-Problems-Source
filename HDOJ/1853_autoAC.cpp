#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
#define N 505
#define MAXN 1<<28
int map[N][N];
int lx[N], ly[N];
int slack[N];
int match[N];
bool visitx[N], visity[N];
int n;
bool Hungary(int u)
{
    visitx[u] = true;
    for(int i = 1; i <= n; ++i)
    {
        if(visity[i])
            continue;
        else
        {
            if(lx[u] + ly[i] == map[u][i])
            {
                visity[i] = true;
                if(match[i] == -1 || Hungary(match[i]))
                {
                    match[i] = u;
                    return true;
                }
            }
            else
                slack[i] = min(slack[i], lx[u] + ly[i] - map[u][i]);
        }
    }
    return false;
}
void KM_perfect_match()
{
    int temp;
    for(int i = 1; i <= n; ++i)
        lx[i] = -MAXN;
    memset(ly, 0, sizeof(ly));
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            lx[i] = max(lx[i], map[i][j]);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            slack[j] = MAXN;
        while(1)
        {
            memset(visitx, false, sizeof(visitx));
            memset(visity, false, sizeof(visity));
            if(Hungary(i))
                break;
            else
            {
                temp = MAXN;
                for(int j = 1; j <= n; ++j)
                    if(!visity[j])
                        temp = min(temp, slack[j]);
                for(int j = 1; j <= n; ++j)
                {
                    if(visitx[j])
                        lx[j] -= temp;
                    if(visity[j])
                        ly[j] += temp;
                    else
                        slack[j] -= temp;
                }
            }
        }
    }
}
int main()
{
    int m;
    int a, b, cost;
    int ans;
    bool flag;
    while(scanf("%d%d", &n, &m) != EOF)
    {
        ans = 0;
        flag = true;
        memset(match, -1, sizeof(match));
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                map[i][j] = -MAXN;
        for(int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d", &a, &b, &cost); 
            if(-cost > map[a][b])
                map[a][b] = -cost;
        }
        KM_perfect_match();
        for(int i = 1; i <= n; ++i) 
        {
            if(match[i] == -1 || map[ match[i] ][i] == -MAXN)
            {
                flag = false;
                break;
            }
            ans += map[match[i]][i];
        }
        if(flag)
            printf("%d\n", -ans);
        else
            printf("-1\n");
    }
    return 0;
}
