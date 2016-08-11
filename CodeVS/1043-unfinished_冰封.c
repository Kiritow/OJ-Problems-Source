#include<stdio.h>
#include<memory.h>
const int size = 0xf;
int max(int x, int y){return x > y ? x : y;}
int main() {
    int a[size][size], dp[size][size], n;
    memset(a,  0, size * size);
    memset(dp, 0, size * size);
    scanf("%d", &n);
    while(1){
        int x, y, v;
        if(x == 0 && y == 0 && v == 0)
            break;
        scanf("%d%d%d", &x, &y, &v);
        a[x][y] = v;
        dp[x][y] = v;
    }
    int i,j;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
            dp[i][j] += max(dp[i-1][j], dp[j][i-1]);
    printf("%d", dp[--i][--j]);
    scanf("%d%d%d");
    return 0;
}
/*
8
2 3 13
2 6 6
3 5 7
4 4 14
5 2 21
5 6 4
6 3 15
7 2 14
0 0 0
*/
