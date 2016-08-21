#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#define EPS (1e-6)
using namespace std;
double Y;
double f(double x){return 8*x*x*x*x+7*x*x*x+2*x*x+3*x+6-Y;}
double f_(double x){return 32*x*x*x+21*x*x+4*x+3;}
double NewtonIteration(double x,int counter=0)
{
    if(counter>10000)return -1;
    double index=f(x)/f_(x);
    return (fabs(index)<EPS)?(x-index):NewtonIteration(x-index,counter+1);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf",&Y);
        double ans=NewtonIteration(0);
        if(ans>=0&&ans<=100)
            printf("%.4lf\n",ans);
        else
            printf("No solution!\n");
    }
    return 0;
}
