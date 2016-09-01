#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL __int64
const LL maxn=1001;
LL e[maxn],t;
LL gcd(LL a,LL b)
{
    return b==0?a:gcd(b,a%b);
}
LL euler_phi(LL n)
{
    LL m=(LL)sqrt(n+0.5);
    LL i,ans=n;
    for(i=2;i<=m;i++)
        if(n%i==0)
        {
            ans=ans/i*(i-1);
            while(n%i==0)n/=i;
        }
    if(n>1)ans=ans/n*(n-1);
    return ans;
}
void find(LL n)
{
    LL m=(LL)sqrt(n+0.5);
    for(LL i=1;i<m;i++)
        if(n%i==0){e[t++]=i;e[t++]=n/i;}
    if(m*m==n)e[t++]=m;
}
LL pow_mod(LL a,LL b,LL mod)
{
    LL s=1;
    while(b)
    {
        if(b&1)
            s=(s*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return s;
}
int main()
{
    LL a,x,y;
    while(cin>>x>>y>>a)
    {
        LL m,phi,i;
        if(y==0){cout<<"1"<<endl;continue;}
        m=a/gcd(y/(x-1),a);
        if(gcd(m,x)!=1){cout<<"Impossible!"<<endl;continue;}
        phi=euler_phi(m);
        t=0;
        find(phi);
        sort(e,e+t);
        for(i=0;i<t;i++)
        {
            if(pow_mod(x,e[i],m)==1)
            {
                cout<<e[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
