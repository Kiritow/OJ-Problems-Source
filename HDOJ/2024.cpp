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

char line[1024];

int main()
{
    //cout<<"Hello World!"<<endl;
    int n;
    scanf("%d%*c",&n);
    for(int i=0;i<n;i++)
    {
        gets(line);
        if(!((line[0]>='A'&&line[0]<='Z')||(line[0]>='a'&&line[0]<='z')||(line[0]=='_')))
        {
            printf("no\n");
            continue;
        }

        int len=strlen(line);
        bool done=false;

        for(int j=1;j<len;j++)
        {
            if(!(
                 (line[j]>='A'&&line[j]<='Z')||
                 (line[j]>='a'&&line[j]<='z')||
                 (line[j]=='_')||
                 (line[j]>='0'&&line[j]<='9')
                ))
            {
                printf("no\n");
                done=true;
                break;
            }
        }

        if(!done)
        {
            printf("yes\n");
        }
    }

    return 0;
}
