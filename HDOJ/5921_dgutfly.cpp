//Thanks to Fsss_7
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<bitset>
#include<math.h>
#include<vector>
#include<string>
#include<stdio.h>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N=400010;
const int M=50010;
const int mod=1000000007;
const int MOD1=1000000007;
const int MOD2=1000000009;
const double EPS=0.00000001;
typedef long long ll;
const ll MOD=1000000007;
const int INF=1000000010;
const ll MAX=1ll<<55;
const double eps=1e-5;
const double inf=~0u>>1;
const double pi=acos(-1.0);
typedef long double db;
typedef unsigned int uint;
typedef unsigned long long ull;
int a[100];
ll b[100],c[100],e[100];
ll get(int len) {
    ll ret=0;
    for (int i=0;i<len;i++) ret+=a[i];
    for (int i=len-1;i>=0;i--)
    if (a[i]) {
        if (i) (ret+=c[i-1])%MOD;
        (ret+=b[i+1]*e[i]%MOD)%=MOD;
    } else (ret+=b[i+1]*e[i]%MOD)%=MOD;
    return ret;
}
ll getlcp(int len) {
    ll ret=0;
    for (int i=len-1;i>=0;i--)
    if (a[i]) {
        if (i) (ret+=(c[i-1]+1)*(c[i-1]+1)%MOD)%=MOD;
        else (ret+=1ll)%=MOD;
        (ret+=b[i+1]*e[i]%MOD*e[i]%MOD)%=MOD;
    } else (ret+=b[i+1]*e[i]%MOD*e[i]%MOD)%=MOD;
    return ret;
}
int main()
{
    int i,ca,T,len;
    ll n,m,ans;
    scanf("%d", &T);
    for (i=0;i<63;i++) e[i]=(1ll<<i)%MOD;
    for (ca=1;ca<=T;ca++) {
        scanf("%I64d", &n);m=n;
        for (len=0;m;m>>=1) a[len++]=m%2;
        b[len]=0;c[0]=a[0];
        for (i=1;i<len;i++) c[i]=(c[i-1]+(a[i]*1ll<<i))%MOD;
        for (i=len-1;i>=0;i--) b[i]=((b[i+1]<<1)+a[i])%MOD;
        ans=((n+1)%MOD*get(len))%MOD;
        printf("Case #%d: %I64d\n", ca, ((ans-getlcp(len))%MOD+MOD)%MOD);
    }
    return 0;
}
