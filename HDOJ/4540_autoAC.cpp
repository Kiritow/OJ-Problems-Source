#include<iostream>
const int inf=1<<30;
using namespace std;
int map[22][22];
int dp[22][22];
int n,m;
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                scanf("%d",&map[i][j]);
                dp[i][j]=inf;
            }
        }
        for(int i=1;i<=m;i++){
            dp[1][i]=0;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=m;k++){
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(map[i][j]-map[i-1][k]));
                }
            }
        }
        int ans=inf;
        for(int i=1;i<=m;i++){
            ans=min(ans,dp[n][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
