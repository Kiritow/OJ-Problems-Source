#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MOD = 9999991;
int C[1010][1010];
int dp1[2020][1010];
int dp2[2020][1010];
int x,y;
int n,m;
int k;
void add(int &a,int b)
{
    a += b;
    if(a >= MOD)a -= MOD;
}
int sum1[1010];
int sum2[1010];
void init()
{
    C[0][0] = 1;
    for(int i = 1;i < 1010;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i;j++)
        {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
            if(C[i][j] >= MOD)
                C[i][j] -= MOD;
        }
    }
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    dp1[y][0] = 1;
    for(int t = 1;t <= k;t++)
        for(int i = 1;i <= m;i++)
        {
            dp1[i][t] = 0;
            if(i-2 >= 1)
            {
                add(dp1[i][t],dp1[i-2][t-1]);
            }
            if(i - 1 >= 1)
            {
                add(dp1[i][t],dp1[i-1][t-1]);
            }
            if(i + 1 <= m)
            {
                add(dp1[i][t],dp1[i+1][t-1]);
            }
            if(i+2 <= m)
            {
                add(dp1[i][t],dp1[i+2][t-1]);
            }
        }
    dp2[x][0] = 1;
    for(int t = 1;t <= k;t++)
        for(int i = 1;i <= n;i++)
        {
            dp2[i][t] = 0;
            if(i-2 >= 1)
            {
                add(dp2[i][t],dp2[i-2][t-1]);
            }
            if(i - 1 >= 1)
            {
                add(dp2[i][t],dp2[i-1][t-1]);
            }
            if(i + 1 <= n)
            {
                add(dp2[i][t],dp2[i+1][t-1]);
            }
            if(i+2 <= n)
            {
                add(dp2[i][t],dp2[i+2][t-1]);
            }
        }
    memset(sum1,0,sizeof(sum1));
    for(int i = 0;i <= k;i++)
        for(int j = 1;j <= m;j++)
            add(sum1[i],dp1[j][i]);
    memset(sum2,0,sizeof(sum2));
    for(int i = 0;i <= k;i++)
        for(int j = 1;j <= n;j++)
            add(sum2[i],dp2[j][i]);
}
int main()
{
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        printf("Case #%d:\n",iCase);
        scanf("%d%d%d%d%d",&n,&m,&k,&x,&y);
        init();
        long long ans = 0;
        for(int i = 0;i <= k;i++)
        {
            ans += (long long)C[k][i] * sum1[i]%MOD*sum2[k-i]%MOD;
            ans %= MOD;
        }
        printf("%d\n",(int)ans);
    }
    return 0;
}
