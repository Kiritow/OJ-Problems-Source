#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main() 
{
    int i, j, k, N;
    double vl, d;
    while (scanf("%lf%lf", &vl, &d) == 2) {
        double dd = (int) ceil(vl / d);
        int n = (int) (sqrt(2 * dd + 0.25) - 0.5001);
        printf("%d\n", (int) dd + n);
    }
    return 0;
}
