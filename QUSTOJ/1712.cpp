#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int M[55][55];

int dp[55][55];

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&M[i][j]);
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+M[i][j];
        }
    }
    printf("%d\n",dp[m][n]);
    return 0;
}
