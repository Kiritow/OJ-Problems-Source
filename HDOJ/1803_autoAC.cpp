#include <cstdlib>
#include <cmath>
#include <iostream>
double pi=3.1415926535897932;
using namespace std;
double MIN(double x,double y)
{
    if(x-y>0) return y;
    else return x;
}     
int main()
{
    double x,y;
    while(scanf("%lf%lf",&x,&y)!=EOF)
    {
        if(x<1&&y<1) break;
        double x1=x*x*(y-x/pi)/(4*pi);
        double temp=MIN(y/(pi+1),x);
        double y1=pi*temp*temp*x/4;       
        if(x1-y1>0) printf("%.3f\n",x1);
        else printf("%.3lf\n",y1);
    }                               
    return 0;
}
