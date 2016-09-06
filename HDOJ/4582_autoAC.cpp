#include <bitset>
#include <iostream>
using namespace std;
const int maxn=2013;
int first[maxn],pre[maxn],vv[maxn*20],nxt[maxn*20];
bitset<2001> to[2001];
bool vis[maxn];
int ans;
void dfs(int u,int p)
{
    vis[u]=true;
    to[u].reset();
    for(int e=pre[u];e;e=nxt[e]) if(vis[vv[e]])
        to[u].set(vv[e]);
    for(int e=first[u];e;e=nxt[e]) if(vv[e]!=p)
        dfs(vv[e],u);
    if(p==-1)
        return;
    if(to[u].test(p))
        ans++;
    else
        to[p]|=to[u];
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m) && n|m)
    {
        memset(vis,0,sizeof(vis));
        memset(first,0,sizeof(first));
        memset(pre,0,sizeof(pre));
        int e=2;
        for(int i=1;i<n;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            nxt[e]=first[u],vv[e]=v,first[u]=e++;
            nxt[e]=first[v],vv[e]=u,first[v]=e++;
        }
        for(int i=n;i<=m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            nxt[e]=pre[u],vv[e]=v,pre[u]=e++;
            nxt[e]=pre[v],vv[e]=u,pre[v]=e++;
        }
        ans=0;
        dfs(1,-1);
        printf("%d\n",ans);
    }
}
