#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NN 5010
#define Min(a,b) (a>b?b:a)
int set[NN];
int dp[1010][NN];
int main()
{
    int t,k,n,i,j;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&k,&n);
        k += 8;
        for(i=n;i>=1;i--)
            scanf("%d",&set[i]);
        for(i=1;i<=k;i++){
            dp[i][i*3] = dp[i-1][i*3-2] + (set[i*3-1] - set[i*3])*(set[i*3-1] - set[i*3]);
            for(j=i*3+1;j<=n;j++)
                dp[i][j] = Min(dp[i][j-1],dp[i-1][j-2] +(set[j-1] -set[j])*(set[j-1] - set[j]));
        }
        printf("%d\n",dp[k][n]);
    }
    return 0;
}
