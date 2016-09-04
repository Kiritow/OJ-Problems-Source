#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
#define N 2005
#define INF 0x7fffffff
int dp[N];
int tmp=0;
int  e, ne[N], v[N], w[N],adj[N];
void add(int x, int y, int z)
{
    v[e] = y, w[e] = z;
    ne[e] = adj[x], adj[x] = e ++;
}
void dfs(int cur, int fa)
{
    int i, flag = 0;
    dp[cur] = 0;
    for(i = adj[cur]; i != -1; i = ne[i])
        if(v[i] != fa)
        {
            flag = 1;
            dfs(v[i], cur);
            dp[cur] += min(w[i], dp[v[i]]);
        }
    if(flag == 0) dp[cur] = INF;
}
int main()
{
    int n,r,a,b,c;
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        if(n==0 && r==0)
            break;
        memset(adj,-1,sizeof(adj));
        for(int i=1; i<n; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
            add(b,a,c);
        }
        for(int i=0; i<=n; i++)
            dp[i]=INF;
        if(n==1)
            printf("0\n");
        else
        {
            e=0;
            dfs(r,-1);
            printf("%d\n",dp[r]);
        }
    }
    return 0;
}
