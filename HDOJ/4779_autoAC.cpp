#pragma comment(linker, "/STACK:1024000000,1024000000")
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
#include<bitset>
#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define eps 1e-6
#define pi acos(-1.0)
using namespace std;
typedef long long ll;
const int maxn=200+5;
const int mod=1e9+7;
ll dp[maxn][maxn][maxn],C[maxn][maxn],A[maxn][maxn],pinv[maxn];
ll pow_mod(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1) res=res*x%mod;
        x=x*x%mod;
        n>>=1;
    }
    return res;
}
ll inv(ll x)
{
    return pow_mod(x,mod-2)%mod;
}
void Init()
{
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for(int i=1;i<maxn;++i)
    {
        C[i][0]=1;
        for(int j=1;j<maxn;++j)
        {
            C[i][j]=C[i-1][j-1]+C[i-1][j];
            if(C[i][j]>=mod) C[i][j]-=mod;
        }
    }
    memset(A,0,sizeof(A));
    A[0][0]=1;
    for(int i=1;i<maxn;++i)
    {
        A[i][0]=1;
        for(int j=i;j>=1;--j)
            A[i][j]=A[i-1][j-1]*i%mod;
    }
    ll x=1;
    pinv[0]=inv(x);
    for(int i=1;i<maxn;++i)
    {
        x=(x<<1)%mod;
        pinv[i]=inv(x);
    }
    memset(dp,0,sizeof(dp));
    for(int i=0;i<maxn;++i)
        for(int j=0;j<maxn;++j)
            dp[i][j][0]=1;
    for(int k=1;k<maxn;++k)
        for(int i=1;i<maxn;++i)
            for(int j=1;j<maxn;++j)
                dp[i][j][k]=(dp[i][j][k-1]+C[i][k]*A[j][k])%mod;
}
int main()
{
    Init();
    int t,n,m,p,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&m,&p,&q);
        ll ans=0,tmp,tmp2;
        for(int x=0;x<=q;++x)
            for(int i=0;i*2<=p;++i)
                for(int j=0;i*2+j*2<=p;++j)
                {
                    int N=n-i-j*2-x;
                    int M=m-i*2-j-x;
                    if(N<0||M<0) continue;
                    tmp2=C[n][x]*A[m][x]%mod;
                    int tot=min(N*M,p-i*2-j*2);
                    tmp=C[n-x][i]*A[m-x][i*2]%mod*pinv[i]%mod;
                    tmp=tmp*C[m-i*2-x][j]%mod*A[n-i-x][j*2]%mod*pinv[j]%mod;
                    if(i||j||x)
                        ans=(ans+dp[N][M][tot]*tmp2%mod*tmp)%mod;
                    else ans=((ans+dp[N][M][tot]-1)*tmp2%mod*tmp)%mod;
                }
        printf("%I64d\n",ans);
    }
    return 0;
}
