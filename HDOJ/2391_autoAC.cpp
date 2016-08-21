#include<iostream>
#include<string.h>
#include <cstdio>
#include <cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cstdlib>
using namespace std;
const int maxn=1001;
int va[maxn][maxn];
int dp[maxn][maxn];
int maxx(int a,int b,int c){
    int sum=a>b?a:b;
    sum=sum>c?sum:c;
    return sum;
}
int main()
{
    int t,r,c;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        scanf("%d%d",&r,&c);
        memset(va,0,sizeof(va));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                scanf("%d",&va[i][j]);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                dp[i][j]=maxx(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])+va[i][j];
            }
        cout<<"Scenario #"<<k<<":"<<endl;            
        cout<<dp[r][c]<<endl;
        cout<<endl;    
    }
    return 0;
}
