#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <string>
#include <cmath>
using namespace std;
#define maxn 480
int dp[maxn][maxn][2];
int pos[maxn];
inline int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    int t;    scanf("%d",&t);
    while(t--){
        int n;    scanf("%d",&n);
        for(int i = 1;i <= n;i++)    scanf("%d",&pos[i]);
        sort(pos+1,pos+1+n);
        for(int i = 1;i <= n;i++)    dp[i][i][0] = dp[i][i][1] = abs(pos[i])*n;
        for(int i = n;i >= 1;i--)
            for(int j = i+1;j <= n;j++){
                dp[i][j][0] = min(dp[i + 1][j][0] + abs(pos[i + 1] - pos[i]) * (n - j + i), dp[i + 1][j][1] + abs(pos[j] - pos[i]) * (n - j + i));
                dp[i][j][1] = min(dp[i][j - 1][0] + abs(pos[i] - pos[j]) * (n - j + i), dp[i][j - 1][1] + abs(pos[j - 1] - pos[j]) * (n - j + i));
            }
        printf("%d\n",min(dp[1][n][0],dp[1][n][1]));
    }
    return 0;
}
