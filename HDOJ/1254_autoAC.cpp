#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#include<iostream>
#include<list>
#include<set>
#include<cmath>
#define INF 0x7fffffff
#define eps 1e-6
using namespace std;
int g[8][8];
int xx[]={1,-1,0,0};
int yy[]={0,0,-1,1};
int n,m;
struct node
{
    int x,y,lv;
};
node box,man,over;
bool vis[8][8];
bool ok;
void dfs(int x1,int y1,int x2,int y2)
{
    if(ok)return;
    if(x1==x2&&y1==y2)
    {
        ok=1;
        return;
    }
    int x,y;
    for(int k=0;k<4;k++)
    {
        x=x1+xx[k];
        y=y1+yy[k];
        if(x>=n||x<0||y>=m||y<0||g[x][y]==1||vis[x][y])
            continue;
        vis[x][y]=1;
        dfs(x,y,x2,y2);
    }
}
int bfs()
{
    bool way[8][8][8][8];
    queue<node>q;
    queue<node>human;
    memset(way,0,sizeof(way));
    q.push(box);
    human.push(man);
    way[box.x][box.y][man.x][man.y]=1;
    node tmp,now,ma;
    while(!q.empty())
    {
        tmp=q.front();q.pop();
        ma=human.front();human.pop();
        if(tmp.x==over.x&&tmp.y==over.y)return tmp.lv;
        for(int k=0;k<4;k++)
        {
            int x=tmp.x+xx[k];
            int y=tmp.y+yy[k];
            if(x>=n||x<0||y>=m||y<0||g[x][y]==1||way[x][y][tmp.x][tmp.y])
            continue;
            int rex=tmp.x-xx[k];
            int rey=tmp.y-yy[k];
            if(rex>=n||rex<0||rey>=m||rey<0||g[rex][rey]==1)
            continue;
            memset(vis,0,sizeof(vis));
            ok=0;
            vis[tmp.x][tmp.y]=1;
            dfs(ma.x,ma.y,rex,rey);
            if(!ok)
            continue;
            now.x=x,now.y=y,now.lv=tmp.lv+1;
            way[x][y][tmp.x][tmp.y]=1;
            q.push(now);
            human.push(tmp);
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            scanf("%d",&g[i][j]);
            if(g[i][j]==2)
                box.x=i,box.y=j,box.lv=0;
            else if(g[i][j]==3)
                over.x=i,over.y=j;
            else if(g[i][j]==4)
                man.x=i,man.y=j;
        }
        int tmp=bfs();
        printf("%d\n",tmp);
    }
}
