#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"math.h"
#define e 1e-9
int n;
int a[10011],b[10011],c[10011];
double MAX(double q,double p)
{
    return q>p?q:p;
}
double cal(double x)
{
    int i;
    double max=-111111111;
    for(i=0;i<n;i++)    max=MAX(max,a[i]*x*x+b[i]*x+c[i]);
    return max;
}
double solve()
{
    double left,right,mid,midmid;
    double mid_cal,midmid_cal;
    left=0;
    right=1000;
    while(right-left>e)
    {
        mid=(left+right)/2;
        midmid=(mid+right)/2;
        mid_cal=cal(mid);
        midmid_cal=cal(midmid);
        if(mid_cal>midmid_cal)    left=mid;
        else                    right=midmid;
    }
    return cal(right);
}
int main()
{
    int T;
    int i;
    double ans;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)    scanf("%d%d%d",&a[i],&b[i],&c[i]);
        ans=solve();
        printf("%.4lf\n",ans);
    }
    return 0;
}
