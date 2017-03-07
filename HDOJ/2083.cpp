#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>

/// This Contest and Compile does not support C++11.
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>

using namespace std;


int main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        int n;
        cin>>n;
        vector<int> vec;
        for(int j=0;j<n;j++)
        {
            int temp;
            cin>>temp;
            vec.push_back(temp);
        }

        int minVal=INT_MAX;
        for(int j=0;j<n;j++)
        {
            int sum=0;
            for(int k=0;k<n;k++)
            {
                sum+=abs(vec.at(j)-vec.at(k));
            }
            minVal=min(sum,minVal);
        }

        cout<<minVal<<endl;
    }
    return 0;
}
