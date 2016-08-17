#include<iostream>
#include<algorithm>
using namespace std;
#define N 1010
#define inf 0xfffffff
int dp[N][N];
int s[N][N];
int sum[N],dia[N];
int main(){
int i,n,j,k,pos;
while(scanf("%d",&n)!=EOF)
{
sum[0]=0;
for(i=0;i<=n+1;i++)
for(j=0;j<=n+1;j++)
dp[i][j]=inf;
for(i=1;i<=n;i++)
scanf("%d",&pos);
for(i=1;i<=n;i++)
{
scanf("%d",&dia[i]);
sum[i]=sum[i-1]+dia[i];
dp[i][i]=0;
s[i][i]=i;
}
int des;
for(k=2;k<=n;k++)
{
for(i=1;i+k-1<=n;i++)
{
des=i+k-1;
for(j=s[i][des-1];j<=s[i+1][des];j++)
{
if(j==i)
{
if(dp[i][des]>=dp[j+1][des]+sum[des]-sum[j])
{
dp[i][des]=dp[j+1][des]+sum[des]-sum[j];
s[i][des]=j;
}
}
else if(j==des)
{
if(dp[i][des]>=dp[i][j-1]+sum[j-1]-sum[i-1])
{
dp[i][des]=dp[i][j-1]+sum[j-1]-sum[i-1];
s[i][des]=j;
}
}
else
{
if(dp[i][des]>=dp[i][j-1]+dp[j+1][des]+sum[j-1]-sum[i-1]+sum[des]-sum[j])
{
dp[i][des]=dp[i][j-1]+dp[j+1][des]+sum[j-1]-sum[i-1]+sum[des]-sum[j];
s[i][des]=j;
}
}
}
}
}
cout<<dp[1][n]<<endl;
}
return 0;
}
