#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#include <algorithm>
int dp[1000010];
int v[1000],m[1000];
void zoreone(int v1,int m1,int sum)
{
    for(int i=sum;i>=m1;i--)
        dp[i]=max(dp[i],dp[i-m1]+v1);
}
void complete(int v1,int m1,int sum)
{
    for(int i=m1;i<=sum;i++)
        dp[i]=max(dp[i],dp[i-m1]+v1);
}
void multiple(int v1,int m1,int sum,int num)
{
    if(m1*num>sum)
        complete( v1, m1, sum);
    else
    {
        for(int k=1;k<num;k*=2)
        {
            zoreone(k*v1,k*m1,sum);
            num-=k;
        }
        zoreone(num*v1,num*m1,sum);
    }
}
int main(){
    int n,sum,sum1;
    while(~scanf("%d",&n)&&(n>=0))
    {
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&v[i],&m[i]);
            sum+=v[i]*m[i];
        }
        sum1=sum/2;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
            multiple(v[i],v[i],sum1,m[i]);
        printf("%d %d\n",sum-dp[sum/2],dp[sum/2]);
    }
    return 0;
}
