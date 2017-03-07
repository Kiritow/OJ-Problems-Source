#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <cstdio>
#include <cstdlib>
#include <cstring>

/// This Contest and Compile does not support C++11.
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>

using namespace std;

int box[105][105];
int dp[105][105];

int main()
{
    int C;
    cin>>C;
    while(C--)
    {
        int n;
        cin>>n;

        memset(box,0,sizeof(box));
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                cin>>box[i][j];
            }
        }

        dp[0][0]=box[0][0];

        for(int i=1;i<n;i++)
        {
            dp[i][0]=box[i][0]+dp[i-1][0];
            for(int j=0;j<i;j++)
            {
                dp[i][j]=box[i][j]+max(dp[i-1][j-1],dp[i-1][j]);
            }
            dp[i][i]=box[i][i]+dp[i-1][i-1];
        }

        int maxVal=-1;
        for(int i=0;i<n;i++)
        {
            maxVal=max(maxVal,dp[n-1][i]);
        }
        cout<<maxVal<<endl;
    }
    return 0;
}
