#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int mod = 1000000007;
typedef long long LL;
LL dp[2][8];
int f[51][51];
int main()
{
    int T,N,M,K,l,now;
    LL tmp;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        LL ans=0;
        scanf("%d%d",&N,&M);
        memset(f,0,sizeof f);
        for(int i=0;i<M;i++){
            scanf("%d",&K);
            for(int j=0;j<K;j++){
                scanf("%d",&l);
                f[i][l-1]++;
            }
        }
        for(int i=0;i<N;i++){
            for(int j=i;j<N;j++){
                for(int k=j;k<N;k++){
                    memset(dp,0,sizeof dp);
                    dp[0][0]=1;
                    now=1;
                    for(int s=0;s<M;s++,now^=1){
                        tmp=0;
                        if(f[s][i]) tmp|=1;
                        if(f[s][j]) tmp|=2;
                        if(f[s][k]) tmp|=4;
                        for(int t=0;t<8;t++){
                            dp[now][t]=dp[now^1][t];
                            dp[now][t]+=dp[now^1][t^tmp];
                            dp[now][t]%=mod;
                        }
                    }
#define u dp[now^1][7]
                    tmp = u;
                    if(i!=j&&j!=k) u*=6;
                    else if(i==j&&j==k) ;
                    else u*=3;
                    ans=(ans+u)%mod;
                }
            }
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
