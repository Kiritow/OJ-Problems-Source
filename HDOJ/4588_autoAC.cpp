#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 40;
ll ti[N], p[N], q[N];
void cat (ll x, ll* a) {
    if (x <= 0) return;
    ll ans = 0, s = 0;
    for (int i = 0; i <= 32; i++) {
        ll t = ti[i+1];
        ll c = x/t, d = x%t;
        d -= ti[i];
        a[i] = c * ti[i] + (d <= 0 ? 0 : d);
    }
}
ll solve () {
    ll ans = 0, s = 0;
    for (int i = 0; i <= 32; i++) {
        s = s + p[i] - q[i];
        s /= 2;
        ans += s;
    }
    while (s) {
        s /= 2;
        ans += s;
    }
    return ans;
}
int main () {
    ti[0] = 1;
    for (int i = 1; i <= 35; i++)
        ti[i] = ti[i-1] * 2;
    ll a, b;
    while (cin >> a >> b) {
        memset(p, 0, sizeof(p));
        memset(q, 0, sizeof(q));
        cat (b+1, p);
        cat (a, q);
        cout << solve () << endl;
    }
    return 0;
}
