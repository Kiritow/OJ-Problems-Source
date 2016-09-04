#include<iostream>
#include<sstream>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>
#include<iomanip>
using namespace std;
const double eps(1e-8);
typedef long long lint;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int H, W, N;
#define next nex
char lr[1000100];
int next[1000100][4];
int dir[1000100];
const int inf = 1e9 + 7;
char maz[1010][1010];
int vis[1010][1010][4];
int sx, sy, ex, ey;
#define mp make_pair
int cas;
int tot;
struct Edge
{
    int x, y, nex;
};
Edge edge[4000010];
int head[1000010];
void addEdge(int s, int x, int y)
{
    edge[tot].x = x, edge[tot].y = y;
    edge[tot].nex = head[s];
    head[s] = tot++;
}
bool bfs()
{
    memset(head, -1, sizeof(head));
    tot = 0;
    while(sx >= 0 && sx < H && sy >= 0 && sy < W && vis[sx][sy][0] != cas && maz[sx][sy] != '#')
    {
        addEdge(0, sx, sy);
        vis[sx][sy][0] = cas;
        if(sx == ex && sy == ey) return true;
        sx += dx[0], sy += dy[0];
    }
    for(int i = 0; i <= N; i++)
    {
        for(int j = head[i]; j + 1; j = edge[j].nex)
        {
            int nx = edge[j].x, ny = edge[j].y;
            for(int d = 0; d < 4; d++)
            {
                if(next[i][d] == inf) continue;
                int tx = nx + dx[d], ty = ny + dy[d];
                while(tx >= 0 && tx < H && ty >= 0 && ty < W && vis[tx][ty][d] != cas && maz[tx][ty] != '#')
                {
                    addEdge(next[i][d], tx, ty);
                    vis[tx][ty][d] = cas;
                    if(tx == ex && ty == ey) return true;
                    tx += dx[d], ty += dy[d];
                }
            }
        }
    }
    return false;
}
void init()
{
    dir[0] = 0;
    for(int i = 0; i < N; i++)
        dir[i + 1] = (lr[i] == 'L') ? (dir[i] + 3) % 4 : (dir[i] + 1) % 4;
    int last[4] = {inf, inf, inf, inf};
    for(int i = N; i >= 0; i--)
    {
        for(int j = 0; j < 4; j++)
            next[i][j] = last[j];
        last[dir[i]] = i;
    }
    return;
}
int main()
{
    cas = 0;
    memset(vis, 0, sizeof(vis));
    while(~scanf("%d %d %d", &H, &W, &N))
    {
        cas++;
        scanf("%s", lr);
        init();
        for(int i = 0; i < H; i++)
        {
            scanf("%s", maz[i]);
            for(int j = 0; j < W; j++)
                if(maz[i][j] == 'S') sx = i, sy = j;
                else if(maz[i][j] == 'E') ex = i, ey = j;
        }
        if(bfs()) puts("Yes");
        else puts("No");
    }
    return 0;
}
