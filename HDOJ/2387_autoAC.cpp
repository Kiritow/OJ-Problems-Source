#include <stdio.h>
#include <malloc.h>
int p[120][5], now, he[6] = {1, 1, 2, 6, 24, 120};
int n, m, **map, **tmp, **ans;
int** dm(int n, int m) {
    int i;
    int *t = (int *)malloc(sizeof(int) * n * m);
    int **pp = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; ++i) {
        pp[i] = t + i * m;
    }
    return pp;
}
void deld(int ** pp) {
    free(*pp);
    free(pp);
}
void p_f(int x) {
    int i, j, bef = now - 1;
    if(x == 0) return;
    for(i = 0; i < x; ++i) {
        for(j = 0; j < 5; ++j) p[now][j] = p[bef][j];
        p[now][i] = p[bef][x];
        p[now][x] = p[bef][i];
        now++;
        for(j = 1; j < x; ++j) p_f(j);
    }
    return;
}
void cmp() {
    int i, k = 0;
    for(i = 0; i < n * m; ++i) {
        if(*(*ans + i) > *(*tmp + i)) {
            k = 1; break;
        }
        if(*(*ans + i) < *(*tmp + i)) break;
    }
    if(k == 1) {
        for(i = 0; i < n * m; ++i) {
            *(*ans + i) = *(*tmp + i);
        }
    }
}
void bl(int a, int b) {
    int i, j;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            tmp[p[a][i]][p[b][j]] = map[i][j];
        }
    }
    cmp();
}
int main() {
    int i, j, t, tt;
    p[0][0] = 0; p[0][1] = 1; p[0][2] = 2; p[0][3] = 3; p[0][4] = 4;
    now = 1;
    for(i = 1; i < 5; ++i) p_f(i);
    scanf("%d", &t);
    for(tt = 0; tt < t; ++tt) {
        scanf("%d %d", &n, &m);
        map = dm(n, m);
        tmp = dm(n, m);
        ans = dm(n, m);
        for(i = 0; i < n; ++i) {
            for(j = 0; j < m; ++j) {
                scanf("%d", &map[i][j]);
                ans[i][j] = map[i][j];
            }
        }
        for(i = 0; i < he[n]; ++i) {
            for(j = 0; j < he[m]; ++j) {
                bl(i, j);
            }
        }
        printf("Scenario #%d:\n", tt + 1);
        for(i = 0; i < n * m; ++i) {
            printf("%d", *(*ans + i));
            if(i != (n * m - 1)) printf(" ");
        }
        printf("\n\n");
        deld(ans);
        deld(map);
        deld(tmp);
    }
    return 0;
}
