#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN=400010;
int q[MAXN];
long long  sum[MAXN];
long long a[MAXN];
long long dp[MAXN];
long long getDP(int i,int j)
{
    return dp[j]+(sum[i]-sum[j])-a[j+1]*(i-j);
}
long long getUP(int j,int k)
{
    return dp[j]-sum[j]+j*a[j+1]-(dp[k]-sum[k]+k*a[k+1]);
}
long long getDOWN(int j,int k)
{
    return a[j+1]-a[k+1];
}
int main()
{
    int n,t;
    int head,tail;
    while(scanf("%d%d",&n,&t)==2)
    {
        dp[0]=sum[0]=0;
        a[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
          sum[i]=sum[i-1]+a[i];
        head=tail=0;
        q[tail++]=0;
        for(int i=1;i<=n;i++)
        {
            while(head+1<tail && getUP(q[head+1],q[head])<=i*getDOWN(q[head+1],q[head]))
              head++;
            dp[i]=getDP(i,q[head]);
            int j=i-t+1;
            if(j<t)continue;
            while(head+1<tail && getUP(j,q[tail-1])*getDOWN(q[tail-1],q[tail-2])<=getUP(q[tail-1],q[tail-2])*getDOWN(j,q[tail-1]))
                   tail--;
            q[tail++]=j;
        }
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
