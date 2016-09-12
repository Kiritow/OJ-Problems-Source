#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string.h>
#define ll long long
using namespace std;
const ll maxn = 10000000+10;
const ll mod = (1ll<<32);
ll t,n,ans;
ll f0[maxn],g0[maxn];
ll sumhe[maxn],sumu[maxn],sumu0[maxn];
bool not_prime[maxn];
ll pri[maxn],cnt;
ll ans0,ans1;
void mobius(){
    sumu[1]=1,sumu0[1]=1,sumu[0]=0,sumhe[0]=0,sumu0[0]=0,cnt=0;
    for(ll i=2;i<=maxn-5;i++){
        if(!not_prime[i]) pri[cnt++]=i,sumu[i]=((-1)%mod+mod)%mod,sumu0[i]=((1-i)%mod+mod)%mod;
        for(ll j=0;j<cnt&&i*pri[j]<=maxn-5;j++){
            not_prime[i*pri[j]]=1;
            if(i%pri[j]==0) { sumu[i*pri[j]]=0,sumu0[i*pri[j]]=sumu0[i]%mod;break; }
            else sumu[i*pri[j]]=((-sumu[i])%mod+mod)%mod,sumu0[i*pri[j]]=(sumu0[pri[j]]*sumu0[i])%mod;
        }
    }
    for(ll i=1;i<=maxn-5;i++) sumu[i]=(sumu[i-1]+sumu[i])%mod,f0[i]=g0[i]=mod+1,sumhe[i]=(sumhe[i-1]+i)%mod,sumu0[i]=(sumu0[i-1]+i*sumu0[i]%mod)%mod;
}
ll calf(ll n){
    if(f0[n]!=mod+1) return f0[n];
    ll ans=0,tmp;
    for(ll i=1;i<=n;i=tmp+1){
        tmp=n/(n/i);
        ans=(ans+((sumu[tmp]-sumu[i-1])%mod+mod)%mod*(n/i)%mod*(n/i)%mod)%mod;
    }
    return f0[n]=ans;
}
ll calg(ll n){
    if(g0[n]!=mod+1) return g0[n];
    ll ans=0,tmp;
    for(ll i=1;i<=n;i=tmp+1){
        tmp=n/(n/i);
        ans=(ans+((sumhe[tmp]-sumhe[i-1])%mod+mod)%mod*calf(n/i)%mod)%mod;
    }
    return g0[n]=ans;
}
int main(){
    mobius();
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n);
        ans=0;
        ll tmp=0;
        for(ll i=1;i<=n;i=tmp+1){
            tmp=n/(n/i);
            ll x=calg(n/i);
            ans=(ans+((sumu0[tmp]-sumu0[i-1])%mod+mod)%mod*x%mod*x%mod)%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
