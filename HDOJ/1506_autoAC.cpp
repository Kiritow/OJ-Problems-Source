#include<cstdio>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
#define maxn 100005
int h[maxn];
int z[maxn], y[maxn];
int main()
{
    int n;
    while(scanf("%d", &n), n)
    {
        int i, j, k=0, x;
        __int64 max=0, sum;
        for(i=0; i<n; i++)
        {
            z[i] = i;
            y[i] = i;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d", &h[i]);
            j = i-1;
            while(z[i] && h[i] <= h[j])
            {
                z[i] = z[j];
                j = z[j] - 1;
            }
        }
        for(i=n-1; i>=0; i--)
        {
            j = i+1;
            while(y[i] != n-1 && h[i] <= h[j])
            {
                y[i] = y[j];
                j = y[j] + 1;
            }
            sum = (__int64)h[i] * (y[i] - z[i] + 1);
            if(max < sum)max = sum;
        }
        printf("%I64d\n", max);
    }
    return 0;
}
