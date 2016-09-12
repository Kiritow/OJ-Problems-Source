#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 80010;
const int maxm = 26;
int dp[2*maxn][maxm];  
bool vis[maxn];
struct edge
{
    int from, to;
    int next;
} e[2*maxn];
int tot,head[maxn];
int cnt;
int num[maxn];
void init()
{
    memset(head,-1,sizeof(head));
    memset(vis,false,sizeof(vis));
    memset(num,0,sizeof(num));
    cnt = 0;
}
void addedge(int u, int v)
{
    e[cnt].from = u;
    e[cnt].to = v;
    e[cnt].next = head[u];
    head[u] = cnt++;
}
int ver[2*maxn], R[2*maxn], first[maxn];
void dfs(int u ,int dep)
{
    vis[u] = true;
    ver[++tot] = u;
    first[u] = tot;
    R[tot] = dep;
    for(int k=head[u]; k!=-1; k=e[k].next)
        if( !vis[e[k].to] )
        {
            int v = e[k].to;
            dfs(v, dep+1);
            ver[++tot] = u;
            R[tot] = dep;
        }
}
void ST(int n)
{
    for(int i=1; i<=n; i++)
        dp[i][0] = i;
    for(int j=1; (1<<j)<=n; j++)
    {
        for(int i=1; i+(1<<j)-1<=n; i++)
        {
            int a = dp[i][j-1] , b = dp[i+(1<<(j-1))][j-1];
            dp[i][j] = R[a]<R[b]?a:b;
        }
    }
}
int RMQ(int l,int r)
{
    int k=0;
    while((1<<(k+1))<=r-l+1)
        k++;
    int a = dp[l][k], b = dp[r-(1<<k)+1][k]; 
    return R[a]<R[b]?a:b;
}
int LCA(int u ,int v)
{
    int x = first[u] , y = first[v];
    if(x > y) swap(x,y);
    int res = RMQ(x,y);
    return ver[res];
}
int DFS(int u,int fa)
{
    for(int i = head[u]; ~i; i = e[i].next)
    {
        int v = e[i].to;
        if(v == fa)
            continue;
        DFS(v, u);
        num[u]+=num[v];
    }
    return 0;
}
int main()
{
    int t;
    int cas = 0;
    int n, m;
    scanf("%d",&t);
    while(t--)
    {
        init();
        scanf("%d%d",&n,&m);
        int u, v;
        for(int i = 0; i < n-1; i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u, v);
            addedge(v, u);
        }
        for(int i = n; i <= m; i++)
        {
            scanf("%d%d",&u,&v);
            int tt = LCA(u, v);
            num[u]++;
            num[v]++;
            num[tt]-=2;
        }
        DFS(1, 1);
        int ans = INF;
        for(int i = 2; i <= n; i++)
        {
            ans = min(ans, num[i]+1);
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
