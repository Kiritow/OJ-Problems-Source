#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 100005;
int n, s[N], f[N];
int main() {
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int a;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            s[i] = a - i;
        }
        int k = 0;
        f[k++] = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] >= f[k - 1])
                f[k++] = s[i];
            else {
                int pos = upper_bound(f, f + k, s[i]) - f;
                f[pos] = s[i];
            }
        }
        printf("Case #%d:\n%d\n", cas++, n - k);
    }
    return 0;
}
