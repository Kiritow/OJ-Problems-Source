#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int m;
    int cc=1;
    while(scanf("%d",&m)==1)
    {
        int k=m*log(2)/log(10);
        printf("Case #%d: %d\n",cc,k);
        ++cc;
    }
    return 0;
}
