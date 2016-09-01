#include <stdio.h>
#include <string.h>
#define Min(a,b) a<b?a:b;
int s[1005],ss[1005],ans[1005][1005],dp[1005];
int main(){
    int n,m,i,j,k;
    while(~scanf("%d%d",&n,&m),(n+m)){
        memset(dp,0,sizeof(dp));
        memset(ans,0,sizeof(ans));
        ss[0]=0;
        for(i=0;i<n;i++){
            scanf("%d",&s[i]);
            ss[i+1]=ss[i]+s[i];
        }
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++)
                ans[i][j]=ans[i][j-1]+s[j]*(ss[j]-ss[i]);
        }
        for(i=0;i<n;i++)
            dp[i]=ans[0][i];
        for(i=0;i<m;i++){
            for(j=n-1;j>=0;j--){
                for(k=i-1;k<j;k++)
                    dp[j]=Min(dp[j],dp[k]+ans[k+1][j]);
            }
        }
        printf("%d\n",dp[n-1]);
    }
    return 0;
}
