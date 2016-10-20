#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[4096];
int c;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&a[c++]);
    }
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&a[c++]);
    }
    sort(a,a+c);
    for(int i=0;i<c-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[c-1]);
    return 0;
}
