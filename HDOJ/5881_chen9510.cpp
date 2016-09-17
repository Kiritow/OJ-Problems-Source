#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <string.h>
using namespace std;

int main()
{
    long long L,R;
    while(scanf("%lld%lld",&L,&R)!=EOF)
    {
        if(L==R)
        {
            if(R<=1) puts("0");
            else if(R==2) puts("1");
            else puts("2");
            continue;
        }
        if(L==0)
        {
            if(R==1) puts("0");
            else if(R==2) puts("1");
            else printf("%lld\n",(R+1)/2);
        }
        else
        {
            if(L==1&&R==2)  puts("1");
            else{
            if(L+2>=R-1) puts("2");
            else printf("%lld\n",(R-L+2)/2);
            }
        }
    }
    return 0;
}
