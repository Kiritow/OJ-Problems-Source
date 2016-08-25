#include <stdio.h>
#include <string.h>
int a[10010];
int gcd(int a, int b)
{
    return b > 0 ? gcd(b, a%b) : a;
}
int n, m;
void Solve()
{
    while(~scanf("%d%d", &n, &m))
    {
        if(!n && !m)
        {
            break;
        }
        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                scanf("%d", &a[i]);
            }
            sum += a[i];
        }
        for(int i = 0; i < n; ++i)
        {
            int t = gcd(sum, a[i]);
            printf("%d / %d\n", a[i]/t, sum/t);
        }
    }
}
int main()
{
    Solve();
    return 0;
}
