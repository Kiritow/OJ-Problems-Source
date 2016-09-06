#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 10005;
int n;
int seq[N];
int k1, k2;
LL K;
int main() {
    int T, ca = 0;
    scanf("%d", &T);
    while (T--) {
        LL sum = 0;
        int c;
        scanf("%d %d %d %I64d", &n, &k1, &k2, &K);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &c);
            sum += c;
        }
        printf("Case #%d: ", ++ca);
        if (sum > K) {
            puts("0");
            continue;
        }
        int k3 = k1 + k2;
        if (k3 >= 0) {
            if (k3 <= 1) {
                puts("inf");
            } else {
                int d = 1;
                while ((long double)1.0*sum <= (long double)1.0*K/k3) ++d, sum*=k3;
                printf("%d\n", d);
            }
        } else {
            if (k3 == -1) {
                puts("inf");
            } else {
                k3 *= -1;
                int d = 1;
                while ((long double)1.0*sum <= (long double)1.0*K/k3) ++d, sum*=k3;
                if (d & 1) printf("%d\n", d+1);
                else printf("%d\n", d);
            }
        }
    }
    return 0;
}
