#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define MAXN 1005
int dir[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} } ;         
int n, flag, p, q ;
int donkey[MAXN][MAXN], tiger[MAXN][MAXN] ;
void DFS(int a, int b, int c, int x, int y, int z) {
    donkey[a][b] = 1;
    tiger[x][y] = 1;
    if(flag) return ;
    if(a == x && b == y) {
        flag = 1;
        printf("%d %d\n", a, b);
        return ;
    }
    if(p && q) {
        flag = 1;
        printf("-1\n");
        return ;
    }
    int aa, bb, xx, yy;
    if(p) {
        aa = a;
        bb = b;
    }
    else {
        aa = a + dir[c][0];
        bb = b + dir[c][1];
        if(aa < 0 || bb < 0 || aa >= n || bb >= n || donkey[aa][bb] == 1) {
            c = (c+1)%4;      
            aa = a + dir[c][0];
            bb = b + dir[c][1];
            if(aa < 0 || bb < 0 || aa >= n || bb >= n || donkey[aa][bb] == 1) {
                p = 1;
                aa = a;
                bb = b;
            }
        }
    }
    if(q) {
        xx = x;
        yy = y;
    }
    else {
        xx = x + dir[z][0];
        yy = y + dir[z][1];
        if(xx < 0 || yy < 0 || xx >= n || yy >= n || tiger[xx][yy] == 1) {
            z = (z-1+4)%4;      
            xx = x + dir[z][0];
            yy = y + dir[z][1];
            if(xx < 0 || yy < 0 || xx >= n || yy >= n || tiger[xx][yy] == 1) {
                q = 1;
                xx = x;
                yy = y;
            }
        }
    }
    DFS(aa, bb, c, xx, yy, z);
}
int main() {
    int a, b, c, x, y, z ;
    while(scanf("%d", &n), n) {
        scanf("%d%d%d", &a, &b, &c);
        scanf("%d%d%d", &x, &y, &z);
        if(a == x && b == y) {
            printf("%d %d\n", a, b);
            continue;
        }
        else {
            memset(donkey, 0, sizeof(donkey));
            memset(tiger,  0, sizeof(tiger ));
            flag = p = q = 0;
            DFS(a, b, c, x, y, z);
        }
    }
    return 0;
}
