#include <iostream>
#include <string.h>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long LL;
const int N=1000005;
const LL INF=(LL)1<<62;
bool prime[N];
LL p[N];
LL fac[N];
LL k,cnt,num,ans,n,m,K;
void isprime()
{
    k=0;
    int i,j;
    memset(prime,true,sizeof(prime));
    for(i=2; i<N; i++)
    {
        if(prime[i])
        {
            p[k++]=i;
            for(j=i+i; j<N; j+=i)
            {
                prime[j]=false;
            }
        }
    }
}
void Solve(LL m,LL n)
{
    cnt=0;
    LL i;
    for(i=0; p[i]*p[i]<=n; i++)
    {
        if(n%p[i]==0)
        {
            fac[cnt++]=p[i];
            while(n%p[i]==0) n/=p[i];
        }
    }
    if(n>1)
        fac[cnt++]=n;
    for(i=0; p[i]*p[i]<=m; i++)
    {
        if(m%p[i]==0)
        {
            fac[cnt++]=p[i];
            while(m%p[i]==0) m/=p[i];
        }
    }
    if(m>1)
        fac[cnt++]=m;
}
void dfs(LL k,LL t,LL s,LL n)
{
    if(k==num)
    {
        if(t&1) ans-=n/s;
        else    ans+=n/s;
        return;
    }
    dfs(k+1,t,s,n);
    dfs(k+1,t+1,s*fac[k],n);
}
LL Binary()
{
    LL l=1,r=INF,mid,ret;
    while(l<=r)
    {
        mid=(l+r)/2;
        ans=0;
        dfs(0,0,1,mid);
        if(ans>=K)
        {
            ret=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    return ret;
}
int main()
{
    isprime();
    LL t,ct,tt=1;
    scanf("%I64d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%I64d",&m,&n,&K);
        printf("Case %d: ",tt++);
        if(n==1&&m==1)
        {
            printf("%I64d\n",k);
            continue;
        }
        Solve(m,n);
        sort(fac,fac+cnt);
        num=1;
        for(LL i=1; i<cnt; i++)
        {
            if(fac[i]!=fac[i-1])
            {
                fac[num++]=fac[i];
            }
        }
        ct=num;
        printf("%I64d\n",Binary());
    }
    return 0;
}
