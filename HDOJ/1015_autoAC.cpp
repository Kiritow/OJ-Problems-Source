#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std; 
char str[20], ans[10]; 
int vis[20], flag; 
bool cmp(char a, char b){return a > b;}
void dfs(int dep, int target, int len){
    if(dep == 5){
        int sum = 0; 
        for(int i = 1; i <= 5; i ++)
            sum += (int)pow(ans[i-1]-'A'+1., i)*(int)pow(-1., i+1); 
        if(sum == target){
            flag = 1; 
            printf("%s\n", ans); 
        }
        return ; 
    }
    for(int i = 0;  i < len; i ++){
        if(!vis[i]){
            vis[i] = 1; 
            ans[dep] = str[i]; 
            dfs(dep+1, target, len); 
            if(flag) return;    
            vis[i] = 0; 
        }
    }
}
int main(){
    int target; 
    while(~scanf("%d%s", &target, str) && strcmp(str, "END") && target){
        flag = 0; 
        memset(vis, 0, sizeof(vis)); 
        int len = strlen(str); 
        sort(str, str+len, cmp); 
        dfs(0, target, len); 
        if(!flag) printf("no solution\n"); 
        memset(str, 0, sizeof(str)); 
    }
    return 0; 
}
