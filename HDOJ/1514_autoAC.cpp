#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
const int candy_num = 40 + 5;
const int basket_num = 5 + 2;
int dp[candy_num][candy_num][candy_num][candy_num];
int h[basket_num], f[candy_num][basket_num];
int ans, n;
set<int> S;
set<int> ::iterator it;
int check(int a)
{
    it = S.find(a);
    if (it != S.end())  
    {
        S.erase(a);
        return 1;
    }
    S.insert(a);   
    return 0;
}
int dfs(int tmp)
{
    if (dp[h[0]][h[1]][h[2]][h[3]] != -1)  
        return dp[h[0]][h[1]][h[2]][h[3]];
    int tt = 0;
    for (int i = 0; i < 4; i++)  
    {
        if (h[i] < n && S.size() < 5)
        {
            int t = check(f[h[i]][i]);
            if (S.size() < 5)
            {
                h[i]++;   
                tt = max(tt, dfs(tmp+t));   
                h[i]--;
            }
            tt = max(tt, tmp+t);     
            if (t == 1)               
                S.insert(f[h[i]][i]);
            else
                S.erase(f[h[i]][i]);
        }
    }
    return dp[h[0]][h[1]][h[2]][h[3]] = tt;
}
int main()
{
    while (scanf("%d", &n) != EOF && n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
                scanf("%d", &f[i][j]);
        }
        ans = 0;
        h[0] = h[1] = h[2] = h[3] = 0;
        memset(dp, -1, sizeof(dp));
        printf("%d\n", dfs(0));
    }
    return 0;
}
