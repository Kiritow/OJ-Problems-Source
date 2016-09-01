#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
char map[105][105];
int sx,sy,n,m;
int visit[105][105];
int dir[4][2]= {1,0,0,1,-1,0,0,-1};
struct node
{
    int x;
    int y;
    int cost;
} a[1000015];
int mvCost(int tx,int ty,int cost)
{
    if(map[tx][ty]=='R')
    cost-=3;
    else if(map[tx][ty]=='T')
    cost-=2;
    else
    cost-=1;
    int flag=0;
    for(int i=0;i<4;i++)
    {
        int ttx=tx+dir[i][0];
        int tty=ty+dir[i][1];
        if(ttx>=0 && ttx<n && tty>=0 && tty<m)
        {
            if(map[ttx][tty]=='E')
            {
                flag=1;
                break;
            }
        }
    }
    if(flag==1 && cost>0)
    cost=0;
    return cost;
}
void bfs(int mv)
{
    memset(visit,-1,sizeof(visit));
    a[0].x=sx;
    a[0].y=sy;
    a[0].cost=mv;
    visit[sx][sy]=mv;
    int start=0,end=1;
    node cur,change;
    while(start<end)
    {
        cur=a[start++];
        if(cur.cost==0)
            continue;
        for(int i=0; i<4; i++)
        {
            int tx=cur.x+dir[i][0];
            int ty=cur.y+dir[i][1];
            if(map[tx][ty]=='#' ||map[tx][ty]=='E' || map[tx][ty]=='Y' )
                continue;
            else if(tx>=0 && tx<n && ty>=0 && ty<m  )
            {
                int Cost=mvCost(tx,ty,cur.cost);
                if(Cost<0)
                continue;
                else
                {
                    if(Cost>visit[tx][ty])
                    {
                        change.x=tx;
                        change.y=ty;
                        change.cost=Cost;
                        a[end++]=change;
                        visit[tx][ty]=Cost;
                        if(map[tx][ty]!='P')
                        map[tx][ty]='*';
                    }
                }
            }
        }
    }
}
int main()
{
    int t,mv;
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>mv;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>map[i][j];
                if(map[i][j]=='Y')
                {
                    sx=i;
                    sy=j;
                }
            }
        }
        bfs(mv);
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                printf("%c",map[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
