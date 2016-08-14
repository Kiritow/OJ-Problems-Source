#include <cstdio>
#include <cstring>
using namespace std;
#define MAXN 320005
int c[MAXN];
int lowbit(int x)
{
    return x & -x;
}
int Sum(int n)
{
    int sum = 0;
    while (n > 0) {
        sum += c[n];
        n -= lowbit(n);
    }
    return sum;
}
void update(int i, int x)
{
    while (i<=MAXN) {
        c[i] += x;
        i += lowbit(i);
    }
}
int ans[MAXN];
int main()
{
    int n, x, y;
    while (~scanf("%d", &n)) {
        memset(c, 0, sizeof(c));
        memset(ans, 0, sizeof(ans));
        for (int i=0; i<n; i++) {
            scanf("%d%d", &x, &y);++x;
            ans[Sum(x)]++;
            update(x, 1);
        }
        for (int i=0; i<n; i++) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
