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
    int n;
    while(cin>>n)
    {
        if(!n) break;

        vector<string> namevec;
        vector<int> cntvec;

        string s;
        int a,b;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            vector<string>::iterator iter=find(namevec.begin(),namevec.end(),s);
            if(iter!=namevec.end())
            {
                a=iter-namevec.begin();
            }
            else
            {
                namevec.push_back(s);
                cntvec.push_back(0);
                a=namevec.size()-1;
            }
            cin>>s;
            iter=find(namevec.begin(),namevec.end(),s);
            if(iter!=namevec.end())
            {
                b=iter-namevec.begin();
            }
            else
            {
                namevec.push_back(s);
                cntvec.push_back(0);
                b=namevec.size()-1;
            }

            ++cntvec.at(b);
        }

        int sz=cntvec.size();
        int cc=0;
        for(int i=0;i<sz;i++)
        {
            if(cntvec.at(i)==0)
            {
                ++cc;
            }
        }

        if(cc!=1)
        {
            cout<<"No"<<endl;
        }
        else
        {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
