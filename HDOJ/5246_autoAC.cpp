#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 10005;
long long n, m, k;
long long s[N];
int main() {
    int t, cas = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld%lld", &n, &m, &k);
        for (int i = 0; i < n; i++)
            scanf("%lld", &s[i]);
        sort(s, s + n);
        if (s[0] > m) {
            printf("Case #%d:\nmadan!\n", cas++);
            continue;
        }
        if (s[n - 1] <= m) {
            printf("Case #%d:\nwhy am I so diao?\n", cas++);
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] > m) {
                int flag = 1, flag2 = 0;
                m = s[i - 1];
                for (int j = i; j < n; j++) {
                    if (m + k >= s[j])
                        continue;
                    else {
                        m = s[j - 1];
                        if (k > 0)
                            k--;
                        if (m + k < s[j]) {
                            flag = 0;
                            break;
                        }
                        j--;
                    }
                }
                if (!flag)
                    printf("Case #%d:\nmadan!\n", cas++);
                else
                    printf("Case #%d:\nwhy am I so diao?\n", cas++);
                break;
            }
        }
    }
    return 0;
}
