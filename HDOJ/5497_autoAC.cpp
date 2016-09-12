#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
using namespace std;
#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, m, a[N], b[N], c[N];
void add(int *b, int i, int v) {
    for(; i <= n; i += i & -i) b[i] += v;
}
int sum(int *b, int i) {
    int ret = 0;
    for(; i; i -= i & -i) ret += b[i];
    return ret;
}
inline int read() {
    int c, x;
    while(c = getchar(), !isdigit(c));
    x = c - '0';
    while(c = getchar(), isdigit(c)) x = x * 10 + c - '0';
    return x;
}
int main() {
    ios_base::sync_with_stdio(0);
    int t; t = read();
    while(t--) {
        n = read(); m = read();
        for(int i = 1; i <= n; ++i) a[i] = read();
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        long long tmp = 0;
        for(int i = m + 1; i <= n; ++i) {
            tmp += i - m - 1 - sum(c, a[i]);
            add(c, a[i], 1);
        }
        long long ans = tmp;
        for(int i = m + 1; i <= n; ++i) {
            tmp -= sum(c, a[i] - 1);
            tmp -= sum(b, n) - sum(b, a[i]);
            add(c, a[i], -1);
            tmp += sum(c, a[i - m] - 1);
            tmp += sum(b, n) - sum(b, a[i - m]);
            add(b, a[i - m], 1);
            ans = min(ans, tmp);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
