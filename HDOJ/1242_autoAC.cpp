#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<queue>
#include<iostream>
#define N 300
using namespace std;
typedef struct node
{
    int x,y;
    int time;
    friend bool operator<(node n1,node n2)
    {
        return n2.time<n1.time;
    }
}node;
int map[N][N];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
int x1,x2,y1,y2;
int judge(int x,int y)
{
    if(x<0||x>=m||y<0||y>=n||map[y][x]==-1)
    return 1;
    return 0;
}
int bfs()
{
     priority_queue<node>Q;
     while(!Q.empty())
     Q.pop();
     node fir,nex;
     fir.x=x1;
     fir.y=y1;
     fir.time=0;
     map[y1][x1]=-1;
     Q.push(fir);
     while(!Q.empty())
     {
            fir=Q.top();
            Q.pop();
            if(fir.x==x2&&fir.y==y2)
            {
                return fir.time;
            }
            for(int i=0;i<4;i++)
            {
                nex.x=fir.x+dir[i][0];
                nex.y=fir.y+dir[i][1];
                if(judge(nex.x,nex.y))
                continue;
                nex.time=fir.time+map[nex.y][nex.x]+1;
                map[nex.y][nex.x]=-1;
                Q.push(nex);
            }
        }
    return -1;
    }
int main()
{
    char c[N][N];
    while(~scanf("%d%d",&n,&m))
    {   
        for(int i=0;i<n;i++)
        scanf("%s",c[i]);
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {   
            if(c[i][j]=='.')
            {
                map[i][j]=0;
                continue;
            }
            if(c[i][j]=='#')
            {
                map[i][j]=-1;
                continue;
            }
            if(c[i][j]=='x')
            {
                map[i][j]=1;
                continue;
            }
            if(c[i][j]=='r')
            {
                map[i][j]=0;
                x1=j,y1=i;
                continue;
            }
            if(c[i][j]=='a')
            {
                map[i][j]=0;
                x2=j,y2=i;
            }
        }
        int step=bfs();
        if(step!=-1)
        printf("%d\n",step);
        else
        printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
    return 0;
}
