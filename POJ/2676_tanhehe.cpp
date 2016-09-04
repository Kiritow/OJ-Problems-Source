#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

struct node {
    int x, y;
}q[9*9+10];

bool row[10][10], col[10][10], sq[4][4][10];
int G[10][10], cnt;

bool dfs(int cn) {
    if(cn < 0) return true;

    int x = q[cn].x, y = q[cn].y;

    for(int k=1; k<=9; k++) {
        if(row[x][k] || col[y][k] || sq[x/3][y/3][k]) continue;
        row[x][k] = col[y][k] = sq[x/3][y/3][k] = true;

        G[x][y] = k;
        if(dfs(cn-1)) return true;

        row[x][k] = col[y][k] = sq[x/3][y/3][k] = false;
    }

    return false;
}


int main() {
    int T;
    scanf("%d", &T);

    while(T--) {
        cnt = 0;
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(sq, false, sizeof(sq));

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                scanf("%1d", &G[i][j]);
                int k = G[i][j];
                if(k != 0) {
                    row[i][k] = col[j][k] = sq[i/3][j/3][k] = true;
                }
                else q[cnt++] = (node){i, j};
            }
        }

        dfs(cnt-1);

        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                printf("%d", G[i][j]);
            }
            putchar('\n');
        }
    }

    return 0;
}
