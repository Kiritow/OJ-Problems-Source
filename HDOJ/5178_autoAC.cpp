#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int kase;
    scanf ("%d", &kase);
    while (kase--)
    {
        int n, k;
        long long ans = 0;
        int num[100200], pos[100200];
        scanf ("%d %d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf ("%d", &num[i]);
        }
        sort (num, num + n);
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
            {
                for (int j = i + 1; j <= n; j++)
                    if ( (j < n && num[j] - num[i] > k) || (j == n))
                    {
                        pos[i] = j - 1;
                        ans += j - i - 1;
                        break;
                    }
            }
            else
            {
                for (int j = pos[i - 1]; j <= n; j++)
                    if ( (j < n && num[j] - num[i] > k) || j == n)
                    {
                        pos[i] = j - 1;
                        ans += j - i - 1;
                        break;
                    }
            }
        }
        printf ("%I64d\n", ans);
    }
    return 0;
}
