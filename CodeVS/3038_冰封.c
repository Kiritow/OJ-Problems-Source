/*
作者:千里冰封
题目:p3038 3n+1问题
*/

#include <stdio.h>

int cnt;

void dfs(int n){
    cnt++;
    if(n <= 0){
        cnt = -1;
        return ;
    }
    if(n == 1)
        return ;
    if(n % 2){
        dfs(n * 3 + 1);
        return ;
    }
    else{
        dfs(n/2);
        return ;
    }
}

int main(int argc, char* argv[]){
    int x;
    scanf("%i", &x);
    while(x--){
        int y;
        cnt = -1;
        scanf("%i", &y);
        dfs(y);
        printf("%i\n", cnt);
    }
    return 0;
}
