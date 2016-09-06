#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define LL long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define N 1000010
#define clr(a) (memset(a,0,sizeof(a)))
using namespace std;
LL dp[21][2],ans[21],c[21][21];
void init()
{
    for(int i=0;i<=20;i++)c[i][0]=c[i][i]=1;
    for(int i=1;i<=20;i++)
        for(int j=1;j<i;j++)c[i][j]=c[i-1][j-1]+c[i-1][j];
    dp[0][0]=dp[0][1]=dp[1][1]=dp[1][0]=1;ans[1]=1;
    for(int i=2;i<=20;i++)
    {
        for(int j=1;j<=i;j++)
        {
            ans[i]+=c[i-1][j-1]*dp[j-1][0]*dp[i-j][1];
        }
        dp[i][0]=dp[i][1]=ans[i]/2;
    }
}
int main()
{
    int t,cas,n;init();
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&cas,&n);
        printf("%d %I64d\n",cas,ans[n]);
    }
}
