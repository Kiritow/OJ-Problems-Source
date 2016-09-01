#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MaxN = 3005;
char s1[MaxN],s2[MaxN];
typedef long long LL;
LL dp[2][MaxN];
int main()
{
 int T,cas=0;scanf("%d",&T);
 while(T--)
 {
 scanf("%s%s",s1,s2+1);
 int n = strlen(s2+1), m = strlen(s1);
 bool ok = 1;
 for(int i = 1; i <= n; i++)if(s2[i]!='*')ok=0;
 if(ok)
 {
 printf("Case %d: %d\n",++cas,m*(m+1)/2);
 continue;
 }
 memset(dp, 0, sizeof(dp));
 for(int i = 0; i <= m; i++)dp[0][i]= 1;
 ok = 1;
 bool first = 1;
 for(int i = 1; i <= n; i++)
 {
 int p = i&1;
 int q = 1-p;
 if(s2[i]=='*')
 {
 dp[p][0] = dp[q][0];
 if(first)
 for(int j = 1; j <= m; j++)
 dp[p][j] = dp[p][j-1]+dp[q][j];
 else
 {
 LL mx = dp[q][0];
 for(int j = 1; j <= m; j++)
 {
 mx = max(mx, dp[q][j]);
 dp[p][j] = mx;
 }
 }
 first = 0;
 }
 else if(s2[i]=='?')
 {
 dp[p][0] = 0;
 for(int j = 1; j <= m; j++)
 dp[p][j] = dp[q][j-1];
 }
 else
 {
 dp[p][0] = 0;
 for(int j = 1; j <= m; j++)
 {
 if(s1[j-1]==s2[i])dp[p][j] = dp[q][j-1];
 else dp[p][j] = 0;
 }
 }
 }
 LL ans = 0;
 for(int i = 1; i <= m; i++)
 ans += dp[n&1][i];
 printf("Case %d: %I64d\n",++cas,ans);
 }
 return 0;
}
