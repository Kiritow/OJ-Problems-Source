#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define LL long long
#define M 500005
#define N 19
int cal(int n, int x)
{
    int res = 0;
    do
    {
        ++res;
        n /= x;
    }
    while (n % x == 0);
    return res;
}
int F[M][N];
int num[M];    
int h[M];        
int mob(int n)
{
    if (h[n] == -1) return 0;    
    if (h[n] & 1) return -1;
    return 1;                    
}
int main()
{
    int t, n, m, p, i, j;
    for (i = 2; i < M; i++)
    {
        if (num[i]) continue;
        for (j = i; j < M; j+=i)
        {
            int tp = cal(j, i);
            num[j] += tp;
            if (tp > 1)      
            {
                h[j] = -1;
            }
            else if (h[j] >= 0)
            {
                ++h[j];
            }
        }
    }
    for (i = 1; i < M; i++)
    {
        for (j = i; j < M; j+=i)
        {
            F[j][num[i]] += mob(j/i);
        }
    }
    for (i = 1; i < M; i++)
    {
        for (j = 1; j < N; j++)
        {
            F[i][j] += F[i][j-1];
        }
    }
    for (i = 1; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            F[i][j] += F[i-1][j];
        }
    }
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &p);
        LL ans = 0;
        if (p >= N)
        {
            ans = (LL)n*m;
        }
        else
        {
            if (n > m)
            {
                n ^= m;
                m ^= n;
                n ^= m;
            }
            for (i = 1; i <= n; i = j + 1)
            {
                j = min(n/(n/i), m/(m/i));
                ans += ((LL)F[j][p]-F[i-1][p])*(n/i)*(m/i);
            }
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
