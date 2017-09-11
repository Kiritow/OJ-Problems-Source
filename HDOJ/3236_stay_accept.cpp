
#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
int dp[505][55][2];
struct node{
    int v,w;
};
int main(){
    int V1,V2,i,j,a,b,c,k,n,ans,cas,sum,pre,sign;
    cas=1;                                      //二维带限制条件的01背包
    while(scanf("%d%d%d",&V1,&V2,&n)!=EOF&&(V1||V2||n)){
        vector<node> G[2];                      //dp[i][j][0]代表容量是i和j，没有用免费机会时的最大值
        memset(dp,-1,sizeof(dp));               //dp[i][j][0]代表容量是i和j，用免费机会时的最大值
        for(i=0;i<n;i++){
            scanf("%d%d%d",&a,&b,&c);
            G[c].push_back((node){a,b});
        }
        sum=dp[0][0][0]=0;
        for(i=0;i<G[1].size();i++){
            pre=sum;                            //只有前一个的值是pre才能
            sum+=G[1][i].w;                     //继续往里装
            for(j=V1;j>=0;j--){
                for(k=V2;k>=0;k--){
                    if(dp[j][k][0]==pre)        
                    dp[j][k][1]=sum;
                    if(j>=G[1][i].v){
                        if(dp[j-G[1][i].v][k][1]==pre)
                        dp[j][k][1]=sum;
                        if(dp[j-G[1][i].v][k][0]==pre)
                        dp[j][k][0]=sum;
                    }
                    if(k>=G[1][i].v){
                        if(dp[j][k-G[1][i].v][1]==pre)
                        dp[j][k][1]=sum;
                        if(dp[j][k-G[1][i].v][0]==pre)
                        dp[j][k][0]=sum;
                    }
                }
            }
        }
        sign=0;
        for(i=0;i<=V1;i++)
        for(j=0;j<=V2;j++)
        for(k=0;k<=1;k++){
            if(dp[i][j][k]!=sum)
            dp[i][j][k]=-1;
            else
            sign=1;
        }
        if(!sign){
            printf("Case %d: -1\n\n",cas++);
            continue;
        }                                       //看是否能装满特殊物品
        for(i=0;i<G[0].size();i++){
            for(j=V1;j>=0;j--){
                for(k=V2;k>=0;k--){
                    if(dp[j][k][0]!=-1)         //要放在最前面，避免了重复装入
                    dp[j][k][1]=max(dp[j][k][1],dp[j][k][0]+G[0][i].w);
                    if(j>=G[0][i].v){
                        if(dp[j-G[0][i].v][k][1]!=-1)
                        dp[j][k][1]=max(dp[j][k][1],dp[j-G[0][i].v][k][1]+G[0][i].w);
                        if(dp[j-G[0][i].v][k][0]!=-1)
                        dp[j][k][0]=max(dp[j][k][0],dp[j-G[0][i].v][k][0]+G[0][i].w);
                    }
                    if(k>=G[0][i].v){
                        if(dp[j][k-G[0][i].v][1]!=-1)
                        dp[j][k][1]=max(dp[j][k][1],dp[j][k-G[0][i].v][1]+G[0][i].w);
                        if(dp[j][k-G[0][i].v][0]!=-1)
                        dp[j][k][0]=max(dp[j][k][0],dp[j][k-G[0][i].v][0]+G[0][i].w);
                    }
                }
            }
        }
        ans=0;
        for(i=0;i<=V1;i++)
        for(j=0;j<=V2;j++)
        for(k=0;k<=1;k++)
        ans=max(ans,dp[i][j][k]);
        printf("Case %d: %d\n\n",cas++,ans);
    }
    return 0;
}

