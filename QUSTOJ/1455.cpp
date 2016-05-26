#include <cstdio>
using namespace std;
 
int main()
{
    long n;
    while(scanf("%ld",&n)==1&&n!=0)
    {
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        int t=1;
        --n;
        while(n>=3)
        {
            n=n/3;
            t++;
        }
        printf("%d\n",t);
    }
    return 0;
}
