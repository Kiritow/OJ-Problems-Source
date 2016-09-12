#include<stdio.h>
typedef long long LL;
#define mod 1000000007
LL pow(LL a, LL b) {
    LL s = 1;
    while(b) {
        if(b&1) s = (s * a) % mod;
        a = (a*a) % mod;
        b >>= 1;
    }
    return s;
}
LL f[200005],inv[200005];
void init()
{
    f[0]=f[1]=inv[0]=inv[1]=1;
    for(LL i=2;i<=200000;++i){
        f[i]=f[i-1]*i%mod;
        inv[i]=pow(f[i],mod-2);
    }
}
LL C(int n,int m)
{
    if(m>n||m<0) return 0;
    return f[n]*inv[m]%mod*inv[n-m]%mod;
}
LL n,m;
LL cal(int x)
{
    LL ans=0;
    for(LL i=0,s=x;i<m&&s<=n;++i,s+=x)    
    {
        LL t=C(m-1,i)*C(n-s+m-2,n-s)%mod;
        if(i&1) ans=((ans-t)%mod+mod)%mod;
        else ans=(ans+t)%mod;
    }
    return ans;
}
int main() {
    int t;
    scanf("%d",&t);
    init();
    while(t--)
    {
        scanf("%lld%lld", &n,&m);
        if(m==1) puts("1");
        else
        {
            LL ans=0;
            for(LL i=1;i<=n;++i) ans=(ans+cal(i))%mod;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
