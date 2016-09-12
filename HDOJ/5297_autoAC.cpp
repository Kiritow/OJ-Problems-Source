#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
int cnt[100]={19,0,1,1,1,1,2,1,1,1,2,1,2,1,2,2,1,1,2,1,2,2,2,1,2,1,2,1,2,1,3,1,1,2,2,2,2,1,2,2
,2,1,3,1,2,2,2,1,2,1,2,2,2,1,2,2,2,2,2,1,3,1,2,2,1};
long long considrt[6000000],nconsidrt;
void GetConsider(int r)
{
    nconsidrt=0;
    int i,j,sz;
    for(i=0;prime[i]<=r;i++)
    {
        sz=nconsidrt;
        for(j=0;j<sz;j++)
        {
            if(considrt[j]*prime[i]<=63)
                considrt[nconsidrt++]=considrt[j]*prime[i];
        }
        considrt[nconsidrt++]=prime[i];
    }
}
long long cal(long long x)
{
    long long ret(0);
    for(int i=0;i<nconsidrt;i++)
    {
        if(cnt[considrt[i]]&1)
            ret+=(long long)pow(x+0.5,1.0/considrt[i])-1;
        else
            ret-=(long long)pow(x+0.5,1.0/considrt[i])-1;
    }
    return x-ret-1;
}
long long solve(long long n,int r)
{
    GetConsider(r);
    long long ans = n;
    while(1)
    {
        long long temp = cal(ans);
        if(temp == n)
            break;
        ans += n - temp; 
    }
    return ans;
}
int main()
{
    int ncase,r;
    long long n;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%I64d%d",&n,&r);
        printf("%I64d\n",solve(n,r));
    }
    return 0;
}
