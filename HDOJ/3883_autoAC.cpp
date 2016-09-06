#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int map[101][101];
int hash[2][101][101][2];
bool vis[101];
int f[2];
int abs(int a){
    if (a < 0) return -a;
    return a;
}
int main(){
    int i, j, k, t, ii, ans;
    int *p;
    while(scanf("%d%d", &n, &m) != EOF){
        for (i = 1; i <= n; i++)
            for (j = 1; j <= m; j++)
                scanf("%d", &map[i][j]);
        memset(vis, 0, sizeof(vis));
        ans = 0x80000000;
        ii = 0;
        for (i = 1; i <= n; i++){            
            ii = 1 - ii;
            for (j = 1; j <= m; j++){
                f[0] = f[1] = 0x80000000;
                for (k = 100; k >= 0; k--){
                    for (t = 0; t <= 1; t++){
                        p = & hash[ii][j][k][t];
                        *p = 0x80000000;
                        if (!vis[k]) continue;
                        if (i > 1 && *p < hash[1 - ii][j][k][t])
                            *p = hash[1 - ii][j][k][t];
                        if (j > 1 && *p < hash[ii][j - 1][k][t])
                            *p = hash[ii][j - 1][k][t];
                        if (k <= abs(map[i][j])) continue;
                        if (f[1 - t] < *p) f[1 - t] = *p;
                    }
                }
                if (f[0] == 0x80000000) f[0] = 0;
                if (f[1] == 0x80000000) f[1] = 0;
                f[0] = map[i][j] - f[0];
                f[1] = map[i][j] - f[1];
                if (ans < f[0]) ans = f[0];
                k = abs(map[i][j]);
                if (!vis[k] || hash[ii][j][k][0] < f[0]){
                    vis[k] = 1;
                    hash[ii][j][k][0] = f[0];
                }
                if (!vis[k] || hash[ii][j][k][1] < f[1]){
                    vis[k] = 1;
                    hash[ii][j][k][1] = f[1];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
