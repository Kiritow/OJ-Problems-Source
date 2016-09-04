#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define eps 1e-7
#define LL long long
using namespace std;
LL fac[21]={1};
LL stir1[21][21];
int main(){
    for(int i=1;i<21;i++)
        fac[i]=fac[i-1]*i;
    for(int i=1;i<=20;i++){
        stir1[i][0]=0;
        stir1[i][i]=1;
       for(int j=1;j<i;j++)
           stir1[i][j]=stir1[i-1][j-1]+(i-1)*stir1[i-1][j];
    }
    int t,n,k;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);
        if(n==1||k==0){
            printf("0.0000\n");
            continue;
        }
        LL sum=0;
        for(int i=1;i<=k;i++)
            sum+=stir1[n][i]-stir1[n-1][i-1];
        printf("%.4f\n",(double)sum/fac[n]);
    }
    return 0;
}
