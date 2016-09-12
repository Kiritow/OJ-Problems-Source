#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define scan(x) scanf("%d",&(x))
#define scan2(x,y) scanf("%d%d",&(x),&(y))
#define scan3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan4(x,y,z,k) scanf("%d%d%d%d",&(x),&(y),&(z),&(k))
const int maxn = 3003;
const int maxm = maxn * maxn;
const int inf = 1000000000;
int n, m;
__int64 mst;
int map[maxn][maxn];
int dp[maxn][maxn], best[maxn][maxn];
int dis[maxn], pre[maxn];
bool vis[maxn];
vector<int> edge[maxn];
#include<iostream>
int minz(int a, int b)
{
    return a < b ? a : b;
}
void init()
{
    int i, j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            map[i][j] = dp[i][j] = inf;
        edge[i].clear();
        vis[i] = 0;
        pre[i] = -1;
        dis[i] = inf;
    }
}
void input()
{
        for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                        int w;scan(w);
                        map[i][j] = map[j][i] = w;
                }
        }
}
void prim()
{
    int i, j, k;
    for(i = 1; i < n; i++)
    {
        dis[i] = map[0][i];
        pre[i] = 0;
    }
    dis[0] = inf;
    vis[0] = 1;
    pre[0] = -1;
    mst = 0;
    for(i = 0; i < n-1; i++)
    {
        k = 0;
        for(j = 1; j < n; j++)
            if(!vis[j] && dis[k] > dis[j])
                k = j;
        vis[k] = 1;
        mst += dis[k];
        if(pre[k] != -1)
            edge[k].push_back(pre[k]),
            edge[pre[k]].push_back(k);
        for(j = 1; j < n; j++)
            if(!vis[j] && dis[j] > map[k][j] )
                dis[j] = map[k][j], pre[j] = k;
    }
}
int dfs1(int u, int fa, int rt) 
{
    int i;
    for(i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if(v == fa) continue;
        dp[rt][u] = minz(dp[rt][u], dfs1(v, u, rt));
    }
    if(fa != rt) dp[rt][u] = minz(dp[rt][u], map[rt][u]);
    return dp[rt][u];
}
int dfs2(int u, int fa, int rt) 
{
    int i;
    int ans = dp[u][rt];
    for(i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if(v == fa) continue;
        ans = minz(ans, dfs2(v, u, rt));
    }
    return ans;
}
void solve()
{
    int i,j;
    for(i = 0; i < n; i++)
        dfs1(i, -1, i);
    for(i = 0; i < n; i++)
        for(j = 0; j < edge[i].size(); j++)
        {
            int v = edge[i][j];
            best[i][v] = best[v][i] = dfs2(v, i, i);
        }
}
void query()
{
    int ans =0 ;
    for(int i=0;i<n;i++){
        int x=i;
        for(int j=0;j<edge[i].size() ; j++){
                int y=edge[i][j];
                if(x<y) continue;
                int sum = mst - map[x][y] + best[x][y];
                if(sum != mst){
                        ans++;
                }
        }
    }
    printf("%d\n",ans);
}
int main(){
    int T;scan(T);
    while(T--){
                scan(n);
                m=n-1;
                init();
                input();
                prim();
                solve();
                query();
    }
}
