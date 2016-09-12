#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<string.h>
#include<set>
#include<map>
#include<queue>
#include<math.h>
#define ll long long
#define pi acos(-1)
#define PLL pair<ll,ll>
#define PLLL pair<PLL,ll>
#define MP make_pair
using namespace std;
const ll mod = 1e9+7;
const ll maxn= 1000+10;
ll m,a[maxn],b[maxn],c[maxn],d[maxn],l[maxn],ans[maxn],s[maxn],cc[maxn],dd[maxn];
map<PLLL,ll> ma;
ll calc(ll p,ll x,ll y){
    if(p==0) return 0;
    PLLL r=MP(MP(p,x),y);
    if(ma.find(r)!=ma.end()) return ma[r];
    if(x<s[a[p]]&&y<s[a[p]]) return ma[r]=(calc(a[p],x,y)%mod);
    else if(x<s[a[p]]&&y>=s[a[p]]) return  ma[r]=(calc(a[p],x,c[p])+calc(b[p],y-s[a[p]],d[p])+l[p])%mod;
    else if(x>=s[a[p]]&&y<s[a[p]]) return  ma[r]=(calc(a[p],y,c[p])+calc(b[p],x-s[a[p]],d[p])+l[p])%mod;
    else return  ma[r]=(calc(b[p],x-s[a[p]],y-s[a[p]])%mod);
}
ll solve(ll p,ll id){
    if(p==0) return 0;
    if(id<s[a[p]])
        return ((calc(a[p],id,c[p])+l[p])%mod*(s[b[p]]%mod)%mod+(dd[p]+solve(a[p],id))%mod)%mod;
    else{
        id=(id-s[a[p]]);
        return ((calc(b[p],id,d[p])+l[p])%mod*(s[a[p]]%mod)%mod+(cc[p]+solve(b[p],id))%mod)%mod;
    }
}
int main(){
    while(scanf("%lld",&m)!=EOF){
        s[0]=1; a[0]=b[0]=c[0]=d[0]=cc[0]=dd[0]=l[0]=0; ma.clear();
        for(ll i=1;i<=m;i++) s[i]=ans[i]=0;
        for(ll i=1;i<=m;i++){
            scanf("%lld%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i],&l[i]); s[i]=s[a[i]]+s[b[i]];
            cc[i]=solve(a[i],c[i])%mod,dd[i]=solve(b[i],d[i])%mod;
            ans[i]=((cc[i]*(s[b[i]]%mod)%mod)+(dd[i]*(s[a[i]]%mod)%mod)+l[i]%mod*(s[a[i]]%mod)%mod*(s[b[i]]%mod)%mod+(ans[a[i]]+ans[b[i]])%mod)%mod;
            printf("%lld\n",ans[i]);
        }
    }
    return 0;
}
