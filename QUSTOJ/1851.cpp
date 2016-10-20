#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int a[2048];
int b[2048];
int x[4096];
int c;
int d;
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
        scanf("%d",&b[d++]);
    }
    int* p=set_difference(a,a+c,b,b+d,x);
    int dd=p-x;
    if(dd==0)
    {
        printf("NULL\n");
        /// 题目似乎有问题...
        /// printf("0\n");
        return 0;
    }
    for(int i=0;i<dd-1;i++)
    {
        printf("%d ",x[i]);
    }
    printf("%d\n",x[dd-1]);
    printf("%d\n",dd);
    return 0;
}
