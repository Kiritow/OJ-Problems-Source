#include <iostream>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <queue>
#define MAXN 55
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
struct Rect
{
    int x1,y1,x2,y2;
}rect[55*55];
struct Point
{
    int x,y;
    Point(int x1,int y1)
    {x=x1;y=y1;}
    Point(){}
};
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};
int map1[MAXN][MAXN],map2[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool flag[55*55];
int cnt;
int N,M,cas;
queue<Point>Q;
int cmp(const void *p1,const void *p2)
{
    if(((struct Rect *)p1)->x1!=((struct Rect *)p2)->x1)
        return ((struct Rect *)p1)->x1-((struct Rect *)p2)->x1;
    if(((struct Rect *)p1)->y1!=((struct Rect *)p2)->y1)
        return ((struct Rect *)p1)->y1-((struct Rect *)p2)->y1;
    if(((struct Rect *)p1)->x2!=((struct Rect *)p2)->x2)
        return ((struct Rect *)p2)->x2-((struct Rect *)p1)->x2;
    return ((struct Rect *)p2)->y2-((struct Rect *)p1)->y2;
}
void Init()
{
    int i,j;
    char s[300];
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            scanf("%d",&map1[i][j]);
    }
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
            scanf("%d",&map2[i][j]);
    }
}
bool Judge(int x,int y)
{
    if(x>=1&&x<=N&&y>=1&&y<=M)
        return true;
    return false;
}
void Run(int dx,int dy,Rect &now)
{
    int i;
    Q.push(Point(dx,dy));
    if(dx<now.x1||dx>now.x2)
    {
        for(i=now.y1;i<=now.y2;i++)
            Q.push(Point(dx,i));
    }
    if(dy<now.y1||dy>now.y2)
    {
        for(i=now.x1;i<=now.x2;i++)
            Q.push(Point(i,dy));
    }
    now.x1=min(now.x1,dx);
    now.y1=min(now.y1,dy);
    now.x2=max(now.x2,dx);
    now.y2=max(now.y2,dy);
}
void BFS(int sx,int sy)
{
    int i,x,y;
    while(!Q.empty()) Q.pop();
    memset(vis,false,sizeof(vis));
    vis[sx][sy]=true;
    rect[cnt].x1=rect[cnt].x2=sx;
    rect[cnt].y1=rect[cnt].y2=sy;
    Q.push(Point(sx,sy));
    while(!Q.empty())
    {
        x=Q.front().x;
        y=Q.front().y;
        Q.pop();
        for(i=0;i<8;i++)
        {
            int dx=x+dir[i][0];
            int dy=y+dir[i][1];
            if(Judge(dx,dy)&&!vis[dx][dy])
            {
                vis[dx][dy]=true;
                if(map1[dx][dy]!=map2[dx][dy])
                {
                    Run(dx,dy,rect[cnt]);
                }
            }
        }
    }
    cnt++;
}
void Solve()
{
    int i,j;
    cnt=0;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            if(map1[i][j]!=map2[i][j])
            {
                BFS(i,j);
            }
        }
    }
    qsort(rect,cnt,sizeof(rect[0]),cmp);
    memset(flag,true,sizeof(flag));
    int num=0;
    for(i=0;i<cnt;i++)
    {
        if(!flag[i]) continue;
        for(j=i+1;j<cnt;j++)
        {
            if(!flag[j]) continue;
            if(rect[i].x1<=rect[j].x1&&rect[i].y1<=rect[j].y1&&rect[i].x2>=rect[j].x2&&rect[i].y2>=rect[j].y2)
            {
                flag[j]=false;
            }
        }
    }
    for(i=0;i<cnt;i++)
        num+=flag[i];
    printf("%d\n",num);
    for(i=0;i<cnt;i++)
    {
        if(flag[i])
            printf("%d %d %d %d\n",rect[i].x1,rect[i].y1,rect[i].x2,rect[i].y2);
    }
}
int main()
{
    while(scanf("%d%d",&N,&M)!=EOF)
    {
        Init();
        Solve();
    }
return 0;
}
