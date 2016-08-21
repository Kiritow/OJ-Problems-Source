#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct node
{
    int x,y,num,step;
    char mp[15][15];
    bool friend operator<(node a,node b)
    {
        return a.step>b.step;
    }
} t;
int dir[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
char s[15][15];
int vis[15][15][55];
int n,m,ex,ey,flag;
int bfs(int x,int y)
{
    priority_queue<node>q;
    int i,j;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            t.mp[i][j]=s[i][j];
    t.step=0;
    t.num=0;
    t.x=x;
    t.y=y;
    vis[t.x][t.y][0]++;
    q.push(t);
    while(!q.empty())
    {
        t=q.top();
        if(t.x==ex && t.y==ey)
            return t.step;
        for(i=0; i<4; i++)
        {
            t.step++;
            t.x+=dir[i][1];
            t.y+=dir[i][0];
            if(t.x>=0 && t.x<n && t.y>=0 && t.y<m && vis[t.x][t.y][t.num]<50)
            {
                if(t.mp[t.x][t.y]=='.')
                {
                    vis[t.x][t.y][t.num]++;
                    q.push(t);
                }
                else if(t.mp[t.x][t.y]=='X' && t.num>0)
                {
                    vis[t.x][t.y][t.num]++;
                    t.step++;
                    t.num--;
                    t.mp[t.x][t.y]='.';
                    q.push(t);
                }
                else if(t.mp[t.x][t.y]>='1' && t.mp[t.x][t.y]<='9')
                {
                    vis[t.x][t.y][t.num]++;
                    t.num+=t.mp[t.x][t.y]-'0';
                    t.mp[t.x][t.y]='.';
                    q.push(t);
                }
            }
            t=q.top();
        }
        q.pop();
    }
    return -1;
}
int main()
{
    int i,j,x1,y1;
    while(~scanf("%d%d",&n,&m) && n)
    {
        for(i=0; i<n; i++)
            scanf("%s",s[i]);
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
            {
                if(s[i][j]=='S')
                {
                    s[i][j]='.';
                    x1=i,y1=j;
                }
                else if(s[i][j]=='D')
                {
                    s[i][j]='.';
                    ex=i,ey=j;
                }
            }
        memset(vis,0,sizeof vis);
        printf("%d\n",bfs(x1,y1));
    }
}
