#include <bits/stdc++.h>
#pragma warning(disable:4786)//使命名长度不受限制
#pragma comment(linker, "/STACK:102400000,102400000")//手工开栈
#define maxn 52
#define mod 1000000007
using namespace std;
int dp[maxn][maxn][maxn][3][maxn];
int A,B,C,a,b,c,sum;
inline int dfs(int x,int y,int z,int t,int n){
    if(x>A||y>B||z>C||x+y+z>sum)return 0;
    if(t==0&&n>a||t==1&&n>b||t==2&&n>c)return 0;
    if(dp[x][y][z][t][n]!=-1)return dp[x][y][z][t][n];
    if(x+y+z==sum)return 1;
    int ans=0;
    if(t==0){
        ans=(ans+dfs(x+1,y,z,0,n+1))%mod;
        ans=(ans+dfs(x,y+1,z,1,1))%mod;
        ans=(ans+dfs(x,y,z+1,2,1))%mod;
        return dp[x][y][z][t][n]=ans;
    }
    if(t==1){
        ans=(ans+dfs(x+1,y,z,0,1))%mod;
        ans=(ans+dfs(x,y+1,z,1,n+1))%mod;
        ans=(ans+dfs(x,y,z+1,2,1))%mod;
        return dp[x][y][z][t][n]=ans;
    }
    if(t==2){
        ans=(ans+dfs(x+1,y,z,0,1))%mod;
        ans=(ans+dfs(x,y+1,z,1,1))%mod;
        ans=(ans+dfs(x,y,z+1,2,n+1))%mod;
        return dp[x][y][z][t][n]=ans;
    }
}
int main(){
    int loop;
    scanf("%d",&loop);
    for(;loop--;){
        scanf("%d%d%d%d%d%d",&A,&B,&C,&a,&b,&c);
        sum=A+B+C;
        memset(dp,-1,sizeof(dp));
        int ans=0;
        ans=(ans+dfs(1,0,0,0,1))%mod;
        ans=(ans+dfs(0,1,0,1,1))%mod;
        ans=(ans+dfs(0,0,1,2,1))%mod;
        printf("%d\n",ans);
    }
    return 0;
}
