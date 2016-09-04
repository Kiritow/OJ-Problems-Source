#include<cstdio>
#include<cmath>
#include<stack>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
#define clr(x) memset(x,0,sizeof(x))
long long dp[31][31];
bool inti(){
    clr(dp);
    for(int i=0;i<=30;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=30;i++){
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    return true;
}
int main(){
    inti();
    int i,j,k,m,n;
    while(cin>>n&&n){
        cout<<dp[n][n]<<endl;
    }
    return 0;
}
