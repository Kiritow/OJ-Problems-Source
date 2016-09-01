#include<stdio.h>
#include<stdlib.h>
#define maxn 1000
#define PI 3.141
const double inf = 0.00001;
double d1[maxn], d2[maxn];
double dis(double x1, double y1, double x2, double y2)
{
    return 1.0 * (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main()
{
    int n, i, j, ans, sum, k = 0;
    double r1, r2, r3, r4, r;
    double x1, y1, x2, y2, x, y;
    while (scanf("%d", &n), n)
    {
        scanf("%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &r);
        r = 1.0 * r / PI;
        for (i = 0; i < n; i++)
        {
            scanf("%lf%lf", &x, &y);
            d1[i] = dis(x, y, x1, y1);
            d2[i] = dis(x, y, x2, y2);
        }
        for (i = 0, ans = n; i < n; i++)
        {
            r1 = d1[i];
            if (r1 <= r)//涓句涓瑰朵腑涓涓濉璺绂r1,╀纾娉㈣绂讳负r2
            {
                r2 = r - r1;
                for (j = 0, sum = 0; j < n; j++)
                {
                    if (d1[j] <= r1)
                    {
                        sum++;
                    }
                    else if (d2[j] <= r2)
                    {
                        sum++;
                    }
                }
                if (ans > n - sum)
                {
                    ans = n - sum;
                }
            }
            r2 = d2[i];
            if (r2 <= r)
            {
                r1 = r - r2;
                for (j = 0, sum = 0; j < n; j++)
                {
                    if (d1[j] <= r1)
                    {
                        sum++;
                    }
                    else if (d2[j] <= r2)
                    {
                        sum++;
                    }
                }
                if (ans > n - sum)
                {
                    ans = n - sum;
                }
            }
        }
        k++;
        printf("%d. %d\n", k, ans);
    }
    return 0;
}
