#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,cnt,x,y,deg[1001];
bool flag,vis[1001],Map[1001][1001];
void dfs(int u)
{
    if(cnt==n) {flag=1;return;}
    for(int i=1;i<=n&&!flag;++i)
        if(!vis[i]&&Map[u][i])
        {
            vis[i]=1;
            ++cnt;
            dfs(i);
            --cnt;
            vis[i]=0;
        }
}
int main()
{
    while(~scanf("%d",&n))
    {
        flag=0;
        cnt=1;
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        memset(Map,0,sizeof(Map));
        for(int i=0;i<n;++i){
            scanf("%d%d",&x,&y);
            if(x!=y&&!Map[x][y])
            {
                Map[x][y]=Map[y][x]=1;
                ++deg[x],++deg[y];
            }
        }
        int s=1,tot=0;
        for(int i=1;i<=n;++i)
            if(deg[i]==1) {s=i;++tot;}
        if(tot>2) {puts("NO");continue;}
        vis[s]=1;
        dfs(s);
        if(flag) puts("YES");
        else puts("NO");
    }
    return 0;
}
