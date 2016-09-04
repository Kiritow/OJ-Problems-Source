#include<iostream>
#include<cstdio>
#include<cmath>
#define N 10000000
#define MOD 1000000007
#define LL long long
using namespace std;
bool flag[N+5]={0};
int prime[1000000],cnt=0;
void Prime(){
    for(int i=2;i<sqrt(N+1.0);i++){
        if(flag[i])
            continue;
        for(int j=2;j*i<=N;j++)
            flag[i*j]=true;
    }
    for(int i=2;i<=N;i++)
        if(!flag[i])
            prime[cnt++]=i;
}
int getsum(int n,int p){
    int sum=0;
    while(n){
        sum+=n/p;
        n/=p;
    }
    return sum;
}
LL PowMod(LL a, LL b){
    LL ans=1;
    while(b){
        if(b&1)
            ans=(ans*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return ans;
}
LL fac[N+5];
int a;
int main(){
    int n;
    fac[1]=1;
    for(int i=2;i<=N;i++)
        fac[i]=(fac[i-1]*i)%MOD;
    Prime();
    while(scanf("%d",&n)!=EOF&&n){
        LL ret=1;
        for(int i=0;i<cnt&&prime[i]<=n;i++){
            a=getsum(n,prime[i]);
            if(a&1)
                ret=(ret*prime[i])%MOD;
        }
        printf("%I64d\n",(fac[n]*PowMod(ret,MOD-2))%MOD);
    }
    return 0;
}
