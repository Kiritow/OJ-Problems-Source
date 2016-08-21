#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
int dp[1024 * 8][140];
int w[20][20];
int e[20][20];
int s[20];
int n;
int dfs(int fs,int x)
{
    if(dp[fs][x] != -1) return dp[fs][x];
    dp[fs][x] = 0;
    for(int i = 0;i < n-1;i++)
        if( (fs & (1 << i)) == 0)
        {
            int ss = (fs | (1 << i));
            if(x > s[i+1])
                dp[fs][x] = max(dp[fs][x],dfs(ss,x+w[0][i+1]) + e[0][i+1]);
            else dp[fs][x] = max(dp[fs][x],dfs(ss,x+w[0][i+1]));
        }
    return dp[fs][x];
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                cin >> w[i][j];
        for(int i = 0;i < n;i++)
            for(int j = 0;j < n;j++)
                cin >> e[i][j];
        for(int i = 0;i < n;i++)
            cin >> s[i];
        memset(dp,-1,sizeof(dp));
        dfs(0,s[0]);
        int ma = 0;
        cout << dp[0][s[0]] << "\n";
    }
    return 0;
}
