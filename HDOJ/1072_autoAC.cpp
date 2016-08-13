#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
    int x, y;
    int step;
    int t;
};
const int maxn = 9;
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int maze[maxn][maxn], graph[maxn][maxn];
int n, m, ex, ey, ans;
bool bfs(int x, int y);
int main()
{
    int test;
    scanf("%d", &test);
    while(test-- != 0)
    {
        scanf("%d %d", &n, &m);
        int sx, sy;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                scanf("%d", &maze[i][j]);
                if(maze[i][j] == 2)
                    sx = i, sy = j;
                if(maze[i][j] == 3)
                    ex = i, ey = j;
                graph[i][j] = 0;
            }
        }
        if(bfs(sx, sy))
            printf("%d\n", ans);
        else
            printf("-1\n");
    }
    return 0;
}
bool bfs(int x, int y)
{
    queue<node> que;
    node s;
    s.x = x;
    s.y = y;
    s.step = 0;
    s.t = 6;
    graph[x][y] = 6;
    que.push(s);
    while(!que.empty())
    {
        node st = que.front();
        que.pop();
        if(st.x == ex && st.y == ey)
        {
            ans = st.step;
            return true;
        }
        if(st.t == 1)
            continue;
        for(int i = 0; i < 4; i++)
        {
            int dx = st.x + dir[i][0];
            int dy = st.y + dir[i][1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < m && maze[dx][dy] != 0)
            {
                node tmp;
                tmp.x = dx; tmp.y = dy;
                tmp.step = st.step + 1;
                tmp.t  = st.t - 1;
                if(maze[dx][dy] == 4)
                    tmp.t = 6;
                if(tmp.t > graph[dx][dy])
                {
                    graph[dx][dy] = tmp.t;
                    que.push(tmp);
                }
            }
        }
    }
    return false;
}
