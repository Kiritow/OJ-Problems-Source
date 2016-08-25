#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
struct bank
{
    int mon;
    float pro;
}b[110];
int n;
int main ()
{
    int T,i,j;
    cin>>T;
    int sum;
    double dp[100010];
    while(T--)
    {
        float p;
        cin>>p>>n;
        sum=0;
        for(i=1;i<=n;i++)
        {
            cin>>b[i].mon>>b[i].pro;
            sum+=b[i].mon;
        }
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(i=1;i<=n;i++)
            for(j=sum;j>=b[i].mon;j--)
            {
                if(dp[j]<dp[j-b[i].mon]*(1-b[i].pro))
                    dp[j]=dp[j-b[i].mon]*(1-b[i].pro);
            }
        for(i=sum;i>=0&&dp[i]<(1-p);i--);
        cout<<i<<endl;
    }
    return 0;
}
