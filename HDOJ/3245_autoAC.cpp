#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define min(a,b) a>b?b:a
#pragma comment(linker,"/STACK:1000000000,1000000000")
const int maxn = 10010;
const int INF = 1000000000;
int dp[maxn][110];
int sum[maxn],sumd[maxn];
int head[maxn];
struct Edge{
    int v,next;
}edge[2*maxn];int N,L,E;
void add_edge(int a,int b)
{
    edge[E].v=b;
    edge[E].next=head[a];
    head[a]=E++;
}
void dfs(int u,int fa)
{
    int i,j,k,v;
    sum[u]=1;sumd[u]=0;
    fill(dp[u],dp[u]+L+1,INF);
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(v==fa) continue;
        dfs(v,u);
        sumd[u]+=sumd[v]+sum[v];
        sum[u]+=sum[v];
    }
    dp[u][0]=sumd[u];
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(v==fa) continue;
        for(j=1;j<=L;j++)
            dp[u][j]=min(dp[u][j],dp[v][j-1]+sumd[u]-sumd[v]-sum[v]);
    }
}
int ans[maxn];
void solve(int u,int fa)
{
    int i,a,v;
    if(u==0) ans[u]=sumd[0];
    else ans[u]=N-sum[u]+sumd[fa]-sum[u];
    int tmp[110];
    fill(tmp,tmp+L+1,INF); 
    int mi=INF;
    for( i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(v==fa) continue;
        for( a=0;a<=L-2;a++)
            mi=min(mi,tmp[L-2-a]+dp[v][a]-sumd[v]-sum[v]);
        for( a=0;a<=L-1;a++)
        {
            tmp[a]=min(tmp[a],dp[v][a]-sumd[v]-sum[v]);
            if(a) tmp[a]=min(tmp[a],tmp[a-1]);
        }
    }
    mi=min(mi,tmp[L-1]);
    sumd[u]=ans[u];
    ans[u]+=mi;
    for(i=head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].v;
        if(v==fa) continue;
        solve(v,u);
    }
}
int main()
{
    int i,j,k,a,b;
    while(scanf("%d%d",&N,&L),(N||L))
    {
        if(N==1) {puts("0");continue;}
        E=0;
        memset(head,-1,sizeof(head));
        for(i=0;i<N-1;i++)
        {
            scanf("%d%d",&a,&b);
            add_edge(a,b);
            add_edge(b,a);
        }
        dfs(0,0);
        solve(0,0);
        printf("%d\n",*min_element(ans,ans+N));
    }
    return 0;
}
