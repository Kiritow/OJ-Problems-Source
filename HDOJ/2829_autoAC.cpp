#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
const int MAXN=1010;
int a[MAXN];
int sum[MAXN];
int cost[MAXN];
int q[MAXN];
int head,tail;
int n,m;
int dp[MAXN][MAXN];
int DP()
{
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=cost[i];
        dp[i][i-1]=0;
    }
    for(int j=1;j<=m;j++)
    {
        head=tail=0;
        q[tail++]=j;
        for(int i=j+1;i<=n;i++)
        {
            while(head+1<tail)
            {
                int p1=q[head];
                int p2=q[head+1];
                int x1=sum[p1];
                int x2=sum[p2];
                int y1=dp[p1][j-1]-cost[p1]+sum[p1]*sum[p1];
                int y2=dp[p2][j-1]-cost[p2]+sum[p2]*sum[p2];
                if((y2-y1)<=sum[i]*(x2-x1)) head++;
                else break;
            }
            int k=q[head];
            dp[i][j]=dp[k][j-1]+cost[i]-cost[k]-sum[k]*sum[i]+sum[k]*sum[k];
            while(head+1<tail)
            {
                int p1=q[tail-2];
                int p2=q[tail-1];
                int p3=i;
                int x1=sum[p1];
                int x2=sum[p2];
                int x3=sum[p3];
                int y1=dp[p1][j-1]-cost[p1]+sum[p1]*sum[p1];
                int y2=dp[p2][j-1]-cost[p2]+sum[p2]*sum[p2];
                int y3=dp[p3][j-1]-cost[p3]+sum[p3]*sum[p3];
                if((y2-y1)*(x3-x2)>=(y3-y2)*(x2-x1))tail--;
                else break;
            }
            q[tail++]=i;
        }
    }
    return dp[n][m];
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)break;
        sum[0]=0;
        cost[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
            cost[i]=cost[i-1]+sum[i-1]*a[i];
        }
        printf("%d\n",DP());
    }
    return 0;
}
