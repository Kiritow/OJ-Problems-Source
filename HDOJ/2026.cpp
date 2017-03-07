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
        string temp;
        istringstream istr(s);
        ostringstream ostr;

        while(istr>>temp)
        {
            if(temp.at(0)>='a'&&temp.at(0)<='z')
            {
                temp.at(0)=temp.at(0)-'a'+'A';
            }
            ostr<<temp<<" ";
        }

        string ss=ostr.str();
        ss.erase(ss.end()-1);
        cout<<ss<<endl;
    }

    return 0;
}
