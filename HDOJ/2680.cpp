#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
#define MAXN 1000
#define INF 0x3f3f3f3f
int mp[MAXN][MAXN];
int dis[MAXN];
bool vis[MAXN];
int n,m,s;
void dij(int from)
{
    for(int i=1;i<=n;i++)
    {
        vis[i]=false;
        dis[i]=mp[from][i];
    }
    vis[from]=1;
    for(int i=2;i<=n;i++)
    {
        int next=i;
        int minnext=INF;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&minnext>dis[j])
            {
                next=j;
                minnext=dis[j];
            }
        }
        vis[next]=true;
        for(int j=1;j<=n;j++)
        {
            if(!vis[j]&&dis[j]>dis[next]+mp[next][j])
            {
                dis[j]=dis[next]+mp[next][j];
            }
        }
    }
//    queue<int> bus;
//    bus.push(from);
//    dis[from]=0;
//    while(!bus.empty())
//    {
//        int pos=bus.front();
//        bus.pop();
//        vis[pos]=true;
//        for(int i=1;i<=n;i++)
//        {
//            if(mp[pos][i]!=INF&&!vis[i])
//            {
//                dis[i]=min(dis[i],dis[pos]+mp[pos][i]);
//                bus.push(i);
//            }
//        }
//    }
}
int main()
{
    while(scanf("%d %d %d",&n,&m,&s)==3)
    {
        memset(mp,0x3f,sizeof(int)*MAXN*MAXN);
        for(int i=0; i<m; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            if(mp[v][u]>w) mp[v][u]=w;
        }
        dij(s);
        int w;
        scanf("%d",&w);
        int mindis=INF;
        for(int i=0;i<w;i++)
        {
            int tfrom;
            scanf("%d",&tfrom);
            mindis=min(mindis,dis[tfrom]);
        }
        if(mindis==INF) printf("-1\n");
        else printf("%d\n",mindis);
    }
    return 0;
}
