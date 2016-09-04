#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1004;
int dp[maxn][maxn];
int data[maxn][2];
int main(){
    int n,a,b;
    while(scanf("%d",&n)!=EOF){
        memset(dp,0,sizeof(dp));
        for(int i=4;i<=n;i++){
            scanf("%d%d",&a,&b);
            data[i][0]=a;
            data[i][1]=b;
        }
        int ans=0;
        for(int i=n;i>=4;i--){
            a=data[i][0];
            b=data[i][1];
            ans=max(ans,dp[a][b]+dp[a][i]+dp[i][b]+3);
            dp[a][b]=dp[b][a]=max(dp[a][b],dp[a][i]+dp[i][b]+1);
        }
        printf("%d\n",max(ans,dp[1][2]+dp[2][3]+dp[1][3]+3));
    }
    return 0;
}
