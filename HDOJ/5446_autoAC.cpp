#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cassert>
using namespace std;
#define debug 0
const int maxn = 101000;
typedef long long ll;
ll A[maxn], inv[maxn];
int res[20];
int p[20];
void gcd(ll a, ll b, ll d, ll& x, ll& y){
    if (!b) { d = a; x = 1; y = 0; }
    else{ gcd(b, a%b, d, y, x); y -= x*(a/b); }
}
int cal(long long n, long long m, int p){
    A[0] = A[1] = 1;
    inv[0] = inv[1] = 1;
    for (int i = 2; i <= p; i++){
        inv[i] = (long long)(p - p/i) * inv[p % i] % p;
        A[i] = A[i-1] * i % p;
    }
    for (int i = 2; i < p; i++){
        inv[i] = inv[i] * inv[i-1] % p;
    }
    if (debug){
        for (int i = 0; i < p; i++){
            assert(inv[i] * A[i] % p == 1);
            printf("%lld %lld\n", inv[i], A[i]);
        }
    }
    int ret = 1;
    while(n&&m){
        int a = n % p, b = m % p;    
        if (a < b) return 0;
        n /= p, m /= p;
        ret = (long long)ret * A[a] % p * inv[b] % p * inv[a-b] % p;
    }
    return ret;
}
ll mul(ll a, ll b, ll p){
    ll ret = 0;
    for (; a; a>>=1){
        if (a&1){
            ret += b;
            if (ret >= p) ret -= p;
        }
        b <<= 1;
        if (b >= p) b -= p;
    }
    return ret;
}
ll crt(int n, int* a, int *m){
    ll M = 1, d, y, x = 0;
    for (int i = 0; i < n; i++) M *= m[i];
    for (int i = 0; i < n; i++){
        ll w = M / m[i];
        gcd(m[i], w, d, d, y);
        int sign;
        if (y < 0) sign = -1;
        else sign = 1;
        x = (x + mul(y*sign, w*a[i]%M, M) * sign) % M;
    }
    return (x + M) % M;
}
int T;
int main()
{
    scanf("%d", &T);
    while(T--){
        ll n, m; int k;
        scanf("%I64d %I64d %d", &n, &m, &k);
        for (int i = 0; i < k; i++){
            scanf("%d", &p[i]);
            res[i] = cal(n, m, p[i]);
        }
        long long ans = crt(k, res, p);
        printf("%I64d\n", ans);
    }
    return 0;
}
