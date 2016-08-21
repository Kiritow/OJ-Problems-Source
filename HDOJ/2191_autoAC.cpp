#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string.h>
using namespace std;
int value[105],weight[105],num[105],dp[1050];
int n,t,m;
int main(){
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&value[i],&weight[i],&num[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=num[i];j*=2)
            {
                for(int k=m;k>=value[i]*j;k--)
                    dp[k]=max(dp[k],dp[k-value[i]*j]+weight[i]*j);
                   num[i]-=j;
            }
            for(int k=m;k>=value[i]*num[i];k--)
                    dp[k]=max(dp[k],dp[k-value[i]*num[i]]+weight[i]*num[i]);
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}
