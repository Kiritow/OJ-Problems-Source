#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    int t;
    double a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        printf("%.1lf\n",sqrt((a-c)*(a-c)+(b-d)*(b-d)));
    }
    return 0;
}
