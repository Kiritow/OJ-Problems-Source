#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int mod=100007;
int dp[30];
int succ[mod],cycle;
void get_T(int m)
{
 int cnt=1;
 memset(succ,-1,sizeof(succ)); 
 succ[0]=0; 
 int now=0;
 while(1)
 {
 now=(now*10+2)%m; 
 if (succ[now]!=-1)
 {
 cycle=cnt-succ[now];
 break; 
 }
 succ[now]=cnt++;
 }
}
int cal(int x,int m)
{
 if (x==1) return 1;
 get_T(m); 
 int tmp=cal(x-1,cycle);
 int now=0;
 while(tmp--)
 {
 now=now*10+2;
 if (now>=m)
 {
 int t=(now-mod)/m;
 now=now-t*m;
 } 
 } 
 return now;
}
int main()
{
 for (int i=1;i<10;i++)
 {
 dp[i]=(9*cal(i,mod)+1)%mod;
 }
 int n;
 while(scanf("%d",&n)!=EOF)
 {
 int ans;
 if (n<=9)
 ans=n==1?1:dp[n-1];
 else
 if (n%2==1)
 ans=dp[8];
 else ans=dp[7];
 printf("%d\n",ans);
 }
 return 0; 
}
