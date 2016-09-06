#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long x,long long y)
{
    return y==0?x:gcd(y,x%y);
}
long long Count(long long n,long long a,long long b)
{
    long long now=0,ret=0,tmp,x=0,y=0;
    while(now<n)
    {
        tmp=min(a-x,b-y);
        if (now+tmp>n) tmp=n-now;
        ret+=tmp*abs(x-y);
        x=(x+tmp)%a;
        y=(y+tmp)%b;
        now+=tmp;
    }
    return ret;
}
int main()
{
    int i,j,T;
    long long a,b,n,l,ans;
    scanf("%d",&T);
    while(T--)
    {
        cin>>n>>a>>b;
        l=a*b/gcd(a,b);
        if (l>=n) ans=Count(n,a,b);
        else ans=Count(l,a,b)*(n/l)+Count(n%l,a,b);
        cout<<ans<<endl;
    }
    return 0;
}
