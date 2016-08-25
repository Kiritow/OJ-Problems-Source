#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#define N 333
using namespace std;
int n,m;
char map[N][N];
int dis[N][N],flag[N][N];
int dir[4][2]={1,0, -1,0, 0,1, 0,-1};
struct node
{
    int x,y;
};
void solve()
{
    queue<node>q;
    node now,next;
    memset(dis,0,sizeof(dis));
    memset(flag,0,sizeof(flag));
    int i,l;
    for(i=0;i<n;i++)
    {
        scanf("%s",map[i]);
        for(l=0;l<m;l++)
        {
            if(map[i][l]=='1')
            {
                now.x=i,now.y=l;
                q.push(now);
                flag[i][l]=1;
            }
        }
    }
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            next.x=now.x+dir[i][0];
            next.y=now.y+dir[i][1];
            if(next.x<0 || next.x>=n || next.y<0 || next.y>=m)    continue;
            if(flag[next.x][next.y])                            continue;
            q.push(next);
            flag[next.x][next.y]=1;
            dis[next.x][next.y]=dis[now.x][now.y]+1;
        }
    }
}
int main()
{
    int i,l;
    while(scanf("%d%d",&n,&m)!=-1)
    {
        solve();
        for(i=0;i<n;i++)
        {
            printf("%d",dis[i][0]);
            for(l=1;l<m;l++)    printf(" %d",dis[i][l]);
            printf("\n");
        }
    }
    return 0;
}
