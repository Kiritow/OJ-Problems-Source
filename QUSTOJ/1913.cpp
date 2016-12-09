#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[110000];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int i=n-1;i>0;--i)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[0]);
    return 0;
}
