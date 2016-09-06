#include<iostream>
#include<algorithm>
#include<string.h>
#include<stack>
#include<queue>
#include<math.h>
#include<cstdio>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
const int maxn=500;
const int inf=0x7fffff;
double A(double x)
{
    double r=1;    
    for(double i=1;i<=x;i++)
        r*=i;
    return r;
}
double C(double m,double n)
{
    double r=1;
    for(double i=n-m+1;i<=n;i++)
        r*=i;
    for(double i=m;i>=1;i--)
        r/=i;
    return r;    
}
int main()
{
    int t,a;
    double n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lf%lf",&a,&n,&m);
        double ans=0;
        if(m==1) ans+=A(n-1);
        else 
            for(double i=1;i<m;i++)
            {
                if(i==1)    
                    ans+=A(n-2);
                else ans+=A(n-1-i)*A(i)*C(i-1,m-2);
            }
        printf("%d %0.lf\n",a,ans);
    }
    return 0;
}
