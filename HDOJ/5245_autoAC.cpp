#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
    int t,tm,k;
    double n,m;
    scanf("%d",&t);tm=t;
    while(t--)
    {
        scanf("%lf%lf%d",&n,&m,&k);
        double ans=0;
        for(double i=1;i<=n;i++)
            for(double j=1;j<=m;j++)
            {
                double p=m*n;
                p+=(i-1)*(j-1)*(n-i+1)*(m-j+1);
                p+=(i-1)*(m-j)*(n-i+1)*j;
                p+=(j-1)*(n-i)*(m-j+1)*i;
                p+=(n-i)*(m-j)*i*j;
                p+=(i-1)*m*(n-i+1);
                p+=(m-j)*n*j;
                p+=(n-i)*m*i;
                p+=(j-1)*n*(m-j+1);
                p=p/n/n/m/m;
                ans+=1-(pow(1-p,k));
            }
            printf("Case #%d: %d\n",tm-t,int(ans+0.5));
    }
    return 0;
}
