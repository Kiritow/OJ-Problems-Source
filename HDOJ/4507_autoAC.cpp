#include <math.h>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long LL;
typedef pair< int,pair<LL,LL> > PILL;
#define F first
#define S second
#define MP make_pair
const int mod = 1e9 + 7;
int digit[20];
LL pow10[20];
PILL dp[20][7][7][2];
bool vis[20][7][7][2];
PILL dfs(int len,int sum,int remain,bool contain,bool fp)
{
    if(!len)
        if(!contain && sum && remain)
            return MP(1,MP(0LL,0LL));
        else
            return MP(0,MP(0LL,0LL));
    if(!fp && vis[len][sum][remain][contain])
        return dp[len][sum][remain][contain];
    PILL ret = MP(0,MP(0,0));
    int fpmax = fp ? digit[len] : 9;
    for(int i=0;i<=fpmax;i++)
    {
        PILL nxt = dfs(len-1,(sum + i) % 7,(remain * 10 + i) % 7,contain | (i == 7),fp && i == fpmax);
        LL pref = i * pow10[len-1] % mod;
        (ret.F += nxt.F) %= mod;
        (ret.S.F += nxt.S.F + pref * nxt.F) %= mod;
        (ret.S.S += nxt.S.S + pref * pref % mod * nxt.F + 2 * pref * nxt.S.F) %= mod;
    }
    if(!fp)
    {
        vis[len][sum][remain][contain] = true;
        dp[len][sum][remain][contain] = ret;
    }
    return ret;
}
long long f(long long n)
{
    int len = 0;
    while(n)
    {
        digit[++len] = n % 10;
        n /= 10;
    }
    return dfs(len,0,0,0,true).S.S;
}
int main()
{
    pow10[0] = 1;
    for(int i=1;i<20;i++)
        pow10[i] = pow10[i-1] * 10 % mod;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        long long a,b;
        scanf("%I64d%I64d",&a,&b);
        printf("%I64d\n",(f(b) - f(a-1) + mod) % mod);
    }
    return 0;
}
