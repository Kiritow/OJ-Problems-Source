#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
const int N = 1005;
#define LL __int64
int n,q,a[N],l,r,dp[N][N];
int main()
{
    while(scanf("%d%d",&n,&q)>0){
        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        for(int k=1; k<n; k++)
        for(int i=1; i+k<=n; i++){
            int j=i+k;
            dp[i][j]=dp[i][j-1]+dp[i+1][j]-dp[i+1][j-1];
            if(a[i]>a[j])
                dp[i][j]++;
        }
        while(q--){
            scanf("%d%d",&l,&r);
            printf("%d\n",dp[l][r]);
        }
    }
    return 0;
}
