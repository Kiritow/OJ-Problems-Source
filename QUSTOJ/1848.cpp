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
    for(int i=0;i<c;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
