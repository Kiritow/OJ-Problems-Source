#include <cstdio>
using namespace std;
typedef long long LL;
LL phi(LL x)
{
    LL ans=x;
    for(LL i=2;i*i<=x;i++)
        if(x%i==0){
            ans=ans/i*(i-1);
            while(x%i==0) x/=i;
        }
    if(x>1)
        ans=ans/x*(x-1);
    return ans;
}
LL pow_mod(LL a,LL p,LL mod)
{
    LL ans=1;
    while(p)
    {
        if(p&1)
        {
            ans=ans*a;
            if(ans>mod)
                ans=ans%mod+mod;
        }
        a=a*a;
        if(a>mod)
            a=a%mod+mod;
        p>>=1;
    }
    return ans;
}
LL f(LL n,LL m)
{
    if(n<10) return n;
    LL p=f(n/10,phi(m));
    return pow_mod(n%10,p,m);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        LL n,m;
        scanf("%I64d%I64d",&n,&m);
        printf("%I64d\n",f(n,m)%m);
    }
    return 0;
}
