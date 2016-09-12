#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef pair <int, int> PII;
const int N = 1e5 + 7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double EPS = 1e-6;
const double PI = acos(-1.0);
int a[N];
LL l[N], r[N];
int main(void){
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, p;
        scanf("%d%d", &n, &p);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);
        l[0] = r[0] = l[n + 1] = r[n + 1] = 0;
        for (int i = 1; i <= n; ++i)
            l[i] = max(l[i - 1] + a[i], (LL)a[i]);
        for (int i = n; i; --i)
            r[i] = max(r[i + 1] + a[i], (LL)a[i]);
        LL ans = -INF;
        for (int i = 1; i <= n; ++i) {
            ans = max(ans, max(l[i - 1], 0LL) + max(r[i + 1], 0LL) + p);
        }
        for (int i = 1; i < n; ++i) {
            ans = max(ans, l[i]);
        }
        for (int i = n; i > 1; --i) {
            ans = max(ans, r[i]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
