#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#define eps 1e-10
#define LL long long
#define INF 0x3f3f3f3f
#define PI 3.1415926535898
#define zero(x) ((fabs(x)<eps)?0:x)
using namespace std;
const int maxn = 100010;
#define mod 998244353
int num[21];
LL dp[15][2100];
LL use[15][2100];
LL f[maxn];
int n;
int add(int x)
{
    if(x == 0) return 20;
    int ans = 0;
    while(x!=1)
    {
        if(x&1) return 20;
        x >>= 1;
        ans++;
    }
    return ans;
}
LL q_mod(LL a,LL b,LL n)
{
    LL ret=1;
    LL tmp=a%n;
    while(b)
    {
        if(b&0x1) ret=ret*tmp%n;
        tmp=tmp*tmp%n;
        b>>=1;
    }
    return ret;
}
LL Del(int n, int m)
{
    if(m > n) return 0LL;
    LL ans = f[n];
    ans = (ans*q_mod((f[m]*f[n-m])%mod, mod-2, mod))%mod;
    return ans;
}
void select()
{
    for(int i = 1; i <= 11; i++)
        for(int j = 0; j < 2048; j++) use[i][j] = Del(num[i-1], j);
}
void change()
{
    select();
    for(int i = 0; i < 2048; i++) dp[1][i] = use[1][i];
    for(int i = 2; i <= 11; i++)
    {
        int cnt = (1<<(12-i));
        for(int j = 0; j < cnt; j++)
        {
            for(int k = 0; k <= 2*j+1; k += 2)
            {
                if(!use[i][j-k/2] || !(dp[i-1][k]+dp[i-1][k+1])) continue;
                dp[i][j] += ((dp[i-1][k]+dp[i-1][k+1])*use[i][j-k/2])%mod;
            }
            dp[i][j] %= mod;
        }
    }
    LL ans = 0LL;
    ans = q_mod(2, num[20], mod);
    LL ps = (dp[11][0]+dp[11][1])%mod;
    ps = q_mod(2, n-num[20], mod)-ps;
    ps = (ps+mod)%mod;
    ans = (ans*ps)%mod;
    printf("%I64d\n",ans);
}
void init()
{
    f[0] = 1LL;
    for(LL i = 1; i < maxn; i++) f[i] = (f[i-1]*i)%mod;
}
int main()
{
    int Case = 1;
    init();
    while(~scanf("%d",&n) && n)
    {
        memset(num, 0, sizeof(num));
        memset(dp, 0, sizeof(dp));
        int x;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x);
            num[add(x)]++;
        }
        printf("Case #%d: ",Case++);
        change();
    }
    return 0;
}
