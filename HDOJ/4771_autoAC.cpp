#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int n,m;
char g[110][110];
int a[110][110];
int sx,sy;
int k;
int dp[110][110][32];
int px[10],py[10];
struct Node
{
    int x,y;
    int s;
    Node(int _x = 0,int _y = 0,int _s = 0)
    {
        x = _x;
        y = _y;
        s = _s;
    }
};
int mo[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int bfs()
{
    queue<Node>q;
    int s = 0;
    for(int i = 0;i < k;i++)
        if(sx == px[i] && sy == py[i])
            s = s|(1<<i);
    q.push(Node(sx,sy,s));
    memset(dp,-1,sizeof(dp));
    dp[sx][sy][s] = 0;
    while(!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        if(tmp.s == ((1<<k) - 1))
        {
            return dp[tmp.x][tmp.y][tmp.s];
        }
        for(int i = 0;i < 4;i++)
        {
            int nx = tmp.x + mo[i][0];
            int ny = tmp.y + mo[i][1];
            int s = tmp.s;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if(a[nx][ny] == -2)continue;
            for(int j = 0;j < k;j++)
                if(nx == px[j] && ny == py[j])
                {
                    s |= (1<<j);
                }
            if(dp[nx][ny][s] != -1)continue;
            dp[nx][ny][s] = dp[tmp.x][tmp.y][tmp.s] + 1;
            q.push(Node(nx,ny,s));
        }
    }
    return -1;
}
int main()
{
    while(scanf("%d%d",&n,&m) == 2)
    {
        if(n == 0 && m == 0)break;
        for(int i = 0;i < n;i++)
            scanf("%s",g[i]);
        memset(a,-1,sizeof(a));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
            {
                if(g[i][j] == '@')
                {
                    sx = i;
                    sy = j;
                }
                if(g[i][j] == '#')
                    a[i][j] = -2;
            }
        scanf("%d",&k);
        int x,y;
        for(int i = 0;i < k;i++)
        {
            scanf("%d%d",&x,&y);
            x --;
            y--;
            px[i] = x;
            py[i] = y;
        }
        printf("%d\n",bfs());
    }
    return 0;
}
