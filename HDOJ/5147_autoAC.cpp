#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=50010;
int a[maxn];
int pre[maxn],suf[maxn];
int n;
int c[maxn]; 
int lowbit(int x)
{
    return x&(-x);
}
void update(int i,int x)
{
    while(i<=n)
    {
        c[i]+=x;
        i+=lowbit(i);
    }
}
int sum(int i) 
{
    int s=0;
    while(i>0)
    {
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            pre[i]=sum(a[i]);
            update(a[i],1);
        }
        memset(c,0,sizeof(c));
        for(int i=n;i>=1;i--)
        {
            suf[i]=(n-i)-sum(a[i]);
            update(a[i],1);
        }
        long long ans=0,dp=0;
        for(int i=1;i<=n-1;i++)
        {
            ans+=dp*suf[i];
            dp+=pre[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
