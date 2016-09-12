#include <iostream>
using namespace std;
#define prt(k) cerr<<#k" = "<<k<<endl
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9 + 7;
const int N = 1000100;
ll p[N];
ll a[N];
bool ok(ll n)
{
    int t = p[n];
    while (n % t==0 && n > 1) n /= t;
    return n==1;
}
ll pmod(ll a, ll n)
{
    ll ret = 1;
    for (; n; n>>=1, a=a*a%mod) if (n & 1)
        ret = ret * a % mod;
    return ret;
}
ll inv(ll a)
{
    return pmod(a, mod - 2);
}
int main()
{
    for (int i=1;i<N;i++) p[i]=i;
    for (int i=2;i<N;i++) if (p[i]==i) {
        for (int j=i+i;j<N;j+=i) p[j] = i;
    }
    a[0] = 1;
    for (int i=1;i<N;i++) {
        if (ok(i))
            a[i] = a[i-1] * p[i] % mod;
        else
            a[i] = a[i-1];
    }
    int n; int re; cin>>re;
    while (re--) {
        scanf("%d", &n);
        n++;
        ll ans = a[n] * inv(n) % mod;
        printf("%I64d\n", ans);
    }
}
