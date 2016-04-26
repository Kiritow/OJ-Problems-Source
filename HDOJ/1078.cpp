#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 101
int map[MAXN][MAXN];
int dp[MAXN][MAXN];
int N;
int K;
int dfs(int y,int x)
{
    if(dp[y][x]!=0) return dp[y][x];
    dp[y][x]=map[y][x];
    for(int i=1;i<=K;i++)
    {
        if(x+i<N&&map[y][x]<map[y][x+i])
        {
            dp[y][x]=max(dp[y][x],dfs(y,x+i)+map[y][x]);
        }
        if(x-i>=0&&map[y][x]<map[y][x-i])
        {
            dp[y][x]=max(dp[y][x],dfs(y,x-i)+map[y][x]);
        }
        if(y+i<N&&map[y][x]<map[y+i][x])
        {
            dp[y][x]=max(dp[y][x],dfs(y+i,x)+map[y][x]);
        }
        if(y-i>=0&&map[y][x]<map[y-i][x])
        {
            dp[y][x]=max(dp[y][x],dfs(y-i,x)+map[y][x]);
        }
    }
    return dp[y][x];
}

int main()
{
    int n,k;
    while(scanf("%d %d",&n,&k)==2&&n!=-1&&k!=-1)
    {
        memset(dp,0,sizeof(int)*MAXN*MAXN);
        memset(map,0,sizeof(int)*MAXN*MAXN);
        N=n;
        K=k;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                scanf("%d",&map[i][j]);
            }
        }
        int ans=dfs(0,0);
        printf("%d\n",ans);
    }
    return 0;
}
