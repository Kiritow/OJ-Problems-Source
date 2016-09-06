#include<iostream>
#include<algorithm>
#include<queue>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;
const int N = 100 + 10;
char g[N][N];
int n, m, t;
int sx, sy, dx, dy, ex, ey;
bool vis[N][N][4];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct node
{
    int x, y, step;
    int state;
    node(){}
    node(int xx, int yy, int st):x(xx), y(yy), step(st){ state = 0;}
};
int BFS()
{
    memset(vis, false, sizeof(vis));
    queue<node> Q;
    Q.push(node(sx, sy, 0));
    vis[sx][sy][0] = true;
    while(!Q.empty())
    {
        node cur = Q.front();
        Q.pop();
        if(cur.step > t) return -1;
        for(int k = 0; k < 4; ++k)
        {
            int x = cur.x + dir[k][0], y = cur.y + dir[k][1];
            if(x < 0 || x >= n || y < 0 || y >= m) continue;
            bool flag = false;
            if(!(cur.state & 1) && (dx == cur.x || dy == cur.y)) flag = true;
            if(!(cur.state & 2) && (ex == cur.x || ey == cur.y)) flag = true;
            if(!flag) continue;
            while(true)
            {    
                if(g[x][y] == 'X') break;
                if(g[x][y] == 'D') {
                    cur.state |= 1;
                    break;
                }
                if(g[x][y] == 'E') {
                    cur.state |= 2;
                    break;
                }
                x += dir[k][0], y += dir[k][1];            
                if(x < 0 || x >= n || y < 0 || y >= m) break;
            }
        }
        if(cur.state == 3) {
            return cur.step;
        }
        for(int k = 0; k < 4; ++k)
        {
            int x = cur.x + dir[k][0], y = cur.y + dir[k][1];
            if(x < 0 || x >= n || y < 0 || y >= m || vis[x][y][cur.state] || g[x][y] == 'X') continue;
            if(g[x][y] == 'D' || g[x][y] == 'E') continue;
            vis[x][y][cur.state] = true;
            node tmp = node(x, y, cur.step + 1);
            tmp.state = cur.state;
            Q.push(tmp);
        }
    }
    return -1;
}
int main()
{
    int T, cas = 0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n, &m, &t);
        for(int i = 0; i < n; ++i)
        {
            scanf("%s",g[i]);
            for(int j = 0; j < m; ++j)
            {
                if(g[i][j] == 'S')
                    sx = i, sy = j;
                if(g[i][j] == 'E')
                    ex = i, ey = j;
                if(g[i][j] == 'D')
                    dx = i, dy = j;
            }
        }
        g[sx][sy] = '.';
        int ans = BFS();
        printf("Case %d:\n%d\n", ++cas, ans);
    }
    return 0;
}
