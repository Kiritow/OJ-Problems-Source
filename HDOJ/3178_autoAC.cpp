#include <cstdio>
#include <iostream>
using namespace std;
#define N 1005
#define L 0.0000001
double a[N];
double b[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int i = 0;
        for(i = 1; i <= n; i++)
            scanf("%lf%lf",&a[i],&b[i]);
        int p1,p2;
        scanf("%d%d",&p1,&p2);
        double x1 = a[p2] - a[p1];
        double y1 = b[p2] - b[p1];
        for(i = 1; i <= n; i++)
        {
            double x2 = a[i] - a[p1];
            double y2 = b[i] - b[p1];
            double sum = x1*y2 - x2*y1;
            if(sum < -L)
                printf("Right\n");
            else if(sum > L)
                printf("Left\n");
            else printf("On\n");
        }
    }
    return 0;
}
