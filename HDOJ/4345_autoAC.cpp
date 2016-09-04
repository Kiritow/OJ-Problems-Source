#include<stdio.h>
#include<string.h>
const int MAXN=1100;
int prime[MAXN+1];
int getPrime()
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=MAXN;i++)
    {
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
    return prime[0];
}
long long dp[MAXN][MAXN];
long long DP(int n,int i) 
{
    if(dp[n][i]!=-1)return dp[n][i];
    if(prime[i]>n)
    {
        dp[n][i]=1;
        return dp[n][i];
    }
    int k=0;
    dp[n][i]=0;
    while(k<=n)
    {
        dp[n][i]+=DP(n-k,i+1);
        if(k==0)k=prime[i];
        else k*=prime[i];
    }
    return dp[n][i];
}
int main()
{
    getPrime();
    memset(dp,-1,sizeof(dp));
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%I64d\n",DP(n,1));
    }
    return 0;
}
