#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1000000
#define MOD 258280327
#define LL long long
int notprime[maxn+10];
int prime[maxn+10],tot;
int mu[maxn+10]={0,1};
LL jie[maxn+10];
LL inv[maxn+10];
LL power(LL x,LL k){
    LL res=1,t=x;
    while(k){
        if(k&1)res=res*t%MOD;
        t=t*t%MOD;
        k>>=1;
    }
    return res%MOD;
}
void init(){
    jie[0]=jie[1]=1;
    tot=0;
    mu[1]=1;
    inv[0]=inv[1]=1;
    for(int i=2;i<=maxn;i++){
        jie[i]=i*jie[i-1]%MOD;
        inv[i]=power(jie[i],MOD-2);
        if(!notprime[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot&&i*prime[j]<=maxn;j++){
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            mu[i*prime[j]]=-mu[i];
        }
    }
}
int n;
int ma;
int cnt[maxn+10];
LL F1[maxn+10],F2[maxn+10];
LL ans1,ans2;
void calc(){
    for(int i=1;i<=ma;i++){
        LL tmp=0;
        for(int j=1;j<=cnt[i];j++){
            LL a=jie[cnt[i]];
            LL b=inv[cnt[i]-j];
            tmp=(tmp+a*b%MOD*jie[n-j+1]%MOD)%MOD;
        }
        F1[i]=tmp;
        if(cnt[i]>0)
            F2[i]=cnt[i]*power(2,cnt[i]-1);
        else F2[i]=0;
    }
    LL tmp1,tmp2;
    ans1=ans2=0;
    for(int i=1;i<=ma;i++){
        tmp1=tmp2=0;
        for(int j=i;j<=ma;j+=i){
            tmp1=(tmp1+mu[j/i]*F1[j]%MOD)%MOD;
            tmp2=(tmp2+mu[j/i]*F2[j]%MOD)%MOD;
        }
        ans1=(ans1+i*tmp1%MOD)%MOD;
        ans2=(ans2+i*tmp2%MOD)%MOD;
    }
}
int main(){
    init();
    while(~scanf("%d",&n)){
        for(int i=1;i<=maxn;i++)cnt[i]=0;
        ma=0;
        for(int i=0;i<n;i++){
            int x;scanf("%d",&x);
            if(ma<x)ma=x;
            for(int j=1;j*j<=x;j++){
                if(j*j==x)cnt[j]++;
                else if(x%j==0){
                    cnt[j]++;
                    cnt[x/j]++;
                }
            }
        }
        calc();
        if(ans1==ans2)printf("Equal %lld\n",ans1);
        else if(ans1>ans2)printf("Mr. Zstu %lld\n",ans1);
        else printf("Mr. Hdu %lld\n",ans2);
    }
    return 0;
}
