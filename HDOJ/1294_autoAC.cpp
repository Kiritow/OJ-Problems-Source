#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
typedef long long LL;
const double pi=acos(-1.0);
int n;
LL dp[40][40];
LL calc(LL n,int m)
{    
    LL ans=1;
    LL tmp=n+m-1;
    for(int i=1;i<=m;i++)
    {
        ans*=tmp;
        ans/=i;
        tmp--;
    }
    return ans;
}
LL dfs(int n,int mx)
{
    if(n<mx) return 0;
    if(n && !mx) return 0;
    if(!n && mx) return 0;
    if(!n) return 1;
    LL &ans=dp[n][mx];
    if(ans!=-1) return ans;
    ans=0;
    LL tmp=0;
    for(int i=0;i<mx;i++)
    {
        tmp+=dfs(mx-1,i);
    }
    for(int i=1;i*mx<=n;i++) 
    {
        LL ans1=calc(tmp,i); 
        LL ans2=0;
        for(int j=mx-1;j>=0;j--)
        {
            ans2+=dfs(n-i*mx,j);
        }
        ans+=ans1*ans2;
    }
    return ans;
}
int main()
{
    memset(dp,-1,sizeof dp);
    while(scanf("%d",&n)==1)
    {
        LL ans=0;
        for(int i=n-1;i>=0;i--)
        {
            ans+=dfs(n-1,i);
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
