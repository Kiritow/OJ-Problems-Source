#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define LL long long
using namespace std;
const int INF = 1000000000;
const int N = 51;
struct node
{
    int t,g;
    bool operator<(const node& tt) const
    {
        if(g == tt.g) return t > tt.t;
        return g < tt.g;
    }
}s[N],now,ne;
int n,m,tot,min1;
int t[N],g[N],vst[N],num[N];
int adj[N][N];
int d[N][N];
priority_queue<node> q1,q2;
void dfs(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(vst[j]) continue;
        if(adj[i][j])
        {
            vst[j] = 1;
            d[tot][num[tot]++] = j;
            dfs(j);
        }
    }
}
void init()
{
    tot = 0;
    for(int i = 1; i <= n; i++)
    {
        if(!vst[i])
        {
            vst[i] = 1;
            d[tot][num[tot]++] = i;
            dfs(i);
            tot++;
        }
    }
}
void solve()
{
    int i,j,k;
    min1 = INF;
    for(i = 0; i < tot; i++)
    {
        while(!q1.empty()) q1.pop();
        while(!q2.empty()) q2.pop();
        now.t = now.g = 0;
        q1.push(now);
        for(j = 0; j < num[i]; j++)
        {
            while(!q1.empty())
            {
                now = q1.top();
                q1.pop();
                q2.push(now);
                ne.t = now.t+s[d[i][j]].t;
                ne.g = now.g+s[d[i][j]].g;
                if(ne.g >= m) {min1 = min(min1, ne.t); continue;}
                if(ne.t < min1) q2.push(ne);
            }
            int tem = INF;
            while(!q2.empty())
            {
                now = q2.top();
                q2.pop();
                if(tem >= now.t)
                {
                    q1.push(now);
                    tem = now.t;
                }
            }
        }
    }
}
int main()
{
    int T;
    int i,j,k;
    scanf("%d", &T);
    for(int cc = 1; cc <= T; cc++)
    {
        scanf("%d%d", &n, &m);
        memset(adj, 0, sizeof(adj));
        memset(num, 0, sizeof(num));
        memset(vst, 0, sizeof(vst));
        for(i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &s[i].t, &s[i].g, &k);
            for(j = 0; j < k; j++)
            {
                int aa;
                scanf("%d", &aa);
                adj[i][aa] = adj[aa][i] = 1;
            }
        }
        printf("Case %d: ", cc);
        init();
        solve();
        if(min1 == INF) puts("Poor Magina, you can't save the world all the time!");
        else printf("%d\n", min1);
    }
    return 0;
}
