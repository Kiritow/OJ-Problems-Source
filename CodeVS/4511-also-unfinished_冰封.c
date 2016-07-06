/*
作者:千里冰封
题目:p4511 信息传递 NOIP2015 day1 T2
*/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

const int size = 200001;

int min = size, all, l[size];

void dfs(int *a, int idx, int from){
    int i, found = 0;
    for(i = 0; i < idx; i++)
        if(a[i] == from){
            found++;
            min = min > idx ? idx : min;
        }
    if(found) return ;
    a[idx + 1] = l[a[idx]];
    dfs(a, idx, from);
}

int main(int argc, char* argv[]) {
    int i, use[size], free[size];
    memset(use, 0, size);
    scanf("%i", &all);
    for(i = 0; i < all; i++){
        int x,y;
        scanf("%i", &l[i]);
        use[l[i]] = 1;
    }
    for(i = 0; i < all; i++){
        memset(free, 0, all);
        if(use[i]) dfs(free, 0, i);
    }
    printf("%i", min);
    for(;;);
    return 0;
}
