#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int T, n;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        int k = sqrt(1.0*n), ans = 0x7FFFFFFF;
        for (int i = 1; i <= k; i++)
            if (n%i == 0) ans = min(ans, 2 * (i + n / i));
        printf("%d\n", ans);
    }
    return 0;
}
