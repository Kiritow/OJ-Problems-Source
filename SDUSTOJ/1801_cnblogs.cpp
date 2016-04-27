/* ***********************************************
Author        :devil
Created Time  :2016/4/26 22:18:57
************************************************ */
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <stdlib.h>
using namespace std;
typedef long long LL;
const int N=110;
const int mod=1e9+9;
LL dp[N][N],dp2[N][N];
int a[N],b[N];
int main()
{
    //freopen("in.txt","r",stdin);
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        memset(dp2,0,sizeof(dp2));
        memset(b,-1,sizeof(b));
        b[a[1]]=dp[a[1]][1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[a[i]][1]=1;
            int mi=min(i,m);
            for(int k=2;k<=mi;k++)
            {
                for(int j=1;j<a[i];j++)
                {
                    dp[a[i]][k]+=dp[j][k-1];
                    if(dp[a[i]][k]>=mod) dp[a[i]][k]-=mod;
                }
                if(b[a[i]]!=-1)
                {
                    dp[a[i]][k]-=dp2[a[i]][k];
                    if(dp[a[i]][k]<0) dp[a[i]][k]+=mod;
                }
                dp2[a[i]][k]=dp[a[i]][k];
            }
            b[a[i]]=i;
        }
        LL ans=0;
        for(int i=1;i<=n;i++)
            ans=(ans+dp[i][m])%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
