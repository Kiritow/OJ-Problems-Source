#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int N = 100000+10;
vector<int> g[N];
bool vis[N];
int w[N];
void dfs(int u)
{
    vis[u]=true;
    int size=g[u].size();
    w[u]=0;
    for(int i=0;i<size;i++)
    {
        int v=g[u][i];
        if(vis[v]) continue;
        dfs(v);
        w[u]^=(w[v]+1);
    }
}
int main()
{
    int T,n;
    int a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<=n;i++)
            g[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            g[a].push_back(b);
            g[b].push_back(a);
        }
        memset(vis,false,sizeof(vis));
        dfs(1);
        if(w[1])
            puts("Alice");
        else puts("Bob");
    }
    return 0;
}
