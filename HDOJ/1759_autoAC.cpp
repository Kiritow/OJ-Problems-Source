#include <cstdlib>
#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
#define MAXN 1005
bool reach[MAXN][MAXN];
int map[MAXN][MAXN];
char s[1005];
int d[MAXN],n;
struct pt
{
    int d,x;
};
void BFS(int x)
{
    int i,j;
    pt now,next;
    queue<pt> q;
    now.x=x;
    now.d=0;
    d[now.x]=now.d;
    q.push(now);
    while(!q.empty())
    {
        now=q.front();
        q.pop();
        if (now.d>n+2) break;
        for(i=1;i<=map[now.x][0];i++)
        {
            next.x=map[now.x][i];
            next.d=now.d+1;
            if (next.d<d[next.x])
            {
                d[next.x]=next.d;
                q.push(next);
                reach[x][next.x]=1;
            }
        }
    }
}
int main()
{
    int m,k,i,x,y,z,j,sum;
    while(scanf("%d %d %s",&n,&m,s)!=EOF)
    {
     memset(reach,0,sizeof(reach));
     for(i=1;i<=n;i++)
         reach[i][i]=1;
     memset(map,0,sizeof(map));
     for(i=1;i<=m;i++)
     {
         scanf("%d %d %d",&x,&y,&z);
         x++;y++;
         if (z>0) {reach[x][y]=1;map[x][++map[x][0]]=y;}
     }
     for(i=1;i<=n;i++)
     {
        for(j=1;j<=n;j++)
         d[j]=0x1fffff;
          BFS(i);
     }
     sum=0;
     for(i=1;i<=n;i++)
         for(j=1;j<=n;j++)
             sum+=reach[i][j];
     printf("%d\n",sum);
    }
    return 0;
}
