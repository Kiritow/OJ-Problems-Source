#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <string>
#include <ctime>
#include <list>
#include <bitset>
typedef unsigned char byte;
#define pb push_back
#define input_fast std::ios::sync_with_stdio(false);std::cin.tie(0)
#define pi acos(-1)
using namespace std;
const int maxn = 30 + 10;
int dp[maxn][maxn][2000];
int g[maxn][maxn] , n , m , px ,dir[2][2] = {0,1,1,0},tans;
int cal(int x,int y)
{
    return px*x - y*y;
}
bool inmap(int x,int y)
{
    return x <= n && x >= 1 && y <= m && y >= 1;
}
void initiation()
{
    tans = 1 << 29;
    scanf("%d%d",&n,&m);
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= m ; ++ j)
            scanf("%d",&g[i][j]);
    px = n + m - 1;
    memset(dp,-1,sizeof(dp));
    dp[1][1][g[1][1]] = g[1][1]*g[1][1];
}
void updata(int &x ,int v)
{
    if(x==-1) x=v;
    else x = min(x,v);
}
int solve()
{
    for(int i = 1 ; i <= n ; ++ i)
        for(int j = 1 ; j <= m ; ++ j)
        {
            for(int z = 0 ; z <= 1900 ; ++ z)
            {
                if(dp[i][j][z] == -1) continue;
                for(int k = 0 ; k < 2 ; ++ k)
                {
                    int newx = i + dir[k][0];
                    int newy = j + dir[k][1];
                    if(!inmap(newx,newy)) continue;
                    int newval = dp[i][j][z] + g[newx][newy]*g[newx][newy];
                    updata(dp[newx][newy][z+g[newx][newy]],newval);
                }
            }
        }
    int ans = 1 << 30;
    for(int i = 0 ; i <= 1900 ; ++ i) if(dp[n][m][i] != -1) ans = min(ans , px*dp[n][m][i] - i*i);
    return ans;
}
void dfs(int x,int y,int s1,int s2)
{
    if(x==n&&y==m)
    {
        tans =min(tans,s1*px-s2*s2);
    }
    else
    {
            for(int k = 0 ; k < 2 ; ++ k)
            {
                int newx = x + dir[k][0];
                int newy = y + dir[k][1];
                if(!inmap(newx,newy)) continue;
                dfs(newx,newy,s1+g[newx][newy]*g[newx][newy],s2+g[newx][newy]);
            }
    }
}
int main(int argc,char *argv[])
{
    int Case,cas=1;
    scanf("%d",&Case);
    while(Case--)
    {
        initiation();
        printf("Case #%d: %d\n",cas++,solve());
    }
    return 0;
}
