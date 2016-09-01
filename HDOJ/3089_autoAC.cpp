#include <cstdio>
#define LL long long
LL solve(LL n,LL k,LL s=1)
{
    if(k==1) return (n-1+s)%n;
    LL ans=0;
    for(LL i=2;i<=n;)
    {
        if(ans+k<i) 
        {
            LL leap;
            if((i-ans-1)%(k-1)==0) leap=(i-ans-1)/(k-1)-1;
            else leap=(i-ans-1)/(k-1);
            if(i+leap>n) return ((ans+(n+1-i)*k)+s)%n;
            i+=leap;
            ans+=leap*k;
        }
        else
        {
            ans=(ans+k)%i;
            i++;
        }
    }
    return (ans+s)%n;
}
int main()
{
    LL n,k;
    while(scanf("%I64d%I64d",&n,&k)!=EOF)
    {
        LL ans=solve(n,k);
        if(ans==0) printf("%I64d\n",n);
        else printf("%I64d\n",ans);
    }
}
