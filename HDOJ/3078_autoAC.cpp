#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define N 80010
int __pow[25];
int fa[N],val[N],p[N];
int node[2*N],first[N],dep[2*N],dp[2*N][25];
bool vis[N];
vector<int>e[N];
void dfs(int &index , int u ,int d , int par)
{
    ++index; vis[u] = true;
    first[u] = index; node[index] = u; dep[index] = d; fa[u] = par;
    for(int i=0; i<e[u].size(); i++)
        if(!vis[e[u][i]])
        {
            dfs(index , e[u][i] , d+1 , u);
            ++index;
            node[index] = u; dep[index] = d;
        }
}
void ST(int n)
{
    int K = (int)(log((double)n) / log(2.0));
    for(int i=1; i<=n; i++) dp[i][0] = i;
    for(int j=1; j<=K; j++)
        for(int i=1; i+__pow[j]-1 <= n ; i++)
        {
            int a = dp[i][j-1];
            int b = dp[i+__pow[j-1]][j-1];
            if(dep[a] < dep[b]) dp[i][j] = a;
            else                dp[i][j] = b;
        }
}
int RMQ(int x ,int y)
{
    int K = (int)(log((double)(y-x+1)) / log(2.0));
    int a = dp[x][K];
    int b = dp[y-__pow[K]+1][K];
    if(dep[a] < dep[b]) return a;
    else                return b;
}
int LCA(int u ,int v)
{
    int x = first[u];
    int y = first[v];
    if(x > y) swap(x,y);
    int index = RMQ(x,y);
    return node[index];
}
bool cmp(int a, int b)
{
    return a > b;
}
void path(int &index , int s , int t)
{
    while(s != t)
    {
        p[index++] = val[s];
        s = fa[s];
    }
    p[index++] = val[t];
}
void solve(int kth , int u,int v)
{
    int lca = LCA(u,v);
    int tot = 0;
    path(tot,u,lca);
    path(tot,v,lca);
    tot--;
    if(kth > tot) 
    {
        printf("invalid request!\n");
        return ;
    }
    sort(p,p+tot,cmp);
    printf("%d\n",p[kth-1]);
}
int main()
{
    for(int i=0; i<25; i++) __pow[i] = 1 << i;
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=n; i++) scanf("%d",&val[i]);
    for(int i=1; i<n; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }
    int tot = 0;
    memset(vis,false,sizeof(vis));
    dfs(tot,1,1,-1);
    ST(tot);
    while(q--)
    {
        int op;
        scanf("%d",&op);
        if(op == 0)
        {
            int x,w;
            scanf("%d%d",&x,&w);
            val[x] = w;
        }
        else
        {
            int u,v;
            scanf("%d%d",&u,&v);
            solve(op,u,v);
        }
    }
    return 0;
}
