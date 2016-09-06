#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int V = 100000 + 50;
const int MaxN = 80 + 5;
const int mod = 10000 + 7;
const __int64 INF = 0x7FFFFFFFFFFFFFFFLL;
const int inf = 0x7fffffff;
int n, m, sum[V], ans;
int main() {
    int i, j;
    while(~scanf("%d%d", &n, &m)) {
        ans = 0;
        for(i = 1; i <= n; ++i) {
            int temp;
            scanf("%d", &temp);
            sum[i] = (sum[i - 1] + temp) % m;
        }
        for(i = n; i >= 1 && i > ans; --i) {
            for(j = 1; j + i - 1 <= n; ++j)
                if((sum[j + i - 1] - sum[j - 1]) % m == 0) {
                    ans = max(ans, i);
                    break;
                }
        }
        printf("%d\n", ans);
    }
}
