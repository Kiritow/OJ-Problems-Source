#include <cstdio>
#include <cstring>
#define  N 50005
#define INF 99999999
struct Edge
{
    int e, next;
}edge[N*2];
int head[N], eNum;
int c[N], val[N], n, k, ans, dp[N][4][2];
void init()
{
    memset(head, -1, sizeof(head));
    eNum = 0; ans = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<4; j++)
        {
            for(int l=0; l<2; l++)
                dp[i][j][l] = -INF;
        }
    }
}
void AddEdge(int u, int v)
{
    edge[eNum].e = v;
    edge[eNum].next = head[u];
    head[u] = eNum++;
}
int max2(int x, int y)
{
    return x > y ? x : y;
}
void dfs(int u, int fa)
{
    dp[u][c[u]][c[u]] = val[u]; 
    for(int i=head[u]; i!=-1; i=edge[i].next)
    {
        int v = edge[i].e;
        if(v==fa) continue;
        dfs(v, u);
        for(int j=0; j<=k; j++) 
        {
            for(int l=0; l+j<=k; l++)
            {
                ans = max2(ans, dp[u][j][1]+dp[v][l][1]); 
                if(j+l!=k) ans = max2(ans, dp[u][j][0]+dp[v][l][0]); 
                ans = max2(ans, dp[u][j][0]+dp[v][l][1]); 
                ans = max2(ans, dp[u][j][1]+dp[v][l][0]); 
            }
        }
        for(int j=0; j<k; j++)
        {
            dp[u][j+c[u]][1] = max2(dp[u][j+c[u]][1],dp[v][j][1]+val[u]); 
            dp[u][j+c[u]][0] = max2(dp[u][j+c[u]][0],dp[v][j][0]+val[u]);
        }
        if(c[u]==0) dp[u][k][1] = max2(dp[u][k][1], dp[v][k][1]+val[u]); 
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0; i<n; i++)
            scanf("%d%d",&val[i],&c[i]);
        init();
        int u, v;
        for(int i=0; i<n-1; i++)
        {
            scanf("%d%d",&u,&v);
            AddEdge(u, v);
            AddEdge(v, u);
        }
        dfs(0,-1);
        printf("%d\n",ans);
    }
    return 0;
}
