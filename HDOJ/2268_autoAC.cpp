#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    double time,a,b,c;
    while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
    {
        if(a>=b)time=c*1.0/a;
        else {
            double L=2*a*c/(3*a+b);
            time=(c-L)/b+L/a;
        }
        printf("%.3lf\n",time);
    }
    return 0;
}
