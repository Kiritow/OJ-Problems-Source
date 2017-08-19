#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    int cnt=0;
    for(int i=0;i<t;i++)
    {
        int a;
        scanf("%d",&a);
        if(a<=35) ++cnt;
    }
    printf("%d\n",cnt);
    return 0;
}