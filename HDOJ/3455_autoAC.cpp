#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<limits.h>
typedef long long LL;
using namespace std;
const int INF=0x3f3f3f;
const int maxn=1e5+100;
int dp[maxn][15];
int ha[10*maxn];
int num[maxn],n;
int main()
{
    while(~scanf("%d",&n)&&n)
    {
        memset(dp,INF,sizeof(dp));
        memset(ha,-1,sizeof(ha));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            ha[num[i]]=i;
        }
        dp[2][num[2]-num[1]]=0;
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<=10;j++)
            {
                if(j>num[i])  break;
                for(int k=j+1;k<=10;k++)
                {
                    int tt=num[i]-j;
                    if(ha[tt]>=0)
                        dp[i][j]=min(dp[ha[tt]][k-j]+1,dp[i][j]);
                }
            }
        }
        int ans=INF;
        for(int i=1;i<=10;i++)
            ans=min(ans,dp[n][i]);
        if(ans<INF) printf("%d\n",ans);
        else   printf("-1\n");
    }
    return 0;
}
