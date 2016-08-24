#include<iostream>
using namespace std;
int dp[200][200],a[200],sum,temp;
int main()
{
 int i,j,k,n,min;
 while(cin>>n&&n)
 {
  min=0;
  sum=0;
  for(i=1;i<=n;i++)
   cin>>a[i];
  for(i=1;i<=n;i++)
  {
   sum+=a[i];
   dp[1][i]=(1+i)*sum;
  }
  for(i=2;i<=n;i++)
   for(j=i;j<=n;j++)
   {
    sum=0;min=100000000;
    for(k=j;k>=i;k--)
    {
     sum+=(i+j)*a[k];
     temp=dp[i-1][k-1]+sum;
     if(temp<min)
      min=temp;
    }
    dp[i][j]=min;
   }
  min=1000000000;
  for(i=1;i<=n;i++)
  {
   if(min>dp[i][n])
    min=dp[i][n];
  }
  cout<<min<<endl;
 }
 return 0;
}
