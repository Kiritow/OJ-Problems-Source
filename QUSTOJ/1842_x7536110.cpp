#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <stack>
using namespace std;
#define mod 1004535809LL
#define G 3LL
#define maxn 455555
 
long long x1[maxn], x2[maxn];
long long qpow (long long a, long long b) {
    long long ret=1;
    while (b) {
        if (b&1) ret = (ret*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }
    return ret;
}
 
void change (long long *y, int len) {
    int i, j, k;
    for(i = 1, j = len / 2; i < len - 1; i++) {
        if (i < j) swap(y[i], y[j]);
        k = len / 2;
        while (j >= k) {
            j -= k;
            k /= 2;
        }
        if (j < k) j += k;
    }
}
 
void ntt (long long *y, int len, int on) {
    change (y, len);
    int id = 0;
    for(int h = 2; h <= len; h <<= 1) {
        id++;
        long long wn = qpow (G, (mod - 1) / (1<<id));
        for(int j = 0; j < len; j += h) {
            long long w = 1;
            for(int k = j; k < j + h / 2; k++) {
                long long u = y[k] % mod;
                long long t = w * (y[k + h / 2] % mod) % mod;
                y[k] = (u + t) % mod;
                y[k + h / 2] = ((u - t) % mod + mod) % mod;
                w = w * wn % mod;
            }
        }
    }
    if (on == -1) {
        for (int i = 1; i < len / 2; i++)
            swap (y[i], y[len - i]);
        long long inv = qpow(len, mod - 2);
        for(int i = 0; i < len; i++)
            y[i] = y[i] % mod * inv % mod;
    }
}
 
long long n, m;
long long f[maxn], g[maxn], h[maxn];
//n个点的有环图 n个点的图 n个点的树
long long fac[maxn], rev[maxn];
 
void solve (int l, int r) { //cout << l << " " << r << endl;
    if (l == r) {
        f[l] += h[l];
        f[l] %= mod;
        return;
    }
    int mid = (l+r) >> 1;
    solve (l, mid);
    int len = 1;
    while (len <= r-l+1) {len <<= 1;}
    for (int i = 0; i < len; i++) {
        x1[i] = x2[i] = 0;
    }
    for (int i = l; i <= mid; i++) {
        x1[i-l] = f[i]*rev[i]%mod;
    }
    for (int i = 1; i <= r-l; i++) {
        x2[i-1] = h[i]*rev[i-1]%mod;
    }
    ntt (x1, len, 1), ntt (x2, len, 1);
    for (int i = 0; i < len; i++) x1[i] = x1[i] * x2[i] % mod;
    ntt (x1, len, -1);
    for (int i = mid+1; i <= r; i++) {
        f[i] += x1[i-l-1]*fac[i-1] %mod;
        f[i] %= mod;
    }
    //cout << l << " " << r << endl;
    //for (int i = 1; i <= 4; i++) cout << f[i] << " "; cout << endl;
    solve (mid+1, r);
}
 
int main () {
   // freopen ("in", "r", stdin);
  //  freopen ("out", "w", stdout);
  //  //int t1 = clock ();
    g[1] = h[1] = 1;
    for (int i = 2; i <= 200000; i++) {
        h[i] = qpow (i, i-2);
        g[i] = qpow (2, 1LL*i*(i-1)/2);
    }
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) fac[i] = fac[i-1] * i % mod;
    rev[200000] = qpow (fac[200000], mod - 2);
    for (int i = 200000-1; i >= 0; i--) rev[i] = rev[i+1] * (i+1) % mod;
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%lld", &n);
        memset (f, 0, sizeof f);
        solve (1, n);
        long long ans = g[n]-f[n];
        (ans %= mod) += mod; ans %= mod;
        printf ("%lld\n", ans);
    }
    //int t2 = clock ();
    //cout << t2-t1 << endl;
    return 0;
}
