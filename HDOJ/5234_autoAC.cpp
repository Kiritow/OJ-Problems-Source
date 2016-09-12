#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>
#define Max 2147483647
#define INF 0x7fffffff
#define N 110
#define ll long long
#define mem(a,b) memset(a,b,sizeof(a))
#define repu(i, a, b) for(int i = (a); i < (b); i++)
const double PI=-acos(-1.0);
using namespace std;
int dp[N][N][N];
int w[N][N];
int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        repu(i,0,1+n)
        repu(j,0,m+1)
        repu(p,0,k+1)
        dp[i][j][p] = 0;
        repu(i,1,1+n)
        repu(j,1,1+m)
        scanf("%d",&w[i][j]);
        repu(i,1,n+1)
        {
            repu(j,1,m+1)
            {
                for(int p = w[i][j]; p<=k; p++)
                {
                    int t = max(dp[i-1][j][p],dp[i][j-1][p]);
                    int s = max(dp[i-1][j][p-w[i][j]]+w[i][j],dp[i][j-1][p-w[i][j]]+w[i][j]);
                    dp[i][j][p] = max(t,s);
                }
            }
        }
        int maxn = 0;
        repu(p,0,k+1)
        maxn = max(dp[n][m][p],maxn);
        printf("%d\n",maxn);
    }
    return 0;
}
