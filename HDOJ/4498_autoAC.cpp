#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
vector<double>x;
void add(int a1,int b1,int c1)
{
    if(a1 == 0 && b1 == 0)
    {
        return;
    }
    if(a1 == 0)
    {
        double t = -c1*1.0/b1;
        if(t >= 0 && t <= 100)
            x.push_back(t);
        return;
    }
    long long deta = b1*b1 - 4LL*a1*c1;
    if(deta < 0)return;
    if(deta == 0)
    {
        double t = (-1.0 * b1)/(2.0 * a1);
        if(t >= 0 && t <= 100)
            x.push_back(t);
    }
    else
    {
        double t1 = (-1.0 * b1 + sqrt(1.0*deta))/(2.0*a1);
        double t2 = (-1.0 * b1 - sqrt(1.0*deta))/(2.0*a1);
        if(t1 >= 0 && t1 <= 100)
            x.push_back(t1);
        if(t2 >= 0 && t2 <= 100)
            x.push_back(t2);
    }
}
int A[100],B[100],C[100];
int best;
double F(double x1)
{
    return sqrt(1.0 + (x1*2*A[best] + 1.0 * B[best])*(x1*2*A[best] + 1.0 * B[best]));
}
double simpson(double a,double b)
{
    double c = a + (b-a)/2;
    return (F(a) + 4*F(c) + F(b))*(b-a)/6;
}
double asr(double a,double b,double eps,double A)
{
    double c = a + (b-a)/2;
    double L = simpson(a,c);
    double R = simpson(c,b);
    if(fabs(L+R-A) <= 15*eps)return L+R+(L+R-A)/15;
    return asr(a,c,eps/2,L) + asr(c,b,eps/2,R);
}
double asr(double a,double b,double eps)
{
    return asr(a,b,eps,simpson(a,b));
}
int main()
{
    int T;
    int k,a,b;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        A[0] = 0;
        B[0] = 0;
        C[0] = 100;
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d%d",&k,&a,&b);
            A[i] = k;
            B[i] = -2*a*k;
            C[i] = k*a*a + b;
        }
        x.clear();
        for(int i = 0;i <= n;i++)
            for(int j = i+1;j <= n;j++)
                add(A[i]-A[j],B[i] - B[j],C[i] - C[j]);
        double ans = 0;
        x.push_back(0);
        x.push_back(100);
        sort(x.begin(),x.end());
        int sz = x.size();
        for(int i = 0;i < sz-1;i++)
        {
            double x1 = x[i];
            double x2 = x[i+1];
            if(fabs(x2-x1) < 1e-8)continue;
            double mid = (x1 + x2)/2;
            best = 0;
            for(int j = 1;j <= n;j++)
            {
                double tmp1 = mid*mid*A[best] + mid*B[best] + C[best];
                double tmp2 = mid*mid*A[j] + mid*B[j] + C[j];
                if(tmp2 < tmp1)best = j;
            }
            ans += asr(x1,x2,1e-8);
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}
