#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int T,a,b;
    scanf("%d",&T);
    for (int i=1;i<=T;i++)
    {
        scanf("%d%d",&a,&b);
        double a1=1-pow(1-1.0/a,b);
        double x=a;
        double ans=x*(x+1)/2*a1;
        printf("Case #%d: %.3lf\n",i,ans);
    }
}
