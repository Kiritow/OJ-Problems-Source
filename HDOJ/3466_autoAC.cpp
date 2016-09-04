#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <map>
#define LL long long
using namespace std;
typedef struct
{
    int p,q,v;
}item;
const int N = 510;
const int M = 5010;
int n,m;
item t[N];
int dp[M];
void zero_dp(int i)
{
    for(int j = m; j >= t[i].p && j >= t[i].q; j--)
        dp[j] = max(dp[j], dp[j-t[i].p]+t[i].v);
}
int cmp(const void *a, const void *b)
{
    item *aa = (item *)a, *bb = (item *)b;
    return (aa->q-aa->p) - (bb->q-bb->p);
}
int main()
{
    int i,j,k;
    while(~scanf("%d%d", &n, &m))
    {
        for(i = 0; i < n; i++)
        {
            scanf("%d%d%d", &t[i].p, &t[i].q, &t[i].v);
            if(t[i].q > m) i--,n--;
        }
        qsort(t, n, sizeof(t[0]), cmp);
        memset(dp, 0, sizeof(dp));
        for(i = 0; i < n; i++)
            zero_dp(i);
        printf("%d\n", dp[m]);
    }
    return 0;
}
