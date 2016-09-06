#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int X,Y;
    double P,Q;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%lf%lf",&X,&Y,&P,&Q);
        double ans1=(1-Q)*X+Q*(P*X+P*Y);
        double ans2=Q*Y+(1-Q)*(P*X+P*Y);
        if(ans1>ans2)printf("tiger %.4lf\n",ans1);
        else printf("wolf %.4lf\n",ans2);
    }
    return 0;
}
