#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int ROW = 16;
const int COL = 10;
const int dr[] = {-1, 0, 1, 0};
const int dc[] = { 0, 1, 0,-1};
struct Node {
    int r,c;
    Node() {}
    Node(int _r,int _c) {
        r = _r;
        c = _c;
    }
};
int n; 
bool ok;
char grid[ROW+1][COL+1];
int ans[ROW*COL];
bool full() {
    for(int i = 1; i <= ROW; i++) {
        for(int j = 1; j <= COL; j++) {
            if(grid[i][j] != grid[1][1]) {
                return false;
            }
        }
    }
    return true;
}
void dfs(int x,int y,int cur) {
    char now[ROW+1][COL+1];
    int vis[ROW+1][COL+1];
    if(cur == n) {
        if(full()) {
            ok = true;
        }
        return ;
    }
    int color = grid[x][y] - '0';
    for(int i = 1; i <= 4; i++) { 
        if(color == i) {
            continue;
        }
        memset(vis,0,sizeof(vis));
        memcpy(now,grid,sizeof(grid));
        queue<Node> que;
        que.push(Node(x,y));
        vis[x][y] = true;
        int r,c;
        while(!que.empty()) {
            Node front = que.front();
            que.pop();
            grid[front.r][front.c] = i + '0';
            for(int d = 0; d < 4; d++) {
                r = front.r + dr[d];
                c = front.c + dc[d];
                if(grid[r][c] - '0' != color || vis[r][c]) {
                    continue;
                }
                vis[r][c] = true;
                que.push(Node(r,c));
            }
        }
        ans[cur] = i;
        dfs(x,y,cur+1);
        if(ok) {
            return ;
        }
        memcpy(grid,now,sizeof(grid));
    }
}
void solve() {
    scanf("%d",&n);
    memset(grid,0,sizeof(grid));
    for(int i = 1; i <= ROW; i++) {
        scanf("%s",grid[i]+1);
    }
    for(int i = 1; i <= ROW; i++) {
        for(int j = 1; j <= COL; j++) {
            if(grid[i-1][j] == grid[i][j] || grid[i][j-1] == grid[i][j]) {
                continue;
            }
            ok = false;
            dfs(i,j,0);
            if(ok) {
                for(int k = 0; k < n; k++) 
                    printf("%d %d %d\n",ans[k],i,j);
                return;
            }
        }
    }
}
int main() {
    int t,cas = 1;
    scanf("%d",&t);
    while(t--) {
        printf("Case #%d:\n",cas++);
        solve();
    }
    return 0;
}
