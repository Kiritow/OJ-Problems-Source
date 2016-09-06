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
using namespace std;
const int MAXN = 50010;
double c[MAXN][10];
double p[MAXN][20];
double a[MAXN][10];
double b[MAXN];
double dp[MAXN];
int main()
{
    int n,m;
    while( scanf("%d%d",&n,&m) == 2 )
    {
        if(n == 0 && m == 0)break;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= m;j++)
                scanf("%lf",&c[i][j]);
        for(int i = 1;i < n;i++)
        {
            double sum = 0;
            for(int j = 1;j <= m;j++)
                sum += c[i][j];
            double s = 0;
            for(int j = 1;j <= m && i-j >= 1;j++)
            {
                p[i][m-j] = 0.3*c[i][j]/(1+sum);
                s += p[i][m-j];
            }
            for(int j = 1;j <= m && i+j <= n;j++)
            {
                p[i][m+j] = 0.7*c[i][j]/(1+sum);
                s += p[i][m+j];
            }
            p[i][m] = -s;
            b[i] = -1;
        }
        for(int i = 1;i <= m+1 && i <= n;i++)
            a[1][i] = p[1][m+i-1];
        for(int i = 2;i < n;i++)
        {
            int end = min(i+m,n);
            int start = max(1,i-m);
            for(int j = start;j < i;j++)
                if(fabs(p[i][m+j-i]) > 1e-6)
                {
                    double t = p[i][m+j-i]/a[j][1];
                    for(int k = 1; k <= m+1 && j+k-1 <= n ;k++)
                    {
                        p[i][m+j-i+k-1] -= t*a[j][k];
                    }
                    b[i] -= t*b[j];
                }
            for(int j = 1;j <= end-i+1;j++)
                a[i][j] = p[i][m+j-1];
        }
        dp[n] = 0;
        for(int i = n-1;i >= 1;i--)
        {
            for(int j = 2;j <= m+1 && i+j-1 <= n;j++)
                b[i] -= dp[i+j-1] * a[i][j];
            dp[i] = b[i]/a[i][1];
        }
        printf("%.2f\n",dp[1]);
    }
    return 0;
}
