#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1001
int num[MAXN*MAXN];
int main(int argc, char** argv) {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d%d", &n, &m);
        getchar();
        char a, b;
        int valA, valB;
        int len = 0, i;
        while (m--) {
            scanf("%c=%d,%c=%d", &a, &valA, &b, &valB);
            getchar();
            if (a == 'X') {
                if (b == 'Y')
                    for (i = 1; i <= n; ++i)
                        num[len++] = valA * n * n + valB * n + i;
                else
                    for (i = 1; i <= n; ++i)
                        num[len++] = valA * n * n + i * n + valB;
            } else if (a == 'Y') {
                if (b == 'X')
                    for (i = 1; i <= n; ++i)
                        num[len++] = valB * n * n + valA * n + i;
                else
                    for (i = 1; i <= n; ++i)
                        num[len++] = i * n * n + valA * n + valB;
            } else {
                if (b == 'X')
                    for (i = 1; i <= n; ++i)
                        num[len++] = valB * n * n + i * n + valA;
                else
                    for (i = 1; i <= n; ++i)
                        num[len++] = i * n * n + valB * n + valA;
            }
        }
        sort(num, num + len);
        int sum(1);
        int p = 0;
        for (i = 1; i < len; ++i) {
            if (num[i] != num[p])
                p = i, ++sum;
        }
        printf("%d\n", sum);
    }
    return 0;
}
