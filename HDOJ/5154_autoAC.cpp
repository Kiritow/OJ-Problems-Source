#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, m, u, v, dp[110][110];
    while(~scanf("%d%d", &n,&m))
    {
        memset(dp, 0, sizeof(dp));
        for(int i=1; i<=m; i++)
        {
            scanf("%d%d", &v,&u);
            dp[u][v] = 1;
        }
        for(int k=1; k<=n; k++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=n; j++)
                    dp[i][j] = max(dp[i][j], dp[i][k]&dp[k][j]);
        int flag = 0;
        for(int i=1; i<=n; i++)
            if(dp[i][i] == 1) flag = 1;
        printf(!flag ? "YES\n" : "NO\n");
    }
    return 0;
}
