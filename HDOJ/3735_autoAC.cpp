#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#define MOD 1000000003
#define MAXN 2010
using namespace std;
using namespace std;
long long n, m, b[MAXN], e[MAXN] = {0}, zero[MAXN] = {0};
struct poly {
 long long a[MAXN];
 poly(long long ta[]) {
 for (int i = 0; i < 2 * m; i++) a[i] = ta[i];
 }
 poly operator*(const poly & po) {
 poly re(zero);
 for (int i = 0; i < m; i++) {
 if (po.a[i])
 for (int j = 0; j < m; j++) {
 re.a[i + j] += a[j] * po.a[i];
 re.a[i + j] %= MOD;
 }
 }
 for (int i = 2 * m - 1; i >= m; i--) {
 if (re.a[i])
 for (int j = 0; j < m; j++) {
 re.a[i + j - m] += b[j] * re.a[i];
 re.a[i + j - m] %= MOD;
 }
 a[i] = 0;
 }
 return re;
 }
 void left() {
 for (int i = m - 1; i >= 0; i--) a[i + 1] = a[i];
 a[0] = 0;
 for (int j = 0; j < m; j++) {
 a[j] += b[j] * a[m];
 a[j] %= MOD;
 }
 a[m] = 0;
 }
 void square() {
 long long ans[MAXN] = {0};
 for (int i = 0; i < m; i++) {
 if (a[i])
 for (int j = 0; j < m; j++) {
 ans[i + j] += a[j] * a[i];
 ans[i + j] %= MOD;
 }
 }
 for (int i = 2 * m - 1; i >= m; i--) {
 if (ans[i])
 for (int j = 0; j < m; j++) {
 ans[i + j - m] += b[j] * ans[i];
 ans[i + j - m] %= MOD;
 }
 ans[i] = 0;
 }
 for (int i = 0; i < 2 * m; i++) a[i] = ans[i];
 }
 poly operator^(long long power) {
 poly re(e), tem(e);
 if (power <= 0) return re;
 tem.left();
 while (power) {
 if (power & 1) re = re * tem;
 power >>= 1;
 tem.square();
 }
 return re;
 }
};
long long ai[MAXN];
int main() {
 int cc;
 cin >> cc;
 e[0] = 1;
 while (cc--) {
 cin >> m >> n;
 memset(ai, 0, sizeof (ai));
 memset(b, 0, sizeof (b));
 for (int i = 0; i < m; i++) scanf(" %I64d", ai + i);
 for (int i = 0; i < m; i++) scanf(" %I64d", b + i);
 poly tem(b), ta(ai);
 tem = tem^n;
 long long ans = 0;
 for (int i = 0; i < m; i++)
 ans = (ans + tem.a[i] * ta.a[i]) % MOD;
 cout << ans << endl;
 }
}
