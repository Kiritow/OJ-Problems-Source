#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 55
#define MAX 1<<28
#define CLR(arr, what) memset(arr, what, sizeof(arr))
int map[N][N];
int lx[N], ly[N], slack[N];
bool visitx[N], visity[N];
int match[N];
int n, m;
bool Hungary(int u)
{
    int temp;
    visitx[u] = true;
    for(int i = 1; i <= m; ++i)
    {
        if(visity[i])
            continue;
        temp = lx[u] + ly[i] - map[u][i];
        if(temp == 0)
        {
            visity[i] = true;
            if(match[i] == - 1 || Hungary(match[i]))
            {
                match[i] = u;
                return true;
            }
        }
        else
            slack[i] = min(slack[i], temp);
    }
    return false;
}
bool KM_Perfect_Match()
{
    int temp;
    CLR(lx, 0);
    CLR(ly, 0);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            lx[i] = max(lx[i], map[i][j]);
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
            slack[j] = MAX;
        while(1)
        {
            CLR(visitx, false);
            CLR(visity, false);
            if(Hungary(i))
                break;
            else
            {
                temp = MAX;
                for(int j = 1; j <= m; ++j)
                    if(!visity[j])
                        temp = min(temp, slack[j]);
                if(temp == MAX)
                    return false;
                for(int j = 1; j <= n; ++j)
                    if(visitx[j])
                        lx[j] -= temp;
                for(int j = 1; j <= m; ++j)
                    if(visity[j])
                        ly[j] += temp;
                    else
                        slack[j] -= temp;
            }
        }
    }
    return true;
}
int main()
{
    int finish;
    int ans, res; 
    while(~scanf("%d%d", &n, &m))
    {
        res = ans = 0;
        CLR(match, -1);
        CLR(map, 0);
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
            {
                scanf("%d", &map[i][j]);
                map[i][j] *= 100; 
            }
        for(int i = 1; i <= n; ++i)
        {
            scanf("%d", &finish);
            res += map[i][finish];
            map[i][finish] += 1; 
        }
        KM_Perfect_Match();
        for(int i = 1; i <= m; ++i)
        {
            if(match[i] != -1)
                ans += map[ match[i] ][i];
        }
        printf("%d %d\n", n - ans % 100, ans / 100 - res / 100);
    }
    return 0;
}
