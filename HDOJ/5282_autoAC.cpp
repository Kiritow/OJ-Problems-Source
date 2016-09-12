#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define MAX_N 1100
char a[MAX_N],b[MAX_N];
int dp[MAX_N+1][MAX_N+1];
int dd[MAX_N+1][MAX_N+1];
int wei[MAX_N+1][26];
__int64 f[MAX_N+1][MAX_N+1];
int mod=1e9+7;
int main()
{
    int n,m,tem,t;
    scanf("%d",&t);
    while(t--) 
    {
        scanf("%s%s",a,b);
        memset(dp,0,sizeof(dp)); 
        n=strlen(a);
        m=strlen(b);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i]==b[j]) 
                    dp[i+1][j+1]=max(dp[i][j]+1,max(dp[i+1][j],dp[i][j+1])); 
                else 
                    dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]); 
            }
        }  
        memset(wei,0,sizeof wei); 
        for(int i=1;i<=m;i++)
        {
            for(int j=0;j<26;j++)
                wei[i][j]=wei[i-1][j];
            wei[i][b[i-1]-'a']=i;
        } 
        memset(f,0,sizeof f);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(dp[i][j]==0)
                {
                    f[i][j]=1;
                    continue;
                }
                if(dp[i-1][j]==dp[i][j]) 
                    f[i][j]=(f[i][j]+f[i-1][j])%mod;
                int p=wei[j][a[i-1]-'a'];
                if(p)
                {
                    if(dp[i-1][p-1]+1==dp[i][j])
                        f[i][j]=(f[i][j]+f[i-1][p-1])%mod;
                }
            }
        }
        printf("%I64d\n",f[n][m]%mod);
    }
    return 0;
}
