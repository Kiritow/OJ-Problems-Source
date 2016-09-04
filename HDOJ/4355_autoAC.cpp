#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int N = 10e4+1;
const float eps = 1e-2;
struct po
{
    double x;
    double w;
} point[N];
int main()
{
    int t;
    scanf("%d",&t);
    for(int cases = 1; cases<=t; cases++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)
            scanf("%lf %lf",&point[i].x,&point[i].w);
        double low = point[1].x;
        double high = point[n].x;
        double sum1 = 10;
        double sum2 = 0;
        while(fabs(sum1-sum2)>eps)
        {
            double mid1 = low + (high-low)/3;
            double mid2 = high - (high-low)/3;
            sum1 = sum2 = 0;
            for(int i=1; i<=n; i++)
            {
                sum1 += pow((fabs(point[i].x - mid1)),3)*point[i].w;
                sum2 += pow((fabs(point[i].x - mid2)),3)*point[i].w;
            }
            if(sum1<sum2)
                high = mid2;
            else if(sum1>sum2)
                low = mid1;
            else if(sum1==sum2)
                low = high;
        }
        printf("Case #%d: %.0lf\n",cases,sum1);
    }
    return 0;
}
