#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
    int i,j,n,t,b;
    int a[11];
    while(scanf("%d",&t)!=EOF)
    {
        int k=1;
        while(t--)
        {
            scanf("%d",&b);
            for(i=0;i<10;i++)
               scanf("%d",&a[i]);
            sort(a,a+10);
            printf("%d %d\n",k++,a[7]);
        }
    }
    return 0;
}
