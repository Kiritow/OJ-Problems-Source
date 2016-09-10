#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include<stack>
using namespace std;
typedef long long ll;
const double eps=0.0000000000001;
double dp[1000005];
int main()
{
    int n,m;
    while(~scanf("%d%d",&m,&n))
    {
        int flag=1;
        memset(dp,0,sizeof(dp));
        dp[0]=1.0;
        dp[1]=1.0/m;
        for(int i=2;i<=n;i++)
        {
           dp[i]+=dp[i-1]*(m+1)/m;
           if(i-1-m>=0)
           dp[i]-=dp[i-1-m]/m;
           if(fabs(dp[i]-dp[i-1])<eps)
         {
             printf("%.5lf\n",dp[i]);
             flag=0;
             break;
        }
        }
        if(flag)
        {
            printf("%.5lf\n",dp[n]);
        }
    }
}
