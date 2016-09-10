#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <map>
using namespace std ;
int n ;
int vis[505][505][4] ;
int b[505][505][4] ;
char mp[505][505] ;
int aa,bb ;
struct node
{
    int x,y ;
    int step ;
    friend bool operator <(node aaa,node bbb)
    {
        return aaa.step>bbb.step ;
    }
} ;
int dx[]={-1,0,1,0,0} ;
int dy[]={0,1,0,-1,0} ;
int bfs(int x,int y)
{
    memset(vis,0,sizeof(vis)) ;
    priority_queue <node> q ;
    node s ;
    s.x=x ;s.y=y ;s.step=0 ;
    vis[x][y][0]=1 ;
    q.push(s) ;
    while(!q.empty())
    {
        node u=q.top() ;
        //printf("%d %d %d\n",u.x,u.y,u.step) ;
        if(u.x==aa && u.y==bb)
        {
            return u.step ;
        }
        q.pop() ;
        for(int i=0 ;i<5 ;i++)
        {
            int xx=u.x+dx[i] ;
            int yy=u.y+dy[i] ;
            if(xx<0 || xx>=n || yy<0 || yy>=n)continue ;
            if(mp[xx][yy]=='#')continue ;
            node p ;
            p=u ;
            if(b[xx][yy][u.step%4] || b[u.x][u.y][u.step%4])
            {
                if(xx==u.x && yy==u.y && !vis[xx][yy][(u.step+1)%4])
                {
                    p.step++ ;
                    vis[xx][yy][p.step%4]=1 ;
                    q.push(p) ;
                }
                else if(!vis[xx][yy][(u.step+3)%4])
                {
                    p.x=xx ;p.y=yy ;
                    p.step+=3 ;
                    vis[xx][yy][p.step%4]=1 ;
                    q.push(p) ;
                }
            }
            else if(!vis[xx][yy][(u.step+1)%4])
            {
                p.x=xx ;p.y=yy ;p.step++ ;
                vis[xx][yy][p.step%4]=1 ;
                q.push(p) ;
            }
        }
    }
    return -1 ;
}
int main()
{
    int T ;
    scanf("%d",&T) ;
    for(int cas=1 ;cas<=T ;cas++)
    {
        scanf("%d",&n) ;
        for(int i=0 ;i<n ;i++)
            scanf("%s",mp[i]) ;
        int x,y ;
        memset(b,0,sizeof(b)) ;
        for(int i=0 ;i<n ;i++)
        {
            for(int j=0 ;j<n ;j++)
            {
                if(mp[i][j]=='M')
                {
                    x=i ;y=j ;
                }
                if(mp[i][j]=='N')
                {
                    b[i][j][0]=b[i][j][1]=b[i][j][2]=b[i][j][3]=1 ;
                    if(i-1>=0)b[i-1][j][0]=1 ;
                    if(j+1<n)b[i][j+1][1]=1 ;
                    if(j-1>=0)b[i][j-1][3]=1 ;
                    if(i+1<n)b[i+1][j][2]=1 ;
                }
                if(mp[i][j]=='W')
                {
                    b[i][j][0]=b[i][j][1]=b[i][j][2]=b[i][j][3]=1 ;
                    if(i-1>=0)b[i-1][j][1]=1 ;
                    if(j+1<n)b[i][j+1][2]=1 ;
                    if(j-1>=0)b[i][j-1][0]=1 ;
                    if(i+1<n)b[i+1][j][3]=1 ;
                }
                if(mp[i][j]=='S')
                {
                    b[i][j][0]=b[i][j][1]=b[i][j][2]=b[i][j][3]=1 ;
                    if(i-1>=0)b[i-1][j][2]=1 ;
                    if(j+1<n)b[i][j+1][3]=1 ;
                    if(j-1>=0)b[i][j-1][1]=1 ;
                    if(i+1<n)b[i+1][j][0]=1 ;
                }
                if(mp[i][j]=='E')
                {
                    b[i][j][0]=b[i][j][1]=b[i][j][2]=b[i][j][3]=1 ;
                    if(i-1>=0)b[i-1][j][3]=1 ;
                    if(j+1<n)b[i][j+1][0]=1 ;
                    if(j-1>=0)b[i][j-1][2]=1 ;
                    if(i+1<n)b[i+1][j][1]=1 ;
                }
                if(mp[i][j]=='T')
                {
                    aa=i ;bb=j ;
                }
            }
        }
        printf("Case #%d: %d\n",cas,bfs(x,y)) ;
    }
    return 0 ;
}
