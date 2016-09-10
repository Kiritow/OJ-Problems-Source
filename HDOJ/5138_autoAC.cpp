#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n<3)
        {
            printf("%d\n",n-1);
        }
        else if(n<5)
        {
            printf("%d %d\n",n-2,n-1);
        }
        else if(n<8)
        {
            printf("%d %d %d\n",n-4,n-2,n-1);
        }
        else if(n<16)
        {
            printf("%d %d %d %d\n",n-7,n-4,n-2,n-1);
        }
        else
        {
            printf("%d %d %d %d %d\n",n-15,n-7,n-4,n-2,n-1);
        }
    }
    return 0;
}
