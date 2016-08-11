#include<stdio.h>

long res ;

void dfs(int cur){
    if(cur == 1 || cur == 0){
        res++ ;
        return ;
    }
    dfs(--cur) ;
    dfs(--cur) ;
}

int main(int argc, char** argv){
    long num ;
    scanf("%li", &num) ;
    dfs(num) ;
    printf("%li", res) ;
    // while(1);
    return 0;
}
