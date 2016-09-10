#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
double a,b,c,d,L,R;
double f(double x)
{
        return fabs(a*x*x*x+b*x*x+c*x+d);
}
const double eps=1e-9;
int dcmp(double x)
{
        if(fabs(x)<=eps)return 0;
        else return x<0?-1:1;
}
bool judge(double x)
{
        return x<=R&&x>=L;
}
int main()
{
        while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&L,&R)!=EOF)
        {
                double delta=4*b*b-12*a*c;
                double ans;
                if(dcmp(a)==0)
                {
                        double mid=-c/2/b;
                        if(judge(mid))
                                ans=max(f(mid),f(L));
                        else ans=f(L);
                        ans=max(ans,f(R));
                }
                else if(delta<=0)
                {
                         ans=max(f(L),f(R));
                }
                else
                {
                        delta=sqrt(delta);
                        double x1=-2*b+delta;
                        x1=x1/6/a;
                        double x2=-2*b-delta;
                        x2=x2/6/a;
                        ans=f(L);
                        ans=max(ans,f(R));
                        if(judge(x1))
                                ans=max(ans,f(x1));
                        if(judge(x2))
                                ans=max(ans,f(x2));
                }
                printf("%.2lf\n",ans);
        }
        return 0;
}
