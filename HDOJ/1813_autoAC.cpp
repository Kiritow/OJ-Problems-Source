#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
const int inf = 1000000000;
struct node
{
    int x,y;
};
char str[4][10] = {"east","north","south","west"};
char map[9][9];
int to[4][2] = {0,1,-1,0,1,0,0,-1};
int L,n,dis[9][9],step,path[1000];
queue<node> Q;
int onedge(int i,int j)
{
    return i==0 || j == 0 || i == n-1 || j == n-1;
}
int ismap(int i,int j)
{
    return i>=0 && i<n && j>=0 && j<n;
}
void bfs()
{
    int i;
    node a,next;
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        for(i = 0; i<4; i++)
        {
            next.x=a.x+to[i][0];
            next.y=a.y+to[i][1];
            if(!ismap(next.x,next.y)) continue;
            if(!map[next.x][next.y]) continue;
            if(dis[next.x][next.y]>dis[a.x][a.y]+1)
            {
                dis[next.x][next.y]=dis[a.x][a.y]+1;
                Q.push(next);
            }
        }
    }
}
void init()
{
    int i,j,k;
    node a;
    while(!Q.empty()) Q.pop();
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            dis[i][j] = inf;
            map[i][j] = map[i][j]=='1'?0:1;
            if(!map[i][j]) continue;
            if(onedge(i,j))
            {
                a.x = i;
                a.y = j;
                dis[i][j] = 0;
                Q.push(a);
            }
        }
    }
    bfs();
}
int get_h(char mat[9][9])
{
    int i,j,k,maxn = 0;
    for(i = 0; i<n; i++)
    {
        for(j = 0; j<n; j++)
        {
            if(mat[i][j])
                maxn = max(maxn,dis[i][j]);
        }
    }
    return maxn;
}
int IDA(char mat[9][9],int cnt)
{
    if(cnt+get_h(mat)>step) return 0;
    if(cnt == step) return 1;
    int i,x,y,tx,ty;
    char tem[9][9];
    for(i = 0; i<4; i++)
    {
        memset(tem,0,sizeof(tem));
        for(x = 0; x<n; x++)
        {
            for(y = 0; y<n; y++)
            {
                if(onedge(x,y) || !mat[x][y]) continue;
                tx = x+to[i][0];
                ty = y+to[i][1];
                if(!map[tx][ty]) tem[x][y] = 1;
                else tem[tx][ty] = 1;
            }
        }
        path[cnt] = i;
        if(IDA(tem,cnt+1)) return 1;
    }
    return 0;
}
int main()
{
    int i,j,k,flag = 0;
    while(~scanf("%d",&n))
    {
        if(flag++)
        printf("\n");
        for(i = 0; i<n; i++)
            scanf("%s",map[i]);
        init();
        step = 0;
        while(1)
        {
            if(IDA(map,0))break;
            step++;
        }
        for(i = 0; i<step; i++)
            printf("%s\n",str[path[i]]);
    }
    return 0;
}
