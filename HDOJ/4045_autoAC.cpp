#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
#define eps 1e-7
#define MOD 1000000007
using namespace std;
int c[2001][2001]={1},stir2[1005][1005]={1};
int main(){
    for(int i=1;i<=2000;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    }
    for(int i=1;i<=1000;i++){
        stir2[i][0]=0;
        stir2[i][i]=1;
        for(int j=1;j<i;j++)
            stir2[i][j]=((LL)j*stir2[i-1][j]+stir2[i-1][j-1])%MOD;
    }
    int n,r,k,m;
    while(cin>>n>>r>>k>>m){
        int sum=0;
        if(n-((r-1)*k+1)<0){
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=min(r,m);i++)
            sum=(sum+stir2[r][i])%MOD;
        cout<<((LL)c[n-((r-1)*k+1)+r+1-1][r]*sum)%MOD<<endl;
    }
    return 0;
}
