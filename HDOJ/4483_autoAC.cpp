#include <stdio.h>
#include <iostream>
using namespace std;
#define maxn 100001
#define LL long long
const LL mod=1000000007;
LL x[maxn],y[maxn],z[maxn],phi[maxn],n;
void init()
{
    LL i,j,k;
    for(i=2;i<maxn;i++)phi[i]=0;
    phi[1]=1;
    for(i=2;i<maxn;i++)
        if(!phi[i])
        for(j=i;j<=maxn;j+=i){
            if(!phi[j])phi[j]=j;
            phi[j]=phi[j]/i*(i-1);
        }
    x[1]=z[1]=1;
    y[1]=2;
    for(i=2;i<maxn;i++)
    {
        x[i]=(x[i-1]+phi[i]*2)%mod;
        y[i]=(y[i-1]+phi[i]*i*3)%mod;
        z[i]=(z[i-1]+phi[i]*i%mod*i)%mod;
    }
}
int main()
{
    LL T;
    init();
    cin>>T;
    while(T--)
    {
        LL k,t,ans,m;
        cin>>n;
        n++;
        t=(n*n)%mod;
        LL md=mod*6;
        ans=t*(t-1)%md*(t-2)%md/6;
        ans-=t*(n-1)%md*(n-2)*2%md/6;
        t=0;
        for(k=2;k<n;k++)
        {
            m=(n-1)/k;
            t=(t+(k-1)*(x[m]*n%mod*n%mod-n*k%mod*y[m]%mod+k*k%mod*z[m]%mod))%mod;
        }
        ans-=t*2;
        cout<<(ans%mod+mod)%mod<<endl;
    }
    return 0;
}
