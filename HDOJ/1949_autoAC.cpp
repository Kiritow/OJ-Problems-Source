#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define maxn 218
#define max(a,b)    a>b?a:b;
#define min(a,b)    a>b?b:a;
#define inf 0x3f3f3f3f
int dp[maxn][maxn][maxn];
char map[maxn][maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(map,'#',sizeof(map));
        int r,c;
        scanf("%d%d",&c,&r);
        for(int i = 0;i < r;i++)
            scanf("%s",map[i]);
        int len = r+c-2;
        for(int i = 0;i <= len;i++)
            for(int j = 0;j < r;j++)
                for(int k = 0;k < r;k++)
                    dp[i][j][k] = -inf;
        dp[0][0][0] = (map[0][0] == '*'?1:0);
        for(int i = 0;i <= c;i++)    map[r][i] = '#';
        for(int i = 0;i <= r;i++)    map[i][c] = '#';
        for(int k = 0;k < len;k++)
        {
            for(int i = 0;i <= k;i++)
            {
                if(i >= r)    break;
                if(k - i >= c)    continue;
                for(int j = 0;j <= k;j++)
                {
                    if(j >= r)    break;
                    if(k - j >= c)    continue;
                    if(dp[k][i][j] < 0 || map[i][k-i] == '#' || map[j][k-j] == '#')    continue;
                    if(map[i+1][k-i] != '#' && map[j+1][k-j] != '#')
                    {
                        int key = dp[k][i][j]+(map[i+1][k-i]=='*')+(map[j+1][k-j]=='*');
                        if(i == j && map[i+1][k-i] == '*')    key--;                
                        dp[k+1][i+1][j+1] = max(dp[k+1][i+1][j+1],key);
                    }
                    if(map[i+1][k-i] != '#' && map[j][k+1-j] != '#')
                    {
                        int key = dp[k][i][j]+(map[i+1][k-i]=='*')+(map[j][k+1-j]=='*');
                        if(i+1 == j && map[i+1][k-i] == '*')    key--;
                        dp[k+1][i+1][j] = max(dp[k+1][i+1][j],key);
                    }
                    if(map[i][k+1-i] != '#' && map[j+1][k-j] != '#')
                    {
                        int key = dp[k][i][j]+(map[i][k+1-i]=='*')+(map[j+1][k-j]=='*');
                        if(i == j+1 && map[i][k+1-i] == '*')    key--;
                        dp[k+1][i][j+1] = max(dp[k+1][i][j+1],key);
                    }
                    if(map[i][k+1-i] != '#' && map[j][k+1-j] != '#')
                    {
                        int key = dp[k][i][j]+(map[i][k+1-i]=='*')+(map[j][k+1-j]=='*');
                        if(i == j && map[i][k+1-i] == '*')    key--;            
                        dp[k+1][i][j] = max(dp[k+1][i][j],key);
                    }
                }
            }
        }
        if(dp[r+c-2][r-1][r-1] < 0)    dp[r+c-2][r-1][r-1] = 0;
        printf("%d\n",dp[r+c-2][r-1][r-1]);
    }
    return 0;
}
