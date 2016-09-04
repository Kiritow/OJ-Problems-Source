#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
using namespace std;
#define eps (1e-9)
double r,v,w,X,E;
bool zero(double t)
{
    return fabs(t)<eps;
}
double jifen(double t)
{
    return (t*v*sqrt(r*r+t*t*v*v)+r*r*log(v*(t*v+sqrt(r*r+t*t*v*v))))/(2*v);
}
bool ok(double mid)
{
    double tmp=X*sqrt(r*r*w*w+v*v)*(jifen(mid)-jifen(0));
    if(tmp+eps>E)
        return true;
    return false;
}
int main()
{
    while(scanf("%lf%lf%lf%lf%lf",&r,&w,&v,&X,&E)!=EOF)
    {
        if(zero(r)&&zero(w)&&zero(v)&&zero(X)&&zero(E))
            break;
        double left=0,right=30*24*3600.0,ans=-1,mid;
        int cas=100;
        if(zero(r))
        {
            printf("%.4lf\n",sqrt(2*E/v/v));
            continue;
        }
        while(cas--)
        {
            mid=(left+right)/2;
            if(ok(mid))
            {
                ans=mid;
                right=mid;
            }
            else
            {
                left=mid;
            }
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}
