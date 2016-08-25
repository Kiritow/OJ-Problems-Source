#include<cstdio>
#include<cstring>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<cmath>
using namespace std;
const double eps=1e-8;
int y;
double g(double x)
{
    return 42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x;
}
double f(double x)
{
    return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&y);
        if(g(100.0)-y<=0)
        {
            printf("%.4lf\n",f(100.0));
            continue;
        }
        double l=0,r=100,m;
        while(l+eps<=r)
        {
            m=(l+r)/2;
            if(g(m)-y<0)
                l=m;
            else
                r=m;
        }
        printf("%.4lf\n",f(m));
    }
    return 0;
}
