#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm> 
using namespace std;
typedef long long Int;
int getphi(int x)
{
    int ret=1;
    for(int i=2;i*(Int)i<=x;i++)
        if(x%i==0)
        {
            ret=ret*(i-1);
            x/=i;
            while(x%i==0)x/=i,ret*=i;
        }
    if(x>1)ret=ret*(x-1);
    return ret;
}
int powmod(int x,int y,int mod)
{
    int ret=1;
    while(y){if(y&1)ret=ret*(Int)x%mod;y>>=1;x=x*(Int)x%mod;}
    return ret;
}
int check(int x,int y,int mod)
{
    vector<int>V;
    while(y){V.push_back(y&1);y>>=1;}
    reverse(V.begin(),V.end());
    int ret=0,tp=1;
    for(int i=0;i<V.size();i++)
    {
        ret=(ret+ret*(Int)tp%mod)%mod;
        tp=tp*(Int)tp%mod;
        if(V[i])
        {
            tp=tp*(Int)x%mod;
            ret=(ret+tp)%mod;
        }
    }
    return (ret+1)%mod;
}
int main()
{
    int _;scanf("%d",&_);
    while(_--)
    {
        int k,b,x,p;
        scanf("%d%d%d%d",&k,&b,&x,&p);
        if(!k){puts(b==x?"1":"-1");continue;}
        if(k==1)
        {
            if(!b)puts("1");
            else
            {
                printf("%d\n",p/__gcd(b,p));
            }
            continue;
        }
        int q=p/__gcd((Int)p,(Int)(k-1)*x+b);
        if(q==1){puts("1");continue;}
        if(__gcd(k,q)!=1){puts("-1");continue;}
        int t=getphi(q);
        int rep=t;
        for(int i=2;i*(Int)i<=t;i++)
        {
            if(t%i==0)
            {
                if(powmod(k,i,q)==1){rep=i;break;}
                if(powmod(k,t/i,q)==1)rep=t/i;
            }
        }
        int ans=check(k,rep-1,q);
        if(!ans){printf("%d\n",rep);continue;}
        printf("%lld\n",q/__gcd(ans,q)*(Int)rep);
    }
}
