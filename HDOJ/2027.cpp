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
    int n;
    char c;
    cin>>n>>c;
    while(n--)
    {
        string s;
        getline(cin,s);
        int A=0;
        int E=0;
        int I=0;
        int O=0;
        int U=0;
        for(size_t i=0;i<s.size();i++)
        {
            switch(s.at(i))
            {
            case 'a':case 'A':A++;break;
            case 'e':case 'E':E++;break;
            case 'i':case 'I':I++;break;
            case 'o':case 'O':O++;break;
            case 'u':case 'U':U++;break;
            }
        }

        cout<<"a:"<<A<<endl;
        cout<<"e:"<<E<<endl;
        cout<<"i:"<<I<<endl;
        cout<<"o:"<<O<<endl;
        cout<<"u:"<<U<<endl;

        if(n) cout<<endl;
    }

    return 0;
}
