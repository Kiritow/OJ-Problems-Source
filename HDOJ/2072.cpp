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

/// This Contest and Compile does not support C++11.
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//#include <functional>

using namespace std;


int main()
{
    string s;
    while(getline(cin,s))
    {
        if(s.at(0)=='#') break;

        istringstream istr(s);

        vector<string> vec;

        int cc=0;
        string temp;
        while(istr>>temp)
        {
            if(find(vec.begin(),vec.end(),temp)==vec.end())
            {
                vec.push_back(temp);
                ++cc;
            }
        }
        cout<<cc<<endl;
    }
    return 0;
}
