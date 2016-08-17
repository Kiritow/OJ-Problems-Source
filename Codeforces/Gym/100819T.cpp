#include <cstdio>
#include <algorithm>
using namespace std;
int a[3];
int b[3];
int main()
{
    for(int i=0;i<3;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<3;i++)
    {
        scanf("%d",&b[i]);
    }
    sort(a,a+3);
    sort(b,b+3);
    if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2] && a[2]*a[2]==a[0]*a[0]+a[1]*a[1] )
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}
