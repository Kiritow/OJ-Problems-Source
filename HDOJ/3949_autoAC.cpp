#include<cstdio>
#include<algorithm>
#define MAXN 10010
typedef long long LL;
using namespace std;
int n;
LL a[MAXN];
void Gauss() {
    int i, j, k, t;
    k = 0;
    for (i = 60; i >= 0; i--) {
        for (j = k; j < n; j++) {
            if ((a[j] >> i) & 1)
                break;
        }
        if (j < n) {
            swap(a[j], a[k]);
            for (t = 0; t < n; t++) {
                if (t != k && ((a[t] >> i) & 1))
                    a[t] ^= a[k];
            }
            k++;
        }
    }
    sort(a, a + n);
    n = unique(a, a + n) - a;
}
LL Cal(int k) {
    LL ans;
    int i;
    ans = i = 0;
    if (a[0] == 0) {
        if (k == 1)
            return 0;
        k--;
        i++;
    }
    for (; i < n && k; k >>= 1, i++) {
        if (k & 1)
            ans ^= a[i];
    }
    if (i == n && k)
        return -1;
    return ans;
}
int main() {
    int c, ca = 1;
    int i, q;
    LL k;
    scanf("%d", &c);
    while (c--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%I64d", &a[i]);
        Gauss();
        scanf("%d", &q);
        printf("Case #%d:\n", ca++);
        while (q--) {
            scanf("%I64d", &k);
            printf("%I64d\n", Cal(k));
        }
    }
    return 0;
}
