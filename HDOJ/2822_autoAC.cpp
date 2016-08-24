#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
#define inf 999999999
struct node
{
    int x,y,time;
    friend bool operator<(node a,node b)
    {
        return a.time>b.time;
    }
};
char map[1010][1010];
int visit[1010][1010];
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int n,m;
int judge(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m)
        return 1;
    return 0;
}
int bfs(int sx,int sy,int dx,int dy)
{
    priority_queue<node>q;
    node in,out;
    int i;
    visit[sx][sy]=0;
    in.x=sx;
    in.y=sy;
    in.time=0;
    q.push(in);
    while(!q.empty())
    {
        in=q.top();
        q.pop();
        if(in.x==dx&&in.y==dy)
            return in.time;
        for(i=0;i<4;i++)
        {
            out.x=in.x+dir[i][0];
            out.y=in.y+dir[i][1];
            if(judge(out.x,out.y))
            {
                if(map[out.x][out.y]=='X')
                    out.time=in.time;
                else
                    out.time=in.time+1;
                if(visit[out.x][out.y]>out.time)
                {
                    visit[out.x][out.y]=out.time;
                    q.push(out);
                }
            }
        }
    }
    return 1;
}
int main()
{
    int x0,y0,x1,y1,i,j,ans;
    while(scanf("%d%d",&n,&m),n+m)
    {
        for(i=1;i<=n;i++)
            scanf("%s",map[i]+1);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                visit[i][j]=inf;
            scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
            ans=bfs(x0,y0,x1,y1);
            printf("%d\n",ans);
    }
    return 0;
}
