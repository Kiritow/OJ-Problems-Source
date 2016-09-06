#include <cstdio>  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <cstring>  
#include <map>  
using namespace std;  
#define Times 10  
typedef __int64 LL;  
map<LL,int>m;  
LL Random(LL n)  
{  
    return ((double)rand()/RAND_MAX*n+0.5);  
}  
LL multi(LL a,LL b,LL mod)  
{  
    LL ans=0;  
    while(b)  
    {  
        if(b&1)  
        {  
            b--;  
            ans=(ans+a)%mod;  
        }  
        else  
        {  
            b/=2;  
            a=(a+a)%mod;  
        }  
    }  
    return ans;  
}  
LL Pow(LL a,LL b,LL mod)  
{  
    LL ans=1;  
    while(b)  
    {  
        if(b&1)  
        {  
            b--;  
            ans=multi(ans,a,mod);  
        }  
        else  
        {  
            b/=2;  
            a=multi(a,a,mod);  
        }  
    }  
    return ans;  
}  
bool witness(LL a,LL n)  
{  
    LL d=n-1;  
    while(!(d&1))  
        d>>=1;  
    LL t=Pow(a,d,n);  
    while(d!=n-1 && t!=1 && t!=n-1)  
    {  
        t=multi(t,t,n);  
        d<<=1;  
    }  
    return t==n-1 || d&1;  
}  
bool miller_rabin(LL n)  
{  
    if(n==2)  
        return true;  
    if(n<2||!(n&1))  
        return false;  
    for(int i=1;i<=Times;i++)  
    {  
        LL a=Random(n-2)+1;  
        if(!witness(a,n))  
            return false;  
    }  
    return true;  
}  
LL gcd(LL a,LL b)  
{  
    if(b==0)  
        return a;  
    return gcd(b,a%b);  
}  
LL pollard_rho(LL n,LL c)  
{  
    LL x,y,d,i=1,k=2;  
    x=Random(n-1)+1;  
    y=x;  
    while(1)  
    {  
        i++;  
        x=(multi(x,x,n)+c)%n;  
        d=gcd(y-x,n);  
        if(1<d&&d<n)  
            return d;  
        if(y==x)  
            return n;  
        if(i==k)  
        {  
            y=x;  
            k<<=1;  
        }  
    }  
}  
void find(LL n,LL c)  
{  
    if(n==1)  
        return ;  
    if(miller_rabin(n))  
    {  
        m[n]++;  
        return ;  
    }  
    LL p=n;  
    while(p>=n)  
        p=pollard_rho(p,c--);  
    find(p,c);  
    find(n/p,c);  
}  
int main()  
{  
    int t;  
    cin>>t;  
    while(t--)  
    {  
        LL n;  
        cin>>n;  
        m.clear();  
        find(n,2013724);  
        if(m.size()==1)  
            cout<<1<<" "<<n/m.begin()->first<<endl;  
        else  
        {  
            LL ans=0;  
            map<LL,int>::iterator it=m.begin();  
            for(;it!=m.end();it++)  
                ans+=Pow(it->first,it->second,n);  
            cout<<m.size()<<" "<<ans<<endl;  
        }  
    }  
    return 0;  
}
