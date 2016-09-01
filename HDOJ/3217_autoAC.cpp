#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
using namespace std;
#define maxn 18
int dp[maxn][1<<18];
int N, M, s, v;
int main(){
    while(scanf("%d", &N) && N){
        scanf("%d", &M);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= M; i++){
            scanf("%d%d", &s, &v);
            dp[0][s] = v;
        }
        for(int i = 1; i <= N; i++){
            for(int sta = 0; sta < (1<<N); sta++ ){
                if(sta & 1<<(i-1)) dp[i][sta] = dp[i-1][sta] + dp[i-1][sta-(1<<(i-1))];
                else dp[i][sta] = dp[i-1][sta];
            }
        }
        int max = -9999;
        for(int sta = 0; sta < (1<<N); sta++){
            if(dp[N][sta] > max) max = dp[N][sta];
        }
        printf("%d\n", max);
    }     
    return 0;
}
