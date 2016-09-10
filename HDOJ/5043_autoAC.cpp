#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
using namespace std;
const int MOD = 1e8+9;
void Add(int &a,int b){
    a += b;
    if(a >= MOD)a -= MOD;
}
int vis[10][33][22][1<<10];
int dp[10][33][22][1<<10];
int TT;
int prime;
int n;
int bit[10][33];
int dfs(int id,int pos,int sum,int s){
    if(id == n){
        id = 0;
        pos--;
        sum = 0;
        if(pos == -1)return 1;
    }
    if(vis[id][pos][sum][s] == TT)return dp[id][pos][sum][s];
    int end = (s&(1<<id))?bit[id][pos]:prime-1;
    int ans = 0;
    for(int i = 0;i <= end;i++){
        if(sum + i >= prime)break;
        Add(ans,dfs(id+1,pos,sum+i,i == end? s : (s & (~(1<<id)))));
    }
    vis[id][pos][sum][s] = TT;
    return dp[id][pos][sum][s] = ans;
}
int x[10];
int solve(){
    memset(bit,0,sizeof(bit));
    int Max = 0;
    for(int i = 0;i < n;i++){
        int cnt = 0;
        do{
            bit[i][cnt++] = x[i]%prime;
            x[i] /= prime;
        }
        while(x[i]);
        Max = max(Max,cnt);
    }
    return dfs(0,Max-1,0,(1<<n)-1);
}
int main()
{
    TT = 0;
    memset(vis,0,sizeof(vis));
    int T;
    scanf("%d",&T);
    assert(T <= 50 && T >= 1);
    int iCase = 0;
    while(T--){
        iCase++;
        TT++;
        scanf("%d%d",&n,&prime);
        assert(n >= 1 && n <= 10);
        assert(prime == 2
                || prime == 3
                || prime == 5
                || prime == 7
                || prime == 11
                || prime == 13
                || prime == 17
                || prime == 19);
        long long tot = 1;
        for(int i = 0;i < n;i++){
            scanf("%d",&x[i]);
            assert(x[i] >= 1 && x[i] <= 1000000000);
            tot = tot*(1+x[i])%MOD;
        }
        tot -= solve();
        tot = (tot%MOD+MOD)%MOD;
        printf("Case #%d: %d\n",iCase,(int)tot);
    }
    return 0;
}
