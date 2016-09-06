#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <cstdlib>
#define inf 99999999
using namespace std;
int map[205][205];
struct node
{
    int x,y,r;
};
node a[205];
int d1[205];
int d2[205];
int d3[205];
int n;
void bfs(int u,int *d)
{
    int i;
    for(i=1;i<=n;i++)
        d[i]=inf;
    int vis[205];
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(u);
    vis[u]=1;
    d[u]=0;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        int i;
        for(i=1;i<=n;i++)
        {
            if(!vis[i]&&map[u][i])
            {
                vis[i]=1;
                d[i]=d[u]+1;
                q.push(i);
            }
        }
    }
}
inline int dis(node a,node b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
inline int isarc(node a,node b)
{
    if(dis(a,b)<=(a.r+b.r)*(a.r+b.r))
        return 1;
    else
        return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    int cas;
    for(cas=0;cas<t;cas++)
    {
        memset(a,0,sizeof(a));
        memset(map,0,sizeof(map));
        scanf("%d",&n);
        int i;
        for(i=1;i<=n;i++)
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].r);
        int j;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(isarc(a[i],a[j]))
                    map[i][j]=map[j][i]=1;
            }
        }
        bfs(1,d1);
        bfs(2,d2);
        bfs(3,d3);
        int res=inf;
        for(i=1;i<=n;i++)
        {
            if(d1[i]!=inf&&d2[i]!=inf&&d3[i]!=inf&&d1[i]+d2[i]+d3[i]<res)   
                res=d1[i]+d2[i]+d3[i];
        }
        if(res==inf)
            printf("-1\n");
        else
            printf("%d\n",n-res-1);
    }
    return 0;
}
