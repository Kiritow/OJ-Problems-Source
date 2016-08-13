#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define M 1005
int map[M][M], vis[M], yy[105], x, y, n, cnt;
int getOne(int i){
    for(int j=0; j<y; j++){
        if(!vis[j] && map[i][j]){
            vis[j] = 1;
            if(!yy[j] || getOne(yy[j])){
                yy[j] = i;
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int i, j, a, b, job;
    while(scanf("%d", &x)!=EOF && x){
        scanf("%d %d", &y, &n);
        cnt = 0;
        memset(map, 0, sizeof(map));
        memset(yy, 0, sizeof(yy));
        for(i=0; i<n; i++){
            scanf("%d %d %d", &job, &a, &b);
            if(a&&b)map[a][b] = 1;
        }
        for(i=0; i<x; i++){
            memset(vis, 0, sizeof(vis));
            if(getOne(i))cnt++;
        }
        printf("%d\n", cnt);
    }
}
