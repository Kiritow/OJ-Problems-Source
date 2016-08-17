#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int xiede(double m,double n)
{
    double gen3=1.732051;
    int max,x,y;
    x=(int)(2*gen3*(m-1)/3.0);
    if(m>=1)x++;
    y=(int)n;
    max=x*y;
    if(n-y<0.50000)
    max=max-(int)(x/2);
    return max;
}
int main()
{
    double m,n,gen3=1.732051;
    int aa,bb,max1,max2,max3,max23,x,y;
    while(~scanf("%lf%lf",&m,&n))
    {
        aa=(int)m;bb=(int)n;
        max1=aa*bb;
        max2=xiede(m,n);
        max3=xiede(n,m);   
        max23=max2>=max3?max2:max3;
        if(max1>=max23)
         printf("%d grid\n",max1);
        else
         printf("%d skew\n",max23);
    }
    return 0;
}
