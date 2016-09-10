#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
int dp[25][25][3];
int bit[25];
int dfs(int pos,int pre,int flag,int z)
{
  if(pos==0)return 1;
  if( !flag && dp[pos][pre][z]!=-1)return dp[pos][pre][z];
  int end=flag?bit[pos]:9;
  int i=0,ans=0;
  if(z==0)i=1;
  for(;i<=end;i++)
  {
       if(pre==0)
         ans+=dfs(pos-1,i,flag&&(i==end),z&&(i==0));
       else
       {
           if( pre>=i && pre%i==0)ans+=dfs(pos-1,i,flag&&(i==end),z&&(i==0));
       }
  }
  if(!flag)dp[pos][pre][z]=ans;
  return ans;
}
int cal(int x)
{
 int len=0;
 memset(bit,0,sizeof(bit));
 memset(dp,-1,sizeof(dp));
 while(x)
 {
   bit[++len]=x%10;
   x/=10;
 }
 return dfs(len,0,1,1);
}
int main()
{
  int l,r;
  int T;
  cin>>T;
  while(T--)
  {
      scanf("%d%d",&l,&r);
      int s1=cal(r);
      int s2=cal(l-1);
      printf("%d\n",s1-s2);
  }
  return 0;
}
