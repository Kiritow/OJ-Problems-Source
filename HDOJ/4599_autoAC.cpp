#include <cstring>  
#include <iostream>  
#include <cmath>  
#include <algorithm>  
#include <cstdio>  
using namespace std;  
typedef long long LL;  
using namespace std;  
LL n;  
LL mod =2011;  
LL exgcd(LL a,LL b,LL &x,LL &y)  
{  
    if(b==0)  
    {  
        x=1;  
        y=0;  
        return a;  
    }  
    else  
    {  
        LL ans=exgcd(b,a%b,x,y);  
        LL tmp=x;  
        x=y;  
        y=tmp-a/b*y;  
        return ans;  
    }  
}  
LL Pow(LL a,LL b,LL mod)  
{  
    LL ans=1;  
    while(b)  
    {  
        if(b&1)  
        {  
            b--;  
            ans=(ans*a)%mod;  
        }  
        else  
        {  
            b/=2;  
            a=(a*a)%mod;  
        }  
    }  
    return ans;  
}  
LL solve0(LL n)  
{  
    LL ans=Pow(6,n%2010,2011);  
    ans+=24;  
    ans%=mod;  
    LL x,y;  
    exgcd(30,mod,x,y);  
    LL niyuan=(x%mod+mod)%mod;  
    ans=(ans*niyuan)%mod;  
    return ans;  
}  
LL solve(LL n)  
{  
    LL ans=Pow(6,n%2010,2011);  
    ans=(ans+2010)%mod;  
    LL x,y;  
    exgcd(5,mod,x,y);  
    LL niyuan=(x%mod+mod)%mod;  
    ans=(ans*niyuan)%mod;  
    return ans;  
}  
int main()  
{  
    while(scanf("%I64d",&n)!=EOF)  
    {  
        if(n==0)  
            break;  
        printf("%I64d %I64d\n",solve0(n),solve(n));  
    }  
    return 0;  
}
