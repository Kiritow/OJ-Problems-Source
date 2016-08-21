#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    while(cin>>n&&n)
    {
        while(n--)
        {
            double x1,x2,x3,y1,y2,y3;
            cin>>x1>>y1>>x2>>y2>>x3>>y3;\
            double ans1=(double)(x1+x2+x3)/3.0;
            double ans2=(double) (y1+y2+y3)/3.0;
            printf("%.1lf %.1lf\n",ans1,ans2);
        }
    }
    return 0;
}
