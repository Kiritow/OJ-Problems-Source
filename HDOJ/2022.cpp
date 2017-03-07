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
    int m,n;
    while(cin>>m)
    {
        cin>>n;
        int maxABS=0;
        int oVal=0;
        int maxLine=-1,maxCol=-1;
        for(int line=0;line<m;line++)
        {
            for(int col=0;col<n;col++)
            {
                int temp;
                cin>>temp;
                if(abs(temp)>maxABS)
                {
                    maxABS=abs(temp);
                    oVal=temp;
                    maxLine=line+1;
                    maxCol=col+1;
                }
            }
        }
        cout<<maxLine<<" "<<maxCol<<" "<<oVal<<endl;
    }

    return 0;
}
