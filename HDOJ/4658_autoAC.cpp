#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;
const int mod=1e9+7;
int f[100010];
void init()
{
    f[0]=1;
    int i,j,k,flag,t,tt;
    for(i=1;i<=100000;i++)
    {
        f[i]=0;
        flag=1;
        for(j=1;;j++)
        {
            t=i-j*(3*j-1)/2;
            tt=i-j*(3*j+1)/2;
            if(t<0)break;
            f[i]=(f[i]+flag*f[t])%mod;
            if(tt<0)break;
            f[i]=(f[i]+flag*f[tt])%mod;
            flag=-flag;
        }
        f[i]=(f[i]+mod)%mod;
    }
}
int find(int n,int k)
{
    int i,j,ans,flag=-1,t,tt;
    ans=f[n];
    for(i=1;;i++)
    {
        t=k*i*(i*3-1)/2;
        tt=k*i*(i*3+1)/2;
        if(t>n)break;
        ans=(ans+flag*f[n-t])%mod;
        if(tt>n)break;
        ans=(ans+flag*f[n-tt])%mod;
        flag=-flag;
    }
    return (ans+mod)%mod;
}
int main()
{
    init();
    int T;
    cin>>T;
    while(T--)
    {
        int n,k,ans;
        scanf("%d%d",&n,&k);
        ans=find(n,k) ;
        printf("%d\n",ans);
    }
    return 0;
}
