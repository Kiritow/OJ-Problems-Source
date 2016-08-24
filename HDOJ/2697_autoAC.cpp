#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N =110;
int a[N];
int dp[N][N];
int main(){
    int t;
    int n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=0;j<=m;j++){
                int cnt=0;
                int sum=0;
                dp[i][j]=dp[i-1][j];
                for(int h=i;h>=1;h--){
                    cnt++;
                    sum+=a[h];
                    if(sum>j) break;
                    dp[i][j]=max(dp[i][j],dp[h-1][j-sum]+cnt*cnt);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
