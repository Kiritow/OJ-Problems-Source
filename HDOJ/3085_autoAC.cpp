#include<stdio.h>
#include<string.h>
#include<string>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
#define M 800
using namespace std;
struct node
{
    int x,y;
    node(){}
    node(int xx,int yy)
    {
        x=xx;
        y=yy;
    }
}gg,mm,zz[2],f[2][M*M];
int step,front[2],rear[2];
char ma[M][M];
int n,m;
int dir[4][2]={{-1,0},{0,1},{0,-1},{1,0}};
bool maphaten(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&ma[x][y]!='X')
    {
        for(int i=0;i<2;i++)
        {
            if(abs(x-zz[i].x)+abs(y-zz[i].y)<=2*step) return false;
        }
        return true;
    }
    return false;
}
queue<node>q[3];
void clear()
{
    for(int i=0;i<3;i++)
        while(!q[i].empty())
            q[i].pop();
}
bool bfs(int num,int move_step,char s,char e)
{
    q[2]=q[num];
    for(int i=0;i<move_step;i++)
    {
        node u,v;
        while(!q[2].empty())
        {
            u=q[2].front();
            q[2].pop();
            q[num].pop();
            if(!maphaten(u.x,u.y)) continue;
            for(int k=0;k<4;k++)
            {
                v=u;
                v.x=u.x+dir[k][0];
                v.y=u.y+dir[k][1];
                if(!maphaten(v.x,v.y)||ma[v.x][v.y]==s) continue;
                if(ma[v.x][v.y]==e) return true;
                ma[v.x][v.y]=s;
                q[num].push(v);
            }
        }
        q[2]=q[num];
    }
    return false;
}
int BFS()
{
    step=0;
    clear();
    q[0].push(mm);
    q[1].push(gg);
    while(!q[0].empty()&&!q[1].empty())
    {
        step++;
        if(bfs(0,3,'M','G')||bfs(1,1,'G','M')) return step;
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
        int k=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",ma[i]);
            for(int j=0;j<m;j++)
            {
                if(ma[i][j]=='M')
                    mm=node(i,j);
                else if(ma[i][j]=='G')
                    gg=node(i,j);
                else if(ma[i][j]=='Z')
                    zz[k++]=node(i,j);
            }
        }
        printf("%d\n",BFS());
    }
    return 0;
}
