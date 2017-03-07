#include <iostream>
#include <string>
#include <vector>
#include <queue>
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


int main()
{
    //cout<<"Hello World!"<<endl;
    string s;
    while(getline(cin,s))
    {
        char maxVal=-1;
        for(size_t i=0;i<s.size();i++)
        {
            maxVal=max(maxVal,s.at(i));
        }

        ostringstream ostr;
        for(size_t i=0;i<s.size();i++)
        {
            ostr<<s.at(i);
            if(s.at(i)==maxVal)
            {
                ostr<<"(max)";
            }
        }
        cout<<ostr.str()<<endl;
    }

    return 0;
}
