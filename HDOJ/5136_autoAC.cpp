#include<cstdio>
#include<ctype.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<stack>
#include<cmath>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<string.h>
#include<string>
#include<sstream>
#include<bitset>
using namespace std;
#define ll __int64
#define ull unsigned long long
#define eps 1e-8
#define NMAX 1000000005
#define MOD 1000000007
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define PI acos(-1)
template<class T>
inline void scan_d(T &ret)
{
    char c;
    int flag = 0;
    ret=0;
    while(((c=getchar())<'0'||c>'9')&&c!='-');
    if(c == '-')
    {
        flag = 1;
        c = getchar();
    }
    while(c>='0'&&c<='9') ret=ret*10+(c-'0'),c=getchar();
    if(flag) ret = -ret;
}
ll dp[100005],sum[100005];
void cal()
{
    ll a = 3,b = MOD-2,ret = 1;
    while(b)
    {
        if(b&1) ret = ret*a%MOD;
        a = a*a%MOD;
        b >>= 1;
    }
    cout<<ret<<endl;
}
int main()
{
    dp[1] = dp[2] = 1;
    sum[0] = 1;
    sum[1] = 2;
    ll tmp = 1;
    for(int i = 3; i <= 100000; i++)
    {
        if(i%2)
        {
            ll a = ((tmp*(tmp-1LL+MOD)%MOD*(tmp-2LL+MOD)%MOD)*166666668LL%MOD + tmp*(tmp-1LL+MOD)%MOD + tmp)%MOD;
            dp[i] = (sum[i/2-1]*((tmp*(tmp-1LL+MOD)%MOD)*500000004LL%MOD+tmp)%MOD+a)%MOD;
        }
        else
        {
            ll a = tmp*sum[i/2-2]%MOD;
            tmp = (tmp*(tmp-1LL+MOD)%MOD*500000004LL%MOD+tmp+a)%MOD;
            dp[i] = (tmp*(tmp-1LL+MOD)%MOD*500000004LL%MOD+tmp)%MOD;
            sum[i/2] = (sum[i/2-1]+tmp)%MOD;
        }
    }
    int n;
    while(~scanf("%d",&n) && n)
    {
        printf("%I64d\n",dp[n]);
    }
    return 0;
}
