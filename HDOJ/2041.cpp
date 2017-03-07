#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cstring>

/// This Contest and Compile does not support C++11.
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>

using namespace std;

long long yh[42][42];
long long vv[42];

int main()
{
    yh[0][0]=0;
    for(int i=1;i<=40;i++)
    {
        yh[i][0]=1;
        for(int j=1;j<i;j++)
        {
            yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
        }
        yh[i][i]=1;
    }

    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        if(m==1)
        {
            cout<<0<<endl;
            continue;
        }
        --m;

        int a=m/2;
        int sum=1;
        for(int j=1;j<=a;j++)
        {
            sum+=yh[m-j][j];
        }
        cout<<sum<<endl;
    }

    return 0;
}
