#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAXN 20
#define MAXKEY 11
int door[MAXN][MAXN][MAXN][MAXN];
int keys[MAXN][MAXN];
int n, m, p;
struct NODE{
    int x, y;
    int step;
    int havkey;
};
int dir[4][2] = {0,1, 0,-1, 1,0, -1,0};
bool vis[MAXN][MAXN][1<<11];
int bfs()
{
    queue<NODE> Q;
    NODE st;
    st.x = st.y = 1;
    st.step = 0;
    st.havkey = keys[1][1];
    Q.push(st);
    while(!Q.empty()){
        NODE cur = Q.front();
        Q.pop();
        if(cur.x == n && cur.y == m) return cur.step;
        for(int i=0; i<4; i++){
            int tx = cur.x + dir[i][0];
            int ty = cur.y + dir[i][1];
            if(tx >= 1 && tx <= n && ty >= 1 && ty <= m){
                int usekey = door[cur.x][cur.y][tx][ty];
                if(usekey == 0) continue;
                if(usekey == -1 || ((cur.havkey >> usekey) & 1)){
                    NODE nod;
                    nod.x = tx;
                    nod.y = ty;
                    nod.step = cur.step+1;
                    nod.havkey = cur.havkey | keys[tx][ty];
                    if(vis[nod.x][nod.y][nod.havkey] == false){
                        vis[nod.x][nod.y][nod.havkey] = true;
                        Q.push(nod);
                    }
                }
            }
        }
    }
    return -1;
}
int main()
{
    int k, s;
    while(scanf("%d%d%d", &n, &m, &p) != EOF){
        memset(door, -1, sizeof door);
        memset(keys, 0, sizeof keys);
        memset(vis, false, sizeof vis);
        scanf("%d", &k);
        int x1, x2, y1, y2, g, q;
        for(int i=0; i<k; i++){
            scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &g);
            door[x1][y1][x2][y2] = door[x2][y2][x1][y1] = g;
        }
        scanf("%d", &s);
        for(int i=0; i<s; i++){
            scanf("%d%d%d", &x1, &y1, &q);
            keys[x1][y1] |= (1 << q);
        }
        int ans = bfs();
        printf("%d\n", ans);
    }
    return 0;
}
