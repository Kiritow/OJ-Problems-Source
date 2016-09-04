#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
const int N = 150010;
vector<int> g[N];
int n,dp[310],K,w[N];
void init()
{
    for(int i=0;i<=n;i++)
        g[i].clear();
}
int dfs(int u)
{
    int size=g[u].size();
    int t=0;
    int cur[310];
    for(int i=1;i<=K;i++)
        dp[i]=cur[i]=-INT_MAX;
    cur[0]=dp[0]=0;
    for(int i=0;i<size;i++)
    {
        int v=g[u][i];
        int now=dfs(v);
        for(int j=t;j>=0;j--)
        {
            for(int k=1;k<=now;k++)
            {
                if(k+j>K)
                    break;
                cur[k+j]=max(cur[k+j],dp[k]+cur[j]);
            }
        }
            t+=now;
    }
    if(size==0) 
        t++;
    cur[1]=max(cur[1],w[u]);
    for(int i=0;i<=K;i++)
        dp[i]=cur[i];
    return t;
}
int main()
{
    int x,root;
    while(scanf("%d %d",&n,&K)==2)
    {
        init();
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&x,&w[i]);
            if(x==0)
                root=i;
            else 
                g[x].push_back(i);
        }
        dfs(root);
        if(dp[K]==-INT_MAX)
            printf("impossible\n");
        else printf("%d\n",dp[K]);
    }
    return 0;
}
