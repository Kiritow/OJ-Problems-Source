#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define lz 2*u,l,mid
#define rz 2*u+1,mid+1,r
const int maxn=110000;
int sum[2*maxn], dp[maxn+5], a[maxn+5];
void Update(int u, int l, int r, int p, int c)
{
    sum[u]=max(sum[u],c);
    if(l==r)return ;
    int mid=(l+r)>>1;
    if(p<=mid) Update(lz,p,c);
    else Update(rz,p,c);
}
int Query(int u, int l, int r, int tl, int tr)
{
    if(tl>tr) return 0;
    if(tl<=l&&r<=tr) return sum[u];
    int mid=(l+r)>>1;
    if(tr<=mid) return Query(lz,tl,tr);
    else if(tl>mid) return Query(rz,tl,tr);
    else
    {
        int t1=Query(lz,tl,mid);
        int t2=Query(rz,mid+1,tr);
        return max(t1,t2);
    }
}
int main()
{
    int n, d;
    while(scanf("%d%d",&n,&d)!=EOF)
    {
        memset(sum,0,sizeof(sum));
        for(int i=1; i<=n; i++)
            scanf("%d",a+i);
        int maxx=0;
        for(int i=1; i<=n; i++)
        {
            if(i>d+1) Update(1,1,maxn,a[i-d-1]+1,dp[i-d-1]);  
            dp[i]=Query(1,1,maxn,1,a[i])+1;
            maxx=max(dp[i],maxx);
        }
        printf("%d\n",maxx);
    }
    return 0;
}
