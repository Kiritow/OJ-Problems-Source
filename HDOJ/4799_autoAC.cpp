#pragma comment(linker,"/STACK:102400000,102400000")
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define maxn 50050
int dp[maxn][2];
int n,X,Y;
bool state;
int v[maxn],f,s[maxn],p;
struct node{
    int t,nxt;
}edge[maxn<<1];
int head[maxn];
bool vis[maxn];
void solve(int u)
{
    vis[u] = 1;
    if(s[u])state ^= 1;
    if(state)v[u] = -v[u];
    dp[u][0] = v[u];
    dp[u][1] = -v[u];
    for (int i = head[u]; i!=-1; i = edge[i].nxt)
    {
        int y = edge[i].t;
        if(!vis[y]){
        solve(y);
        dp[u][0] += max(dp[y][0],dp[y][1]-(s[y]?Y:X));
        dp[u][1] += max(dp[y][1],dp[y][0]-(s[y]?Y:X));
        }
    }
    if(s[u]) state ^= 1;
}
int main()
{
    while(scanf("%d%d%d",&n,&X,&Y)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        memset(head,-1,sizeof(head));
        memset(vis,0,sizeof(vis));
        int ind = 0;
        state = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d%d",&v[i],&f,&s[i],&p);
            if(p) v[i] = -v[i];
            edge[ind].t = i;
            edge[ind].nxt = head[f];
            head[f] = ind++;
        }
        solve(0);
        if(dp[0][0] < 0)
            puts("HAHAHAOMG");
        else printf("%d\n",dp[0][0]);
    }
    return 0;
}
