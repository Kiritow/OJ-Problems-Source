#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1<<29
#define LL long long
#define MOD 1000000007
using namespace std;
int dp[41][41][5][5][5][5][2];
int get_dp(int x,int y,int l,int r,int u,int d,int k){
    if(dp[x][y][l][r][u][d][k]!=-1)
        return dp[x][y][l][r][u][d][k];
    dp[x][y][l][r][u][d][k]=0;
    if((x==1&&k==0)||(y==1&&k)){
        for(int i=1;i<5;i++)
           if(i!=l&&i!=r&&i!=u&&i!=d)
               dp[x][y][l][r][u][d][k]++;
        return dp[x][y][l][r][u][d][k];
    }
    dp[x][y][l][r][u][d][k]=0;
    if(!k){
        for(int i=1;i<x;i++)
            for(int j=1;j<5;j++){
                if(j!=u&&j!=l&&j!=r)
                    dp[x][y][l][r][u][d][k]=(dp[x][y][l][r][u][d][k]+get_dp(x-i,y,l,r,j,d,1))%MOD;
                if(j!=d&&j!=l&&j!=r)
                    dp[x][y][l][r][u][d][k]=(dp[x][y][l][r][u][d][k]+get_dp(i,y,l,r,u,j,1))%MOD;
            }
        int t=0;
        for(int i=1;i<=4;i++)
            if(i!=u&&i!=l&&i!=r)
                for(int j=1;j<=4;j++)
                    if(j!=d&&j!=l&&j!=r&&j!=i)
                       t++;
        dp[x][y][l][r][u][d][k]=(dp[x][y][l][r][u][d][k]+MOD-t*(x-1))%MOD;
        for(int i=1;i<5;i++)
            if(i!=l&&i!=r&&i!=u&&i!=d)
                dp[x][y][l][r][u][d][k]++;
    }
    else{
        for(int i=1;i<y;i++)
            for(int j=1;j<5;j++){
                if(j!=l&&j!=d&&j!=u)
                    dp[x][y][l][r][u][d][k]=(dp[x][y][l][r][u][d][k]+get_dp(x,y-i,j,r,u,d,0))%MOD;
                if(j!=r&&j!=d&&j!=u)
                    dp[x][y][l][r][u][d][k]=(dp[x][y][l][r][u][d][k]+get_dp(x,i,l,j,u,d,0))%MOD;
            }
        int t=0;
        for(int i=1;i<=4;i++)
            if(i!=l&&i!=u&&i!=d)
                for(int j=1;j<=4;j++)
                   if(j!=r&&j!=u&&j!=d&&j!=i)
                      t++;
        dp[x][y][l][r][u][d][k]=(dp[x][y][l][r][u][d][k]+MOD-t*(y-1))%MOD;
        for(int i=1;i<5;i++)
            if(i!=l&&i!=r&&i!=u&&i!=d)
                dp[x][y][l][r][u][d][k]++;
    }
    return dp[x][y][l][r][u][d][k]%MOD;
}
int main(){
    memset(dp,-1,sizeof(dp));
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",get_dp(x,y,0,0,0,0,0));
    }
    return 0;
}
