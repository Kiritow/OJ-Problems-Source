#include <iostream>
#include <cstdio>
using namespace std;
double dp[3][3][1002],map[3][3];
double DFS(int i,int j,int n){
    if(dp[i][j][n]!=-1) return dp[i][j][n];
    dp[i][j][n] = 0;
    for(int k = 0;k<3;k++)
       dp[i][j][n]+=DFS(i,k,n-1)*map[k][j];
    return dp[i][j][n];
}
int main(){
    int T,m,a,b,n;
    scanf("%d",&T);
    while(T--){
        for(int i = 0;i<3;i++)
        for(int j = 0;j<3;j++)
        for(int k = 0;k<1002;k++)
            dp[i][j][k] = -1;
        for(int i = 0;i<3;i++)
        for(int j = 0;j<3;j++){
             scanf("%lf",&map[i][j]);
             dp[i][j][1] = map[i][j];
        }
        scanf("%d",&m);
        for(int i = 0;i<m;i++){
             scanf("%d%d%d",&a,&b,&n);
             printf("%.3lf\n",DFS(a-1,b-1,n));
        }
    }
    return 0;
}
