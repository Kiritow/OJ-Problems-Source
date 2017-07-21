#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <queue>
#include <stack>
//notice the '#' can be placed.
using namespace std;
const int MAXN = 10;

int n, m;
int ans = 0;
char my_map[MAXN][MAXN];
bool vis_row[MAXN];     //vis_row[i], i row is visited.
bool vis_col[MAXN];     //vis_col[j], j col is visited.

bool judge(int x, int y){
    if(x<0 || x>=n || y<0 || y>=n || my_map[x][y]!='#') return false;
    if(vis_row[x] || vis_col[y]) return false;
    return true;
}

void DFS(int x, int y, int step){
    //int xx, yy;
    if(step == m) {ans++; return;}
    for(int i=x; i<n; i++)
    for(int j=0; j<n; j++){
        if(judge(i, j)){
            vis_row[i] = vis_col[j] = true;
            DFS(i, j, step+1);
            vis_row[i] = vis_col[j] = false;
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m) && n!=-1 && m!=-1){
        ans = 0;
        memset(vis_row, false, sizeof(vis_row));
        memset(vis_col, false, sizeof(vis_col));
        for(int i=0; i<n; i++) scanf("%s", my_map[i]);
        DFS(0, 0, 0);
        printf("%d\n", ans);
    }
    return 0;
}
