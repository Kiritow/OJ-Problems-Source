#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
const int maxn = 1005;
bitset<maxn> a[maxn];
int main() {
    int t, cas = 1;
    int n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            a[i].reset();
            a[i][i] = 1;
        }
        int c, x;
        for (int i = 0; i < n; i++) {
            scanf("%d", &c);
            while (c--) {
                scanf("%d", &x);
                a[i][--x] = 1;
            }
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) 
                if (a[j][i])
                    a[j] |= a[i];
        double ans = 0;
        for (int i = 0; i < n; i++) {
            c = 0;
            for (int j = 0; j < n; j++)
                if (a[j][i]) 
                    c++;
            ans += 1.0 / c;
        }
        printf("Case #%d: %.5lf\n",cas++,ans);
    }
    return 0;
}
