#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
int dp[15][1<<15];
int sum[1<<15];
int sub[1<<15];
int L[15],R[15],n;
int cal(int S){
   int num=0;
   for(int i=0; i<n; ++i)
     if(S&(1<<i)) num++;
   return num;
}
int main()
{
     int cas;
     scanf("%d",&cas);
     for(int cc= 1; cc<=cas; ++cc){
         scanf("%d",&n);
         for(int i=0; i<n; ++i)
            scanf("%d%d",&L[i],&R[i]);
         for(int i=0; i<n; ++i){
             dp[i][0]=1;
         }
         sum[0]=1; sub[0]=1;
         for(int S=1; S<(1<<n); ++S){
                sum[S]=0; sub[S]=0;
              int ge = cal(S);
              for(int i =0; i<n; ++i){
                dp[i][S]=0;
                if( ( S&(1<<i) )!=0 && L[i]<=ge&&R[i]>=ge ){
                    dp[i][S]= sub[S^(1<<i)];
                    sum[S]= (dp[i][S]+sum[S])%mod;
                }
              }
              int j=0;
              for( j=0; j<n; ++j ) if(S&(1<<j)) break;
              for(int H=S; H>0; H=S&(H-1)){
                    if((H&(1<<j))==0) continue;
                    ll a = sum[H];
                    ll b = sub[S^H];
                    sub[S]= ( sub[S] + a*b%mod )%mod;
              }
         }
         int ans=0;
         for(int i=0; i<n; ++i) ans=(ans+ dp[i][(1<<n)-1])%mod;
         printf("%d\n",ans);
     }
    return 0;
}
