#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 0x0f0f0f0f
using namespace std;
char s[105];
int dp[105][105];
int min(int a,int b){
    return a>b?b:a;
}
bool Judge(int a,int b){
    while(a<b){
        if(s[a]!=s[b]) return 0;
        a++,b--;
    }
    return 1;
}
int DFS(int a,int b){
    if(dp[a][b]!=MAX) return dp[a][b];
    if(Judge(a,b)) {dp[a][b] = 1;return 1;}
    for(int k = a;k<b;k++){
            dp[a][b]=min(dp[a][b],DFS(a,k)+DFS(k+1,b));
    }
    return dp[a][b];
}
int main(){
    while(~scanf("%s",s)){
        memset(dp,MAX,sizeof(dp));
        printf("%d\n",DFS(0,strlen(s)-1)-1);
    }
    return 0;
}
