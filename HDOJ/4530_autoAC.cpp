#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
    int t,q,a,b,i;
    double x,ans;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%d",&x,&q);
        for(i = 1; i<=q; i++)
        {
            scanf("%d%d",&a,&b);
            if(a == 1)
                ans = b*60.0-b*x;
            else if(a == 2)
                ans = b*3600.0/(60.0-x);
            else if(a == 3)
                ans = 43200*b*60/x;
            printf("%.2lf\n",ans);
        }
    }
    return 0;
}
