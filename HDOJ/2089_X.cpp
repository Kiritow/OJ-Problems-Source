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

bool ck[1000100];
char buff[16];

int main()
{
    for(int i=0;i<1000001;i++)
    {
        sprintf(buff,"%d",i);
        ck[i]=(strstr(buff,"4")!=NULL||strstr(buff,"62")!=NULL);
    }

    int n,m;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(!n&&!m) break;
        int cc=0;
        for(int i=n;i<=m;i++)
        {
            cc+=(int)!ck[i];
        }
        printf("%d\n",cc);
    }
    return 0;
}
