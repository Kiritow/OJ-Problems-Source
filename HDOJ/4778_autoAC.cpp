#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1 << 21;
bool vis[N];
int n,g,s,dp[N],score[N],a[22][9];
void get_score()
{
    int sum[9];
    for(int mask=0;mask<(1<<n);mask++)
    {
        memset(sum,0,sizeof(sum));
        for(int i=0;i<n;i++)
            if(mask >> i & 1 ^ 1)
                for(int j=1;j<=g;j++)
                    sum[j] += a[i][j];
        int ans = 0;
        for(int j=1;j<=g;j++)
            ans += sum[j] / s;
        score[mask] = ans;
    }
}
int dfs(int mask)
{
    if(vis[mask])
        return dp[mask];
    vis[mask] = true;
    int ret = 0;
    for(int i=0;i<n;i++)
        if(mask >> i & 1)
        {
            int __mask = mask ^ (1 << i);
            int _delta = score[__mask] - score[mask];
            if(_delta > 0)
                ret = max(ret,_delta + dfs(__mask));
            else
                ret = max(ret,score[0] - score[mask] - dfs(__mask));
        }
    return dp[mask] = ret;
}
int main()
{
    while(~scanf("%d%d%d",&g,&n,&s),g||n||s)
    {
        memset(vis,false,sizeof(vis));
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            int num,color;
            scanf("%d",&num);
            while(num--)
            {
                scanf("%d",&color);
                a[i][color]++;
            }
        }
        get_score();
        printf("%d\n",2*dfs((1<<n)-1)-score[0]);
    }
    return 0;
}
