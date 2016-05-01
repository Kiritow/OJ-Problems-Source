#include <cstdio>
using namespace std;
 
 
const double pi=3.1415926;
 
double round;
 
int main()
{
    while(scanf("%lf",&round)==1)
    {
        double ans=4*pi*round*round*round/3;
        printf("%.3lf\n",ans);
    }
    return 0;
}
