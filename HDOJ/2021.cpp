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


int main()
{
    //cout<<"Hello World!"<<endl;
    while(1)
    {
        int n;
        cin>>n;
        if(!n) break;
        int cc=0;
        for(int i=0;i<n;i++)
        {
            int temp;
            cin>>temp;
            int ans=0;
            ans+=temp/100;
            temp%=100;
            ans+=temp/50;
            temp%=50;
            ans+=temp/10;
            temp%=10;
            ans+=temp/5;
            temp%=5;
            ans+=temp/2;
            temp%=2;
            ans+=temp;
            cc+=ans;
        }
        cout<<cc<<endl;
    }

    return 0;
}
