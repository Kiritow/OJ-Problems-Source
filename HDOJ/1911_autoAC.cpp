#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const long long inf=1LL<<35;
const long long maxn=1e6+100;
char str[110];
long long x[maxn],y[maxn],z[maxn],cnt;
long long Sum(long long val)
{
    long long sum=0;
    for(int i=0;i<cnt;i++)
    {
        if(val<x[i])
            continue;
        sum+=(min(val,y[i])-x[i])/z[i]+1;
    }
    return sum;
}
void solve()
{
    long long l=1,r=inf,ans=-1;
    while(l<=r)
    {
        long long mid=(l+r)>>1;
        if(Sum(mid)&1)
        {
            r=mid-1;
            ans=mid;
        }
        else
            l=mid+1;
    }
    if(ans==-1)
    {
        printf("no corruption\n");
        return;
    }
    printf("%I64d %I64d\n",ans,Sum(ans)-Sum(ans-1));
}
int main()
{
    cnt=0;
    while(gets(str)!=NULL)
    {
        if(strlen(str)==0)
        {
            if(cnt==0)
                continue;
            solve();
            cnt=0;
        }
        else
        {
            sscanf(str,"%I64d%I64d%I64d",&x[cnt],&y[cnt],&z[cnt]);
            cnt++;
        }
    }
    if(cnt)
        solve();
    return 0;
}
