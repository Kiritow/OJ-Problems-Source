#include<iostream>
using namespace std;
const int N=110;
__int64 dp[N][N],fact[N];
__int64 bell[N];
const int mod=20090126;
void init()
{
 int i,j;
 fact[0]=1;
 for(i=1;i<=100;i++)
 {
  fact[i]=fact[i-1]*i%mod;
 }
 for(i=0;i<=100;i++) dp[i][1]=dp[i][i]=1;
 for(i=2;i<=100;i++)           //绗浜绫
 {
  for(j=1;j<i;j++)
  {
           dp[i][j]=(dp[i-1][j-1]+j*dp[i-1][j])%mod;
  }
 }
 __int64 s;
 for(i=1;i<=100;i++)
 {
  s=0;
  for(j=1;j<=i;j++)
  {
   s+=dp[i][j]*fact[j];
   s%=mod;
  }
  bell[i]=s;
 }
}
int main()
{
 init();
 int t,n;
 cin>>t;
 while(t--)
 {
    cin>>n;
    printf("%I64d\n",bell[n]);
 }
 return 0;
}
