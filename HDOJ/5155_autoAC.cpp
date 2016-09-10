#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define Mod 1000000007
#define lll __int64
using namespace std;
lll c[55][55];
lll dp[55][55];
void calc()
{
    for(int i=0;i<=51;i++)
    {
        c[i][0] = 1;
        for(int j=1;j<=i;j++)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%Mod;
    }
}
int main()
{
    int n,m,i,j,k,t;
    calc();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0] = 1;
        for(i=1;i<=n;i++)           
        {
            for(k=1;k<=m;k++)        
            {
                for(j=0;j<=k;j++)   
                {
                    for(t=max(1,k-j);t<=k;t++)   
                    {
                        dp[i][k] = (dp[i][k]+dp[i-1][j]*c[m-j][k-j]%Mod*c[j][t-(k-j)]%Mod)%Mod;
                    }
                }
            }
        }
        printf("%I64d\n",dp[n][m]%Mod);
    }
    return 0;
}
