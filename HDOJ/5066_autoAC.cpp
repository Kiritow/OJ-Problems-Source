#include <cstdio>
using namespace std;
int main(void)
{
    int v,v0;
    while(~scanf("%d %d", &v,&v0))
        printf("%d\n",2 * v - v0);
    return 0;
}
