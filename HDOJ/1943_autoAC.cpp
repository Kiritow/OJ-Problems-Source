#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
const double PI=acos(-1.0);
#define eps 1e-3
int main()
{
    int T;
    double D,d,s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf",&D,&d,&s);
       double temp=asin((d+s)/(D-d));
       double tt=(2*PI)/(2*temp);
       printf("%d\n",(int)tt);
    }
    return 0;
}
