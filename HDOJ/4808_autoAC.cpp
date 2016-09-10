#include <cstdio>
#include <cmath>
const int MAXN = 200000 + 5;
double t[MAXN];
int main()
{
    t[0] = acos(-1) / 2., t[1] = 1.;
    for (int i = 2; i < MAXN; ++ i) {
        t[i] = t[i - 2] * (i - 1) / i;
    }
    int n, R;
    while (scanf("%d%d", &n, &R) == 2) {
        double res = .5 * t[n + 1] * R / t[2];
        printf("%.10lf\n", res);
    }
    return 0;
}
