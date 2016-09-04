#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[510][510];    
int tt[510][510], an[510];
int main()
{
    int i, j, k;
    int n, a, b;
    while(scanf("%d", &n) != EOF)
    {
        memset(dp, 0, sizeof(dp));
        memset(an, 0, sizeof(an));
        memset(tt, 0, sizeof(tt));
        for(i = 0; i < n; ++i) {
            scanf("%d %d", &a, &b);
            if(a+b < n && tt[a][n-b] < (n-a-b))
                tt[a][n-b]++;
        }
        for(i = 1; i <= n; ++i)
        for(j = 0; j < i; ++j) {
            dp[j][i] = an[j]+tt[j][i];
            an[i] = max(an[i], dp[j][i]);
        }
        printf("%d\n", an[n]);
    }
    return 0;
}
