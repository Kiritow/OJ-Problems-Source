/*
作者:千里冰封
题目:p1014 装箱问题
*/

int i, v, max = 0, a[35], n; 
#include<stdio.h>
#include<memory.h>
void dfs(int idx, int size){
    if(size >= v) return ;
    max = max > size ? max : size;
    if(idx >= n - 1) return ;
    idx++;
    dfs(idx, size);
    dfs(idx, size + a[idx]);
}
int main(){
    scanf("%i%i", &v, &n);
    for(i = 0; i < n; i++)
        scanf("%i", &a[i]);
    dfs(-1, 0);
    printf("%i", v - max);
    return 0;
}
