#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
const int maxn=1001;
const int maxs=101;
int dp[maxs][maxn];
int data[maxn];
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    int n,s,la,lb;
    while(scanf("%d",&n)&&n){
        scanf("%d%d%d",&lb,&la,&s);
        memset(dp,0,sizeof(dp));
        int i,j,k;
        for(i=1;i<=n;i++){
            scanf("%d",&data[i]);
            dp[0][i]=data[i];
            dp[0][i]+=dp[0][i-1];
        }
        for(i=1;i<=s;i++){
            for(j=1;j<=n;j++){
                dp[i][j]=dp[i][j-1]+data[j];
                for(k=la;k<=lb && k<=j;k++){
                    dp[i][j]=min(dp[i][j],dp[i-1][j-k]);
                }
            }
        }
        int ans=1<<30;
        for(i=0;i<=s;i++){
            ans=min(dp[s][n],ans);
        }
        printf("%d\n",ans);
    }
    return 0;
}
