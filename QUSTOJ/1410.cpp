#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
 
int main()
{
    int m,n;
    scanf("%d",&n);
    int ans=1;
    m=2;
    while(1)
    {
        int p=m*m*m;
        if(ans+p<=n)
        {
            ans+=p;
            m++;
            continue;
        }
        else
        {
            break;
        }
    }
    printf("%d\n",m-1);
    return 0;
}
 
/**************************************************************
    Problem: 1410
    User: 1508080112
    Language: C++
    Result: 正确
    Time:4 ms
    Memory:800 kb
****************************************************************/
