#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define maxn 2300
#define  ll long long
const long long inf = 200000 * 10000000LL;
int n,k;
ll dp[maxn][120];
ll tmp[120];
struct edge
{
    int u,v,w,next;
}e[maxn*10];
int head[maxn],cnt;
void add(int u,int v,int w)
{
    e[cnt].u=u;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u,int fa)
{
    for(int i=head[u];i!=-1;i=e[i].next)
    {
        int v=e[i].v;
        if(v==fa) continue;
        dfs(v,u);
        for(int j=0;j<=k;j++) tmp[j]=dp[u][j];
        for(int j=0;j<=k;j++)
            for(int t=0;t<=j;t++)
                tmp[j]=min(tmp[j],dp[u][j-t]+dp[v][t]+(k-t)*t*e[i].w*2);
        for(int j=0;j<=k;j++) dp[u][j]=tmp[j];
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(head,-1,sizeof(head));
        cnt=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
            for(int j=0;j<=k;j++)
            {
                if(j<=1) dp[i][j]=0;
                else dp[i][j]=inf;
            }
        for(int i=1;i<n;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add(u,v,w);
            add(v,u,w);
        }
        dfs(1,-1);
        printf("%I64d\n",dp[1][k]);
    }
    return 0;
}
