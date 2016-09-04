#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000009
#define ll long long
using namespace std;
const ll mod=987654321;
ll f[maxn];
int main()
{
    ll n,m;
    f[1]=1;
    for(ll i=2;i<maxn-1;i++)
    {
        f[i]=f[i-1]*i;
        if(f[i]>mod)f[i]%=mod;
    }
    while(scanf("%lld%lld",&n,&m)&&(n+m)>0)
    {
        ll ans=1;
        if(n<m||m==1||m==2)
        {
            while(n>0)
            {
                if(n&1)ans*=m;
                if(ans>mod)ans%=mod;
                n>>=1;
                m*=m;
                if(m>mod)m%=mod;
            }
        }
        else
        {
            ans=f[m]+m;
            if(ans>mod)ans%=mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
