#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std ;
const int INF=0xfffffff ;
int n,m ;
char M[25][25] ;
int vis[25][25] ;
int dis[25][25] ;
int dx[]={1,-1,0,0} ;
int dy[]={0,0,1,-1} ;
int dp[16][1<<16] ;
struct node 
{
    int x1,y1,x2,y2 ;
}kk[25] ;
struct point
{
    int x,y,step ;
} ;
int bfs(node a,node b)
{
    memset(vis,0,sizeof(vis)) ;
    queue <point> q ;
    point s ;
    s.x=a.x2 ;s.y=a.y2 ;s.step=0 ;    
    vis[s.x][s.y]=1 ;
    q.push(s) ;
    while(!q.empty())
    {
        point u=q.front() ;
        q.pop() ;
        if(u.x==b.x1 && u.y==b.y1)
        {
            return u.step ;
        }
        for(int i=0 ;i<4 ;i++)
        {
            int xx=u.x+dx[i] ;
            int yy=u.y+dy[i] ;
            if(xx<0 || xx>=n || yy<0 || yy>=n)continue ;
            if(M[xx][yy]=='#')continue ;
            if(vis[xx][yy])continue ;
            vis[xx][yy]=1 ;
            point next ;
            next.x=xx ;next.y=yy ;next.step=u.step+1 ;
            q.push(next) ;
        }
    }
    return INF ;
}
void INIT()
{
    for(int i=0 ;i<25 ;i++)
        for(int j=0 ;j<25 ;j++)
            dis[i][j]=INF ;
    for(int i=0 ;i<m ;i++)
    {
        for(int j=0 ;j<m ;j++)
        {
            if(i==j)
            {    
                dis[i][j]=0 ;
                continue ;
            }
            dis[i][j]=bfs(kk[i],kk[j]) ;
        }
    }
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0 ;i<n ;i++)
            scanf("%s",M[i]) ;
        for(int i=0 ;i<m ;i++)
        {
            scanf("%d%d%d%d",&kk[i].x1,&kk[i].y1,&kk[i].x2,&kk[i].y2) ;
            kk[i].x1-- ;kk[i].y1-- ;kk[i].x2-- ;kk[i].y2-- ;
        }
        INIT() ;
        for(int i=0 ;i<16 ;i++)
            for(int j=0 ;j<(1<<16) ;j++)
                dp[i][j]=INF ;
        for(int i=0 ;i<m ;i++)dp[i][1<<i]=0 ;
        int ans=INF ;
        for(int i=0 ;i<(1<<m) ;i++)
        {
            for(int j=0 ;j<m ;j++)
            {
                if(i&(1<<j))
                {
                    for(int k=0 ;k<m ;k++)
                    {
                        if(dis[k][j]==INF || !(i&(1<<k)))continue ;
                        dp[j][i]=min(dp[j][i],dp[k][i^(1<<j)]+dis[k][j]) ;
                    }
                }
            }
        }
        for(int i=0 ;i<m ;i++)
            ans=min(ans,dp[i][(1<<m)-1]) ;
        if(ans==INF)puts("-1") ;
        else printf("%d\n",ans) ;
    }
    return 0 ;
}
