#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
double POW(int n)
{
    double s = 1;
    for(int i = 1; i <= n; i++)
    {
        s*=0.95;
    }
    return s;
}
int main()
{
    int n;
    int t;
    double a[57];
    while(~scanf("%d",&t))
    {
        while(t--)
        {
            scanf("%d",&n);
            for(int i = 1; i <= n; i++)
            {
                scanf("%lf",&a[i]);
            }
            sort(a+1,a+n+1);
            double ans = 0;
            int j = 0;
            for(int i = n; i >= 1; i--)
            {
                ans+=a[i]*POW(j++);
            }
            printf("%.10lf\n",ans);
        }
    }
    return 0;
}
