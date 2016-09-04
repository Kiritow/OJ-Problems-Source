#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 210
int nx, ny, g[MAXN][MAXN], sy[MAXN], cx[MAXN], cy[MAXN];
int path(int u) {
    for (int v = 1; v <= ny; v++)if (g[u][v] && !sy[v]) {
            sy[v] = 1;
            if (!cy[v] || path(cy[v])) {
                cx[u] = v;
                cy[v] = u;
                return 1;
            }
        }
    return 0;
}
int MaximumMatch() {
    int i, ret = 0;
    memset(cx, 0, sizeof (cx));
    memset(cy, 0, sizeof (cy));
    for (i = 1; i <= nx; i++)if (!cx[i]) {
            memset(sy, 0, sizeof (sy));
            ret += path(i);
        }
    return ret;
}
char c[2010];
int s[2010][2010], w, h, n, m;
int sum(int x0, int y0, int x1, int y1){
    x0--, y0--;
    return s[x1][y1] - s[x0][y1] - s[x1][y0] + s[x0][y0];
}
int sumx[2010], sumy[2010];
int pd(int a, int b){
    int i, j, ans = 0, t;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            if (sum((a + b) * i + b + 1, (a + b) * j + b + 1, (a + b) * i + b + a, (a + b) * j + b + a) != a * a){
                ans++;
            }
        }
    }
    for (i = 0; i <= n; i++){
        sumx[i] = sum((a + b) * i + 1, 1, (a + b) * i + b, w);
    }
    for (j = 0; j <= m; j++){
        sumy[j] = sum(1, (a + b) * j + 1, h, (a + b) * j + b);
    }
    for (i = 0; i <= n; i++){
        for (j = 0; j <= m; j++){
            g[i + 1][j + 1] = 0;
            t = sum((a + b) * i + 1, (a + b) * j + 1, (a + b) * i + b, (a + b) * j + b);
            sumx[i] -= t;
            sumy[j] -= t;
        }
    }
    for (i = 0; i <= n; i++){
        if (sumx[i]) ans++;
    }
    for (j = 0; j <= m; j++){
        if (sumy[j]) ans++;
    }
    for (i = 0; i <= n; i++){
        if (sumx[i]) continue;
        for (j = 0; j <= m; j++){
            if (sumy[j]) continue;
            t = sum((a + b) * i + 1, (a + b) * j + 1, (a + b) * i + b, (a + b) * j + b);
            if (t) g[i + 1][j + 1] = 1;
        }
    }
    nx = n + 1;
    ny = m + 1;
    return ans + MaximumMatch();
}
int main(){
    int t, i, j, x, y, ans;
    while (scanf("%d%d%d%d%d", &h, &w, &n, &m, &t) != EOF){
        for (i = 1; i <= h; i++){
            scanf("%s", c);
            for (j = 0; c[j]; j++){
                s[i][j + 1] = s[i][j];
                if (c[j] == '1'){
                    s[i][j + 1]++;
                }
            }
        }
        for (i = 1; i <= h; i++){
            for (j = 1; j <= w; j++){
                s[i][j] += s[i - 1][j];
            }
        }
        if (n != m){
            y = (h * m - w * n) / (m - n);
            x = (h * (m + 1) - w * (n + 1)) / (n - m);
            if (x <= 0 || y <= 0 || y > x || n * x + y * (n + 1) != h || m * x + y * (m + 1) != w){
                printf("-1\n");
                continue;
            }
            printf("%d\n", pd(x, y) * t);
        }else{
            if (h != w){
                printf("-1\n");
                continue;
            }
            ans = 1<<30;
            for (x = 1; n * x < h; x++){
                if ((h - n * x) % (n + 1) == 0){
                    y = (h - n * x) / (n + 1);
                    if (x >= y){
                        ans = min(ans, pd(x, y));
                    }
                }
            }
            if (ans == (1<<30)){
                printf("-1\n");
            }else{
                printf("%d\n", ans * t);
            }
        }
    }
    return 0;
}
