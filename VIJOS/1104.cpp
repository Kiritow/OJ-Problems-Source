#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 1005
int dp[MAXN];
int cost[MAXN];
int value[MAXN];
int main()
{
    int t,m;
    scanf("%d %d",&t,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d",&cost[i],&value[i]);
    }
    for(int i=0;i<m;i++)
    {
        for(int j=t;j>0;j--)
        {
            if(j-cost[i]>=0)
            dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);
        }
    }
    printf("%d\n",dp[t]);
    return 0;
}
