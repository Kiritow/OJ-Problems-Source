#include <cstdio>
#include <string.h>
using namespace std;
#define P 50000000001507329LL
#define G 3
int T;
int n, s[110000];
long long ans[140000], a[140000], b[140000], c[140000], x[140000], w[140000];
long long pu[110000];
int nn;
long long Mul(long long x, long long y) {
    return (x*y-(long long)(x/(long double)P*y+1e-3)*P+P)%P;
}
long long Pow(long long x, long long y) {
    long long i, ans = 1;
    for (i = 1; i <= y; i *= 2, x = Mul(x, x)) if (y & i)  ans = Mul(ans, x);
    return ans;
}
void DFT(long long *a, int n) {
    int m, i, d, p, q;
    for (m = 1; (1 << m) <= n; m++){
        for (i = 0; i < (n >> m); i++)
        for (q = 0, d = p = i; d < n; q += (n >> m), d += (n >> (m - 1)), p += (n >> m)){
            x[p] = (Mul(a[d + (n >> m)], w[q]) + a[d]) % P;
            x[p + n / 2] = (Mul(a[d + (n >> m)], w[q + n / 2]) + a[d]) % P;
        }
        for (i = 0; i < n; i++) a[i] = x[i];
    }
}
void DFT1(long long *a, int n){
    int m, i, d, p, q;
    for (m = 1; (1 << m) <= n; m++) {
        for (i = 0; i < (n >> m); i++)
        for (q = 0, d = p = i; d < n; q += (n >> m), d += (n >> (m - 1)), p += (n >> m)){
            x[p] = (Mul(a[d + (n >> m)], w[n - q]) + a[d]) % P;
            x[p + n / 2] = (Mul(a[d + (n >> m)], w[n / 2 - q]) + a[d]) % P;
        }
        for (i = 0; i < n; i++) a[i] = x[i];
    }
}
void doit() {
    long long S = Pow(n, P - 2);
    DFT(a, n);
    DFT(b, n);
    for (int i = 0; i < n; i++)
        c[i] = Mul(a[i], b[i]);
    DFT1(c, n);
    for (int i = 0; i < n; i++)
        c[i] = Mul(c[i], S);
    for (int i = 0; i < n; i++)
        ans[i] = (ans[i] + c[i]) % P;
}
int main() {
    scanf("%d", &T);
    n = 131072;
    for (int i = 0; i <= n; i++)
        w[i] = Pow(G, (P - 1) / n * i);
    s[0] = 0;
    while (T--) {
        scanf("%d", &nn);
        for (int i = 1; i <= nn; i++)
            scanf("%d", &s[i]), s[i] += s[i - 1];
        memset(ans, 0, sizeof ans);
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 1; i <= nn; i++)
            a[s[i]] += i;
        for (int i = 1; i <= nn; i++)
            b[s[nn] - s[i - 1]]++;
        doit();
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        for (int i = 0; i <= 50000; i++)
            a[i] = b[i] = 0;
        for (int i = 1; i <= nn; i++)
            a[s[i]] = (a[s[i]] + P - 1) % P;
        for (int i = 1; i <= nn; i++)
            b[s[nn] - s[i - 1]] += i - 1;
        doit();
        long long ans0 = 0;
        int q, h;
        for (int i = 1; i <= nn; i++)
            pu[i] = pu[i - 1] + 1LL * i * (i + 1) / 2;
        for (q = 1; q <= nn; q = h + 1)
            if (s[q] != s[q - 1]) h = q;
            else {
                for (h = q; h < nn && s[h + 1] == s[q]; h++);
                ans0 += pu[h - q + 1];
            }
        printf("%lld\n", ans0);
        for (int i = 1; i <= s[nn]; i++)
            printf("%lld\n", ans[i + s[nn]]);
    }
}
