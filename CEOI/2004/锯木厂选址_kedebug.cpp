/// Day2 : Two sawmills
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAXN = 20010;
const int INFS = 0x7fffffff;

int w[MAXN], d[MAXN], x[MAXN], deq[MAXN];

inline double slope(int i, int j)
{
    return 1.0 * (w[i] * x[i] - w[j] * x[j]) / (w[i] - w[j]);
}

int main()
{
    freopen("two.in","r",stdin);
    freopen("two.out","w",stdout);

    int n;
    scanf("%d\n", &n);

    for (int i = 1; i <= n; ++i)
        scanf("%d %d", &w[i], &d[i]);

    w[0] = d[0] = x[1] = 0;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        x[i+1] = x[i] + d[i];
        sum += x[i] * w[i], w[i] += w[i-1];
    }

    int ans = INFS;
    int s = 0, e = -1;
    for (int i = 1; i <= n; ++i)
    {
        while (s < e && slope(deq[e], deq[e-1]) >= slope(i, deq[e]))
            --e;
        deq[++e] = i;
        while (s < e && slope(deq[s], deq[s+1]) <= x[i])
            ++s;

        int delta = -sum + w[i] * x[i] + (w[n] - w[i]) * x[n+1];
        ans = min(ans, delta + w[deq[s]] * x[deq[s]] - x[i] * w[deq[s]]);
    }
    printf("%d\n", ans);

    fclose(stdin);
    fclose(stdout);
    return 0;
}
