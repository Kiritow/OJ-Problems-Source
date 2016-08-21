#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int map[30][30],vis[30][30],v[5];
int sx,sy,ex,ey,m,n;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
struct Node
{
    int x,y,step;
    friend bool operator < (Node n1,Node n2)
    {
        return n1.step>n2.step;
    }
};
int check(int x,int y)
{
    if(x<0||y<0||x>=m||y>=n||map[x][y]==-1||vis[x][y])
        return 1;
    return 0;
}
int bfs()
{
    priority_queue<Node> qu;
    Node next,q;
    memset(vis,0,sizeof(vis));
    q.x=sx;q.y=sy;q.step=0;
    map[q.x][q.y]=-1;
    vis[q.x][q.y]=1;
    qu.push(q);
    while(!qu.empty())
    {
        q=qu.top();
        qu.pop();
        if(q.x==ex&&q.y==ey)
            return q.step;
        for(int i=0;i<4;i++)
        {
            next=q;
            next.x+=dir[i][0];next.y+=dir[i][1];
            if(check(next.x,next.y))
                continue;
            next.step+=v[map[next.x][next.y]];
            vis[next.x][next.y]=1;
            qu.push(next);
        }
    }
    return -1;
}
int main()
{
    int cas=1,i,j;
    while(~scanf("%d%d",&m,&n))
    {
        scanf("%d%d%d",&v[3],&v[2],&v[1]);
        getchar();
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                char temp=getchar();
                if(temp=='T')map[i][j]=1;
                else if(temp=='.')map[i][j]=2;
                else if(temp=='#')map[i][j]=3;
                else if(temp=='@')map[i][j]=-1;
            }
            getchar();
        }
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        printf("Case %d: %d\n",cas++,bfs());
    }
}
