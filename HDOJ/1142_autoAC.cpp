#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
int map[1010][1010];
int n, p;
bool flag[1010];
int dis[1010];
void spfa()
{
    for(int i = 1; i <= n ;++i)
    {
        flag[i] = false;
        dis[i] = inf;
    }
    dis[2] = 0;
    flag[2] = true;
    queue<int> que;
    que.push(2);
    while(!que.empty())
    {
        int now = que.front();
        que.pop();
        flag[now] = false;
        for(int i = 1; i <= n ;++i)
        {
            if(dis[i] > dis[now] + map[now][i])
            {
                dis[i] = dis[now] + map[now][i];
                if(!flag[i])
                {
                    flag[i] = true;
                    que.push(i);
                }
            }
        }
    }
}
int cou[1010];
void dfs(int now)
{
    if(now == 2)
    {
        cou[2] = 1;
        return;
    }
    int result(0);
    for(int i = 1; i <= n ;++i)
    {
        if(map[now][i] != inf && dis[i] < dis[now])
        {
            if(cou[i] >= 0)
            {
                result += cou[i];
            }
            else
            {
                dfs(i);
                result += cou[i];
            }
        }
    }
    cou[now] = result;
}
int main()
{
    int a, b, dist;
    while(scanf("%d", &n) != EOF)
    {
        if(!n)
            break;
        scanf("%d", &p);
        for(int i = 0; i <= n; ++i)
            for(int j = 1; j <= n;++j)
                map[i][j] = inf;
        for(int i= 0; i < p; ++i)
        {
            scanf("%d %d %d", &a, &b, &dist);
            map[a][b] = map[b][a] = dist;
        }
        spfa();
        for(int i = 1; i <= n;++i)
        {
            cou[i] = -1;
        }
        dfs(1);
        printf("%d\n", cou[1]);
    }
    return 0;
}
