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
        int a,b;
        scanf("%d %d",&a,&b);
        printf("%d\n",a/b+!!(a%b));
    }
    return 0;
}
