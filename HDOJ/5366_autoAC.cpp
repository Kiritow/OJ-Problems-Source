#include <iostream>
#include <cstdio>
using namespace std;
__int64 dp[62];
int main()
{
    int m;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int i=4; i<61; i++)
        dp[i] = dp[i-1]+dp[i-3]+1;
    while(~scanf("%d",&m))
    {
        printf("%I64d\n",dp[m]);
    }
    return 0;
}
