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
using namespace std;
int a[100][100];
int dp[110][55];
int b[110];
int main()
{
    int T;
    int n,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= m;i++)
            for(int j = 1;j <= m;j++)
                scanf("%d",&a[i][j]);
        memset(dp,-1,sizeof(dp));
        for(int i = 1;i <= n;i++)scanf("%d",&b[i]);
        for(int i = 1;i <= m;i++)
            dp[1][i] = 0;
        int ans = -1;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                if(b[i] > 0 && j != b[i])
                    dp[i][j] = -1;
                if(dp[i][j] == -1)continue;
                if(i == n){
                    ans = max(ans,dp[i][j]);
                    continue;
                }
                for(int k = 1;k <= m;k++)
                    dp[i+1][k] = max(dp[i+1][k],dp[i][j]+a[j][k]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
