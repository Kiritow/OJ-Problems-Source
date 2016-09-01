#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
    int x[2],y[2],step;
    int b[2],h[2];
};
char map[25][25];
bool vis[25][25][25][25];
int sx[2],sy[2],n,m;
int to[4][2] = {0,1,1,0,0,-1,-1,0};
int bfs()
{
    queue<node> Q;
    node a,next;
    a.x[0] = sx[0],a.y[0]=sy[0];
    a.x[1] = sx[1],a.y[1]=sy[1];
    a.step = 0;
    a.b[0] = a.b[1] = a.h[0] = a.h[1] = 0;
    Q.push(a);
    memset(vis,false,sizeof(vis));
    while(!Q.empty())
    {
        a = Q.front();
        Q.pop();
        int i,j;
        for(i = 0; i<4; i++)
        {
            next = a;
            for(j = 0; j<2; j++)
            {
                if(next.b[j]) continue;
                next.x[j]+=to[i][0];
                next.y[j]+=to[i][1];
                if(map[next.x[j]][next.y[j]]=='*')
                {
                    next.x[j]-=to[i][0];
                    next.y[j]-=to[i][1];
                }
            }
            if(vis[next.x[0]][next.y[0]][next.x[1]][next.y[1]])
                continue;
            if(next.x[0]==next.x[1]&& next.y[0]==next.y[1] && next.b[0]+next.b[1]==0)
                continue;
            next.step++;
            vis[next.x[0]][next.y[0]][next.x[1]][next.y[1]] = true;
            int flag = 1;
            for(j = 0; j<2; j++)
            {
                int now = map[next.x[j]][next.y[j]];
                if(now<2 && !next.h[now])
                {
                    next.h[now]=1;
                    next.b[j] = 1;
                }
                if(!next.b[j])
                    flag = 0;
            }
            if(flag)
                return next.step;
            Q.push(next);
        }
    }
    return -1;
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int cnt = 0,len = 0;
        for(i = 0; i<n; i++)
        {
            scanf("%s",map[i]);
            for(j = 0; j<m; j++)
            {
                if(map[i][j]=='H') map[i][j] = cnt++;
                else if(map[i][j]=='B')
                {
                    sx[len] = i,sy[len] = j;
                    len++;
                }
            }
        }
        int ans = bfs();
        if(ans!=-1)
            printf("%d\n",ans);
        else
            printf("Sorry , sir , my poor program fails to get an answer.\n");
    }
    return 0;
}
