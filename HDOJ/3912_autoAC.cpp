#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<ctime>
using namespace std;
#define N 50009
int R,C,ER,EC,num;
int map1[505][505];
int map2[505][505];
int vis[505][505];
struct Point
{
    int x,y,f;
    Point(int _x,int _y,int _f){x=_x;y=_y;f=_f;}
};
void init()
{
    scanf("%d%d%d%d",&R,&C,&ER,&EC);
    memset(vis,0,sizeof(vis));
    num=0;
    for(int i=0;i<2*R-1;i++)
    {
        if(i&1)
        {
        for(int j=0;j<C;j++)
        scanf("%d",&map1[i/2][j]);
        }
        else 
        {
        for(int j=0;j<C-1;j++)
        scanf("%d",&map2[i/2][j]);
        }
    }
}
void dfs(Point s,Point ss)
{
    int ff=s.f;
    for(;;)
    {
    if(!vis[s.x][s.y])num++;
    vis[s.x][s.y]=1;
    if(s.x==ss.x&&s.y==ss.y)
    {
        if((s.f==3&&ff==0)||(s.f==1&&ff==2))
        break;
        if(s.f==ff&&ff==0&&(s.y==0||map2[s.x][s.y-1]==1))
        break;
        if(s.f==ff&&ff==2&&(s.y==C-1||map2[s.x][s.y]==1))
        break;
    }
    if(s.f==0)
    {
        if(s.y>0&&map2[s.x][s.y-1]==0)
        {
            s.y--;
            s.f=1;
        }
        else if(s.x+1<R&&map1[s.x][s.y]==0)
        {
            s.x++;
            s.f=0;
        }
        else if(s.y+1<C&&map2[s.x][s.y]==0)
        {
            s.y++;
            s.f=3;
        }
        else if(s.x>0&&map1[s.x-1][s.y]==0)
        {
            s.x--;
            s.f=2;
        }
    }
    else if(s.f==1)
    {
         if(s.x>0&&map1[s.x-1][s.y]==0)
        {
            s.x--;
            s.f=2;
        }
        else if(s.y>0&&map2[s.x][s.y-1]==0)
        {
            s.y--;
            s.f=1;
        }
        else if(s.x+1<R&&map1[s.x][s.y]==0)
        {
            s.x++;
            s.f=0;
        }
        else if(s.y+1<C&&map2[s.x][s.y]==0)
        {
            s.y++;
            s.f=3;
        }
    }
    else if(s.f==2)
    {
         if(s.y+1<C&&map2[s.x][s.y]==0)
        {
            s.y++;
            s.f=3;
        }
        else  if(s.x>0&&map1[s.x-1][s.y]==0)
        {
            s.x--;
            s.f=2;
        }
        else if(s.y>0&&map2[s.x][s.y-1]==0)
        {
            s.y--;
            s.f=1;
        }
        else if(s.x+1<R&&map1[s.x][s.y]==0)
        {
            s.x++;
            s.f=0;
        }
    }
    else if(s.f==3)
    {
         if(s.x+1<R&&map1[s.x][s.y]==0)
        {
            s.x++;
            s.f=0;
        }
         else if(s.y+1<C&&map2[s.x][s.y]==0)
        {
            s.y++;
            s.f=3;
        }
        else  if(s.x>0&&map1[s.x-1][s.y]==0)
        {
            s.x--;
            s.f=2;
        }
        else if(s.y>0&&map2[s.x][s.y-1]==0)
        {
            s.y--;
            s.f=1;
        }
    }
    }
}
void solve()
{
    Point s=Point(0,ER,0);    
    Point ss=Point(R-1,EC,2);
    dfs(s,ss);
    dfs(ss,s);
    if(num==R*C) puts("YES");
    else puts("NO");
}
int main()
{
    int Case;
    scanf("%d",&Case);
    while(Case--)
    {
        init();
        solve();
    }
    return 0;
}
