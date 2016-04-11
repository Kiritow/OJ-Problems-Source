#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int n,R,r;
    while(scanf("%d %d %d",&n,&R,&r)==3)
    {
        if(n==1)
        {
            if(R<r)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
            continue;
        }
        if(n==2)
        {
            if(R<2*r)
            {
                printf("NO\n");
            }
            else
            {
                printf("YES\n");
            }
            continue;
        }
        int maxN=1/(asin((double)r/(R-r))/3.1415927);
        if(n<=maxN)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}
