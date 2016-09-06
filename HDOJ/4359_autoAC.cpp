#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<vector>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-9
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=365;
const int mod=1000000000+7;
ll dp[maxn][maxn],C[maxn][maxn];
void Init()
{
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for(int i=1;i<maxn;++i)
    {
        C[i][0]=1;
        for(int j=1;j<=i;++j)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=mod) C[i][j]-=mod;
        }
    }
}
ll f(int n,int d)
{
    if(n==1&&d>=1) return 1;
    if(n==1||d==0) return 0;
    if(dp[n][d]!=-1) return dp[n][d];
    ll &ans=dp[n][d];
    ans=0;
    ans=(ans+f(n-1,d-1)*n*2)%mod;
    for(int k=1;k<=n-2;++k)
        ans=(ans+(f(k,d-1)*f(n-k-1,d-1)%mod*C[n-2][k]%mod)*n)%mod;
    return ans;
}
int main()
{
    Init();
    memset(dp,0xff,sizeof(dp));
    int t,tcase=0,n,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&d);
        ll ans=f(n,d)-f(n,d-1);
        ans=(ans+mod)%mod;
        printf("Case #%d: %I64d\n",++tcase,ans);
    }
    return 0;
}
