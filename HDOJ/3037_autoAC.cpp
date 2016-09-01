#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
ll fac[100003];
void init(ll p) {
    fac[0] = 1;
    for (int i=1; i<=p; i++) fac[i] = fac[i-1]*i%p;
}
ll PowerMod(ll a, ll b, ll k) {
    ll tmp = a, ret = 1;
    while (b) {
        if (b & 1) ret = ret * tmp % k;
        tmp = tmp * tmp % k;
        b >>= 1;
    }
    return ret;
}
ll Lucas(ll n, ll m, ll p) {
    ll ret = 1;
    while (n && m) {
        ll nn = n%p, mm = m%p;
        if (nn < mm) return 0;
        ret = ret*fac[nn]*PowerMod(fac[mm]*fac[nn-mm]%p, p-2, p)%p;
        n /= p;
        m /= p;
    }
    return ret;
}
int main() {
    int T;
    ll n, m, p;
    cin >> T;
    while (T--) {
        cin >> n >> m >> p;
        init(p);
        cout << Lucas(n+m, m, p) << endl;
    }
    return 0;
}
