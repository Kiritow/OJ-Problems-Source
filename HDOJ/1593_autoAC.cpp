#include <stdio.h>
#define PI 3.1415926
int main()
{
    double R, v1, v2, r;
    while(~scanf("%lf%lf%lf", &R, &v1, &v2))
    {
        r = R * v1 / v2;
        printf((R - r) / v1 < PI * R / v2 ? "Yes\n" : "No\n");
    }
    return 0;
}
