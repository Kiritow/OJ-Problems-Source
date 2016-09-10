#include<stdio.h>
#include<string.h>
#include<math.h>
#define ll long long 
#define max(a,b) a>b?a:b
int dp[320][50005];
int main(){
    int T;
    while(scanf("%d",&T)!=EOF){
        for(int q=1;q<=T;q++){
            int n,mod,ans=0;
            scanf("%d%d",&n,&mod);
            memset(dp,0,sizeof(dp));
            int m=(sqrt(8.0*n+1)-1)/2;
            int i,j;
            dp[0][0]=1;
            for(i=1;i<=m;i++){
                for(j=0;j<=n;j++){
                    if(i>j)dp[i][j]=0;
                    else dp[i][j]=(dp[i-1][j-i]+dp[i][j-i])%mod;
                    if(j==n)ans=(ans+dp[i][j])%mod;
                }
            }
            printf("Case #%d: %d\n",q,ans);
        }
    }
    return 0;
}
