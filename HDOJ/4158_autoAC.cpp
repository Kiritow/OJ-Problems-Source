#include <stdio.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int map[21][21];
bool vis[21][21];
int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,-1,1};
int cb,cw,n;
struct point
{
    int x,y;
}p,t;
void bfs(int x,int y)
{
    p.x=x,p.y=y;
    queue <point> q;
    q.push(p);
    int num=0;
    vis[p.x][p.y]=true;
    int r2=-1,r3=-1;
    while(!q.empty())
    {
        t=q.front();
        num++;
        q.pop();
        for(int i=0; i<4; i++)
        {
            p.x=t.x+dx[i];
            p.y=t.y+dy[i];
            if(vis[p.x][p.y]) continue;
            if(p.x<1||p.x>n||p.y<1||p.y>n) continue;
            if(map[p.x][p.y]==1) r2=1;
            else if(map[p.x][p.y]==2) r3=1;
            else q.push(p),vis[p.x][p.y]=true;
        }
    }
    if(r2==1&&r3==1) return ;
    if(r3==-1) cb+=num;
    else if(r2==-1) cw+=num;
    return ;
}
int main()
{
    int b,w,x,y;
    while(scanf("%d",&n)==1&&n)
    {
        memset(map,0,sizeof(map));
        memset(vis,false,sizeof(vis));
        cb=cw=0;
        scanf("%d%d",&b,&w);
        for(int i=0; i<b; i++)
            scanf("%d%d",&x,&y),map[x][y]=1;
        for(int i=0; i<w; i++)
            scanf("%d%d",&x,&y),map[x][y]=2;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=n; j++)
                if(!map[i][j]&&!vis[i][j]) bfs(i,j);
        if(cb==cw) printf("Draw\n");
        else if(cb>cw) printf("Black wins by %d\n",cb-cw);
        else printf("White wins by %d\n",cw-cb);
    }
    return 0;
}
