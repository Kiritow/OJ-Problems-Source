#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll dp[55][55][55][5][55];
int n1,n2,n3,d1,d2,d3;
ll dfs(int a,int b,int c,int t,int e)
{
    if(a<0||b<0||c<0)
        return 0;
    if(t==0&&e>d1||t==1&&e>d2||t==2&&e>d3)
        return 0;
    if(a==0&&b==0&&c==0)
        return 1;
    if(dp[a][b][c][t][e]!=-1)
        return dp[a][b][c][t][e];
    ll ans=0;
    if(t==0)
    {
        ans=(ans+dfs(a-1,b,c,0,e+1))%mod;
        ans=(ans+dfs(a,b-1,c,1,1))%mod;
        ans=(ans+dfs(a,b,c-1,2,1))%mod;
        return dp[a][b][c][t][e]=ans;
    }
    if(t==1)
    {
        ans=(ans+dfs(a-1,b,c,0,1))%mod;
        ans=(ans+dfs(a,b-1,c,1,e+1))%mod;
        ans=(ans+dfs(a,b,c-1,2,1))%mod;
        return dp[a][b][c][t][e]=ans;
    }
    if(t==2)
    {
        ans=(ans+dfs(a-1,b,c,0,1))%mod;
        ans=(ans+dfs(a,b-1,c,1,1))%mod;
        ans=(ans+dfs(a,b,c-1,2,e+1))%mod;
        return dp[a][b][c][t][e]=ans;
    }

}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d%d%d%d%d%d",&n1,&n2,&n3,&d1,&d2,&d3);
        memset(dp,-1,sizeof(dp));
        ll ans=0;
            ans=(ans+dfs(n1-1,n2,n3,0,1))%mod;
            ans=(ans+dfs(n1,n2-1,n3,1,1))%mod;
            ans=(ans+dfs(n1,n2,n3-1,2,1))%mod;
        cout<<ans<<endl;
    }
    return 0;
}
