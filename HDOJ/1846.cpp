#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        if(n%(m+1)==0)
        {
            printf("second\n");
        }
        else
        {
            printf("first\n");
        }
    }
    return 0;
}
