#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
const LL MOD = 1000000007;
const int MXN = 200005;
int mu[MXN], p[MXN], pn;
bool flag[MXN];
void init(int n=MXN-5) {
    pn = 0;
    mu[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!flag[i]) {
            p[pn ++ ] = i;
            mu[i] = -1;                     
        }
        for(int j = 0; j < pn && i * p[j] <= n; j++) {
            flag[i * p [j]] = true;
            if(i % p[j] == 0) {
                mu[i * p[j]] = 0;         
                break;
            } else  mu[i * p[j]] = -mu[i];  
        }
    }
}
LL inv[200005];
LL fact[200005];
LL ifac[200005];
LL comb(LL a,LL b){
    return fact[a]*ifac[b]%MOD*ifac[a-b]%MOD;
}
LL play(int n,int m){
    return comb(n+m-1,n-1);
}
int N,M,K,n;
LL solve(int n,int M){
    LL ans=0;
    for(int i=0;i<=n&&i*K<=M;i++){
        LL mul=comb(n,i);
        LL add=play(n,M-i*K);
        if(i&1)ans-=mul*add%MOD;
        else ans+=mul*add%MOD;
    }
    return ans%MOD;
}
LL g(int x){
    int d=n/x;
    if(M%d)return 0;
    return solve(x,M/d);
}
LL gao(int x){
    int y=x;
    vector<int>L;
    for(int i=2;i*i<=x;i++)if(x%i==0){
        L.PB(i);
        while(x%i==0)x/=i;
    }
    if(x>1)L.PB(x);
    x=y;
    LL ret=0;
    for(int i=0;i<1<<L.SZ;i++){
        int d=1,mu=1;
        for(int j=0;j<L.SZ;j++)if(i>>j&1)
            d*=L[j],mu=-mu;
        ret+=mu*inv[d];
    }
    return ret%MOD;
}
int main(){
    init();
    int i,j,_T;
    for(inv[0]=inv[1]=1,i=2;i<=200001;i++)
        inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
    for(fact[0]=i=1;i<=200001;i++)
        fact[i]=fact[i-1]*i%MOD;
    for(ifac[0]=i=1;i<=200001;i++)
        ifac[i]=ifac[i-1]*inv[i]%MOD;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
        scanf("%d%d%d",&N,&M,&K);
        printf("Case #%d: ",CA);
        n=N-M;
        if(n==0)printf("%d\n",N>=K?0:1);
        else {
            int gg=__gcd(n,M);
            set<int>SD;
            for(i=1;i*i<=gg;i++)if(gg%i==0)
                SD.insert(i),SD.insert(gg/i);
            vector<int>D(SD.OP,SD.ED);
            LL ans=0;
            map<int,LL>W;
            for(i=0;i<D.SZ;i++){
                int u=D[i],v=n/u;
                for(int w=1;w*w<=v;w++)if(v%w==0){
                    int d=w;
                    W[d]+=inv[v]*mu[v/d];
                    if(w*w!=v){
                        d=v/w;
                        W[d]+=inv[v]*mu[v/d];
                    }
                }
            }
            for(map<int,LL>::iterator it=W.OP;it!=W.ED;++it)
                ans+=(*it).BB%MOD*g((*it).AA);
            ans=(ans%MOD+MOD)%MOD;
            printf("%d\n",int(ans));
        }
    }
    return 0;
}
