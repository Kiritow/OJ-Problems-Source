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

const char* lab="0123456789ABCDEF";

int main()
{
    int n,r;
    while(cin>>n)
    {
        cin>>r;
        bool isE=false;
        if(n<0){isE=true;n=abs(n);}
        stack<char> s;
        while(1)
        {
            int b=n%r;
            s.push(lab[b]);
            n/=r;
            if(n<r)
            {
                s.push(lab[n]);
                break;
            }
        }
        if(isE) cout<<"-";
        while(!s.empty())
        {
            cout<<s.top();
            s.pop();
        }
        cout<<endl;
    }

    return 0;
}
