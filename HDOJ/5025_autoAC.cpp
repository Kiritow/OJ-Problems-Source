#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
using namespace std ;
int n,m ;
int sx,sy ;
int tx,ty ;
char mp[105][105] ;
int vis[105][105][10][33] ;
struct node
{
    int x,y ;
    int time ;
    int snake ;
    int key ;
    friend bool operator <(node a,node b)
    {
        return a.time>b.time ;
    }
} ;
int cnt ;
struct sk
{
    int x,y ;
}ss[10] ;
int OK(node a)
{
    if(a.x==tx && a.y==ty)
    {
        if(a.key==m)return 1 ;
    }
    return 0 ;
}
int dx[]={1,-1,0,0} ;
int dy[]={0,0,1,-1} ;
int bfs(int x,int y)
{
    priority_queue <node> q ;
    node s ;
    s.x=x ;s.y=y ;s.time=0 ;s.snake=0 ;s.key=0 ;
    vis[x][y][0][0]=1 ;
    q.push(s) ;
    while(!q.empty())
    {
        node u=q.top() ;
        if(OK(u))return u.time ;
        q.pop() ;
        for(int i=0 ;i<4 ;i++)
        {
            int xx=u.x+dx[i] ;
            int yy=u.y+dy[i] ;
            if(xx<0 || xx>=n || yy<0 || yy>=n)continue ;
            if(mp[xx][yy]=='#')continue ;
            if(vis[xx][yy][u.key][u.snake])continue ;
            node T ;
            T=u ;
            T.x=xx ;T.y=yy ;T.time=u.time+1 ;
            if(mp[xx][yy]>='1' && mp[xx][yy]<='9')
            {
                int num=mp[xx][yy]-'0'-1 ;
                if(T.key==num)
                {
                    T.key++ ;
                    vis[xx][yy][T.key][T.snake]=1 ;
                    q.push(T) ;
                }
                else
                {
                    vis[xx][yy][T.key][T.snake]=1 ;
                    q.push(T) ;
                }
            }
            else if(mp[xx][yy]=='S')
            {
                for(int i=0 ;i<cnt ;i++)
                {
                    if(xx==ss[i].x && yy==ss[i].y)
                    {
                        if((T.snake>>i)&1)
                        {
                            vis[xx][yy][T.key][T.snake]=1 ;
                            q.push(T) ;
                        }
                        else
                        {
                            T.time++ ;
                            T.snake+=(1<<i) ;
                            vis[xx][yy][T.key][T.snake]=1 ;
                            q.push(T) ;
                        }
                        break ;
                    }
                }
            }
            else
            {
                vis[xx][yy][T.key][T.snake]=1 ;
                q.push(T) ;
            }
        }
    }
    return -1 ;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(!n && !m)break ;
        for(int i=0 ;i<n ;i++)
            scanf("%s",mp[i]) ;
        cnt=0 ;
        for(int i=0 ;i<n ;i++)
        {
            for(int j=0 ;j<n ;j++)
            {
                if(mp[i][j]=='K')sx=i,sy=j ;
                if(mp[i][j]=='T')tx=i,ty=j ;
                if(mp[i][j]=='S')
                {
                    ss[cnt].x=i ;
                    ss[cnt++].y=j ;
                }
            }
        }
        memset(vis,0,sizeof(vis)) ;
        int ans=bfs(sx,sy) ;
        if(ans==-1)puts("impossible") ;
        else printf("%d\n",ans) ;
    }
    return 0 ;
}
