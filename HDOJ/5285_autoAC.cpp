#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define LL long long
using namespace std;
int vis[100005];
vector <int> v[100005];
int bfs(int u)
{
    queue <int> q;
    q.push(u);
    vis[u] = 0;
    int res[2] = {1, 0};
    while(!q.empty())
    {
        int tmp = q.front();
        q.pop();
        int len = v[tmp].size();
        for(int i = 0; i < len; i++)
        {
            if(vis[v[tmp][i]] == -1)
            {
                vis[v[tmp][i]] = !vis[tmp];
                q.push(v[tmp][i]);
                res[vis[v[tmp][i]]]++;
            }
            else if(vis[v[tmp][i]] == vis[tmp])
                return -1;
        }
    }
    return max(res[0], res[1]);
}
int main()
{
    int T;
    while(~scanf("%d", &T))
    {
        while(T--)
        {
            int n, m;
            for(int i = 0; i < 100005; i++)
                v[i].clear();
            memset(vis, -1, sizeof vis);
            scanf("%d%d", &n, &m);
            for(int i = 0; i < m; i++)
            {
                int a, b;
                scanf("%d%d", &a, &b);
                v[a].push_back(b);
                v[b].push_back(a);
            }
            int ans = 0;
            for(int j = 1; j <= n; j++)
            {
                if(vis[j] == -1)
                {
                    int tmp = bfs(j);
                    if(tmp == -1)
                    {
                        ans = -1;
                        break;
                    }
                    else
                    {
                        ans += tmp;
                    }
                }
            }
            if(ans == -1 || (ans == n && n < 2))
            {
                puts("Poor wyh");
            }
            else if(ans != n)
                printf("%d %d\n", ans, n - ans);
            else
                printf("%d %d\n", ans - 1, n - ans + 1);
        }
    }
    return 0;
}
