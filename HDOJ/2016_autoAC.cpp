#include <cstdio>
#include <algorithm>
using namespace std;
int main(void)
{
    int i, n;
    int f[100], m;
    while (scanf("%d", &n), n)
    {
        m = 0;
        for (i = 0 ; i < n ; i++)
        {
            scanf("%d", f + i);
            if (f[i] < f[m]) m = i;
        }
        swap(f[m], f[0]);
        for (i = 0 ; i < n ; i++)
            printf("%d%c", f[i], (i < n - 1 ? ' ' : '\n'));
    }
    return 0;
}
