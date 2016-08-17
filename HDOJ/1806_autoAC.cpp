#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int MAXN=100010;
int a[MAXN];
int b[MAXN];
int dp[MAXN][20];
void makeRMQ(int n,int b[])
{
    for(int i=0;i<n;i++)
      dp[i][0]=b[i];
    for(int j=1;(1<<j)<=n;j++)
      for(int i=0;i+(1<<j)-1<n;i++)
        dp[i][j]=max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}
int rmq(int s,int v)
{
    int k=(int)(log(v-s+1.0)/log(2.0));
    return max(dp[s][k],dp[v-(1<<k)+1][k]);
}
int bi_search(int s,int t)
{
    int tmp=a[t];
    int l=s;
    int r=t;
    int mid;
    while(l<r)
    {
        mid=((l+r)>>1);
        if(a[mid]>=tmp)r=mid;
        else l=mid+1;
    }
    return r;
}
int main()
{
    int n,q;
    int s,t;
    while(scanf("%d",&n),n)
    {
        scanf("%d",&q);
        for(int i=0;i<n;i++)
          scanf("%d",&a[i]);
        int tmp;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)tmp=1;
            else
            {
                if(a[i]==a[i+1])tmp++;
                else tmp=1;
            }
            b[i]=tmp;
        }
        makeRMQ(n,b);
        while(q--)
        {
            scanf("%d%d",&s,&t);
            s--;
            t--;
            int temp=bi_search(s,t);
            int ans=t-temp+1;
            t=temp-1;
            if(s>t)printf("%d\n",ans);
            else printf("%d\n",max(ans,rmq(s,t)));
        }
    }
    return 0;
}
