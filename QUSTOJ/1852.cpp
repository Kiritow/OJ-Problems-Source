#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[2048];
int b[2048];
int c;
int d;
int main()
{
    int t;
    int tmp;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d",&tmp);
        if(tmp<=0)
        {
            a[c++]=tmp;
        }
        else
        {
            b[d++]=tmp;
        }
    }
    for(int i=0;i<c-1;i++)
    {
        printf("%d ",a[i]);
    }
    printf("%d\n",a[c-1]);
    for(int i=0;i<d-1;i++)
    {
        printf("%d ",b[i]);
    }
    printf("%d\n",b[d-1]);
    return 0;
}
